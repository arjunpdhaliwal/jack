#include <sys/io.h>
#include <system.h>
#include <interrupt/idt.h>
#include <interrupt/pic.h>

void sys_init()
{
    video_ptr = (char **) VGA_TEXT_BUFFER;
    video_ptr_line = 0;
    video_ptr_offset = 0;
    idt_init();
    pic_init();
	return;
}

void writel(char *str) 
{
	writes(str);
	newl();
    return;
}

void writes(char *str)
{
	while (*str != '\0') 
	{
		writec(*str++);
	}
    return;
}

void writetest()
{
    char *str = "Test";
	while (*str != '\0') 
	{
		writec(*str++);
	}
    return;
}

void writec(char character)
{
	video_ptr[video_ptr_line][video_ptr_offset] = character;
	video_ptr[video_ptr_line][video_ptr_offset + 1] = '/';
	video_ptr_offset += 2;
	return;
}

void newl() 
{
	video_ptr_line += 1;
	video_ptr_offset = 0;
    return;
}