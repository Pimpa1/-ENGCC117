#include<stdio.h>

int add( int x , int y ) {
   return x + y ;
} //end function

int operation( int x , int y , int(*function) (int,int)) {
   return (*function)(x , y) ;
} //end function

int main() {
   printf( "=> %d\n" , operation(5,5,add) ) ;
   return 0 ;
} //end function
