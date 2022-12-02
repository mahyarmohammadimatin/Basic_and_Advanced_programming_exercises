def permutation(lst):
    if len(lst) == 0:
        return []
    if len(lst) == 1:
        return [lst]
    l = []
    for i in range(len(lst)):
        m = lst[i]
        remLst = lst[:i] + lst[i + 1:]
        for p in permutation(remLst):
            l.append([m] + p)
    return l
n=int(input())
mylist=[1,0]*(n)
re=set()
for i in permutation(mylist):
    i=tuple(i)
    re.add(i)
newset=set()
for i in re:
    c,flag=0,1
    for j in i:
        if j==1: c+=1
        elif j==0 and c>0: c-=1
        else:
            flag=0
            break
    if flag: newset.add(i)
for i in newset:
    print()
    for j in i:
        if j==1: print("(",end="")
        else: print(")",end="")