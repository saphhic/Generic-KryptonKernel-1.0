//written by shappic.
#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdint.h>

extern uint32_t FRAMEBUFFER_ADDR;
extern uint32_t FRAMEBUFFER_WIDTH;
extern uint32_t FRAMEBUFFER_HEIGHT;
extern uint32_t FRAMEBUFFER_PITCH;

extern uint32_t* framebuffer;
extern uint32_t width;
extern uint32_t height;
extern uint32_t pitch;

void framebuffer_init();
void put_pixel(int x, int y, uint32_t color);
void draw_rect(int x, int y, int w, int h, uint32_t color);
void print(int x, int y, const char* str, uint32_t color);

extern "C" void framebuffer_init_stub();

//color table:
#define black 0x00000000
#define white 0xFFFFFFFF
#define red 0xFF0000FF
#define green 0x00FF00FF
#define blue 0x0000FFFF
#define yellow 0xFFFF00FF
#define magenta 0xFF00FFFF
#define gray 0x808080FF
#define light_gray 0xC0C0C0FF
#define dark_gray 0x404040FF
#define orange 0xFFA500FF
#define purple 0x800080FF
#define pink 0xFFC0CBFF
#define brown 0xA52A2AFF
#define violet 0x800080FF
#define cyan 0x87CEEBFF
#define lime_green 0x00FF7FFF

#endif // FRAMEBUFFER_H