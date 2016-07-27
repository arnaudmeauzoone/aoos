#ifndef keyboard_h
#define keyboard_h

void outb(short port, char val);
uint8_t inb(uint16_t port);
uint8_t getScancode();

#endif