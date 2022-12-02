def getmat(n):
    m=[]
    for i in range(n):
        m.extend([list(map(int,input().split()))])
    return m
n=int(input("Enter row:"))
m=getmat(n)
max=0
for i in range(1,n+1):
    summat = [[0 for p in range(i)] for j in range(i)]
    for row1 in range(n-i+1):
        for col1 in range(n-i+1):
            sum=0
            for row2 in range(i):
                for col2 in range(i):
                    sum+=m[row1+row2][col1+col2]
                    summat[row2][col2]=m[row1+row2][col1+col2]
            if sum>max:
                max=sum
                maxmat=summat
print(max,maxmat)