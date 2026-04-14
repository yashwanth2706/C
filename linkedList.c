#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *createNewNode(int value);
void createLinkedList(int n);
void printLinkedList();
void deleteLinkedList(int value);
void updateLinkedList(int currVal, int newVal);

struct node *createNewNode(int value){
    struct node *newNode = malloc(sizeof(struct node));

    if (newNode == NULL){
        printf("MALLOC FAILED, couldn't allocate memory, exiting");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void createLinkedList(int n){

    struct node *tail = NULL;
    int nodeValue;

    for(int i = 0; i < n; i++){

        printf("Enter node value:");
        scanf("%d", &nodeValue);

        struct node *newNode = createNewNode(nodeValue);

        if(head == NULL){
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }
    return;
}

void printLinkedList(){
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("(null)\n");
    return;
}

void deleteLinkedList(int value){
    struct node *currNode = head;
    struct node *prevNode = NULL;

    if(currNode != NULL && currNode->data == value){
	    head = currNode->next;
	    free(currNode);
	    return;
    }

    while(currNode != NULL && currNode->data != value){
	prevNode = currNode;    
        currNode = currNode->next;
    
    }

    if(currNode == NULL){ printf("Nothing to remove\n"); }

    prevNode->next = currNode->next;
    free(currNode);
}

void updateLinkedList(int currVal, int newVal){
	struct node *currNode = head;
	while(currNode != NULL ){
		if(currNode->data == currVal){
			currNode->data = newVal;
			break;
		}
	}
}

int main(){

    int length;
    printf("Enter the length of nodes for linkedList\n");
    scanf("%d", &length);

    createLinkedList(length);
    printLinkedList();
    deleteLinkedList(2);
    printLinkedList();
    updateLinkedList(3, 333);
    printLinkedList();

    free(head);
    return 0;
}
