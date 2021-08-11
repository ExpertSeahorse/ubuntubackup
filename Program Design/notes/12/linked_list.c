#include <stdio.h>
struct node{
	int value;
	struct node *next;
};

struct node *add_to_list(struct node *list, int n){
	struct node *new_node, *prev, *cur;
	new_node = malloc(sizeof(struct node));
	new_node -> value = n;
	
	// Determine where new node is supposed to be
	for(prev=NULL, cur=list; cur!=NULL && cur->value<new_node->value; prev=cur, cur=cur->next)
		;

	// If number already exists
	if(cur!=NULL && new_node->value==cur->value){
		printf("Number already exists");
		free(newn=_node);
		return list;
	}

	// If number is first in list
	if(prev=NULL){
		new_node->next = cur;
		return new_node;
	}

	// If number is in the middle of the list	
	else{
		prev->next = new_node;
		new_node->next = cur;
		return list;
	}
}

void print_list(struct node *list){
	struct node *p;
	for(p=list; p->next!=NULL; p=p->next)
		printf("Value: %d", p->value)
}


int main(){

	return 0;
}
