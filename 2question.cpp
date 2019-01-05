#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct n{
	int data;
	n * next;
};
typedef n node;

bool isCycle(node*list){ 
	if(list == NULL){ // Check the list NULL or not
		return false;
	}
	node * fastIt = list -> next; // I'm creating a car and It's going to look the whole array before slowIt
	node * slowIt = list; // Its moving normally.
	while(fastIt != NULL && slowIt != NULL){
		if(fastIt == slowIt){ 
			return true;
		}
		fastIt=fastIt -> next -> next; // Move Time!
		slowIt = slowIt -> next; // Move Time!
	}
	return false;
	
}

node * newNode(int data){ // Create My Linked List
	node * root=(node*)malloc(sizeof(node));
	root -> data = data;
	root -> next = NULL;
	return root;
}

int main(){
	node * list = newNode(1);
	list -> next = newNode(2);
	list -> next -> next = newNode(3);
	list -> next -> next -> next = list -> next;
	isCycle(list);
	if( isCycle(list)== true){
		printf("There is a Loop!");
	}
	else{
		printf("There isn't a Loop!");
	}
}

