#include "framebuffer.hpp"
#include "hal/comparator.h"
#include "font8x8_basic.h"

uint32_t* framebuffer = nullptr;
uint32_t width = 1024;
uint32_t height = 768;
uint32_t pitch = 3072;

extern "C" void framebuffer_init_stub();

void framebuffer_init() {
    framebuffer_init_stub();
  
    framebuffer = (uint32_t*)FRAMEBUFFER_ADDR;
    width = FRAMEBUFFER_WIDTH;
    height = FRAMEBUFFER_HEIGHT;
    pitch = FRAMEBUFFER_PITCH;

    if (pitch == 0) {
        pitch = width * 4; // Assuming 32 bits per pixel
    }
}
void put_pixel(int x, int y, uint32_t color) {
    if (x < 0 || y < 0 || x >= (int)width || y >= (int)height) return;
    uint32_t* pixel = (uint32_t*)((uint8_t*)framebuffer + y * pitch + x * 4);
    *pixel = color;
}

void draw_rect(int x, int y, int w, int h, uint32_t color) {
    for(int j = 0; j < h; j++)
        for (int i = 0; i < w; i++)
             put_pixel(x + i, y + j, color);
}

extern uint8_t font8x8_basic[128][8];

void print(int x, int y, const char* str, uint32_t color) {
    while(*str) {
        char c = *str++;
        for(int row = 0; row < 8; row++) {
            uint8_t bits = font8x8_basic[(uint8_t)c][row];
            for(int col = 0; col < 8; col++) {
                if(bits & (1 << col)) {
                    put_pixel(x + col, y + row, color);
                }
            }
        }
        x += 8;
    }
}