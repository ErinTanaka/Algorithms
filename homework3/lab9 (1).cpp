#include <iostream>

//void make_board();
//void towers(int disks,board[][3],int 0,int 1,int 2);

using namespace std;

void make_board(int *board[]);
void dele(int *board[],int rows, int cols){
void towers(int disks,int *board[],int rows,int cols,int from,int to,int spare);
void move(int disks,int *board[],int rows,int cols,int from, int to);

int main(){
    int board[][3];
    int *rows, cols=3;
    cout<<"Enter rows: "<<endl;
    cin>>rows;
    board=new int *[rows];
    for(int i=0; i<rows; i++){
        board[i]=new int[3];
    }
    make_board(board);   
    return 0;
}

void make_board(){
    //int rows=2;
    //int cols=3;
   // int **board;
    //int rows, cols;
    //board=new int*[rows];
    //for(int i=0; i<rows; i++){
      //  board[i]=new int[3];
    //}
    //int board[rows][3];
    for(int i=0; i<rows;i++){
        for(int j=0; j<cols; j++){
            board[i][j]=0;
        }
    }
    board[0][0]=1;
    board[1][0]=2;
    int disks=3;
    towers(disks,board,rows,cols,0,1,2);
    dele(board, rows, cols);
}

void dele(int *board[],int rows, int cols){
    for(int i=0; i<rows;i++){
        delete [] board[i];
    }
    delete [] board;
}

void towers(int disks,int *board[],int rows,int cols,int from,int to,int spare){
    //int rows = 2, 
    //int cols=3;
    if(disks>1){
        towers(disks-1,board,rows,cols,from,spare,to);
        move(disks,board,rows,cols,from,to);
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
        towers(disks-1,board,rows,cols,spare,to,from);
    }
}

void move(int disks,int *board[],int rows,int cols,int from, int to){
    int temp;
    for(int i=0; i<rows;i++){
        if(board[i][from]!=0){
            temp=board[i][from];
            cout<<"temp is "<<board[i][from]<<endl;
            board[i][from]=0;
            cout<<"reset "<<board[i][from]<<endl;
            break;
           }
    }
    for(int i=0;i<2;i++){
        //if(/*board[i][to]*/temp==disks){
            if(board[i+1][to]==0){
                cout<<"A"<<endl;
                board[i+1][to]=temp;
                break;
            }
            else if(board[i+1][to]!=0){
                cout<<"b"<<endl;
                board[i][j+1]=temp;
                break;
            }
            //else if(board[i+1][to]==0){
              //  board[i+1][to]=temp;
           // }
            //else{
              //  board[i][to]=temp;
           // }
       // }
    }
}


