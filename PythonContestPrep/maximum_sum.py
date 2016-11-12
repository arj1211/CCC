import sys
import time

#time.clock()

# reclim=10010
# sys.setrecursionlimit(reclim)


lines=sys.stdin.readlines()
N=int(lines[0])

arr = [0 for x in range (3)]
# best = [-1 for y in range(N+1)]





def getMaxSum(i):
    #gets max sum from i till end


    if i>N:
        #if we overshot
        return 0

    if best[i]!=-1:
        #if we already have the best sum from i till end
        return best[i]


    '''
    best sum from i till end is max( (arr[i], the current number
    in sequence, plus getMaxSum(i+2), the number after the next one) and (getMaxSum(i+1), the next number) )
    it is arr[i]+getMaxSum(i+2) and getMaxSum[i+1] since we cannot choose adjacent numbers in sequence.
    arr[i] is added to getMaxSum(i+2) to get the max sum if current number plus the next choosable one is chosen
    '''
    best[i] = max(arr[i]+getMaxSum(i+2),getMaxSum(i+1))

    #print(i,arr[i],best[i])
    return best[i]

best = [0,0,0]
arr[0]=int(lines[1])
best[0]=arr[0]

arr[1]=int(lines[2])
best[1]=max(arr[0],arr[1])

ans=0
for i in range(3,len(lines)):
    #Handle input
    #sys.stdout.write(output)
    val=int(lines[i])
    best[(i-1)%3]=max(val+best[i%3],best[(i-2)%3])
    ans=best[(i-1)%3]
    #print(i,val,ans)
print(ans)

# for i in range(1,N+1):
#     arr[i]=int(input())
# while 1:
#     #if 1.8<time.clock()<=1.9:
#      #   print(best[1])
#       #  break
#     try:
# if N<50000:
#     print(getMaxSum(1))
# else:
#     for i in range(N-5000,0,-10000):
#         getMaxSum(i)
#     print(getMaxSum(1))

# time.sleep(100)
#         break
#     except:
#         reclim+=5000
#         sys.setreaccursionlimit(reclim)










