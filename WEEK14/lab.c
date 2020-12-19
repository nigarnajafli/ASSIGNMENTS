#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	bool swapped;
	int data;
	struct Node * next;
}; 

void print_list (struct Node *head) {
	struct Node *current = head;
	while (current != NULL){
		printf("%d ", current->data);
		current = current -> next;
	}
}

void swap_nodes(struct Node** head, int swap_data){
	struct Node *first = *head;
	struct Node *prevf = NULL;
	while (first && first->data != swap_data){
		prevf = first;
		first = first->next;
	}
	struct Node *second = first->next;
	struct Node *prevs = first;
	if (first == NULL || second == NULL || first->swapped == 1 || second->swapped == 1){
		printf("No swap candidates found. Try again:\n");
		return;
	}
	if (prevf != NULL)
		prevf->next = second;
	else
		*head = second;
	if (prevs != NULL)
		prevs->next = first;
	else
		*head = first;
	struct Node *temp = second->next;
	second->next = first->next;
	first->next = temp;
	first->swapped = 1;
	second->swapped = 1;
	printf("result: ");
	print_list(*head);
	printf("\n");
}

void append(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *last = *head_ref;
	new_node->swapped = 0;
    new_node->data  = new_data; 
    new_node->next = NULL; 

    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    }   
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return;     
}

int main(){
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head = NULL;
	printf("Enter numbers to add to your list:\n");
	char input[256];
	int new_data;
	int swap_data;
	bool quit=0;
	while (!quit){
		scanf("%s", input);
		if (strcmp (input, "DONE") == 0)
			quit = 1;
		else
		{
			new_data = atoi(input);
			append(&head, new_data);
		}
	}
	quit=0;
	printf("Type two numbers to swap them around:\n");
	while (!quit){
		scanf("%s", input);
		if (strcmp (input, "DONE") == 0)
			quit = 1;
		else
		{
			swap_data = atoi(input);
			swap_nodes(&head, swap_data);
		}
	}
	free(head);
}
