
// written by saphhic.


#include "lector.h"
#include "printf.h"
#define BUF_SIZE 256

static char buffer[BUF_SIZE];
static int index = 0;

static char scancode_map[256] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', /* 9 */
    '9', '0', '-', '=', '\b', /* Backspace */
    '\t', /* Tab */
    'q', 'w', 'e', 'r', /* 19 */
    't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', /* Enter key */
    0, /* 29 - Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',
    '\'', '`',
    0, /* Left Shift */
    '\\',
    'z', 'x', 'c', 'v', 'b', 'n', /* 39 */
    'm', ',', '.', '/',
    0, /* Right Shift */
    '*',
    0, /* Alt */
    ' ', /* Space bar */
};

char* read_line() {
  while(true) {
    uint8_t scancode = read_input();

    if (scancode & 0x80) continue;

    char c = scancode_map[scancode];
    if (c == 0) continue;

    if (c == '\b' && index > 0) {
        index--;
        buffer[index] = '\0';
        putchar('\b');
        return buffer;
    }
    else if (c == '\n') {
        buffer[index] = '\0';
        index = 0;
        putchar('\n');
        return buffer;
    }
    else if (index < BUF_SIZE - 1) {
        buffer[index++] = c;
        buffer[index] = '\0';
        putchar(c);
    }
  }
}

