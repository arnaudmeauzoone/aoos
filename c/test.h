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

#ifndef console_h
#define console_h

struct registers_t
{
	uint32_t ds;
	uint32_t edi, esi, edp, esp, ebx, edx, ecx, eax;
	uint32_t int_no, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
};

typedef void (*isr_t)(registers_t);

isr_t interrupt_handlers[256];

void isr_handler(struct registers_t regs);
void irq_handler(struct registers_t regs);
void register_interupt_handler(uint8_t n, isr_t handler);


#endif
