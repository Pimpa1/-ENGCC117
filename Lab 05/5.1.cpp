#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct studentNode {
  char name[20] ;
  int age ;
  char sex ;
  float gpa ;
  struct studentNode *next ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode( struct studentNode **head, const char *name, int age, char sex, float gpa ) ;
void InsNode( struct studentNode *walk, const char *name, int age, char sex, float gpa ) ;
void DelNode( struct studentNode *walk );

int main() {
  struct studentNode *start, *now ;
  start = NULL ;
  now = AddNode( &start , "one" , 6 , 'M' , 3.11 ) ; ShowAll( start ) ;
  now = AddNode( &start , "two" , 8 , 'F' , 3.22 ) ; ShowAll( start ) ;
  InsNode( now , "there" , 10 , 'M' , 3.33 ) ; ShowAll( start ) ;
  InsNode( now , "four" , 10 , 'M' , 3.33 ) ; ShowAll( start ) ;
  DelNode( now ) ; ShowAll( start ) ;

  return 0 ;
} //end function

void ShowAll( struct studentNode *walk) {
  while( walk != NULL ) {
    printf( "%s " , walk->name ) ;
    walk = walk->next ;
  }// end while
  printf( "\n" ) ;
} //end function ShowAll

struct studentNode *AddNode( struct studentNode **head , const char *name , int age , char sex , float gpa ) {
  struct studentNode *newnode = NULL , *lastNode = NULL ;
  newnode = (struct studentNode *)malloc(sizeof(struct studentNode)) ;
  strcpy( newnode->name , name ) ;
  newnode->age = age ;
  newnode->sex = sex ;
  newnode->gpa = gpa ;
  newnode->next = NULL ;
  
  if( *head == NULL ) {
    *head = newnode ;
  }else {
    lastNode = *head ;
    while( lastNode->next != NULL ) {
      lastNode = lastNode->next ;
    }
    lastNode->next = newnode ;
  }

  return newnode ;
}

void InsNode( struct studentNode *head , const char *name , int age , char sex , float gpa ) {
  struct studentNode *newnode = NULL , *lastNode = NULL ;
  newnode = (struct studentNode *) malloc(sizeof(struct studentNode)) ;
  strcpy( newnode->name , name ) ;
  newnode->age = age ;
  newnode->sex = sex ;
  newnode->gpa = gpa ;
  newnode->next = head->next ;
  head->next = newnode ;
}

void DelNode( struct studentNode *walk ) {
  struct studentNode *current , *temp ;
  current = walk ;
  while( current != NULL ) {
    temp = current->next ;
    current->next = current->next->next ;
    free( temp ) ;
    break ;
  }
}
