#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 50

typedef struct {
    char item[SIZE];
    int top;
}stack;

int isOverflow(stack *sp){
    return sp->top == SIZE - 1;
}

int isUnderflow(stack *sp){
    return sp->top == -1;
}

void push(stack *sp, char value){
    //check stack overflow
    if(isOverflow(sp)){
        printf("Stack overflow\n");
        return;
    }
    sp->top++;
    sp->item[sp->top] = value;
}

int pop(stack *sp){
    //check stack underflow
    if(sp->top == -1){
        printf("Stack underflow\n");
        return -9999;
    }
    int value;
    value = sp->item[sp->top];
    sp->top--;
    return value;
}

int matches(stack *sp, char pair){
    int match = 0;
    switch(sp->item[sp->top]){
        case '(': if (pair == ')')
        match = 1;
        break;

        case '{': if (pair == '}')
        match = 1;
        break;

        case '[': if (pair == ']')
        match = 1;
        break;

        default: printf("Invalid symbol was encountered\n");
        exit(1);
    }
    return match;
}

int checkExpression(stack *sp, char ex[SIZE]){
    bool error = false; 

    int i = 0;
    while(ex[i] != '\0'){
        if(ex[i] == '(' || ex[i] == '{' || ex[i] == '['){
            push(sp, ex[i]);
        }
        else if(ex[i] == ')' || ex[i] == '}' || ex[i] == ']'){
            if(isUnderflow(sp)){
                error = true;
                break;
            }
            else if(matches(sp, ex[i])){
                pop(sp);
            }
            else{
                error = true;
                break;
            }
        }
        i++;
    }
    if(error == 0 && !isUnderflow(sp)){
        error = true;
    }

    return error;
}

//initialize the top with -1
void init(stack *sp){
    sp->top = -1;
}

int main(){
    char ex[SIZE];
    printf("Type the expression: ");
    fgets(ex, 50, stdin);
    stack stack;
    init(&stack);
    if(!checkExpression(&stack, ex)){
        printf("The input is well formed\n");
    }
    else if(checkExpression(&stack, ex)){
        printf("The input does not contain well formed bracket\n");
    }

    return 0;
}