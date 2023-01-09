#include<stdio.h>

int Data(int *ptr){
   *ptr = 999;
}
 
int main() {
   int data = 100;
   Data( &data );
   printf( "data = %d",data );

   return 0 ;
} //end function
