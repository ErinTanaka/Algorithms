
global vertexBoard
global tourBoardboard
global LocationArray
global tourCounter

def makeVertexBoard (n):
    board=[0]*n
    for i in range(0,n):
        board[i]=[0]*n
    for i in range(0,n): #rows
        for j in range(0,n): #cols
            if (i-2>=0):
                if(j-1>=0):
                    board[i-2][j-1]=board[i-2][j-1]+1
                if(j+1<n):
                    board[i-2][j+1]=board[i-2][j+1]+1
            if (i-1>=0):
                if(j-2>=0):
                    board[i-1][j-2]=board[i-1][j-2]+1
                if(j+2<n):
                    board[i-1][j+2]=board[i-1][j+2]+1
            if (i+1<n):
                if(j-2>=0):
                    board[i+1][j-2]=board[i+1][j-2]+1
                if(j+2<n):
                    board[i+1][j+2]=board[i+1][j+2]+1
            if (i+2<n):
                if(j-1>=0):
                    board[i+2][j-1]=board[i+2][j-1]+1
                if(j+1<n):
                    board[i+2][j+1]=board[i+2][j+1]+1

    return board
def getPossibleLocations(x, y, board, n):
    possibleLocations=[None] * 8
    if (x-2>=0):
        if(y-1>=0):
            possibleLocations[0]=board[x-2][y-1]
        if(y+1<n):
            possibleLocations[1]=board[x-2][y+1]
    if (x-1>=0):
        if(y-2>=0):
            possibleLocations[2]=board[x-1][y-2]
        if(y+2<n):
            possibleLocations[3]=board[x-1][y+2]
    if (x+1<n):
        if(y-2>=0):
            possibleLocations[4]=board[x+1][y-2]
        if(y+2<n):
            possibleLocations[5]=board[x+1][y+2]
    if (x+2<n):
        if(y-1>=0):
            possibleLocations[6]=board[x+2][y-1]
        if(y+1<n):
            possibleLocations[7]=board[x+2][y+1]
    return possibleLocations

def findNextMove(array):
    index=-7
    value=20
    for i in range(0,8):
        if array[i]!=None:
            if (array[i]<value and array[i]!= 0):
                # print("valid location found?")
                # print(array[i])
                index=i
                value=array[i]
    return index

def updateVertexBoard(row, col, n):
    global vertexBoard
    vertexBoard[row][col]=0
    # print("setting vertex board 00 to 0???")
    # for j in range (0,4):
    #     print(vertexBoard[j])
    if (row-2>=0):
        if(col-1>=0):
            if vertexBoard[row-2][col-1]!=0:
                vertexBoard[row-2][col-1]=vertexBoard[row-2][col-1]-1
        if(col+1<n):
            if vertexBoard[row-2][col+1]!=0:
                vertexBoard[row-2][col+1]=vertexBoard[row-2][col+1]-1
    if (row-1>=0):
        if(col-2>=0):
            if vertexBoard[row-1][col-2]!=0:
                vertexBoard[row-1][col-2]=vertexBoard[row-1][col-2]-1
        if(col+2<n):
            if vertexBoard[row-1][col+2]!=0:
                vertexBoard[row-1][col+2]=vertexBoard[row-1][col+2]-1
    if (row+1<n):
        if(col-2>=0):
            if vertexBoard[row+1][col-2]!=0:
                vertexBoard[row+1][col-2]=vertexBoard[row+1][col-2]-1
        if(col+2<n):
            if vertexBoard[row+1][col+2]!=0:
                vertexBoard[row+1][col+2]=vertexBoard[row+1][col+2]-1
    if (row+2<n):
        if(col-1>=0):
            if vertexBoard[row+2][col-1]!=0:
                vertexBoard[row+2][col-1]=vertexBoard[row+2][col-1]-1
        if(col+1<n):
            if vertexBoard[row+2][col+1]!=0:
                vertexBoard[row+2][col+1]=vertexBoard[row+2][col+1]-1

def updateBoards(nxtMvIndex, row, col, n):
    global tourCounter
    global vertexBoard
    global tourBoard
    tourBoard[row][col]=tourCounter
    tourCounter=tourCounter+1
    nextCoor=[0,0]
    if nxtMvIndex==0:
        nextCoor[0]=row-2
        nextCoor[1]=col-1
    if nxtMvIndex==1:
        nextCoor[0]=row-2
        nextCoor[1]=col+1
    if nxtMvIndex==2:
        nextCoor[0]=row-1
        nextCoor[1]=col-2
    if nxtMvIndex==3:
        nextCoor[0]=row-1
        nextCoor[1]=col+2
    if nxtMvIndex==4:
        nextCoor[0]=row+1
        nextCoor[1]=col-2
    if nxtMvIndex==5:
        nextCoor[0]=row+1
        nextCoor[1]=col+2
    if nxtMvIndex==6:
        nextCoor[0]=row+2
        nextCoor[1]=col-1
    if nxtMvIndex==7:
        nextCoor[0]=row+2
        nextCoor[1]=col+1
    updateVertexBoard(row, col, n)
    return nextCoor

def isCompleteTour(tourBoard, vertexBoard, n):
    for i in range(0,n):
        for j in range(0,n):
            if (vertexBoard[i][j]!=0):
                return False
            if (tourBoard[i][j]==0):
                return False
    return True


#5x5 starting from each of the 25 possible squares
n=5
for i in range(0, n):
    for j in range(0,n):
        vertexBoard=makeVertexBoard(n)
        tourBoard=[0]*n
        for k in range(0,n):
            tourBoard[k]=[0]*n
        tourCounter=1
        tourBoard[i][j]=tourCounter
        nextCoor=[i,j]
        print "starting point:",nextCoor
        while(True):
            myarray=getPossibleLocations(nextCoor[0], nextCoor[1], vertexBoard, n)
            nextmove=findNextMove(myarray)
            nextCoor=updateBoards(nextmove, nextCoor[0], nextCoor[1], n)
            if nextmove<0:
                break
        if(isCompleteTour(tourBoard, vertexBoard, n)==False):
            print("Failed to find complete tour, partial tour:")
        else:
            print("Tour found:")
        for j in range (0,n):
            print(tourBoard[j])
        print
print ("done with 25 starting spots")


print
print


print("starting 6x6 tours")

n=6
#rows and cols arrays are used to choose four starting points
rows=[0,0,1,2]
cols=[0,1,1,2]
for i in range (0,4):
    vertexBoard=makeVertexBoard(n)
    tourBoard=[0]*n
    for k in range(0,n):
        tourBoard[k]=[0]*n
    tourCounter=1
    tourBoard[rows[i]][cols[i]]=tourCounter
    nextCoor=[rows[i],cols[i]]
    print "starting point:",nextCoor
    while(True):
        myarray=getPossibleLocations(nextCoor[0], nextCoor[1], vertexBoard, n)
        nextmove=findNextMove(myarray)
        nextCoor=updateBoards(nextmove, nextCoor[0], nextCoor[1], n)
        if nextmove<0:
            break
    if(isCompleteTour(tourBoard, vertexBoard, n)==False):
        print("Failed to find complete tour, partial tour:")
    else:
        print("Tour found:")
    for j in range (0,n):
        print(tourBoard[j])
    print
print ("done with 6x6 tours")


print
print


print("starting 8x8 tours")

n=8
rows=[0,0,1,2]
cols=[0,1,1,2]
for i in range (0,4):
    vertexBoard=makeVertexBoard(n)
    tourBoard=[0]*n
    for k in range(0,n):
        tourBoard[k]=[0]*n
    tourCounter=1
    tourBoard[rows[i]][cols[i]]=tourCounter
    nextCoor=[rows[i],cols[i]]
    print "starting point:",nextCoor
    while(True):
        myarray=getPossibleLocations(nextCoor[0], nextCoor[1], vertexBoard, n)
        nextmove=findNextMove(myarray)
        nextCoor=updateBoards(nextmove, nextCoor[0], nextCoor[1], n)
        if nextmove<0:
            break
    if(isCompleteTour(tourBoard, vertexBoard, n)==False):
        print("Failed to find complete tour, partial tour:")
    else:
        print("Tour found:")
    for j in range (0,n):
        print(tourBoard[j])
    print

print ("done with 8x8 tours")

n=9
rows=[0,0,1,2]
cols=[0,1,1,2]
for i in range (0,4):
    vertexBoard=makeVertexBoard(n)
    tourBoard=[0]*n
    for k in range(0,n):
        tourBoard[k]=[0]*n
    tourCounter=1
    tourBoard[rows[i]][cols[i]]=tourCounter
    nextCoor=[rows[i],cols[i]]
    print "starting point:",nextCoor
    while(True):
        myarray=getPossibleLocations(nextCoor[0], nextCoor[1], vertexBoard, n)
        nextmove=findNextMove(myarray)
        nextCoor=updateBoards(nextmove, nextCoor[0], nextCoor[1], n)
        if nextmove<0:
            break
    if(isCompleteTour(tourBoard, vertexBoard, n)==False):
        print("Failed to find complete tour, partial tour:")
    else:
        print("Tour found:")
    for j in range (0,n):
        print(tourBoard[j])
    print
