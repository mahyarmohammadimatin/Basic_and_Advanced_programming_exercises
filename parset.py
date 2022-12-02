def generate(mylist,k):
    a = [i + 1 for i in range(k)]
    i=k-1
    while(i>=0):
        re=[]
        for r in a:
            re.append(mylist[r-1])
        yield re
        while ( (i>=0) and (a[i]==len(mylist)-k+i+1)):
            i=i-1
        if (i>=0):
            a[i]=a[i]+1
            for j in range(i+1, k):
                a[j]=a[j-1]+1
            i=k-1
mylist=list(map(int,input().split()))   #baraye adade tekrari dar list momken ast tekrari javab dahad(list vorodi bayad set bashad va tekrari nadashte bashad)
for i in range(len(mylist)//2):
    for kset in generate(mylist,i+1):
        reversekset=mylist.copy()
        for item in kset:
            reversekset.remove(item)
        if sum(reversekset)==sum(kset):
            print(reversekset,"=",kset)