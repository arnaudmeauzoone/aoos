#ifndef keyboard_h
#define keyboard_h

#define IRQ1 33

struct Keyb {

   bool isPressed;
   uint8_t keyPressed;
};

struct Keyb *myKeyb;

void outb(short port, char val);
uint8_t inb(uint16_t port);
uint8_t getScancode();
void keyborad_interupt();
void InitializeKeyboard();

#endif
