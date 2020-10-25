#include <stdio.h> 
#include <stdlib.h>

struct Stack  
{ 
    char item;
    struct Stack* self_reference;
};

void push(struct Stack** stack, int item) 
{ 
    struct Stack* new_stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    if (new_stack == NULL)
    { 
        printf("Stack overflow\n"); 
        getchar(); 
        exit(0); 
    }
    new_stack->item = item; 
    new_stack->self_reference = (*stack);
    (*stack) = new_stack; 
} 

int pop(struct Stack** stack) 
{ 
    char top; 
    struct Stack* new_stack2; 
 
    if (*stack == NULL)  
    { 
        printf("Stack overflow\n"); 
        getchar(); 
        exit(0); 
    } 
    else 
    { 
        new_stack2 = *stack; 
        top = new_stack2->item;
        *stack = new_stack2->self_reference; 
        free(new_stack2);
        return top; 
    } 
}

int pair(char opening, char closing) 
{ 
    if (opening == '(' && closing == ')') 
        return 1; 
    else if (opening == '{' && closing == '}') 
        return 1; 
    else if (opening == '[' && closing == ']') 
        return 1; 
    else
        return 0; 
} 

int balanced(char arg[]) 
{ 
    struct Stack* stack = NULL; 
    int i = 0;

    while (arg[i])  
    {
        if (arg[i] == '{' || arg[i] == '(' || arg[i] == '[') 
            push(&stack, arg[i]);
        else if (arg[i] == '}' || arg[i] == ')' || arg[i] == ']')  
        {
            if (stack == NULL) 
                return 0; 
            else if (!pair(pop(&stack), arg[i])) 
                return 0; 
        } 
        i++; 
    } 

    if (stack == NULL) 
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