#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 100
bool win=1;
char *checkMatch (char *try, char *password, int length){
    char *arr = (char *)malloc(length*sizeof(char));
    for (int i=0; i<length; i++){
        int match=0;
        if (try[i] == password[i])
            arr[i] = '+';
        else {
            win = 0;
            for (int k=0; k<length; k++){
                if (try[i] == password[k]){
                    arr[i] = '!';
                    match = 1;
                    break;
                }
            }
            if (match == 0)
                arr[i] = '.';
        }
    }
    return arr;
}

void win_or_not(bool win){
    if (win == 1)
        printf("correct, here's how you did:\n");
    else
        printf("incorrect, here's how you did\n");
}

void check(char *try, char *password, int length){
    int i=0;
    for (; try[i]!='\0'; i++)
        ;
    if (i == length){
        char *feedback = (char *)malloc(length*sizeof(char));
        feedback = checkMatch(try, password, length);
        win_or_not(win);
        for (int k=0; k<length; k++)
            printf("%c", try[k]);
        printf("\n");
        for (int j=0; j<length; j++)
            printf("%c", feedback[j]);
        printf("\n");
        free(feedback);
    }
    else{
        printf("Wrong number of characters, try again.\n");
        win = 0;
    }
}

void asking(char *password, int length, int tries){
    char quit[5]="!quit";
    while(true){
        printf("You have %d tries left: ", tries);
        char *try = (char *)malloc(50*sizeof(int));
        scanf("%s", try);
        for(int k=0; k<5; k++){
            if (try[k] != quit[k])
                break;
            if (k=4)
                return;}
        check(try, password, length);
        if (win == 1){
            printf("you win\n");
            return;
        }
        else{
            win=1;
            printf("try again\n");
        }
        tries--;
        if (tries == 0){
            printf("game over\n");
            return;
        }
        free(try);
    }
}

int main(int argc, char **argv){
    if (argc < 2 ){
        fprintf(stderr, "needs at least one argument");
        exit(1);
    }
    FILE* infile = fopen(argv[1], "r");
    if (infile == NULL) {
        printf("Cannot open a file\n");
        exit(2);
    }
    char buf[BUF_SIZE];
    buf[BUF_SIZE-1] = '\0';
    size_t buf_size = sizeof(buf);
    fread(buf, 1, buf_size, infile);
    char *password = (char *)malloc(buf_size*sizeof(int));
    int length = 0;
    int tries = 0;
    int i=0;
    for (; buf[i]!=32; i++)
        password[i] = buf[i];
    for (; buf[i]==32; i++)
        ;
    for (; buf[i]>=48 && buf[i]<=57; i++)
        length = 10*length + (buf[i] - '0');
    for (; buf[i]==32; i++)
        ;
    for (; buf[i]>=48 && buf[i]<=57; i++)
        tries = 10*tries + (buf[i] - '0');
    printf("Welcome to Fallout 3 hacking minigame!\n");
    printf("The passphrase contains %d letters.\n", length);
    asking(password, length, tries);
    free(password);
    return 0;
}