#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//int ** initializeTowers(& int array);
void printTowers(int** structure, int m);
void hanoi(int * A, int * B, int* C, int n, int ** s);
void hanoiForPrinting(int * A, int * B, int* C, int n, int** s);
void moveDisk(int* from, int * to);
int binConversion(int num);
void printFull(int ** s, int numDisks, char from, char to);

int count;


int main(){
   count=0;
   int m=4; //number of disks
   
   //structure representing towers
   int ** structure=malloc(sizeof(int*)*3); //allocation three towers 
   
   int i;
   for(i=0;i<3;i++){ //allocate space for max number of disks that can be on one tower
      structure[i]=calloc(m, sizeof(int));
   }
   //pointers to beginning of each tower
   int * A, * B, * C;
   A=structure[0]; 
   B=structure[1]; 
   C=structure[2];  
   
   //put m disks on first tower in order
   int j=m;
   for(i=0; i<m; i++){
      A[i]=j;
      j--;
   } 
   
   //print start stateof towers
   printTowers(structure, m);

   //call recursive function
   hanoi(A, B, C, m, structure);
   
   //print last state of towers
   printTowers(structure, m);
   
   //free allocated memory
   for(i=0;i<3;i++){
      free(structure[i]);
   }
   free(structure);

   //running hanoi for printing reasons

   structure=malloc(sizeof(int*)*3); //allocation three towers 
   for(i=0;i<3;i++){ //allocate space for max number of disks that can be on one tower
      structure[i]=calloc(m+2, sizeof(int));
   }
   //pointers to beginning of each tower
//   int * A, * B, * C;
   A=structure[0]; 
   B=structure[1]; 
   C=structure[2];  
   A[0]='A';
   B[0]='B';
   C[0]='C';
   //put m disks on first tower in order
   j=m;
   for(i=1; i<m; i++){
      A[i]=j;
      j--;
   } 
   hanoiForPrinting(A, B, C, m, structure);

   return 0;
}
//cute printing
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
void hanoiForPrinting(int * A, int * B, int* C, int n, int** s){
   if(n==1){
      //printFull(s, n, A[0], C[0]);
      moveDisk(A, C);
      printTowers(s,n);
   }
   else{
      hanoi(A, C, B, n-1, s);
      //printFull(s, n, A[0], C[0]);
      moveDisk(A, C);
      printTowers(s,n);
      hanoi(B, A, C, n-1, s);
   }
}



void moveDisk(int* from, int * to){
   int d;
   int i=0;
   int index=0;

   while(from[index]!=0){
      index++;
   }
   d=from[index-1];
   from[index-1]=0;
   while(true){
      if (to[i]==0){
         to[i]=d;
	 break;
      }
      i++;
   }
}
//printing like in class notes
void printFull(int ** s, int numDisks, char from, char to){
   int i, j;
   for(i=0; i<numDisks; i++){
      printf("%d",s[0][i]);
   }
   printf("	");
   for(i=0; i<numDisks; i++){
      printf("%d",s[1][i]);
   }
   printf("	");
   for(i=0; i<numDisks; i++){
      printf("%d",s[2][i]);
   }
   printf("	");
   int bin=binConversion(count);
   printf("%d", bin);
   int disk=0;
   for(i=1;i<3; i++){
      if(s[i][0]==from){
      for(j=1;j<numDisks; j++){
       //  if
      }
      }
   }

   printf("	%d	%c	%c\n", disk, from, to);
   count++;
}
int binConversion(int num){
   if(num==0) return 0;
   else return (num % 2)+10*binConversion(num/2);
}
