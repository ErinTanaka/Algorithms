#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>

int main(){
   int y=15;
   //for(y=1; y<11; y++){
   printf("Iterative\nNumber of Disks: %d\n", y);
   int n=y; //number of disks
     

   char ** move;
   double numMoves=pow(2,n)+1;
   move=malloc(sizeof(char *)*numMoves);
   int i;
   char L1, L2, L3;   
   
   for(i=0; i<numMoves; i++){
      move[i]=calloc(6, sizeof(char));
   }

   //timerstuff
   struct timeval stop,start;

   gettimeofday(&start, NULL);
   if (n%2==0)strcpy(move[1], "A to B");
   else strcpy(move[1], "A to C");
   int k=1;
   do{
      n=n-1;
      k=2*k;
      if (n%2==0){
	 strcpy(move[k],"A to B");
	 L1='C';
	 L2='A';
	 L3='B';
      }
      else{
	 strcpy(move[k], "A to C");
	 L1='B';
	 L2='C';
	 L3='A';
      }
      for(i=1; i<k; i++){
         if(strcmp(move[i], "A to B")==0){   
	    sprintf(move[k+i], "%c to %c", L1, L2);
	 }
	 else if (strcmp(move[i], "A to C")==0){   
	    sprintf(move[k+i], "%c to %c", L1, L3);
	 }
	 else if(strcmp(move[i], "B to A")==0){   
	    sprintf(move[k+i], "%c to %c", L2, L1);
	 }
	 else if(strcmp(move[i], "B to C")==0){   
	    sprintf(move[k+i], "%c to %c", L2, L3);
	 }
	 else if(strcmp(move[i], "C to A")==0){   
	    sprintf(move[k+i], "%c to %c", L3, L1);
	 }
	 else if(strcmp(move[i], "C to B")==0){   
	    sprintf(move[k+i], "%c to %c", L3, L2);
	 }
	 else{
	    printf("this fucked up man\n");
	 }
      }
   
   }while (n>1);
   
   gettimeofday(&stop, NULL);
   printf("%d disks took %lu\n", y, stop.tv_usec - start.tv_usec);
   

   //for(i=1; i<numMoves; i++){
     // printf("%s\n", move[i]);
  // }

   return 0;
}

