#include "input.hpp"
#include "output.hpp"
#include "tasks.hpp"

extern "C" void (*__ctors_start[])(void);
extern "C" void (*__ctors_end[])(void);

void syscallctors() {
    for (auto **ctor = __ctors_start; ctor != __ctors_end; ++ctor) {
        (*ctor)();
    }
}

void delay(unsigned long long ticks){
    unsigned long long i = 0;
    while(i < ticks) {i++;}
}

extern "C" void halt(){
    __asm__ volatile ("cli");
    while(1){
        __asm__ volatile ("hlt");
    }
}

extern "C" void kmain(){
    syscallctors();
    sysclear();

    /*kernel code here*/

    halt();
}
