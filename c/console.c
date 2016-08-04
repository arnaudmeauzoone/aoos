#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "console.h"
#include "test.h"
#include "idt.h"
#include "keyboard.h"
#include "kernel.h"

void console_setup(){

p_video_mem = (uint8_t*) 0xb8000; 		    //this is the base video memory adress
										//for text-ui graphical card
										//Simply write something at this adress
										//and it will be printed :)
	for(line = 0; line < 25; line++ ){
		for(column = 0; column < 80; column++ ){


            *(p_video_mem +1)=inCadre(line,column)?B_COLOR_LIGHT_BLUE:B_COLOR_BLACK;
        	p_video_mem = p_video_mem + 2;			//Increment by two to write next caracter
   		}

	}
line = 0;
column = 0;
update_cursor(5,5);
}

bool inCadre(int line, int column){

return (line == 0 || line == 24 || column == 0 || column == 79)?true:false;

}


int strlen(const char* str) {			//Symply return the lenght of the string
	int len = 0;
	while (str[len])
		len++;
	return len;
}

void append_String(uint8_t* string){
      for(int i=0; i< strlen(string);){

      column++;
      (column == 79)?returnLine():NULL;
      (line == 25)?returnTop():NULL;
      //That is to stay inside the console

      	if(!inCadre(line,column)){
      		write(string[i],column, line, COLOR_BLACK, COLOR_BROWN);
					update_cursor(line,column);
				 	i++;
		    }
      }
}

void write_Nbr(uint8_t num){

      *p_video_mem = num +48;				    //
	  *(p_video_mem +1) = COLOR_BLUE;			//
	  p_video_mem = p_video_mem + 2;			//
}

void write(uint8_t letter, int x, int y, uint8_t color1, uint8_t color2){

     p_video_mem = (uint8_t*) (0xb8000 +80*y*2 + x*2);
     //Those two two are here because each video memory cells are 16 bit wise

     *p_video_mem = (uint8_t) letter;
     *(p_video_mem +1) = color1 << 4 | color2;
}

//This is to write into the virtual console with 78 characters wide and 23 lines
uint8_t write_console(uint8_t letter, int x, int y, uint8_t color1, uint8_t color2){

	uint8_t result = 0;

     (x<0 || x>77)?result = 1:x++;
     (y<0 || y>22)?result = 1:y++;
     //This avoid the user to write outside the buffer and also
     //make the virtual console corespond with the real one

     p_video_mem = (uint8_t*) (0xb8000 +80*y*2 + x*2);
     //Those two two are here because each video memory cells are 16 bit wise

     *p_video_mem = (uint8_t) letter;
     *(p_video_mem +1) = color1 << 4 | color2;

     return result;
}

void returnLine(){

line++;
column = 0;
update_cursor(line,column);
}

void returnTop(){

	line = 0;
	column = 0;
	update_cursor(line,column);
}

void update_cursor(int row, int col)
{
	 uint16_t position=(row*80) + col;

	 // cursor LOW port to vga INDEX register
	 outb(0x3D4, 0x0F);
	 outb(0x3D5, (uint32_t)(position&0xFF));
	 // cursor HIGH port to vga INDEX register
	 outb(0x3D4, 0x0E);
	 outb(0x3D5, (uint32_t)((position>>8)&0xFF));
}

void clear_console(){

	returnTop();

	for(int i=0; i <= 80*25;){

	column++;
	(column == 79)?returnLine():NULL;
	(line == 25)?returnTop():NULL;
	//That is to stay inside the console

		if(!inCadre(line,column)){
			write(NULL,column, line, COLOR_BLACK, COLOR_WHITE);
			update_cursor(line,column);
			i++;
		}
	}
	returnTop();

}
