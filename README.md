
# OS-EX  
  OS example  

## development environment
	OS: Ubuntu
## Softwares/Libraries:  
 - `sudo apt-get install gcc`
 - `sudo apt-get install gdb`
 - `sudo apt-get install gdb-doc`
## compile:  
 `nasm -f bin boot_sect_simple.asm -o boot_sect_simple.bin` 
## run:  
 `qemu-system-x86_64 boot_sect_simple.bin`  
## order to access:  
 - boot_sect_simple.asm 
 - boot_sect_hello_world.asm 
 - boot_sect_memory_without_org.asm , boot_sect_memory_with_org.asm
   ![boot sector diagram](https://github.com/meetsandesh/OS-EX/blob/main/boot_sector.png)
 - boot_sect_stack.asm
 - boot_sect_print_main.asm , boot_sect_print.asm , boot_sect_print_hex.asm
 - boot_sect_segmentation.asm
 - boot_sect_disk_main.asm , boot_sect_disk.asm
 - 32bit-main.asm , 32bit-gdt.asm , 32bit-print.asm , 32bit-switch.asm
 - kernel
 - kernel-barebones
 - kernel-checkpoint
 - kernel-video-port
 - kernel-video-driver
