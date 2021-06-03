
# OS-EX  
  OS example  
  Inspired from [os-tutorial](https://github.com/cfenollosa/os-tutorial)

## Development Environment
	OS: Ubuntu

## Softwares/Libraries:  
 - `sudo apt-get install gcc`
 - `sudo apt-get install gdb`
 - `sudo apt-get install gdb-doc`
 - `sudo apt-get install qemu`
 - `sudo apt-get install nasm`
 - `sudo apt-get install libgmp3-dev`
 - `sudo apt-get install libmpc-dev`
 - `sudo apt-get install libmpfr-dev`
 - `sudo apt-get install build-essential`

## Compile:  
 `nasm -f bin boot_sect_simple.asm -o boot_sect_simple.bin` 

## Link output files:
 `ld -o kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o --oformat binary`

## Generate Binary:
 `nasm bootsect.asm -f bin -o bootsect.bin`

## Run:  
 `qemu-system-x86_64 boot_sect_simple.bin`  

## Order to access files:  
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
 - kernel-video-scroll
 - kernel-interrupts
