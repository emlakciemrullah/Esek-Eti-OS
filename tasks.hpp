#ifndef TASKS_HPP
#define TASKS_HPP

void (*task_stack[1024])() = {0};
void (**TS_pointer)() = &task_stack[0];

inline void task_push(void (*function)()) {
    *TS_pointer = function;
    
    TS_pointer++;
}


void task_pop(){
    TS_pointer--;
    *TS_pointer = 0;
}

void (*task_top())(){
    return *(TS_pointer - 1);
}

inline bool stack_is_empty(){
    return TS_pointer == &task_stack[0];
}

inline int stack_execute() {
    if (stack_is_empty()) {
        return 1;
    }

    while (TS_pointer != &task_stack[0]) {
        TS_pointer--;
        (*TS_pointer)();
    }

    return 0;
}


#endif
