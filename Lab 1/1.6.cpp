#include<stdio.h>

int Data(int data){
   data = 999 ;
}
 
int main() {
   int data = 100;
   Data( data );
   printf( "data = %d",data );

   return 0 ;
} //end function
