def up(p,q,m):
    p-=1
    mat[p][q]=m
    return p,q
def down(p,q,m):
    p+=1
    mat[p][q] = m
    return p, q
def right(p,q,m):
    q+=1
    mat[p][q] = m
    return p, q
def left(p,q,m):
    q-=1
    mat[p][q] = m
    return p, q
n=int(input())
mat=[[0 for _ in range(2*n-1)] for _ in range(2*n-1)]
p=(2*n-1)//2
q=p
if n==1:
    print(1)
else:
    mat[p][q]=1
    p,q=up(p,q,2)
    p,q=right(p,q,2)
    for _ in range(2):
        p,q=down(p,q,2)
    for _ in range(2):
        p,q=left(p,q,2)
    for _ in range(2):
        p,q=up(p,q,2)
    for m in range(3,n+1):
        p,q=up(p,q,m)
        for _ in range(2*m-3):
            p,q=right(p,q,m)
        for _ in range(2*m-2):
            p,q=down(p,q,m)
        for _ in range(2*m-2):
            p,q=left(p,q,m)
        for _ in range(2*m-2):
            p,q=up(p,q,m)
if mat!=[[0]]:
    for i in mat:
        print(i)