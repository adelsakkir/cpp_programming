#include <stdio.h>
#include <string.h>

typedef struct stack {
    int top;
    char data[100];
} stack;

void printStack(stack s) {
    printf("Stack contents:\n");
    // Loop through the stack from 0 to top and print the elements
    for (int i = 0; i <= s.top; i++) {
        printf("%c ", s.data[i]);  // Print each character
    }
    printf("\n");
}

int empty(stack *s){
    if (s->top == -1){return 1;}
    else{return 0;}
}

void pop(stack *s){
    if (!empty(s)){
        // return s->data[(*s).top]
        (*s).top--;}
}


void printReverseStack(stack *s) {
    printf("Stack contents in reverse:\n");
    // Loop through the stack from 0 to top and print the elements

    while (s->top != -1){
        printf("%c", s->data[s->top]);
        pop(s);
    }
}



void push(stack *s, char element){
    (*s).top++;
    (*s).data[(*s).top] = element;
}




int top(stack *s){
    if (!empty(s)){return s->data[s->top];}
    else {
        printf("Stack is empty!\n");
        return '\0';  // Return null character if stack is empty
    }
}

int main(void){
    char str[20] = "Adelisgod@1";
    stack s;
    s.top = -1;

    int i;
    for (i = 0; i< strlen(str); i++){
        push(&s, str[i]);
        
    }

    printStack(s);
    printReverseStack(&s);
}