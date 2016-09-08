# cSimpleStack
用C实现的一个栈

```c
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
```