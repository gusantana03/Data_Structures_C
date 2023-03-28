#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

typedef struct{
    struct node *head;
    struct node *tail;
    int nodeCount;
}linkedList;

void initList(linkedList *listPointer){
    listPointer->head = NULL;
    listPointer->tail = NULL;
    listPointer->nodeCount = 0;
}

int insertTail(linkedList *listPointer, int data){
    node *newNodePointer = (node*)malloc(sizeof(node));
    if (newNodePointer == NULL){
        printf("Error while allocating memory.\n");
        return 1;
    }
    newNodePointer->data = data;
    newNodePointer->next = NULL;

    if(listPointer->nodeCount == 0){
        listPointer->head = newNodePointer;
        listPointer->tail = newNodePointer;
    }
    else{
        listPointer->tail->next = newNodePointer;
        listPointer->tail = newNodePointer;
    }
    listPointer->nodeCount++;
    return 0;
}

int insertHead(linkedList *listPointer, int data){
    node *newNodePointer = (node*)malloc(sizeof(node));
    if (newNodePointer == NULL){
        printf("Error while allocating the memory.\n");
        return 1;
    }
    newNodePointer->data = data;
    newNodePointer->next = NULL;

    if(listPointer->nodeCount == 0){
        listPointer->head = newNodePointer;
        listPointer->tail = newNodePointer;
    }
    else{
        newNodePointer->next = listPointer->head;
        listPointer->head = newNodePointer;
    }
    listPointer->nodeCount++;  
    return 0;
}

int printList(linkedList *listPointer){
    if (listPointer->nodeCount == 0){
        printf("List it's empty.\n");
        return 1;
    }

    node *current = listPointer->head;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
    return 0;
}

int menu(linkedList *listPointer){
    int choice, value;
    printf("1-> ");
    while(1){
        printf("Choose a option: ");
        scanf("%d", &choice);
        switch(choice){
                case 1: 
                    scanf("%d", &value);
                    insertTail(listPointer, value);
                    break;
                case 2:
                    printList(listPointer);
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
    linkedList list;
    initList(&list);

    menu(&list);

}