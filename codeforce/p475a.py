bus =[ '+------------------------+',
    '|#.#.#.#.#.#.#.#.#.#.#.|D|)',
    '|#.#.#.#.#.#.#.#.#.#.#.|.|',
    '|#.......................|',
    '|#.#.#.#.#.#.#.#.#.#.#.|.|)',
    '+------------------------+']
k = int(raw_input())
#print k

arr = [ list(s) for s in bus]
#print arr
if k !=0:
    for j in range(1,22,2):
        if k == 0:
            break
        for i in range(1,5):
            if arr[i][j] == '#' and k > 0 :
                arr[i][j] = 'O'             
                #print 'set',i,j,arr[i][j]
                k-=1
for s in arr:
    print "".join(s)
