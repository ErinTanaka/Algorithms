#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//int ** initializeTowers(& int array);
void printTowers(int** structure, int m);
void hanoi(int * A, int * B, int* C, int n, int ** s);
void moveDisk(int* from, int * to);

int main(){
   int m=3; //number of disks
   int i;
   
   //structure representing towers
   int ** structure=malloc(sizeof(int*)*3); 
   int * A; 
   int * B;
   int * C;
   for(i=0;i<3;i++){
      structure[i]=calloc(m, sizeof(int));
   }
   A=structure[0]; 
   B=structure[1]; 
   C=structure[2];  
   //put m disks on first tower
   int j=m;
   for(i=0; i<m; i++){
      A[i]=j;
      j--;
   } 
   
   printTowers(structure, m);
   hanoi(A, B, C, m, structure);
   printTowers(structure, m);

   /*
   int T=0; //tower that holds disk 1
   int count=0; //m bits
   int p=1; //1 if m is even and 0 if m is odd

   do{

   }while(true);


*/
   return 0;
}
void printTowers(int** structure, int m){
   int i;
   int j=0;
   for (i=m; i>-1; i--){
      for(j=0; j<3; j++){
      	if(structure[j][i]!=0) printf("%d", structure[j][i]);
      	else printf(" ");
	printf(" ");
      }
      	printf("\n");
   }
   printf("\n\n");
}
void hanoi(int * A, int * B, int* C, int n, int** s){
   if(n==1){
      moveDisk(A, C);
      printTowers(s,n);
   }
   else{
      hanoi(A, C, B, n-1, s);
      moveDisk(A, C);
      printTowers(s,n);
      hanoi(B, A, C, n-1, s);
   }
}
void moveDisk(int* from, int * to){
   int d;
   int i=0;
   int index=0;

  // printf("moving disk\n");
   while(from[index]!=0){
   //   printf("%d\n", from[index]);
      index++;
   }
   d=from[index-1];
  // printf("d holds: %d\n", d);
   from[index-1]=0;
   while(true){
      if (to[i]==0){
         to[i]=d;
	 break;
      }
      i++;
   }
   /*
  // printf("contents of two towers: \n");
   int j=0;
   while(from[j]!=0){
    //  printf("%d  ", from[j]);
      j++;
   }
  // printf("\n");
   j=0;
   while(to[j]!=0){
  //    printf("%d ", to[j]);
      j++;
   }
   printf("\n");
//   printf("done moving\n");
*/
}
