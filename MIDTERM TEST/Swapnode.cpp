//นางสาวพิมพา นารี 65543206074-8
//https://youtu.be/TvhVIB0pPHE


#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int value ;
	struct Node *link ;
}Node ;

void AddNode( Node **start , int new_value ) ;
void ShowAll( Node *start ) ; 
void Swap( Node **start , int x , int y ) ;

int main() {
	Node *start= NULL ;
    AddNode( &start, 10 ) ;
    AddNode( &start, 20 ) ;
    AddNode( &start, 30 ) ;
    AddNode( &start, 40 ) ;
    ShowAll(start) ; //10, 20, 30, 40
    Swap(&start, 20, 30) ;
    ShowAll(start) ; //10, 30, 20, 40
    Swap(&start, 40, 10) ;
    ShowAll(start) ; //40, 30, 20, 10
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

void Swap( Node **start , int x , int y  ) {
    
    if (x == y)
        return;

    Node *prevX = NULL, *currX = *start;
    while (currX && currX->value != x) {
        prevX = currX;
        currX = currX->link;
    }
 
    Node *prevY = NULL, *currY = *start;
    while (currY && currY->value != y) {
        prevY = currY;
        currY = currY->link;
    }
    if (currX == NULL || currY == NULL)
        return;
    if (prevX != NULL)
        prevX->link = currY;
    else 
        *start = currY; 
    if (prevY != NULL)
        prevY->link = currX;
    else 
        *start = currX;
    Node* temp = currY->link;
    currY->link = currX->link;
    currX->link = temp;
}//end funtions void Swap
