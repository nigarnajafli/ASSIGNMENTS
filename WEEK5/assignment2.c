#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_CAPACITY 2

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack()
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = STACK_CAPACITY;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void deallocStack(struct Stack* stack)
{
    free(stack->array);
    free(stack);
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
void resize(struct Stack* stack)
{
    stack->capacity *= 2;
    stack->array = (char*)realloc(stack->array,stack->capacity * sizeof(int));
}

void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        resize(stack);
    stack->array[++stack->top] = item;
}

void pop(struct Stack* stack)
{
    --stack->top;
}

int pair(char opening, char closing){
    if (opening == '[' && closing ==']')
        return 1;
    else if (opening == '{' && closing == '}')
        return 1;
    else if (opening == '(' && closing == ')')
        return 1;
    else
        return 0;
}

int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

int balanced(char arg[]){
    struct Stack* stack = createStack();
    int i = 0;
    while (arg[i]){
        if (arg[i] == '[' || arg[i] =='{' || arg[i] == '(')
            push(stack, arg[i]);
        else if (arg[i] = '}' || arg[i] ==']' || arg[i] == ')'){
            if (isEmpty(stack))
                return 0;
            else if (!(peek(stack), arg[i])){
                return 0;}
            pop(stack);
        }
        i++;
    }
    if (isEmpty(stack))
        return 1;
    else
        return 0;
}

int main(int argc, char *argv[]){
    if (balanced(argv[1]))
        printf("Yes\n");
    else
        printf("No\n");
}
      