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
def coloring(G,n):
    color=[-1]*n
    for i in range(n):
        nibrcolor = []
        for j in range(n):
            if G[i][j]==1:
                nibrcolor.append(color[j])
        for j in range(n):
            if j not in nibrcolor:
                color[i]=j
                break
    for i in range(n):
        print("vertex",i,"colored:",color[i])
n=int(input("enter vertices number:"))
G=[[0 for _ in range(n)] for _ in range(n)]
graphRead(G,n)
coloring(G,n)