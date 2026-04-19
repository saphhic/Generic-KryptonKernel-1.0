// written by saphhic.
#include "drivers/vga/printf.h"
#include "drivers/vga/keymap.h"
#include "hal/reb_shtdw.h"
#include "hal/user.h"
#include "drivers/vga/disable.h"
#include "hal/startup.h"
    
void terminal_main() {
    printf("vga shell started. type 'clear' to clear the screen, 'shutdown' to power off, 'reboot' to restart.\n");
    printf("\n\n");

    while (1) {
        
        printf("home/> ");

        char* input = read_line();
        if (input == nullptr || input[0] == '\0') {
            continue;
        }

        if (input[0] == 'c' && input[1] == 'l' && input[2] == 'e' && input[3] == 'a' && input[4] == 'r' && input[5] == '\0') {
            clear_screen();
            continue;
        }

        if (input[0] == 's' && input[1] == 'h' && input[2] == 'u' && input[3] == 't' && input[4] == 'd' && input[5] == 'o' && input[6] == 'w' && input[7] == 'n' && input[8] == '\0') {
            printf("shutting down...\n");
            shutdown();
            continue;
        }

        if (input[0] == 'r' && input[1] == 'e' && input[2] == 'b' && input[3] == 'o' && input[4] == 'o' && input[5] == 't' && input[6] == '\0') {
            printf("rebooting...\n");
            reboot();
            continue;
        }

        if (input[0] == 'h' && input[1] == 'e' && input[2] == 'l' && input[3] == 'p' && input[4] == '\0') {
            printf("available commands:\n");
            printf("  clear    - clear the screen\n");
            printf("  shutdown - power off the machine\n");
            printf("  reboot   - restart the machine\n");
            printf("  help     - show this message\n");
            printf("  dvga     - disable vga output (turns on framebuffer automatically by starting ulsys)\n");
            continue;
        }

        if (input[0] == 'd' && input[1] == 'v' && input[2] == 'g' && input[3] == 'a' && input[4] == '\0') {
            printf("disabling vga...\n");
            disable_vga();
            ulsys_jmp("start");
            continue;
        }

        printf(input);
        printf("\n");
    }
}
