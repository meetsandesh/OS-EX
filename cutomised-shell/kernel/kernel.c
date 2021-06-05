#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"
#include "../system_commands/syscommand.h"
#include <stdint.h>

void kernel_main() {
    isr_install();
    irq_install();

    clear_screen();

    kprint("Booting OS...\n\n\n");
    kprint(" ******************************************************************************\n");
    kprint(" ****         ********         ****************         ******** *********** **\n");
    kprint(" ** *********** **** ********** ************** ********* ******** ********* ***\n");
    kprint(" ** *********** **** ********** ************** ******************* ******* ****\n");
    kprint(" ** *********** **** ************************* ******************** ***** *****\n");
    kprint(" ** *********** **** ************************* ********************* *** ******\n");
    kprint(" ** *********** **** ************************* ********************** * *******\n");
    kprint(" ** *********** *****          ****       ****      ****************** ********\n");
    kprint(" ** *********** *************** ************** ********************** * *******\n");
    kprint(" ** *********** *************** ************** ********************* *** ******\n");
    kprint(" ** *********** *************** ************** ******************** ***** *****\n");
    kprint(" ** *********** **** ********** ************** ******************* ******* ****\n");
    kprint(" ** *********** **** ********** ************** ********* ******** ********* ***\n");
    kprint(" ****         ********         ****************         ******** *********** **\n");
    kprint(" ******************************************************************************\n");
    kprint("\n\n\n");
    setup_enviroment();
    kprint("Start typing commands, type help for more info.\n");
    print_prompt();
}

void user_input(char *input) {
    if (strcmp(input, "END") == 0) {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    } else if (strcmp(input, "PAGE") == 0) {
        /* Lesson 22: Code to test kmalloc, the rest is unchanged */
        uint32_t phys_addr;
        uint32_t page = kmalloc(1000, 1, &phys_addr);
        char page_str[16] = "";
        hex_to_ascii(page, page_str);
        char phys_str[16] = "";
        hex_to_ascii(phys_addr, phys_str);
        kprint("Page: ");
        kprint(page_str);
        kprint(", physical address: ");
        kprint(phys_str);
        kprint("\n");
    }
    // kprint("You said: ");
    // kprint(input);
    execute_command(input);
    print_prompt();
}

void setup_enviroment() {
    // OS version
    kprint("OS version : ");
    kprint(OS_VERSION);
    kprint("\n");

    kprint("\n");
    kprint("\n");
}

void print_prompt() {
    char* user = "username";
    char* address = "localhost";
    char* working_dir = "working_dir";
    kprint("\n");
    kprint(user);
    kprint("@");
    kprint(address);
    kprint(":");
    kprint(working_dir);
    kprint("$ ");
}

void execute_command(char *input) {
    if(strcmp(input, "HELP") == 0) {
        system_help();
    }
}
