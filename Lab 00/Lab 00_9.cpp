#include<stdio.h>

int main() {   
   int i = 0 ;
   int n = 0 ;
   int sum = 0 ;

   printf( "Please input n number = " ) ;
   scanf( "%d" , &n ) ;

   for( i = 1 ; i <= n ; i++ ) {
      if((i == 1 || i%2 == 0 || i%3 == 0 || i%5==0 || i%7==0) 
        && (i!=2 && i!=3 && i!=5 && i!=7)) {
        continue ;
      }
      sum++ ;
   }
   printf( "All prime numbers %d from %d" , sum , n ) ;
   return 0;
}
