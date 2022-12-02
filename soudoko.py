from math import sqrt
def getmat(n):
    m=[]
    for i in range(n):
        m.extend([list(map(int,input().split()))])
    return m
n=int(input("Enter row:"))
m=getmat(n)
flag=1
for i in range(n):
    if flag==0:
        break
    s = []
    for j in range(n):
        s.append(m[i][j])
    s.sort()
    for j in range(n):
        if s[j]!=j+1:
            flag=0
            break
if flag:
    for i in range(n):
        if flag==0:
            break
        s = []
        for j in range(n):
            s.append(m[j][i])
        s.sort()
        for j in range(n):
            if s[j]!=j+1:
                flag=0
                break
if flag:
    p=int(sqrt(n))
    for k in range(0,n,p):
        for l in range(0,n,p):
            s=[]
            if flag:
                for i in range(p):
                    for j in range(p):
                        s.append(m[i+k][j+l])
                s.sort()
                for t in range(n):
                    if s[t] != t+1:
                        flag = 0
                        break
if flag:
    print("it's soudoko!")
else:
    print("it's not soudoko!")