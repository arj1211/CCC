'''
Some helpful template code
'''

#multiple numbers on same line input, separated by spaces
inLine = input().split()
M,N=int(inLine[0]),int(inLine[1])

#making 2d 'array' and filling in using list comprehension
grid = [[0 for i in range(M)] for j in range(N)]


