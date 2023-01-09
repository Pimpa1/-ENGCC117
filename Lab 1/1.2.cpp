#include<stdio.h>
int main() {
   int n = 5 ;
   int g [ 4 ][ 3 ] = {
      { 10 , 20 , 30 } ,
      { 11 , 21 , 31 } , 
      { 12 , 22 , 32 } ,
      { 13 , 23 , 33 }
      } ;

   for(int a = 0 ; a < 3 ; a++ ) {
      for(int b = 0 ; b < 3 ; b++) {
         printf( "%d " , g[ a ][ b ] ) ;
      } //end for
      printf( "\n" ) ;
   }  //end for
   printf( "\n--------\n" ) ;

   int ( *j )[ 3 ] = g ;
   j [ 1 ][ 4 ] = 99 ;

   for(int a = 0 ; a < 3 ; a++ ) {
      for(int b = 0 ; b < 3 ; b++) {
         printf( "%d " , g[ a ][ b ] ) ;
      } //end for
      printf( "\n" ) ;
   }  //end for

   return 0 ;
} // end function
