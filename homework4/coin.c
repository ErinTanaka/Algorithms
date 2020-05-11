#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
int weighs;
int oddVal;
void divide(char*, char*, char*, int);
int weigh(char*, char*, int);
int main(){
   srand(time(NULL));
   //int k=3;
   int coins=3*3*3*3*3*3*3*3*3*3*3*3*3*3*3*3*3*3*3;
   int placement=(rand()%coins);
   int weight=(rand()%2);
   
   char* bag=calloc(coins, sizeof(char));
   if (weight==0){
      bag[placement]='1';
   }
   else{
      bag[placement]='2';
   }
   printf("placement: %d\nweight: %d\n", placement, bag[placement]);
   //printf("coins decimal values: %d, %d, %d\n",bag[0], bag[1], bag[2]);
   //printf("coins character values: %c, %c, %c\n",bag[0], bag[1], bag[2]);
   
   char* ptrA=&bag[0];
   char* ptrB=&bag[coins-1];
   //printf("ptrA: %d, %c and ptrb: %d, %c\n", bag[0], bag[0], bag[2], bag[2]);
   //int* ptrC=bag[coins/3*2]
   weighs=0;
   oddVal=1;
   struct timeval start,stop;
   gettimeofday(&start, NULL);

   divide(bag, ptrA, ptrB, coins);
   gettimeofday(&stop, NULL);
   //printf("k=%d\n",k);
   printf("number of weighs: %d\n", weighs);
   printf("time in milliseconds: %lu\n", stop.tv_usec - start.tv_usec);
      
   return 0;
 
}
void divide(char* beg, char* a, char* b, int coins){
   int result, weight;
   //printf("in divide function\n");
   //printf("a and b %d, %d\n",a[0], b[0]);
   //printf("checking addres arithmetic: %d ?= %d\n", a+sizeof(char[0]), a[1]);
   if(coins==3){
      result=weigh(a, &a[1], 1);
      weighs++;
      //weight of odd coin is known
      if(result==1 && oddVal!=1){//c was odd fake known
         printf("odd coin at index: %d\n", b-beg-1);
	 if(oddVal==2){//odd is light
	    printf("coin was lighter\n");
	 }
	 else{ //odd is heavy
	    printf("coin was heavier\n");
	 }
      }
      else if(result==2 && oddVal!=1){ //a is light
         if(oddVal==2){ //a is odd and light
	    printf("odd coin at index: %d\n",a-beg);
	    printf("coin was lighter\n");
	 }
	 else{//oddval==3 //b is light
	    printf("odd coin at index: %d\n", b-beg-2);
	    printf("coin was heavier\n");
	 } 
      }
      else if (result==3 && oddVal!=1){ //a is heavy odd
         if(oddVal==2){ //b is odd and light
	    printf("odd coin at index: %d\n",b-beg-2);
	    printf("coin was lighter\n");
	 }
	 else{//oddval==3 a is odd and heavy
	    printf("odd coin at index: %d\n", a-beg);
	    printf("coin was heavier\n");
	 }
      }
      //weight of odd coin is NOT known
      else if (result!=1 && oddVal==1){//a and b not equal
         weight=weigh(a, b, 1);
	 weighs++;
	 if(weight==1){// a and c are equal so, b is odd coin
	    printf("odd coin at index: %d\n", b-beg-2);
	    if(result==2) printf("odd coin was heavy\n");
	    else printf("odd coin was light\n");
	 }
	 else{ // a!=c -> a is odd 
	    printf("odd coin at index: %d\n", a-beg);
	    if (result==2)printf("odd coin was light\n");
	    else printf("odd coin was heavy\n");
	 }
      }
      else if (result==1 && oddVal==1){//a==b -> c is odd coin
	 weight=weigh(a,b, 1);
	 if(weight==2){//a hevier than c-> c is odd and light
	    printf("odd coin at index: %d\n", b-beg-1);
	    printf("odd coin was lighter\n");
         }
	 else{ //c is odd and heavy
	    printf("odd coin at index: %d\n", b-beg-1);
	    printf("odd coin was heavier\n");
	 }
      }
      
   }

      
   //more than 3 coins in bag
   //weigh sub sections a and b
   //if equal divide up section c
   else{
   char * sectionA=a;
   char * sectionB=&a[coins/3];
   char * sectionC=&a[coins/3*2];
   result=weigh(sectionA, sectionB, coins/3);
   weighs++;
   //printf("section a and b : %d\n", result);
   if (result==1&&oddVal==1){ //sectionA and sectionB were equal weight unknown
      //printf("divide section c\n");
      result=weigh(sectionA, sectionC, coins/3);
      weighs++;
      if(result==2)oddVal=3;
      else oddVal=2;
      divide(beg, sectionC, &sectionC[coins/3], coins/3);
   }
   else if(result==1&&oddVal!=1){// A=B and know fake weight
      divide(beg, sectionC, &sectionC[coins/3], coins/3);
   }
   else if(result==2 && oddVal==1){//section A was lighter and fake weight unknown
      result=weigh(sectionA, sectionC, coins/3);
      weighs++;
      //printf("weighed section a and c: %d\n", result);
      if (result==1){ //b was odd fakeweight= heavy
	 oddVal=3;
	 //printf("divide section b\n");
         divide(beg, sectionB, &sectionB[coins/3], coins/3);
      }
      else{ //a was odd and fake weight light
	 //printf("divide section a\n");
	 oddVal=2;
         divide(beg, sectionA, &sectionA[coins/3], coins/3);
      } 
   }
   else if (result==3 && oddVal==1){ //A  was heavy fake weight unknown 
      result=weigh(sectionA, sectionC, coins/3);
      weighs++;
      if(result==1){ //b is odd and fake=light
         oddVal=2;
	 divide(beg, sectionB, &sectionB[coins/3], coins/3);
      }
      else{ //a is odd and fake==light
         oddVal=3;
	 divide(beg, sectionA, &sectionA[coins/3], coins/3);
      }
   }
   else{ //a!=b and fake known
      if(result==oddVal){ //a was light and fake is light || a is havy and fake is heavy
	 divide(beg, sectionA, &sectionA[coins/3], coins/3);
      }
      else{//a was light and fake is heavy || a is heavy and fake is light
	 divide(beg, sectionB, &sectionB[coins/3], coins/3);
      }
   }
   }
}
/*
 * parameters: 
 * 	a: pointer to beginning of first section to weigh
 * 	b: pointer to beginning of second section to weigh
 * 	length: length of the sections (ie. number of coins 
 * 	to go on one side of the scale)
 * return value:
 * 	1: equal
 * 	2: a is lighter
 * 	3: a is heavier
 * */
int weigh(char* a, char* b, int length){
   //printf("weighing %d, %d\n",a[0], b[0]);
   char* tmp=memchr(a,'1', length); //look for lighter coin in a
   if(tmp==NULL){
      tmp=memchr(a, '2', length); //look for heavier coin in a
      if (tmp==NULL){
	 tmp=memchr(b,'1', length); //look for lighter coin in b
	 if(tmp==NULL){
	    tmp=memchr(b, '2', length); //look for heavier coin in b
	    if(tmp==NULL){
	       return 1;
	    }
	    else{
	       return 2;
	    }
	 }
	 else{
	    return 3;
	 }
      }
      else{
	 return 3;
      }
   }
   else{
      return 2;
   }
}
