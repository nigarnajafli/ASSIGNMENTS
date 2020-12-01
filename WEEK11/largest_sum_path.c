#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 512

struct Node{
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->right = NULL;
    node->left = NULL;
    return node;
}

int addNodes (struct Node *iter){
    if (iter == NULL){
        return 0;
    }
    return iter->value + addNodes(iter->left) + addNodes(iter->right);
}

int largestSumPath(struct Node *iter){
    if (iter == NULL){
        return 0;
    }
    int left = largestSumPath(iter->left);
    int right = largestSumPath(iter->right);
    if (left>=right)
        return iter->value + left;
    else
        return iter->value + right;
}

char *readLine(char *buf, int num, FILE* stream){
    for (size_t i=0; i<num; i++){
        if (fread(buf, 1, 1, stream) == 0){
            if (i == 0){
                buf[i]='\0';
                return NULL;
            }
            else{
                buf[i]='\0';
                break;
            }
        }
        if (buf[i]=='\n'){
            buf[i]='\0';
            break;
        }
    }
    buf[num-1] = '\0';
    return buf;
}

struct Node* levelOrderInsert(int *numStack, int SIZE, int index){
    struct Node* tmp = NULL;
    if (index < SIZE){
        tmp = newNode(numStack[index]);
        tmp->value = numStack[index];
        tmp->left = levelOrderInsert(numStack, SIZE, 2*index + 1);
        tmp->right = levelOrderInsert(numStack, SIZE, 2*index+2);
    }
    return tmp;
}

int main(int argc, char** argv){
    if (argc < 2){
        fprintf(stderr, "needs at least one argument\n");
        exit(1);
    }

    FILE *infile = fopen (argv[1], "r");
    if (infile == NULL){
        fprintf(stderr, "can't open the file\n");
        exit(2);
    }
    char buf[BUF_SIZE];
    int numStack[256];
    int numStackTop = -1;
    struct Node* head = NULL;

    for (; readLine(buf, BUF_SIZE, infile) != NULL; ){
        for (int i=0; buf[i] != '\0'; i++){
            if (buf[i] >= 48 && buf[i]<=57){
                int temp = (int)(buf[i]-48);
                numStack [++numStackTop]=temp;
            }
        }
    }
    head = levelOrderInsert(numStack, numStack+1, 0);
    printf("max path sum of the tree is %d\n", largestSumPath(head));
    return 0;
}