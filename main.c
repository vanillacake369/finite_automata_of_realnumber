#include <stdio.h>
#include <stdlib.h>

void FSM_of_Realnumber(FILE* file) {
    char inchar = '\0';
    int state = 0;

    while ((inchar = fgetc(file)) != EOF) {
        switch (state) {
            case 0: {
                if (inchar >= '0' && inchar <= '9') {
                    state = 1;
                    printf("%c", inchar);
                } else {
                    printf("\n");
                    printf("reject\n");
                    exit(0);
                }
                break;
            }
            case 1: {
                if (inchar >= '0' && inchar <= '9') {
                    state = 1;
                    printf("%c", inchar);
                } else if (inchar == '.') {
                    printf("%c", inchar);
                    state = 2;
                } else {
                    printf("\n");
                    printf("reject\n");
                    exit(0);
                }
                break;
            }
            case 2: {
                if (inchar >= '0' && inchar <= '9') {
                    state = 3;
                    printf("%c", inchar);
                } else {
                    printf("\n");
                    printf("reject\n");
                    exit(0);
                }
                break;
            }
            case 3: {
                if (inchar >= '0' && inchar <= '9') {
                    state = 3;
                    printf("%c", inchar);
                } else {
                    printf("\n");
                    printf("reject\n");
                    exit(0);
                }
                break;
            }
        }
    }
    if (inchar == EOF && state == 3) {
        printf("\n");
        printf("accept\n");
    } else {
        printf("\n");
        printf("reject\n");
    }
}

int main() {
    FILE* file = fopen("C:\\Users\\user\\CLionProjects\\untitled\\input.txt", "r");

    if (!file) {
        printf("error on opening file.\n");
        exit(1);
    }
    FSM_of_Realnumber(file);
    fclose(file);
    return 0;
}