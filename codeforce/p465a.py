n = int(raw_input())
#print n
cell = raw_input()
#print cell
cnt = 0

if cell[0] == '1':
    cnt = 1
    for i in range(1,n):
        if cell[i] == '1':
            cnt +=1
        else:
            cnt +=1
            break

    print cnt
else:
    print "1"
