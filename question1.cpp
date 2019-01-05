#include <stdio.h>
#include <stdlib.h>

int valueIndex=0;
int comingNumberIndex=0;
bool checkTree=true;
int numBers[50];

struct n{
	int data;
	n* right;
	n* left;
};
typedef n node;

void isBst(int comingNumber) // Add in array which I get data from dolas 
{
	numBers[comingNumberIndex] = comingNumber;			
	comingNumberIndex++;	
}


void dolas(node*tree)// I sort my data from small to large and send isBst function every single data.
{ 
	if(tree==NULL){		
		return;		
	}
	
	dolas(tree -> left);
	printf("%d " , tree->data);
	isBst(tree -> data);	  	  
	dolas(tree->right);
}

node* newNode(int data) //This function is creating my BinarySearchTree
{
	node * root=(node*)malloc(sizeof(node));
	root -> data = data;
	root -> right = NULL;
	root -> left=NULL;

}


int main(){
	int i;
   node * tree = newNode(10); 
   tree->left = newNode(5); 
   tree->right= newNode(9); 
   tree->left->left = newNode(3); 
   tree->left->right = newNode(6);	
   dolas(tree);
   
   for(i =0 ; i<comingNumberIndex; i++){
   	if(i==0){ continue;} // I wanna compare indexLeft,index,indexRight and continue the first number.
	   else if(i == (comingNumberIndex-1)){ // I'm checking the end of the array or not
	   	   if(numBers[i] < numBers[i-1]){ // If I'm end of the array just check indexLeft,index
	   	   	checkTree = false;
	   	   	break;
			  }
			  else{
			  break;
			  }
	   }
	   else if(numBers[i] < numBers[i-1] || numBers[i] > numBers[i+1]){ // It's the normal check which indexLeft,index,indexRight
            checkTree = false;
	   	   	break;
	   }	   
   }
   printf("\n");
   if(checkTree==true){ // And Control!
   	printf("It's Binary Search Tree");
   }
   else{
   	printf("It's not Binary Search Tree");
   }
}
