#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value ;
	struct Node *link ;
}Node ;

void AddNode( Node **start , int new_value ) ;
void ShowAll( Node *start ) ; 
void ShowBack( Node *start ) ;

int main() {
	Node *start= NULL ;
    AddNode( &start, 10 ) ;
    AddNode( &start, 20 ) ;
    AddNode( &start, 30 ) ;
    AddNode( &start, 40 ) ;
    ShowAll( start ) ; //10, 20, 30, 40
    ShowBack( start ) ; //40, 30, 20, 10
}//end funtions int main

void AddNode( Node **start , int new_value ) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    Node* tmp = (Node*) malloc(sizeof(Node));
    new_node->value = new_value;
    new_node->link = (*start);
    (*start)    = new_node;
}//end funtions void AddNode

void ShowAll( Node *start ) {
	while ( start != NULL ) {
		printf ( "%d " , start->value ) ;
		start = start->link ;
	}
	printf ( "\n" ) ;
}//end funtions void ShowAll

void ShowBack( Node *start ) {
	if(start == NULL || start->link == NULL) return;
	Node *parent = start ;
	Node *me = start->link;
	Node *child = me->link;
	parent->link = NULL;
	
	while(child != NULL) {
		me->link = parent;
		parent = me;
		me = child;
		child = child->link;
	}

	start = me;
	
	start->link = parent; 
	ShowAll( start ) ;
}//end funtions void ShowBack
