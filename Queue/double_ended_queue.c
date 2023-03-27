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
    qu->front = 0;
    qu->rear = -1;
}

bool isRearOverflow(queue *qu){
    if(qu->rear == SIZE -1){
        return true;
    }
    return false;
}

bool isFrontOverflow(queue *qu){
    if(qu->front == 0){
        return true;
    }
    return false;
}

bool isUnderflow(queue *qu){
    if(qu->front > qu->rear){
        return true;
    }
    return false;
}

int insertRear(queue *qu, int value){
    qu->rear++;
    qu->item[qu->rear] = value;
}

int deleteRear(queue *qu){
    int value = qu->item[qu->rear];
    qu->rear--;
    return value;
}   

int insertFront(queue *qu, int value){
    qu->front--;
    qu->item[qu->front] = value;
}

int deleteFront(queue *qu){
    int value = qu->item[qu->front];
    qu->front++;
    return value;
}

int menu(queue *qu){  
    int choice;
    int value;
    printf("1-> insert at rear\n2-> delete from rear\n3-> insert at front\n4-> delete from front\n5-> exit");
    while(1){
            printf("Choose a option: ");
            scanf("%d", &choice);
            switch(choice){
                    case 1: 
                            if(isRearOverflow(qu)){
                                printf("Queue is overflow\n");
                            }
                            else {
                                printf("Enter a value: ");
                                scanf("%d", &value);
                                insertRear(qu, value);
                                printf("Success\n");
                            }
                            break;
                    case 2:
                            if(isUnderflow(qu)){
                                printf("Queue is underflow\n");
                            }
                            else{
                                value = deleteRear(qu);
                                printf("Data deleted: %d\n", value);
                            }
                            break;
                    case 3:
                            if(isFrontOverflow(qu)){
                                printf("Queue is overflow\n");
                            }
                            else {
                                printf("Enter a value: ");
                                scanf("%d", &value);
                                insertFront(qu, value);
                                printf("Success\n");
                            }
                            break;
                    case 4:
                            if(isUnderflow(qu)){
                                printf("Queue is underflow\n");
                            }
                            else{
                                value = deleteFront(qu);
                                printf("Data deleted: %d\n", value);
                            }
                            break;
                    case 5: 
                            exit(0);
                    default:
                            printf("Invalid choice\n");
            }
    }
}

int main(){
    queue queue;
    init(&queue);
    menu(&queue);
    
    return 0;
}