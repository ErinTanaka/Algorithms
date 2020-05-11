#n queens problem
import numpy as np
import random


def queenIsSafe(board, row, col, n):
    if (col!=0):
        for i in range(0,col):
            if board[row][i]==1: return False
    if (row!=0 and col!=0):
        i=row-1
        j=col-1
        while True:
            if (board[i][j]==1): return False
            i=i-1
            j=j-1
            if (i<0 or j<0): break
    if (row!=n-1 and col!=0):
        i=row+1
        j=col-1
        while True:
            if (board[i][j]==1): return False
            i=i+1
            j=j-1
            if (i==n or j<0): break
    return True
def isUnique(board, solutions, numberOfSolutions):
    #for every unique solution:
        #make all rotations, mirror and mirrored rotation
        #if board is the same as any of the boards above return
        #if board if different from all of the boards as above
        cc90=np.rot90(board)
        cc180=np.rot90(cc90)
        cc270=np.rot90(cc180)
        mirror=np.fliplr(board)
        m90=np.rot90(mirror)
        m180=np.rot90(m90)
        m270=np.rot90(m180)
        for i in range(0, numberOfSolutions):
            if(np.array_equal(solutions[i],board)): return False
            if(np.array_equal(solutions[i],cc90)): return False
            if(np.array_equal(solutions[i],cc180)): return False
            if(np.array_equal(solutions[i],cc270)): return False
            if(np.array_equal(solutions[i],mirror)): return False
            if(np.array_equal(solutions[i],m90)): return False
            if(np.array_equal(solutions[i],m180)): return False
            if(np.array_equal(solutions[i],m270)): return False
        return True
def solveNQueens(board, col, n):
    #print("n queens fn")
    if(col==n):
        #print("basecase")
        if(isUnique(board, solutionList, len(solutionList))):
            global solutionList
            solutionList=np.append(solutionList, [board], axis=0)
            return True
        else:
            return False
    for i in range(0,n):
        if(queenIsSafe(board, i, col, n)):
            board[i][col]=1
            solveNQueens(board, col+1, n)
            board[i][col]=0
    return False

#main script

global totalNumberOfBoards
totalNumberOfBoards=0


for n in range(1,10):
    theBoard=np.array([[0]*n]*n)
    solutionList=np.array([theBoard])
    solveNQueens(theBoard, 0, n)
    for i in range(1, len(solutionList)):
        print(solutionList[i])
        print("")
    print("finished with "),(n)
    totalNumberOfBoards=totalNumberOfBoards+len(solutionList)-1
    print("totalNumberOfBoards: "),(totalNumberOfBoards)

print("There are "),(totalNumberOfBoards),(" chessboards in Wonderland.")
