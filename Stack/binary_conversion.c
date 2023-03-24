#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *item;
    int top;
    int size;
}stack;

int isOverflow(stack *sp){
    return sp->top == sp->size - 1;
}

int isUnderflow(stack *sp){
    return sp->top == -1;
}

void push(stack *sp, int value){
    //check stack overflow
    if(isOverflow(sp)){
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
    if(isUnderflow(sp)){
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

void printBinary(unsigned int n){
    stack s;
    int temp = n;
    const int BASE = 2;
    init(&s, 10);

    while(n > 0){
        int rem = n % BASE;
        push(&s, rem);
        n /= BASE;
    }
    printf("Binary equivalent of %d is: ", temp);
    while(!isUnderflow(&s)){
        printf("%d", pop(&s));
    }
    deallocate(&s);
}

int main(){

    printBinary(10);

    return 0;
}