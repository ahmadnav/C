bits	32
section		.text		;Text Section Holds instructions and read-only data
	align	4		;4 byte, 32 bit
	dd	0x1BADB002	;Tells BootLoader that this is a multiboot operating system, 					;capable of boot 
	dd	0x00		
	dd	-(0x1BADB002+0x00) 
global start			;Global can be accessed by linker and calls start, called in 					;link.ld
extern kmain	; This Function is located in c code (Kernel.c)
start:		;Computer will start excecuting here
	cli	;Clears Interrupts (Services By BIOS etc. , clears up space for c-code)
	call kmain	;Tells procesor to execute the kmain function
	hlt		;Halt the CPU after kmain as we dont hae anything else to execute!
			;If Not Halted to CPU might excecute some random function or Garbage. 
			;Halt the CPU, until next interupt is fired. Interupts signal events that 
			; require immediate CPU attention (hardware or software)
