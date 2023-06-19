/*1.Entry Point*/
ENTRY(Reset_Handler)

/*2.Memory Definition*/
MEMORY
{
	SRAM(rwx):ORIGIN =0x20000000,LENGTH =96K
	FLASH(rx):ORIGIN =0x08000000,LENGTH =512K
}

_estack = ORIGIN(SRAM)+LENGTH(SRAM);


/*3.Indicate required heap and stack size */
__max_heap_size = 0x200;
__max_stack_size = 0x400;

/*4.Sections*/

SECTIONS
{
	/*first section of output file*/

	.text :
	{
		. = ALIGN(4);
		*(.isr_vector_tbl)    /*merge all isr vector table sections of input files*/*/
		*(.text)     /*merge all .text sections of input files*/
		*(.rodata)	/*merge all .rodata sections of input files*/ 
		. = ALIGN(4);
		_etext = .;	/*Create a global to hold end of text section*/
	}>FLASH
	
	
	/*second section of output file*/
	.data :
	{
		. = ALIGN(4);
		_sdata = .;	/*Create a global to hold start of data section*/
		*(.data)
		. = ALIGN(4);
		_edata = .;	/*Create a global to hold end of data section*/
	} >SRAM AT> FLASH  /*(vma) AT> (lma)*/


	/*third section of output file*/
	.bss :
	{	
		. = ALIGN(4);
		_sbss = .;	/*Create a global to hold start of bss section*/
		*(.bss)	/*merge all .bss sections of input files*/
		. = ALIGN(4);
		_ebss = .;	/*Create a global to hold end of bss section*/
	} >SRAM

}