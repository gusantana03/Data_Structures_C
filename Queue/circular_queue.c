#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

typedef struct{
    int item[10];
    int rear;
    int front;
}queue;

void init(queue *qu){
    qu->front = SIZE-1;
    qu->rear = SIZE -1;
}

bool isOverflow(queue *qu){
    if((qu->rear + 1) % SIZE == qu->front){
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
    qu->rear = (qu->rear + 1) % SIZE;
    qu->item[qu->rear] = value;
    return 0;
}

int deQueue(queue *qu){
    int value;
    qu->front = (qu->front + 1) % SIZE;
    value = qu->item[qu->front];
    return value;
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
                            value = deQueue(qu);
                            printf("Data deQueue: %d\n", value);
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