#include <stdio.h>

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
}Node;

void addNode(Node** p, int val);
int calcSum(Node*p);
void printTree(Node *p);
void cleanTree(Node *p);

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    
    int i=0;
    while(i<5){
    	int value;
    	printf("Escreva um numero: ");
    	scanf("%d", &value);
    	addNode(&head, value);
    	i++;
	}
	
	printf("\nSoma dos nos: %d\n", calcSum(head));
	printf("\nArvore: ");
	printTree(head);
	printf("\n");
	cleanTree(head);
    
    return 0;
}

void addNode(Node **p, int val){
	if(*p == NULL){
		*p = (Node*) malloc(sizeof(Node*));
		(*p)->value = val;
		(*p)->left=NULL;
		(*p)->right=NULL;
	}else{
		if(val < (*p)->value){
			addNode(&(*p)->left, val);
		}else{
			addNode(&(*p)->right, val);
		}
	}
}

int calcSum(Node *p){
	if(p == NULL){
		return 0;
	}
	
	return p->value + calcSum(p->left) + calcSum(p->right);
}

void printTree(Node *p){
	if(p == NULL){
		return;
	}
	
	printTree(p->left);
	printf("%d ", p->value);
	printTree(p->right);
}

void cleanTree(Node *p){
	if(p == NULL){
		return;
	}
	
	cleanTree(p->left);
	cleanTree(p->right);
	
	printf("No %d deletado!\n", p->value);
	free(p);
}




