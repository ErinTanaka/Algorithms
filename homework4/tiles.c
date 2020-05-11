#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

//global variable
int trominoNum;
//function declarations
void print(int **, int);
void divide(int **, int);

int main(){
   struct timeval stop, start;

   int side=256;//length of one side of board *note board is 2^k x 2^k
   int ** board=calloc(side, sizeof(int*));
   int i;
   for (i=0; i<side; i++){
      board[i]=calloc(side, sizeof(int));
   }
   srand(time(NULL));
   int rm1=rand()%side;
   int rm2=rand()%side;

   //printf("removing tile at %d, %d\n",rm2, rm1);
   board[rm1][rm2]=-1;
   //print(board, side);
   
   trominoNum=1;
//start timer
   gettimeofday(&start, NULL);
   divide(board, side);
   gettimeofday(&stop, NULL);
//end timer
  // printf("finished board:\n");
  // print(board, side);
   
   printf("k=%d, time: %lu\n", side, stop.tv_usec -start.tv_usec);

   for(i=0;i<side; i++){
      free(board[i]);
   }  
   free(board);
   return 0;
}
void print(int ** board, int side){
   int i, j;
   for(i=0; i<side; i++){
      for(j=0; j<side; j++){
         if (board[i][j]==0){
	    printf("0   ");
	 }
	 else{
	    if(board[i][j]==-1){
	       printf("X   ");
	    }
	    else{
	       if(board[i][j]<10){
	          printf("%d   ", board[i][j]);
	       }
	       else if(board[i][j]<100){
	          printf("%d  ", board[i][j]);
	       }
	       else{
	          printf("%d", board[i][j]);  
	       }
	    }
	 }
      }
      printf("\n");
   }
}
void divide(int ** board, int length){
   if(length==2){
      if (board[0][0]==0){
         board[0][0]=trominoNum;
      }
      if (board[0][1]==0){
         board[0][1]=trominoNum;
      }
      if (board[1][0]==0){
         board[1][0]=trominoNum;
      }
      if (board[1][1]==0){
         board[1][1]=trominoNum;
      }
      trominoNum++;
   }
   
   else{
      int i,j;
      int qLen=length/2;
      int** qI=calloc(qLen, sizeof(int*));
      int** qII=calloc(qLen,sizeof(int*));
      int** qIII=calloc(qLen,sizeof(int*));
      int** qIV=calloc(qLen,sizeof(int*));
      for ( i=0; i<4; i++){//do each quadrant
         for(j=0; j<qLen; j++){
            if(i==0){ //qI
	       qI[j]=&board[j][0];
	    }
	    if(i==1){ //q2
	       qII[j]=&board[j][qLen];
	    }
	    if(i==2){ //q3
	       qIII[j]=&board[j+qLen][0];
	    }
	    if(i==3){ //q4
	       qIV[j]=&board[j+qLen][qLen];
	    }
         }
      }
      //print(qI, qLen);
      int m1, m2;
      //find coordinates of missing tile
      for(i=0; i<length; i++){
         for(j=0; j<length; j++){
	    //printf("j: %d\n", j);
            if(board[i][j]!=0){
	       m1=i;
	       m2=j;
	    }
         }
      }
      //based on which quadrant is 'missing' a tile
      //add a tile to the touching corners of the oher three quadrants
      if(m1<qLen){ // missing from qI or qIII
         if(m2<qLen){ //qI ->add tromino to cover II III IV
	    board[qLen-1][qLen]=trominoNum;
	    board[qLen][qLen-1]=trominoNum;
	    board[qLen][qLen]=trominoNum; 
         }
         else{ //qII ->add tromino to cover I III IV
	    board[qLen-1][qLen-1]=trominoNum;
	    board[qLen][qLen-1]=trominoNum;
	    board[qLen][qLen]=trominoNum;
         }
      }
      else{ //missing from qII or qIV
         if(m2<qLen){ //qIII ->add tromino to cover I II IV
	    board[qLen-1][qLen-1]=trominoNum;
	    board[qLen-1][qLen]=trominoNum;
	    board[qLen][qLen]=trominoNum;
         }
         else{ //qIV ->add tromino to cover I II III
	    board[qLen-1][qLen-1]=trominoNum;
	    board[qLen-1][qLen]=trominoNum;
	    board[qLen][qLen-1]=trominoNum;
         }
      }
      trominoNum++;
      //call divide on each quadrant;
      divide(qI, qLen);
     // print(qI,qLen);
     // printf("dividing qII\n");
      divide(qII, qLen);
     // print(qII, qLen);
     // printf("dividing qIII\n");
      divide(qIII, qLen);
     // print(qIII, qLen);
     // printf("dividing qIV\n");
      divide(qIV, qLen);
     // print(qIV, qLen);

     // printf("printing 'board':\n");
     // print(board, length);
     free(qI);
     free(qII);
     free(qIII);
     free(qIV);

   }
}
