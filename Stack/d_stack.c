#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    int top;
    int size;
}stack;

void push(stack *sp, int value){
    //check stack overflow
    if(sp->top == sp->size - 1){
        int *temp;
        temp = (int *)malloc(sizeof(int) * sp->size * 2);
        if(temp == NULL){
            printf("Stack overflow\n");
            return;
        }
        int i;
        for(i=0; i<=sp->top; i++){
            temp[i] = sp->item[i];
        }
        free(sp->item);
        sp->item = temp;
        sp-> size *= 2;
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
void init(stack *sp, int size){
    sp->top = -1;
    sp->item = (int *)malloc(sizeof(int) * size);
    if(sp->item == NULL){
        printf("Unbale to allocate memory\n");
        exit(1);
    }
    sp->size = size;
}

void deallocate(stack *sp){
    if(sp->item!=NULL){
        free(sp->item);
    }
    sp->top = -1;
    sp->size = 0;
}

int getSize(stack *sp){
    return sp->size;    
}

int main(){
    stack s1;
    init(&s1, 3);

    printf("1. Push\n");    
    printf("2. Pop\n");  
    printf("3. Exit\n");
    int choice, value;

    while(1){
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("size of stack: %d\n", getSize(&s1));
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