#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void hanoi(char A, char B, char C, int n);

int main(){
   int i=4;
//   for(i=14; i<25; i++){
   
   int n=i; //number of disks

   struct timeval stop,start;
   
   printf("Recursive\nNumber of Disks: %d\n",n);
   
   gettimeofday(&start, NULL);
   hanoi('A', 'B', 'C', n);
   gettimeofday(&stop, NULL);
   

   printf("time: %lu\n", stop.tv_usec - start.tv_usec);
  // }
   return 0;
}
void hanoi(char A, char B, char C, int n){
   if(n==1){
      //printf("%c to %c\n", A, C);
   }
   else{
      hanoi(A, C, B, n-1);
      //printf("%c to %c\n", A, C);
      hanoi(B, A, C, n-1);
   }
}
