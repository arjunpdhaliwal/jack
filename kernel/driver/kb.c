#include <driver/kb.h>
#include <interrupt/irq.h>
#include <system.h>
#include <string.h>
#include <stdint.h>

#define FROM_BUF_SIZE 64
#define TO_BUF_SIZE 64

#define KEY_ERROR_BUF_OVERRUN_1 0x00
#define SELF_TEST_PASSED 0xAA
#define ECHO_ACK 0xEE
#define CMD_ACK 0xFA
#define SELF_TEST_FAILED_1 0xFC
#define SELF_TEST_FAILED_2 0xFD
#define CMD_RESEND 0xFE
#define KEY_ERROR_BUF_OVERRUN_2 0xFF

// http://www.brokenthorn.com/Resources/OSDev19.html

static int scancode_table[] = {

	//! key			scancode
	KEY_UNKNOWN,	//0
	KEY_ESCAPE,		//1
	KEY_1,			//2
	KEY_2,			//3
	KEY_3,			//4
	KEY_4,			//5
	KEY_5,			//6
	KEY_6,			//7
	KEY_7,			//8
	KEY_8,			//9
	KEY_9,			//0xa
	KEY_0,			//0xb
	KEY_MINUS,		//0xc
	KEY_EQUAL,		//0xd
	KEY_BACKSPACE,	//0xe
	KEY_TAB,		//0xf
	KEY_Q,			//0x10
	KEY_W,			//0x11
	KEY_E,			//0x12
	KEY_R,			//0x13
	KEY_T,			//0x14
	KEY_Y,			//0x15
	KEY_U,			//0x16
	KEY_I,			//0x17
	KEY_O,			//0x18
	KEY_P,			//0x19
	KEY_LEFTBRACKET,//0x1a
	KEY_RIGHTBRACKET,//0x1b
	KEY_RETURN,		//0x1c
	KEY_LCTRL,		//0x1d
	KEY_A,			//0x1e
	KEY_S,			//0x1f
	KEY_D,			//0x20
	KEY_F,			//0x21
	KEY_G,			//0x22
	KEY_H,			//0x23
	KEY_J,			//0x24
	KEY_K,			//0x25
	KEY_L,			//0x26
	KEY_SEMICOLON,	//0x27
	KEY_QUOTE,		//0x28
	KEY_GRAVE,		//0x29
	KEY_LSHIFT,		//0x2a
	KEY_BACKSLASH,	//0x2b
	KEY_Z,			//0x2c
	KEY_X,			//0x2d
	KEY_C,			//0x2e
	KEY_V,			//0x2f
	KEY_B,			//0x30
	KEY_N,			//0x31
	KEY_M,			//0x32
	KEY_COMMA,		//0x33
	KEY_DOT,		//0x34
	KEY_SLASH,		//0x35
	KEY_RSHIFT,		//0x36
	KEY_KP_ASTERISK,//0x37
	KEY_RALT,		//0x38
	KEY_SPACE,		//0x39
	KEY_CAPSLOCK,	//0x3a
	KEY_F1,			//0x3b
	KEY_F2,			//0x3c
	KEY_F3,			//0x3d
	KEY_F4,			//0x3e
	KEY_F5,			//0x3f
	KEY_F6,			//0x40
	KEY_F7,			//0x41
	KEY_F8,			//0x42
	KEY_F9,			//0x43
	KEY_F10,		//0x44
	KEY_KP_NUMLOCK,	//0x45
	KEY_SCROLLLOCK,	//0x46
	KEY_HOME,		//0x47
	KEY_KP_8,		//0x48	//keypad up arrow
	KEY_PAGEUP,		//0x49
	KEY_KP_2,		//0x50	//keypad down arrow
	KEY_KP_3,		//0x51	//keypad page down
	KEY_KP_0,		//0x52	//keypad insert key
	KEY_KP_DECIMAL,	//0x53	//keypad delete key
	KEY_UNKNOWN,	//0x54
	KEY_UNKNOWN,	//0x55
	KEY_UNKNOWN,	//0x56
	KEY_F11,		//0x57
	KEY_F12			//0x58
};


int to_buffer[TO_BUF_SIZE];
int to_buf_top;

int from_buffer[FROM_BUF_SIZE];
int from_buf_top = 0;

void init_kb_driver()
{
    memset((void *) to_buffer, sizeof(int), TO_BUF_SIZE - 1);
    memset((void *) from_buffer, sizeof(int), FROM_BUF_SIZE - 1);
    install_interrupt_handler(1, kb_interrupt_handler);
    return;
}

void push_buf_to(int cmd)
{
    to_buffer[to_buf_top] = cmd;
    to_buf_top++;
}

uint8_t pop_buf_to()
{
    return to_buffer[to_buf_top--];
}

void push_buf_from(int cmd)
{
    from_buffer[from_buf_top] = cmd;
    from_buf_top++;
}

uint8_t pop_buf_from()
{
    return from_buffer[from_buf_top--];
}

void kb_interrupt_handler(int arg)
{
    uint8_t scancode = inb(0x60);
    if (scancode == CMD_ACK) {
        outb(pop_buf_to(), 0x60);
        return;
    }

    uint8_t character = scancode & 0b01111111;
    int release = (scancode & 0b10000000) >> 7;

    if (release) {
        writec(scancode_table[character]);
    }
    
    return;
}
