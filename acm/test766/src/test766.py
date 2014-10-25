import copy
class num:
    den = 0  #
    mol = 0 #
def initTbl(n):
    emp = list([])
    for i in range(n):
        emp.append( list([]) )
    for i in range(n):
        for j in range(n):
            cn = num()
            cn.real =0
            cn.mol = 0
            cn.den = 0
            emp[i].append(cn) 
    return emp    
def dumptbl(x):
    for i in range(21):
        print tbl[x][i].real,' ',tbl[x][i].den,' ', tbl[x][i].mol
        
def gcd(n,m):
    if m == 0:
        return n
    else:
        return gcd(m,n%m)
    
def longMul(l,mul):
    lenl = len(l)+len(mul) + 1
    res = []
    for i in range(lenl):
        n = num()
        res.append(n)
    for i in range(len(l)):
        for j in range(len(mul)):
            tmpmol = l[i].mol*mul[j].mol
            tmpden = l[i].den*mul[j].den
            if tmpmol ==0:
                continue
            if res[i+j].den == 0 and res[i+j].mol==0:
                res[i+j].den = tmpden
                res[i+j].mol = tmpmol
            elif res[i+j].den <> tmpden:
                minMul = tmpden* res[i+j].den / gcd(res[i+j].den ,tmpden)
                
                tmpmol = minMul/tmpden * tmpmol
                tmpden = minMul
                
                res[i+j].mol = copy.copy(minMul/res[i+j].den * res[i+j].mol)
                res[i+j].den = copy.copy(minMul)
                res[i+j].mol += tmpmol   
            else:
                res[i+j].mol += tmpmol
    return res


    
    
maxp = 22
tbl = copy.deepcopy(initTbl(maxp))

c = [num(),num()]

tbl[1][0].mol = 0
tbl[1][0].den = 0
tbl[1][1].mol = 1
tbl[1][1].den = 1
'''
c[0].mol=-2
c[0].den=3
c[1].mol=1
c[1].den=3

tbl[2][0].mol = 0
tbl[2][0].den = 0
tbl[2][1].mol = -1
tbl[2][1].den = 2
tbl[2][2].mol = 1
tbl[2][2].den = 2
'''
for i in range(2,21):
    c[0].mol=-(i-1)
    c[0].den=i
    c[1].mol=1
    c[1].den=i
    testlst = copy.copy( longMul(tbl[i-1],c))
    tbl[i] = copy.copy(testlst)
    strR = ''
    
    for r in testlst:
        strR += str(r.mol)+"/"+str(r.den)+" "
    print i,' ',strR
    
#---------------------------------------------------------

tblC = [[]]
for i in range(1,21):
    powerlist = [j**i for j in range(1,i+1+1)]
    res = copy.copy([powerlist[0]])
    for j in range(i):
        for k in range(1,i+1):
            powerlist[k-1] = copy.copy(powerlist[k]-powerlist[k-1])
        res.append(powerlist[0])
    tblC.append(res)
    s = ''


for r in tblC:
    s = ''
    for p in r:
        s += str(p)+' '
    print s


#-----------------------------------------------------------
def addDiv(a,b):
    if a.den == 0:
        return b
    if b.den == 0:
        return a
    
    minM = a.den*b.den/gcd(a.den,b.den)
    
    a.mol = copy.copy(minM/a.den *a.mol)
    b.mol = copy.copy(minM/b.den *b.mol)
    a.den = copy.copy(minM)
    b.den = copy.copy(minM)
    
    n = num()
    n.mol = a.mol + b.mol
    n.den = minM
    return n
def print2DLst(l):
    s = ''
    print "== print2DLst =="
    for r in l:
        s = ''
        for n in r:
            s += str(n.mol) + '/' + str(n.den) + ' '
        print s
    print "================"
def printList(l):
    s = ''
    print "==  printLst  =="
    for n in l:
        s += str(n) +' '
    print s
    print "================"
resTbl = list([])
clist = list([])
el = list([])
r = list([])
emp22 = list([])
cnt = 0
for i in range(21):
    resTbl.append([])
    clist.append([])
    emp22.append([])
for i in range(21):
    for j in range(21):
        clist[i].append([])
for i in range(1,21):
    #print "0",tbl[1][1].mol ," ", tbl[1][1].den 
    #print "0",tbl[2][1].mol ," ", tbl[2][1].den 
    
    #for j in range(i+1):
        #print "1",tbl[1][1].mol ," ", tbl[1][1].den 
        #print "1",tbl[2][1].mol ," ", tbl[2][1].den 
        #clist.append([])
        #clist[j]=copy.copy(emp22)
    
    for j in range(1,i+1+1):   
        #print "2",tbl[1][1].mol ," ", tbl[1][1].den 
        #print "2",tbl[2][1].mol ," ", tbl[2][1].den    
        clist[j-1]=copy.copy(tbl[j])
  
    for k in range(i+1):
        #print "3",tbl[1][1].mol ," ", tbl[1][1].den 
        #print "3",tbl[2][1].mol ," ", tbl[2][1].den 
        s = ''
        el = list([])
        for e in clist[k]:
            el.append( copy.copy(e))
        #print "err....",el," ",tbl[2][1]," ",clist[k]
        for l in range(len(el)):
            #print "4",tbl[1][1].mol ," ", tbl[1][1].den 
            print "4 ",k," ",l," ",tbl[2][1].mol ," ", tbl[2][1].den 
            el[l].mol = copy.copy(tblC[i][k]* el[l].mol)
        clist[k] = copy.copy(el)
        
    #print2DLst(clist)
    #r = []
    
    r =copy.copy(clist[0])
    for j in range(1,i+1):
        for k in range(len(r)):
            r[k] = copy.copy(addDiv(r[k],clist[j][k]))
    
    resTbl[cnt] = copy.copy(r)
    cnt +=1
    s = ''
    for n in r:
        s += str(n.mol) + '/' + str(n.den) + ' '
    print "- >", s
  
    #print2DLst(resTbl)
#-------------------------------------------------------------
print "...........resTbl...................."
print2DLst(resTbl)


cnt = 0
for c in resTbl:
    if(len(c)<2):
        continue
    g = c[1].mol
    for i in range(len(c)):
        g = gcd(g,c[i].mol)
        #print g,'  ',n.mol,'  ',n.den
        
    print g
    for i in range(len(c)):
        resTbl[cnt][i].mol = copy.copy(resTbl[cnt][i].mol/g)
        resTbl[cnt][i].den = copy.copy(resTbl[cnt][i].den/g)
    cnt +=1
    
print2DLst(resTbl)
