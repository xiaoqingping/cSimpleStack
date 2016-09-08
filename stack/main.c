#include <stdio.h>
#include "stack.h"

typedef struct user_data_s {
    int data;
} user_data_t;

user_data_t user_data[11];

int main(void)
{
    stack_head_t *stack_head;
    stack_t *stack_node;
    int i;

    stack_head = init_stack(10);
    if (stack_head == NULL) {
        return 1;
    }
    for (i = 0; i < 11; i++) {
        user_data[i].data = i * 123;
        stack_node = init_stack_node(&user_data[i].data);
        push(stack_head, stack_node);
        dump_stack(stack_head);
    }

    for (i = 0; i < 12; i++) {
        stack_node = pop(stack_head);
        if (stack_node != NULL) {
            printf("-------------------\ndata: %d\n-------------------\n", *(int *)stack_node->data);
            free(stack_node);
        }
        dump_stack(stack_head);
    }
    
    free_stack(stack_head);
    
    return 0;
}

