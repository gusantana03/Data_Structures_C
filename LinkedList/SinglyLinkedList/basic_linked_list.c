#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} struct_node;

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
    struct_node *newNodePointer = (struct_node*)malloc(sizeof(struct_node));
    if (newNodePointer == NULL){
        printf("Error while allocating memory.\n");
        return 1;
    }
    //if the pointer was allocated it receives the data and the next node address is set to null.
    newNodePointer->data = data;
    newNodePointer->next = NULL;

    //if the node created is the first node of the linked list, both head and tail receives it's address. 
    if(listPointer->nodeCount == 0){
        listPointer->head = newNodePointer;
        listPointer->tail = newNodePointer;
    }
    //if the node created is not the first, the last node will receive the address of the new node and tail will receive the new node pointer.
    else{
        listPointer->tail->next = newNodePointer;
        listPointer->tail = newNodePointer;
    }
    listPointer->nodeCount++;
    return 0;
}

int insertHead(linkedList *listPointer, int data){
    struct_node *newNodePointer = (struct_node*)malloc(sizeof(struct_node));
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
    //the concept is the same as inserting into tail, but here the new node receives the address of the old one and head receive the address of the created node.
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

    //current will receive the head pointer, if not null it prints the data and receive the pointer of the next node of the linked list.
    struct_node *current = listPointer->head;
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
                    scanf("%d", &value);
                    insertHead(listPointer, value);
                    break;
                case 3:
                    printList(listPointer);
                    break;
                case 4: 
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