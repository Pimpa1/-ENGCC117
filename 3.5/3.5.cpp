#include<stdio.h>

void swap( int * xp , int * yp ) {
   int temp = *xp ;
   *xp = *yp ;
   *yp = temp ;
} // end function swap

void bubbleS( int arr[] , int n ) {
   int i = 0 ;
   int j = 0 ;

   for( i = 0 ; i < n -1 ; i++) {
     for( j = 0 ; j < n - i ; j++ ) {
      if( arr[ j ] > arr[ j + 1 ] ) {
         swap( &arr[ j ] , &arr[ j + 1 ] ) ; // swap function
      } // end if
     } // end for
   } // end for
} // end function bubbleS

void printArray( int arr[] , int size ) {
   int prev = arr[ 0 ] ;
   int count = 1 ;
   int i = 0 ;

   for( i = 1 ; i <= size ; i++ ) {
      if( arr[ i ] == prev ) {
         count++ ;
      }else {
         printf( "%d -> %d\n" , prev , count ) ;
         prev = arr[ i ] ;   
         count = 1 ;
      } // end if else
   } // end for
}// end printArray

int main() {
   int check_arr ;
   int s[100] ;
   int sum = 0 ;
   int i = 0 ;

   printf( "Input number of element to be stroe in array : " ) ;
   scanf( "%d" , &check_arr ) ;

   printf( "----\n" ) ;
   for( i = 0 ; i < check_arr ; i++ ) {
      printf( "Element[%d] : " , i + 1 ) ;
      scanf( "%d" , &s[ i ] ) ;
   } // end for
   
   bubbleS( s , check_arr ) ; // bubbleS function
   printf( "----\n" ) ;
   printArray( s , check_arr ) ; // printArray function

   return 0 ;
} // end function
