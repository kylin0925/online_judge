import math
def adjust(in_float,target_int):
    ret = int(in_float)
    tmp = ret **2
    d = target_int - tmp
#    print "diff ",d

    while d > 10:
        ret+=1
        tmp = ret **2
        d = target_int - tmp
#        print "diff ",d

#    print " ",ret
    return  ret
t = 0
r = 0
n = int(raw_input())

for idx in range(n):
    tmp = raw_input().split()
    r,t = map(int,tmp)
    a = (r+1) ** 2 - r**2
#    print a,r,t
    cnt = 1

    # t * 8 - a **2 - 4*a >= b ** 2 + 4 *b
    target = t * 8 + a **2 - 4*a
#    print "t :",target
    tar_int = target -4
    adj_float = (target -4) ** 0.5
    tmp = adjust(adj_float,target) 
    max_b = int(tmp) -2
#    print "1 ",max_b 

    max_b = int(math.ceil( (max_b -a) / 4.0 ))
#    print "2 ",max_b 
    max_b = max_b*4+a
#    print "3 ",max_b 
    eq = max_b ** 2 + max_b *4
#    print "eq ",eq 
    while target< eq:
        max_b -=4
        eq = max_b ** 2 + max_b *4

    cnt=(max_b-a)/4 + 1
    ''' 
    br = r+1 
    while True:
        tt = br**2 - (br -1)**2
        t = t - tt
        if t<0:
            break
        cnt +=1
        br+=2
    '''
    print "Case #%d: %d" %(idx+1,cnt) 
