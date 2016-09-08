#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/* ��ʼ��ջͷ */
stack_head_t *init_stack(int capacity)
{
    stack_head_t *stack_hp;

    stack_hp = (stack_head_t *)malloc(sizeof(stack_head_t));
    if (stack_hp == NULL) {
        return NULL;
    }
    stack_hp->stack_capacity = capacity;
    stack_hp->node_num = 0;
    stack_hp->top = NULL;
    stack_hp->bottom = NULL;

    return stack_hp;
}

/* ��ʼ��ջ�ڵ� */
stack_t *init_stack_node(void *param)
{
    stack_t *node;

    node = (stack_t *)malloc(sizeof(stack_t));
    if (node == NULL) {
        return NULL;
    }
    node->back = NULL;
    node->data = param;

    return node;
}

/* ��ջ */
void push(stack_head_t *stack_head, stack_t *node)
{
    if (stack_head == NULL || node == NULL) {
        return;
    }

    if (stack_head->node_num >= stack_head->stack_capacity) {
        printf("Error: stack is full.\n");
        return;
    }
    
    if (stack_head->node_num == 0) {
        stack_head->bottom = node;
        stack_head->top = node;
        stack_head->node_num++;
    } else {
        stack_head->top->back = node;
        stack_head->top = node;
        stack_head->node_num++;
    }

    return;
}

/* ��ջ */
stack_t *pop(stack_head_t *stack_head)
{
    stack_t *tmp;
    
    if (stack_head == NULL || stack_head->bottom == NULL || stack_head->top == NULL) {
        return NULL;
    }

    tmp = stack_head->bottom;

    /* ֻ��һ���ڵ� */
    if (stack_head->bottom == stack_head->top) {
        stack_head->bottom = NULL;
        stack_head->top = NULL;
        stack_head->node_num--;
        return tmp;
    }
    
    while (tmp->back != stack_head->top) {
        tmp = tmp->back;
    }

    stack_head->top = tmp;
    tmp = tmp->back;
    stack_head->top->back = NULL;
    stack_head->node_num--;

    return tmp;
}

/* ��ȡ�ڵ��ַ */
stack_t *get_node(stack_head_t *stack_head, int index)
{
    stack_t *node;
    int i;

    if (stack_head == NULL) {
        return NULL;
    }

    if (index > stack_head->node_num) {
        printf("index is too large, the number of the node is just: %d", stack_head->node_num);
        return NULL;
    }

    node = stack_head->bottom;
    i = 1;
    while (node) {
        if (node == NULL) {
            printf("data may be wrong.\n");
            return NULL;
        }
        if (i == index) {
            return node;
        }
        node = node->back;
        i++;
    }

    return NULL;
}

/* ��ȡջ��ָ�� */
stack_t *get_top(stack_head_t *head)
{
    return get_node(head, 1);
}

/* ��ȡջ��ָ�� */
stack_t *get_bottom(stack_head_t *head)
{
    return get_node(head, head->node_num);
}

/* ��ȡ�ڵ����� */
int get_node_num(stack_head_t *head)
{
    if (head == NULL) {
        return 0;
    }
    
    return head->node_num;
}

/* ��ȡջ�ռ��С */
int get_stack_capacity(stack_head_t *head)
{
    if (head == NULL) {
        return 0;
    }

    return head->stack_capacity;
}

/* ɾ��ջ */
void free_stack(stack_head_t *head)
{
    if (head == NULL) {
        return;
    }

    while (head->bottom != NULL) {
        free(pop(head));
    }

    return;
}

/* ��ӡջ */
void dump_stack(stack_head_t *head)
{
    stack_t *node;
    int i;
    
    if (head == NULL) {
        return;
    }
    printf("Stack Capacity: %d\n", head->stack_capacity);
    printf("Stack node num: %d\n", head->node_num);
    if (head->node_num > 0) {
        i = 0;
        node = head->bottom;
        while (node) {
            i++;
            printf("  %04d. data: %d ->\n", i, *(int *)(node->data));
            node = node->back;
        }
    }

    return;
}
