#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}struct_node;

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
    if(newNodePointer == NULL){
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
    if(newNodePointer == NULL){
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

int insertFromFile(linkedList *listPointer){
    FILE *inputFile = fopen("integers.txt", "r");
    if (inputFile == NULL){
        printf("File couldn't be opended.\n");
        return 1;
    }
    int data;
    fscanf(inputFile, "%d", &data);
    while (!feof(inputFile)){
        insertTail(listPointer, data);
        fscanf(inputFile, "%d", &data);
    }
    return 0;
}

int deleteFirstNode(linkedList *listPointer){
    if(listPointer->nodeCount == 0){
        return 0;
    }
    struct_node *firstNode = listPointer->head;
    int data = firstNode->data;
    if(listPointer->nodeCount == 1){
        listPointer->head = NULL;
        listPointer->tail = NULL;
    }
    else{
        listPointer->head = firstNode->next;
    }
    free(firstNode);
    listPointer->nodeCount--;
    return data;
}

int deleteLastNode(linkedList *listPointer){
    if(listPointer->nodeCount == 0){
        return 0;
    }
    struct_node *currentNode = listPointer->head;
    int data = listPointer->tail->data;
    if(listPointer->nodeCount == 1){
        listPointer->head = NULL;
        listPointer->tail = NULL;
    }
    else{
        while(currentNode->next != listPointer->tail){
            currentNode = currentNode->next;
        }
        free(listPointer->tail);
        listPointer->tail = currentNode;
        listPointer->tail->next = NULL;
    }
    listPointer->nodeCount--; 
    return data;
}

int printList(linkedList *listPointer){
    if(listPointer->nodeCount == 0){
        printf("The list it's empty.\n");
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
    printf("1-> Insert at tail.\n2-> Insert at head.\n3-> Insert integers from file.\n4-> Delete the first node.\n5-> Delete the last node.\n6-> Display list.\n7-> Exit.\n");
    while(1){
        printf("Choose an option: ");
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
                    if(insertFromFile(listPointer) == 0){
                        printf("Integers were loaded from the file.\n");
                    }
                    else{
                        printf("Error while loading the integers from the file.\n");
                    }
                    break;
                case 4: 
                    int funcReturn = deleteFirstNode(listPointer);
                    if(funcReturn == 0){
                        printf("The list is empty.\n");
                    }
                    else{
                        printf("The deleted data is: %d.\n", funcReturn);
                    }
                    break;
                case 5:
                    funcReturn = deleteLastNode(listPointer);
                    if(funcReturn == 0){
                        printf("The list is empty.\n");
                    }
                    else{
                        printf("The deleted data is: %d.\n", funcReturn);
                    }
                    break;
                case 6:
                    printList(listPointer);
                    break;
                case 7: 
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