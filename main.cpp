// written by saphhic.
#include "hal/startup.h"
#include "ulsysid/ulsys.h"
#include "hal/startup.h"
#include "hal/terminal.h"
#include <stdint.h>

extern "C" void kernel_main() {
    startup(); 
    while (1) {
        // Kernel main loop
    }
}

extern "C" void ulsys_jmp(const char* arg) {
    if (arg == "start") {
        ulsys_main();
    }

    else if (arg != "start") {
          terminal_main();
    }
}
