# 1,1,2,3,5,8,13,21,...
#     a,b,c,(b+c)
#       a,b,c
a,b,c=1,1,2
n=10

for i in range(n):
	a,b,c = b,c,b+c
	print (a,b,c)
