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
#include "test.h"
#include "kernel.h"
#include "console.h"
#include "test.h"
#include "idt.h"
#include "keyboard.h"
#include "timer.h"

void entry(){

										//This is the static entry point
										//It is needed for the assembly
	kernel_Main();						//because kernel_main adress can change but
										//not entry adress
}


void kernel_Main(){

     console_setup();
		 append_String("Console setup");
		 returnLine();

		 InitializeKeyboard();
		 append_String("keyboard initialized");
		 returnLine();

		 InitializeIDT();
		 append_String("IDT initialized");
		 returnLine();

		 InitializeTimer(5000000);
		 append_String("Timmer initialized");
		 returnLine();

		 program -> clear_con = false;

		 append_String("kernel in c is fully started :)))");
}
