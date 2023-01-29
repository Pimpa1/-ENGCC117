#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value ;
	struct Node *link ;
}Node ;

void AddNode( Node **start , int new_value ) ;
void ShowAll( Node *start ) ; 
void Update( Node **start , int value , int pim ) ;

int main() {
	Node *start= NULL ;
	AddNode( &start, 10 ) ;
    AddNode( &start, 20 ) ;
    AddNode( &start, 30 ) ;
    AddNode( &start, 40 ) ;
    ShowAll( start ) ; //10, 20, 30, 40
    Update( &start, 10, 99 ) ;
    ShowAll( start ) ; //99, 20, 30, 40
    Update( &start, 10, 98 ) ;
    ShowAll( start ) ; //99, 20, 30, 40
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

void Update( Node **start , int value , int pim ) {
	Node* tmp = new Node();
    tmp = *start;
    while(tmp != NULL && tmp->value != value ) {
    	tmp = tmp-> link ;
    }
    if(tmp != NULL) {
        tmp->value = pim ;
        return;
    } 
}//end funtions void Update


