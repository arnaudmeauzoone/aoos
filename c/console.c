#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.h"    
#include "keyboard.h"
#include "timer.h"
#include "console.h"

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

p_video_mem = (char*) (0xb8000 +80*2 + 2);
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

void write_String(char* string){
      for(int i=0; i< strlen(string); i++ ){

      *p_video_mem = string[i];					//Write the first caractere at the base adress
	  *(p_video_mem +1) = COLOR_RED;			//Just after this is the color of your caracter
	  p_video_mem = p_video_mem + 2;			//Increment by two to write next caracter

      }
}

void write_Nbr(uint8_t num){

      *p_video_mem = num +48;				    //
	  *(p_video_mem +1) = COLOR_BLUE;			//
	  p_video_mem = p_video_mem + 2;			//
}