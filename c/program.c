#if !defined(__cplusplus)
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>
#include "program.h"
#include "keyboard.h"

void initializeProgram(){

//has to be set true to allow you to choose the program
//you want to start
programs -> choosePro = true;

programs -> clear_con = false;

programs -> welcomePro = false;


}

void chooseProgram(){

  if(!(myKeyb -> isPressed))return;

  myKeyb -> isPressed = false;

  switch (myKeyb -> keyPressed) {

    case 0x1c :
    programs -> welcomePro = true;
    break;

  }
}
