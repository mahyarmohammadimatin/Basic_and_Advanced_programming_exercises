def graphRead(G, n):
    i,j=0,0
    while ((i!=-1) and (j!=-1)):
        print("Enter two connected vertices or (-1, -1) for end: ", end='')
        i,j=tuple(map(int,input().strip().split(" ")))
        if i==-1:
            break
        if ((i>=0) and (j>=0)) and ((i<n) and (j<n)) :
            G[i][j]=1 ; G[j][i]=1
        else:
            print("wrong vertex number")
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
def pathcheck(G,l):
    for i in range(len(l)-1):
        if G[l[i]][l[i+1]]==0:
            return 0
    return 1
n=int(input("enter vertices number:"))
G=[[0 for _ in range(n)] for _ in range(n)]
graphRead(G,n)
mynumbers=[i for i in range(n)]
mylist=permutation(mynumbers)
flag=1
for i in range(len(mylist)):
    mylist[i].append(mylist[i][0])
    if pathcheck(G,mylist[i]):
        print(mylist[i])
        flag=0
        break
if flag:
    print("no path find :(")