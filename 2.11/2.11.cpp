#include<stdio.h>
#include<locale.h>

int main() {
   int Input =  0 ;
   int sum = 0 ;
   int j = 9 ;
   int i = 0 ;
   setlocale(LC_ALL,"") ;

   printf( "User Input : " ) ;
   scanf( "%d" , &Input ) ;

   printf( "----\n" ) ;

   printf( "Series = " ) ;
   for( i = 0  ; i < Input ; i++ ) {
      sum = sum + j ;
      if( i != 0 ) {
         printf( " + " ) ;
      } // end if
      printf( "%d" , j  ) ;
      j = ( j * 10 ) + 9 ;
   } // end for
   printf( "\nSum = %'d" , sum ) ;
   return 0 ;
} // end function
