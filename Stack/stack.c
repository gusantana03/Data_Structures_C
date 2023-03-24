#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int item[10];
    int top;
}stack;

void push(stack *sp, int value){
    //check stack overflow
    if(sp->top == SIZE - 1){
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

//initialize the top with -1
void init(stack *sp){
    sp->top = -1;
}

int main(){
    stack s1;
    init(&s1);

    printf("1. Push\n");    
    printf("2. Pop\n");  
    printf("3. Exit\n");
    int choice, value;

    while(1){
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                    printf("Enter a value: ");
                    scanf("%d", &value);
                    push(&s1, value);
                    break;
            case 2:
                    value = pop(&s1);
                    if(value!= -9999){
                        printf("Popped data: %d\n", value);
                    }
                    break;
            case 3: 
                    exit(0);

            default:
                    printf("Invalid choice\n");
        }
    }  
    return 0;
}