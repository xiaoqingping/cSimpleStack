#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack_s stack_t;

typedef struct stack_head_s {
    int stack_capacity;         /* ջ�ռ��С */
    int node_num;               /* ջ�ڵ����� */
    stack_t *top;               /* ջ�� */
    stack_t *bottom;            /* ջ�� */
} stack_head_t;

struct stack_s {
    stack_t *back;              /* ָ���һ����ջ�ڵ��ָ�� */
    void *data;                 /* �ڵ����� */
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

