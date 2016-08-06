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
void update_cursor(int row, int col);
void clear_console();

#endif
