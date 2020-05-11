#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

int main(){
   struct timeval start, stop;
   int n=4;//n is number of polynomials
   int * A=calloc(n, sizeof(int));
   int * B=calloc(n, sizeof(int));
   int * C=calloc((2*n)-1, sizeof(int));
   srand(time(NULL));
   int i,j;
   //fill polynomial arrays with random numbers
   for (i=0; i<n; i++){
      A[i]=2;//rand() %5;
      B[i]=3;//rand() %5;
   }
   //A[0]=4;
   //A[1]=4;
   //B[0]=6;
   //B[1]=6;

   
   for(i=0; i<n; i++){
      for(j=0; j<n; j++){
         C[i+j]=A[i]*B[j]+C[i+j];
      }
   }
   //print results
   printf("A: ");
   for(i=0; i<n; i++){
      printf(" %d ", A[i]);
   }
   printf("\nB: ");
   for(i=0; i<n; i++){
      printf(" %d ", B[i]);
   }
   printf("\nC: ");
   for(i=0; i<(2*n)-1; i++){
      printf(" %d ", C[i]);
   }
   printf("\n");   

   free(A);
   free(B);
   free(C);
   return 0;
}

