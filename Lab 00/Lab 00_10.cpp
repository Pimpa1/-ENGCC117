#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{   
   int n = 100 ;
   int input ;
   int i ;
   int max ;

   srand( time(NULL) ) ;

   for( i = 1 ; i <= n ; i++ )
   {
      input = rand() ;
      printf( "Number #%d = %d\n" , i , input ) ;

      if( i == 0 || input > max ) {
         max = input ;
      }
   }
    
   printf( "\nMaximum is %d\n\n" , max ) ;
    
   return 0 ;
}
