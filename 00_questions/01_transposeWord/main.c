#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

struct Stack {
    char* items[MAX_LEN];
    int top;
};

struct Stack* creat_stack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int is_empty(struct Stack* stack) {
    return (stack->top == -1);
}

void push(struct Stack* stack, char* item) {
    stack->items[++stack->top] = strdup(item);
}

char* pop(struct Stack* stack) {
    if(is_empty(stack)) return NULL;
    return stack->items[stack->top--];
}

char* transpose_word(const char* str) {
    struct Stack* stack = creat_stack();
    char* word = (char*)malloc(MAX_LEN * sizeof(char));
    char* res = (char*)malloc(MAX_LEN * sizeof(char)); 
    memset(word, 0, MAX_LEN);
    memset(res, 0, MAX_LEN);

    int j = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') {
            push(stack, word);
            word = (char*)malloc(MAX_LEN * sizeof(char));
            memset(word, 0, MAX_LEN);
            j = 0;
        } else {
            word[j++] = str[i];
        }
    }
    push(stack, word);

    while(!is_empty(stack)) {
        strcat(res, pop(stack));
        strcat(res, " ");
    }
    return res;
}

void main() {
    const char* str = "I love Beijing";
    printf("orgiginal string is : %s\n", str);
    char* res = transpose_word(str);
    printf("transposed string is: %s\n", res);

}