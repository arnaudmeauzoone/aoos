void kernel_Main();

char  *p_video_mem = (char*) 0xb8000; 	//this is the base video memory adress 
										//for text-ui graphical card
										//Simply write something at this adress
										//and it will be printed :)

void entry(){							//This is the static entry point 
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

static inline void outb(short port, char val)
{
    asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
    /* There's an outb %al, $imm8  encoding, for compile-time constant port numbers that fit in 8b.  (N constraint).
     * Wider immediate constants would be truncated at assemble-time (e.g. "i" constraint).
     * The  outb  %al, %dx  encoding is the only option for all other cases.
     * %1 expands to %dx because  port  is a uint16_t.  %w1 could be used if we had the port number a wider C type */
}

void kernel_Main(){


     //update_cursor(2,2);
     write_String("kernel in c has started :)))");
	
	while(1){

	}

}
