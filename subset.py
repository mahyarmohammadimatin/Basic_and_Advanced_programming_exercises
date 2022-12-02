n=int(input())
l=[i for i in range(1,n+1)]
sub=[]
i=0
while i!=2**n - 1:
    for j in l[::-1]:
        if j in sub:
            sub.remove(j)
        else:
            sub.append(j)
            print(sub)
            i+=1
            break