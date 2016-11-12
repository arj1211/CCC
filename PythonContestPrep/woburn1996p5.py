inLine = input().split()
M,N=int(inLine[0]),int(inLine[1])
grid,dp = [[0 for i in range(M)] for j in range(N)],[[0 for i in range(M)] for j in range(N)]

#dp[ (a,b,c,d) ]=[2,3,4]

def plenty():
    for i in range(M):
        for j in range(N):
            if i==0:
                #if on bottom row
                if j==0:
                    #if first location; starting from bottom left
                    dp[i][j]=grid[i][j]
                else:
                    #if on the bottom row but not initial location
                    '''
                     apples collected at this location is
                     the sum of current spot and previous to
                     the left (since we cannot go down or left,
                     and we are still on bottom row, the
                     previous spot must've been adjacent on left of current spot)
                    '''
                    dp[i][j] = (grid[i][j] + dp[i][j-1])
            else:
                #if not on bottom row
                if j==0:
                    #if on first column
                    '''
                     apples collected at any place in first column
                     is # of apples collected at current spot, plus
                     # of apples collected thus far at spot directly below us
                     (since we can move only right and up, and we are on
                     first column and haven't moved right yet, the previous
                     location has to be adjacent below of current spot)
                    '''
                    dp[i][j]=(grid[i][j]+dp[i-1][j])
                else:
                    #if not first row OR first column
                    '''
                     apples collected at this location is # of apples at current
                     spot, plus the MAXIMUM of the two adjacent spots on bottom and
                     left of current spot. This is because we did not come from
                     BOTH previous spots (thats not possible), and we would rather have
                     collected the MAXIMUM amount of apples we could have, up till
                     right before arriving at the current spot. So at the current
                     spot, we have collected the # of apples in current spot, plus
                     the maximum we could've collected by the previous spot, thus far.
                    '''
                    dp[i][j]= (grid[i][j] + max(dp[i-1][j],dp[i][j-1]))



while True:
    inLine=input().split()
    p,q = int(inLine[0]),int(inLine[1])

    if (p==0 and q==0):
        break
    grid[p-1][q-1]=1
    dp[p-1][q-1]=1

plenty()
print(dp[M-1][N-1])


#print('aight')
