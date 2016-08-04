#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "test.h"
#include "console.h"
#include "idt.h"
#include "keyboard.h"
#include "kernel.h"

void isr_handler(struct registers_t regs)
{
	     //write_String("this is the interupt function");

}

void irq_handler(struct registers_t regs)
{

	if(regs.int_no >= 40)
	{
		outb(0xA0, 0x20);
	}

	outb(0x20, 0x20);

	if(interrupt_handlers[regs.int_no] != 0)
	{
		isr_t handler = interrupt_handlers[regs.int_no];
		handler(regs);
	}
}

void register_interupt_handler(uint8_t n, isr_t handler)
{
	interrupt_handlers[n] = handler;
}
