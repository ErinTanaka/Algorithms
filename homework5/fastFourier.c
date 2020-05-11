#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

void divNcon(int * p, int * q, int * storage, int size);
int main(){
   struct timeval start, stop;
   int n=8;//n is number of polynomials
   srand(time(NULL));
   int i,j;
   //iterative method
   /*
   int * A=calloc(n, sizeof(int));
   int * B=calloc(n, sizeof(int));
   int * C=calloc(n*2-1, sizeof(int));
   
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
   printf("\nQ: ");
   for(i=0; i<n; i++){
      printf(" %d ", B[i]);
   }
   printf("\nC: ");
   for(i=0; i<(2*n)-1; i++){
      printf(" %d ", final[i]);
   }
   printf("\n");
   free(A);
   free(B);
   free(C)   
   */
   //divide and conquer method
   /*
   int * p=calloc(n, sizeof(int));
   int * q=calloc(n, sizeof(int));
   int * final=calloc((2*n)-1, sizeof(int));
   //fill polynomial arrays with random numbers
   for (i=0; i<n; i++){
      p[i]=2;//rand() %5;
      q[i]=3;//rand() %5;
   }
   
   //divide and conquer method
   divNcon(p, q, final, n);

   

   //print results
   printf("P: ");
   for(i=0; i<n; i++){
      printf(" %d ", p[i]);
   }
   printf("\nQ: ");
   for(i=0; i<n; i++){
      printf(" %d ", q[i]);
   }
   printf("\nC: ");
   for(i=0; i<(2*n)-1; i++){
      printf(" %d ", final[i]);
   }
   printf("\n");   

   free(p);
   free(q);
   free(final);
   */
   //Fast Fourier Transform
   int * A=calloc(n, sizeof(int));
   int * B=calloc(n, sizeof(int));
   int * F_A;
   int * F_B;
   int * F_C;   
   F_A=FFT(A, m, w); 
   F_B=FFT(B, m, w);
   for(i=1; i<m; i++){
      F_C[i]=F_A[i]*F_B[i];
   }
   C=1/m * FFT(F_C, m, w^(-1));
   return 0;
}

int * FFT(int* A, int m, int w){
   if(m==1){
      return(A);
   }
   else{
      int* A_even=calloc(m/2, sizeof(int)); 
      int* A_odd=calloc(m/2, sizeof(int));
      int i;
      A_even[0]=A[0];
      A_even[1]=A[2];

      F_even=FFT() 
   }
}
void divNcon(int * p, int * q, int * storage, int size){
   if(size==2){
      storage[0]+=p[0]*q[0];
      storage[1]+=p[0]*q[1]+p[1]*q[0];
      storage[2]+=p[1]*q[1];
   }

   else{
      int i;
      int* M1=calloc(size-1, sizeof(int));
      int* M2=calloc(size-1, sizeof(int));
      int* M3=calloc(size-1, sizeof(int));
      int* tmpP=calloc(size-1, sizeof(int));
      int* tmpQ=calloc(size-1, sizeof(int));
      for(i=0; i<size-1; i++){
         tmpP[i]=p[i]+p[i+size/2];
         tmpQ[i]=q[i]+q[i+size/2];
      }
      divNcon(tmpP, tmpQ, M1, size/2);
      divNcon(&p[0], &q[0], M2, size/2);
      divNcon(&p[size/2], &q[size/2], M3, size/2);
      for(i=0; i<size; i++){
	 storage[i]+=M2[i];
	 storage[i+size/2]+=M1[i]-M2[i]-M3[i];
	 storage[i+size]+=M3[i];
      }
      free(M1);
      free(M2);
      free(M3);
      free(tmpP);
      free(tmpQ);
   }
}
