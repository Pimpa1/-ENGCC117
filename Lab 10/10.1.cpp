#include <stdio.h>

long SumLoop( int ) ;
long SumRecur( int ) ;

int main() {
  printf( "SumLoop(n) = %d\n", SumLoop( 10 ) ) ;
  printf( "SumRecur(n) = %d\n", SumRecur( 10 ) ) ;
  return 0 ;
}//end function

long SumLoop( int num ) {
  int i, sum;
  for( i = 1 ; i <= num ; i++ )
    sum = sum + i ;
  return sum ;
}

long SumRecur( int num ) {
  if( num >= 1 )
    return num + SumRecur( num - 1 ) ;
  return 0 ;
}
