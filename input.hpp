#include "output.hpp"

#ifndef INPUT_HPP
#define INPUT_HPP

unsigned char inb(unsigned short port){
    unsigned char result;

    __asm__ volatile("inb %1, %0" : "=a"(result) : "Nd"(port));

    return result;
}

const unsigned char ascii_scancode[58] = {
    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', 
    '9', '0', '-', '=', '\b', '\t',               
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
    '[', ']', '\r', 0,                         
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
    0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0, 0, 0, ' '
};

unsigned char sysgetch() {
    static bool extended = false;

    while (true) {
        while ((inb(0x64) & 0x01) == 0);
        unsigned char scancode = inb(0x60);

        if (scancode == 0xE0) {
            extended = true;
            continue;
        }

        if ((scancode & 0x80) != 0) {
            extended = false;
            continue;
        }

        if (extended) {
            extended = false;
            continue;
        }

        if (scancode >= sizeof(ascii_scancode)) {
            continue;
        }

        unsigned char ascii = ascii_scancode[scancode];
        if (ascii == 0) {
            continue;
        }

        return ascii;
    }
}

unsigned char* sysgets(int& written, int index_start){
    static unsigned char string[80];
    unsigned char* string_ptr = string;
    written = 0;

    unsigned char c = sysgetch();
    while(c != 13 && c){
        *string_ptr = c;
        written++;
        string_ptr++;
        index_start++;
        c = sysgetch();
    }

    return string;
}


#endif
