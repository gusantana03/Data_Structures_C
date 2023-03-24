#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

typedef struct{
    int item[10];
    int rear;
    int front;
}queue;

bool isOverflow(queue *qu){
    if(qu->rear == SIZE){
        return true;
    }
    return false;
}

bool isUnderflow(queue *qu){
    if(qu->front == qu->rear){
        return true;
    }
    return false;
}

int enQueue(queue *qu, char value){
    qu->item[qu->rear] = value;
    qu->rear++;
    return 1;
}

int deQueue(queue *qu){
    qu->front++;
}

void init(queue *qu){
    qu->front = 0;
    qu->rear = 0;
}

int menu(queue *qu){
    int choice;
    int value;
    printf("1-> enQueue\n2-> deQueue\n3-> exit\n");
    while(1){
        printf("Choose a option: ");
        scanf("%d", &choice);
        switch(choice){
                case 1: 
                        if(isOverflow(qu)){
                            printf("Queue is overflow\n");
                        }
                        else {
                            printf("Enter a value: ");
                            scanf("%d", &value);
                            enQueue(qu, value);
                            printf("Success\n");
                        }
                        break;
                case 2:
                        if(isUnderflow(qu)){
                            printf("Queue is underflow\n");
                        }
                        else{ 
                            deQueue(qu);
                            printf("Data deQueue\n");
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

int main(){
    queue queue;
    init(&queue);
    menu(&queue);
    
    return 0;
}