n = int(raw_input())
flag = [0 for i in range(n+1)]

for i in range(2):
    arr =[int(x) for x in raw_input().split()]
    p = arr[0]
    for i in range(p):
        flag[ arr[i+1] ] = 1
cnt = 0
for i in range(1,n+1):
    if flag[i] == 1 :
        cnt +=1
#print flag
#print  cnt
if cnt == n:
    print "I become the guy."
else:
    print "Oh, my keyboard!"
