/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Written by Arnaud Meauzoone

*/
#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"    
#include "keyboard.h"
#include "timer.h"


void kernel_Main();

void entry(){	

	p_video_mem = (char*) 0xb8000; 		//this is the base video memory adress 
										//for text-ui graphical card
										//Simply write something at this adress
										//and it will be printed :)

										//This is the static entry point 
										//It is needed for the assembly
	kernel_Main();						//because kernel_main adress can change but
										//not entry adress
}
										//Declare those value so it will be easier 
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
};

int strlen(const char* str) {			//Symply return the lenght of the string
	int len = 0;
	while (str[len])
		len++;
	return len;
}

void write_String(char* string){
      for(int i=0; i< strlen(string); i++ ){

      *p_video_mem = string[i];					//Write the first caractere at the base adress
	  *(p_video_mem +1) = COLOR_RED;			//Just after this is the color of your caracter
	  p_video_mem = p_video_mem + 2;			//Increment by two to write next caracter

      }
}

void write_Integer(uint8_t* num){

      for(int i=0; i<sizeof(num); i++){
      *p_video_mem = num[i] +48;				    //
	  *(p_video_mem +1) = COLOR_BLUE;			//
	  p_video_mem = p_video_mem + 2;	
	  }											//
}



void kernel_Main(){

     //kernel_setup();

     setup_timer();

     //update_cursor(2,2);
     write_String("kernel in c has started :)))");

     int64_t currentNano = 0;

    while(1){

    	timer();

    	if(getNano() - currentNano > 0 ){

           currentNano = getNano();
           

    	getScancode();
    	//kernel_run();

    	}
    }
}
