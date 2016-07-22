#ifndef keyboard_h
#define keyboard_h



static inline void outb(short port, char val);
static inline uint8_t inb(uint16_t port);
char getScancode();

#endif