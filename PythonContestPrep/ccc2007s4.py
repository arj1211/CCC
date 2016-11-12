n = int(input())

ways = [-1 for i in range(n+1)]



# first index represents 'start' point,
# second index represents 'end' point to which there
# is a direct slide from the 'start' point
# Ex.   paths[4][7] : the direct slide from point 4 to point 7
#       if paths[4] == [7,3,5] , there are direct slides from point 4 to points 3, 5 and 7

paths = [[] for k in range(n+1)]

#print(paths)



#gets # of ways to go from initial point 1-1, to end point n-1 (since zero indexed)
def getWays(point):
    if point==n:
        #if we're at the end point; another path
        return 1

    if ways[point] != -1 :
        #if we already have # of paths from given point to end
        return ways[point]

    total = 0

    #for every next point that that starts at given 'point'...
    for nextPoint in paths[point]:
        # total # of slides from given point to end,
        # is sum of all paths from the subject 'nextPoint' to the end point
        total += getWays(nextPoint)

    # the total # of paths from given point to end point (stored)
    ways[point]=total

    #return # of paths from given point to end
    return ways[point]



while True:
    line = input().split()
    x,y=int(line[0]),int(line[1])
    if x==0 and y==0:
        break
    #add new slide starting at x: from x to y (they are zero indexed)
    paths[x].append(y)
    #print('paths from',x,':',paths[x])

print(getWays(1))
