#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "keyboard.h"
#include "kernel.h"
#include "console.h"

static inline void outb(short port, char val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
    /* There's an outb %al, $imm8  encoding, for compile-time constant port numbers that fit in 8b.  (N constraint).
     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                   : "=a"(ret)
                   : "Nd"(port) );
    return ret;
}

/*
PS/2 keyboard code.
Dependencies:
inb function and scancode table.
*/
uint8_t getScancode()
{
	uint8_t c;
		if(inb(0x60)!= c)
			{
			c=inb(0x60);
				  if(c == 0x12){
				  write_Nbr(c);
				  outb(0x60,0x00);			  
			      }
			}
	return c;
}