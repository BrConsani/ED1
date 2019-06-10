#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
}Node;

void addNode(Node** p, int val);
int lowestNode(Node *p);
int highestNode(Node *p);
int pairNodes(Node *p);
int highestThanValue(Node *p, int val);
int removeLowest(Node *p);

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

    printf("Menor valor: %d\n", lowestNode(head));
    printf("Maior valor: %d\n", highestNode(head));
    printf("Pares: %d\n", pairNodes(head));

    int value;
    printf("Escreva um numero para comparacao: ");
    scanf("%d", &value);
    printf("Valores maiores que %d: %d\n", value, highestThanValue(head, value));
    removeLowest(head);

    return 0;
}

void addNode(Node **p, int val){
	if(*p == NULL){
		*p = (Node*) malloc(sizeof(Node));
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

int lowestNode(Node *p){
    if(p->left==NULL){
        return p->value;
    }
    return lowestNode(p->left);
}

int highestNode(Node *p){
    if(p->right==NULL){
        return p->value;
    }
    return highestNode(p->right);
}

int pairNodes(Node *p){
    if(p == NULL){
        return 0;
    }

    int i = pairNodes(p->left);
    i += pairNodes(p->right);
    if(p->value % 2 == 0){
        return i + 1;
    }else{
        return i;
    }
}

int highestThanValue(Node *p, int val){
    if(p == NULL){
        return 0;
    }

    int i;
    i = highestThanValue(p->left, val);
    i += highestThanValue(p->right, val);

    if(p->value > val){
        return i + 1;
    }else{
        return i;
    }
}

int removeLowest(Node *p){
    if(p == NULL){
        return 0;
    }

    int i = removeLowest(p->left);
    if(i != -1){
        printf("No %d removido!\n", p->value);
        free(p);
        return -1;
    }
    
}