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
