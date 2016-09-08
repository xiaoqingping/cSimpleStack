#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack_s stack_t;

typedef struct stack_head_s {
    int stack_capacity;         /* 栈空间大小 */
    int node_num;               /* 栈节点数量 */
    stack_t *top;               /* 栈顶 */
    stack_t *bottom;            /* 栈底 */
} stack_head_t;

struct stack_s {
    stack_t *back;              /* 指向后一个入栈节点的指针 */
    void *data;                 /* 节点数据 */
};

stack_head_t *init_stack(int capacity);

stack_t *init_stack_node(void *param);

void push(stack_head_t *head, stack_t *node);

stack_t *pop(stack_head_t *head);

stack_t *get_node(stack_head_t *head, int index);

stack_t *get_top(stack_head_t *head);

stack_t *get_bottom(stack_head_t *head);

int get_node_num(stack_head_t *head);

int get_stack_capacity(stack_head_t *head);

void free_stack(stack_head_t *head);

void dump_stack(stack_head_t *head);

#endif  /* _STACK_H_ */

