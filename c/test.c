#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"    
#include "keyboard.h"
#include "timer.h"
#include "console.h"
#include "test.h"
#include "idt.h"

#define IRQ0 32

struct registers_t
{
	uint32_t ds;
	uint32_t edi, esi, edp, esp, ebx, edx, ecx, eax;
	uint32_t int_no, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
};

typedef void (*isr_t)(registers_t);

isr_t interrupt_handlers[256];

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

void timer_test() 
{
         //write_String("this is the timer function1");

}

void register_interupt_handler(uint8_t n, isr_t handler)
{
	interrupt_handlers[n] = handler;
}

void InitializeTimer(uint32_t freq) {

    register_interupt_handler(IRQ0, &timer_test);

    uint32_t delitel = 1193180 / freq;

    outb(0x43, 0x36);

    uint8_t l = (uint8_t) (delitel & 0xFF);
    uint8_t h = (uint8_t) ((delitel >> 8) & 0xFF);

    outb(0x40, l);
    outb(0x40, h);
}

void test(){

     InitializeIDT(); 
     InitializeTimer(5000000);

     write_String("this is the test function");

	
}