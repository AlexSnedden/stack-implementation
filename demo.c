/*
 * A demo program to show use of stack api
*/
#include "stack.h"
#include <stdlib.h>

int main() {
        /* demo */
        struct stack *demo_stack = new_stack();
        int ints[] = {1,2,3,4,5,6,7,8,9,10};
        for(int i=0; i < 10; i++) {
                push(demo_stack, (void *)ints[i]);
        }
        push(demo_stack, "I'm the first element of a multi data type stack. The rest are these numbers...\n");
        printf("%s", pop(demo_stack));
        void * popped;
        while(1) {
                if((popped = pop(demo_stack))) {
                        printf("%d\n", (int)popped);
                }else { break; }

        }
}
