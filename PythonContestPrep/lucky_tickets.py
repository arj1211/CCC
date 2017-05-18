line = raw_input().split()

# print(repr(line))

N,S = int(line[0]),int(line[1])

targ = S/2
tickets=0

def solve():
	if S%2!=0:
		return 0
	# rec(1,0)
	print(getWays(1,0)**2)


def rec( i , s):
	global tickets
	
	if s > targ:
		return

	print 's:',s,'i:',i

	if s == targ: 
		tickets+=1
		print 'ticket found'
		return

	if i > N:
		return

	for digit in range(10):
		rec(i+1, s+digit)

ways = {}

def getWays( i , s):
	global ways

	if s > targ:
		return 0

	# print 's:',s,'i:',i

	if s == targ: 
		# print 'ticket found'
		return 1
		
	if i > N:
		return 0

	if (s,i) in ways:
		return ways[s,i]

	ans=0
	for digit in range(10):
		ans+=getWays(i+1, s+digit)

	ways[s,i] = ans
	return ans



solve()
# print(tickets**2)



