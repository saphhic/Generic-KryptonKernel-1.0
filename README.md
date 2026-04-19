# Generic-KryptonKernel-1.0
This kernel is a free to use project made by me, its from the project LawOS. KryptonKernel is a kernel of LawOS made for developers who seek to make their own distro of LawOS, The kernel has support to BIOS Legacy and UEFI, but using UEFI is not recommended do to the kernel not having full framebuffer and VGA support.

Functions for DEVS:
hal:
 hal contains all of the critical kernel funciones:
  -Comaparator[ compare(const char* a, const char* b) ]
   this function compares text instead of doing it manualy whit str[].
   
  -io[ outw, inw, outl, inl, outb, inb ]
   similar as linux IO.
   
  -reb_shtdw[ reboot(), shutdown() ]
   shutdown and reboot functions, works on vm and real hardware.
   
  -user[ chek_priv(), check_login(), login_user(const char* username, const char* password), create_privuser(const char* username, const char* password), init_default_user() ]
   user logic: check_priv() checks if user has privilage, check_login() checks if user is loged in, login_user() login function, create_privuser() creates a privilaged user, init_default_user() starts default user (root) password: toor.

drivers:
 drivers contains drivers for system such as:
  -vga[ printf(const char* str), printxy(const char* str, int x, int y), putchar(char c), clear_screen(), upd_cursor(), disable_vga()]
   vga controler: printf() prints text on vga, printxy() prints text in a certain coordinate, putchar(), puts character, clear_screen() clears vga to default, upd_cursor() updates consoles cursor position, disable_vga() disables vga mode so framebuffer can start.
   
  -framebuffer[ framebuffer_init(), put_pixel(int x, int y, uint32_t color), draw_rect(int x, int y, int w, int h, uint32_t color), print(int x, int y, const char* str, uint32_t color) ]
   framebuffer controler: framebuffer_init() starts framebuffer mode, put_pixel() darws a pixel at certain coordinate, draw_rect() draws a rectangle at a certain coordinate, print() prints text in framebuffer mode.
   
  -gpu
   none, this will contain adapted and advanced gpu drivers in a future.

ulsysid:
 starts upper level system, function is:
  ulsys_main()


NOTE: there is no official ulsys yet, so you will have to make your own. There also arent any wifi, ethernet or graphical processing unit (gpu) drivers yet do to their complexity, but we are actively working on them.

GRUB may work but it can encaunter bugs because VGA uses functions from our personal bootloader.
here is the official BIOS Legacy bootloader, its needed because of the frambuffer.asm or else framebuffer will not work properly:
https://github.com/saphhic/Krypton-BIOS-Bootloader-1.0.git

the kernel was severaly tested by me and vareity of AI models and the kernel according to the reports should run and work whitout any trouble, if you do encounter bugs or malfunctions, contact me.

IF YOU ENCOUNTER ANY BUGS OR MALFUNCTIONS DURING THE USAGE OF THE ORIGINAL KRYPTONKERNEL, DONT BE SHY AND CONTACT ME SO IT CAN BE FIXED, THANK YOU!


   
