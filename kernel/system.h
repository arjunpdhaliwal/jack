#ifndef SYSTEM_H
#define SYSTEM_H

#define VGA_TEXT_BUFFER 0xb8000
#define HEIGHT 25
#define WIDTH 160

char (*video_ptr)[WIDTH];
int video_ptr_line;
int video_ptr_offset;

void writec(char);
void writes(char *);
void writel(char *str); 
void newl();

void sys_init();

#endif