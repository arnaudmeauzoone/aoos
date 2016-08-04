#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "timer.h"
#include "test.h"
#include "keyboard.h"

void timer_callBack()
{
				 (myKeyb -> isPressed)?
				 (append_String(myKeyb -> keyPressed),myKeyb -> isPressed = false)
				 :NULL;
}

void InitializeTimer(uint32_t freq) {

    //Here we register the timer into the empty idt
    register_interupt_handler(IRQ0, &timer_callBack);

    //Then we will initialize the timer to trigger interupts
    uint32_t delitel = 1193180 / freq;

    outb(0x43, 0x36);

    uint8_t l = (uint8_t) (delitel & 0xFF);
    uint8_t h = (uint8_t) ((delitel >> 8) & 0xFF);

    outb(0x40, l);
    outb(0x40, h);
}
