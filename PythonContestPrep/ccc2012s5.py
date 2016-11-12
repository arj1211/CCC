import sys

lines=sys.stdin.readlines()


rc = lines[0].split()
R,C = int(rc[0]),int(rc[1])

K = int(lines[1])


# false: no cat. true: cat
grid = [[False for i in range(C+1)] for j in range(R+1)]

paths = [[-1 for k in range(C+1)] for l in range(R+1)]


def getWays(row,col):
	#if been here..
	if paths[row][col]>-1:
		return paths[row][col]

	#if first col and row
	if row == 1 and col == 1:
		paths[row][col]=1 #only 1 way to get there
		return paths[row][col]

	#if too far past
	if row<1 or col<1:
		return 0

	#if cat
	if grid[row][col]:
		return 0

	# # if on first row but not first col
	# if row == 1 and col<=C:
	# 	paths[row][col] = getWays(row,col-1)
	# 	return paths[row][col]
	# # if on first col but not first row
	# if col==1 and row<=R:
	# 	paths[row][col] = getWays(row-1,col)
	# 	return paths[row][col]

	'''
	the # of ways to get to a cell [r][c]
	is the sum of the ways to get to cells
	[r][c-1] and [r-1][c]
	'''

	paths[row][col] = getWays(row,col-1) + getWays(row-1,col)

	return paths[row][col]


for l in range(2,K+2):
	curr_line = lines[l].split()
	rw, cl= int(curr_line[0]), int(curr_line[1])
	grid[rw][cl]=True


print(getWays(R,C))





