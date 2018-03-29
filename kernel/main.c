#include <system.h>
#include <sys/io.h>

int kinit() {
    sys_init();
	writel("Initialized");
    return 0;
}

int kmain()
{
	int i;
	int j;

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			video_ptr[i][j] = 0;
		}
	}
	video_ptr_line = 0;
	video_ptr_offset = 0;

	while(1) __asm__("sti; hlt");
	return 0;
}
