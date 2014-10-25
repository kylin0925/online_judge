p=0
q=0
r=0
l=0
X = []
Z = []

p,q,l,r = [int(i) for i in raw_input().split()]
#print p,q,l,r

for i in range(p):
    tmp = [int(i) for i in raw_input().split()]
    Z.append(tmp)

for i in range(q):
    tmp = [int(i) for i in raw_input().split()]
    X.append(tmp)
flag = [ 0 for i in range(0,r+1)]

#print flag
'''
for i in range(l,r+1):
    #print i
    for dx in X:
        #print dx[0]+i,dx[1]+i
        for dz in Z:
            if (dx[0] + i >= dz[0] and dx[0] + i <= dz[1]) \
                or (dx[1] + i>= dz[0] and dx[1] + i <= dz[1]):
                #print "set i ",i
                flag[i] = 1 
            elif (dz[0]>=dx[0]+i and dz[0] <=dx[1]+i) \
                or (dz[1] >= dx[0] + i and dz[1] <= dx[1] + i):
                #print "sec i ",i
                flag[i] = 1
'''
res = []
#print "l r",l,r
for dx in X:
    #print dx[0]+i,dx[1]+i
    for dz in Z:
        d1 = dz[0] - dx[1]
        if d1 < l:
            d1 = l 

        d2 = dz[1] - dx [0]
        if d2 > r:
            d2 = r
        print dx[0],dx[1],d1,d2
        if d1 >=l and d1<= r and d2 >=l and d2<=r:
            print "ok ",dx[0],dx[1],d1,d2
            res.append([d1,d2])
#print res
for d in res:
    for i in range(d[0],d[1]+1):
        flag[i]=1
print flag.count(1)
