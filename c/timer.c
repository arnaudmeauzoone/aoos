#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "timer.h"
#include "test.h"
#include "keyboard.h"
#include "program.h"

#define IRQ0 32

void timer_callBack()
{        //This is the program that will set the flags
         //of the others programs
				 (programs -> choosePro)?chooseProgram():NULL;

         //If the flag of one program has been set to true
         //we lunch the program and the the flag back to false

         (programs -> clear_con)?
         (programs -> clear_con = false, clear_console()):NULL;
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
