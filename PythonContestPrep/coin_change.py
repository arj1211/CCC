import sys

sys.setrecursionlimit(10**6)
#print(sys.getrecursionlimit())

T = int(input())
N = int(input())

coins = []

look = {}

for i in range(N):
	coins.append(int(input()))

def getMin(s, i):
	if s == T:
		return 0

	if s > T:
		return 9999999

	if i >= len(coins):
		return 9999999

	if (s,i) in look:
	 	return look[s,i]

	miniCoins=9999999

	k=0
	while 1:
		currCoins = k + getMin( s+k*coins[i] , i+1 )
		if s+k*coins[i] > T:
			break
		miniCoins = min(miniCoins, currCoins )
		k+=1

	look[s,i] = miniCoins
	# print("  "*i,s,i,coins[i],miniCoins)
	return miniCoins

print(getMin(0,0))