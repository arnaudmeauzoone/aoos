/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Written by Arnaud Meauzoone

*/
#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"    
#include "keyboard.h"
#include "timer.h"
#include "console.h"
#include "isr.h"

isr_t interrupt_handlers[256];

void isr_handler(struct registers_t regs)
{
	write_String("interupt");
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