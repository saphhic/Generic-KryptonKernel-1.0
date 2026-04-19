// written by saphhic.
#include "drivers/vga/keymap.h"
#include "drivers/vga/printf.h"
#include "hal/terminal.h"
#include "hal/user.h"
#include "hal/startup.h"
#include "drivers/vga/disable.h"
#include "drivers/frameb/framebuffer.hpp"

void startup() {
    clear_screen();
    printf("Starting kernel...\n");

    init_default_user();

    printf("created default user.\n");
    printf("you can log in or create new account:\n");

    while (!check_login()) {
        printf("username: ");
        char* username = read_line();
        printf("password: ");
        char* password = read_line();

        if (login_user(username, password)) {
            printf("login successful. Welcome, ");
            printf(username);
            printf("!\n\n");
            break;
        } else {
            printf("login failed.\n");
            printf("creating new user? (y/n): ");
            char* choice = read_line();

            if (choice != nullptr && (choice[0] == 'y' || choice[0] == 'Y')) {
                printf("username: ");
                char* new_username = read_line();
                printf("password: ");
                char* new_password = read_line();

                if (create_privuser(new_username, new_password)) {
                    printf("user created successfully. You can now continue.\n");
                    login_user(new_username, new_password);
                } else {
                    printf("failed to create user. Maximum users reached or username taken.\n");
                }
            }
        }
    }

    clear_screen();
    printf("VGA mode on.\n");
    printf("kernel started successfully.\n");
    printf("do you want to open terminal? (y/n): ");
    
    char* choice = read_line();
    if (choice != nullptr && (choice[0] == 'n' || choice[0] == 'N')) {
        printf("disabling VGA...\n");
        disable_vga();
        printf("starting framebuffer mode...\n");
        framebuffer_init();
        ulsys_jmp("start");
        return;
    }
    
        printf("starting terminal...\n");
        terminal_main();
}
