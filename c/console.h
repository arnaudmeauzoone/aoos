#ifndef console_h
#define console_h

uint8_t  *p_video_mem;		

int line;
int column;			 

enum vga_color {						//To enderstand your code
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,

	B_COLOR_BLACK = COLOR_BLACK << 4,
	B_COLOR_LIGHT_BLUE = COLOR_LIGHT_BLUE << 4,
};	

bool inCadre(int line, int column);
void append_String(uint8_t* string);
void write_Nbr(uint8_t num);
void console_setup();
void write(uint8_t letter,int x,int y, uint8_t color1, uint8_t color2);
uint8_t write_console(uint8_t letter, int x, int y, uint8_t color1, uint8_t color2);
void returnLine();
void returnTop();

#endif