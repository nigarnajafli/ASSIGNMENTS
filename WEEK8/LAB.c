#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node {
    char name[256];
    struct node * next;
} node_t;

void free_up (node_t *head){
    while (head != NULL){
        free(head);
        head=head->next;
    }
}

void print_list(node_t *head){
    node_t *current = head;
    while (current != NULL){
        printf("%s ", current->name);
        current = current->next;
    }
    printf("\n");
}

void push(node_t * head, char *name){
    node_t *current = head;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = (node_t *)malloc(sizeof(node_t));
    strcpy(current->next->name, name);
    current->next->next = NULL;
}

bool in_queue=1;
void remove_customer(node_t **head, char *name){
    node_t *current = *head;
    node_t *temp_node = NULL;
    if (current != NULL && strcmp(current->name, name)==0){
        *head = current->next;
        free(current);
        return;}
    while (current != NULL && strcmp(current->name, name) != 0){
        temp_node = current;
        current = current->next;
    }

    if (current == NULL){
        in_queue = 0;
        printf("Not in queue\n");
        return;
    }

    temp_node->next = current->next;
    free(current);
}

int main(){
    char input[256];
    bool quit = 0;
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));

    strcpy(head->name, "Turgut");
    head->next = NULL;
    push(head, "Nazrin");
    push(head, "Nigar");
    push(head, "Kamran");
    push(head, "Eljan");
    print_list(head);
    while(!quit)
    {
        printf("Enter a command: ");
        scanf( "%s" , input);
        if (strcmp(input,"quit") == 0)
        {
            free_up(head);
            head = NULL;
            quit = 1;
        }
        else if (strcmp(input,"admit") == 0)
        {
            printf("%s was admitted\n", head->name);
            remove_customer(&head, head->name);
            print_list(head);
        }
        else
        {
            remove_customer(&head, input);
            if (in_queue){
            push(head, input);}
            in_queue=1;
            print_list(head);
        }
    }
}