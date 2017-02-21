OUTPUT_FORMAT(elf32-i386)
ENTRY(start) /*Located in kernel.asm. Enter at this function*/
SECTIONS
{
	. = 0x100000; /*Very First Memory Space, stored for OS*/
	.text : { *(.text) } /* Calls the .text section in the kernel.asm, Holds instructions and read only data*/
	.data : { *(.data) } /* Holds Initialized writable data*/			
	.bss  : { *(.bss)  } /* uninitialized data */
}
