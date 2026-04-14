#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;

struct node *createNode(int value);

void constructStack(int n);
void pushNode(int nodeValue);
void popNode();
void peek();
void showStack();

struct node *createNode(int value){

	struct node *newNode = malloc(sizeof(struct node));


	if(newNode == NULL){
		printf("MALLOC FAILED, UNABLE TO ALLOCATE MEMORY, EXITING!\n");
		printf("stack overflow!\n");
		exit(1);
	}

	newNode->data = value;
	newNode->next = NULL;

	return newNode;
}

void pushNode(int nodeValue){
	struct node *newNode = createNode(nodeValue);
	newNode->next = head;
	head = newNode;
	printf("pushed %d into stack\n", nodeValue);
}

void popNode(){
	if(head == NULL){
		printf("stack underflow, nothing to pop\n");
		return;
	}
	struct node *temp = head;
	head = head->next;
	printf("popped value %d\n", temp->data);
	free(temp);
}

void peek(){
	if(head == NULL){
		printf("stack empty\n");
		return;
	}
	printf("top element: %d", head->data);
}

void showStack(){
	if(head == NULL){
		printf("stack empty\n");
		return;
	}

	struct node *temp = head;

	while(temp != NULL){
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(){

	int choice, val;

	while(1){
		printf("--------------\n");
		printf("stack options\n");
		printf("1. Push\n2. Pop\n3. Peek\n4. ShowStack\n5. Exit\n");
		printf("--------------\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &val);
				pushNode(val);
				break;
			case 2:
				popNode();
				break;
			case 3:
				peek();
				break;
			case 4:
				showStack();
				break;
			case 5:
				if(head != NULL){
					popNode();
				}
				exit(1);
			default:
				printf("Invalid choice\n");
		}
	}

	free(head);
	return 0;
}
