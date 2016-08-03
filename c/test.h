#ifndef console_h
#define console_h

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

void test();
void isr_handler(struct registers_t regs);
void irq_handler(struct registers_t regs);
void timer_test();
void register_interupt_handler(uint8_t n, isr_t handler);
void InitializeTimer(uint32_t freq);


#endif
