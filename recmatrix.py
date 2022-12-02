def readmatrix(n,i):
    if i==n:
        return 0
    i+=1
    matrix.extend([list(map(int,input("enter %s row:" %i).split()))])
    readmatrix(n,i)
def printmatrix(n,i):
    if i==n:
        return 0
    print(matrix[i])
    i+=1
    printmatrix(n,i)
def determinan(n,matrix1):
    if n>2:
        power = -1
        re=0
        for i in range(n):
            power += 1
            newmatrix=[]
            for p in range(1,n):
                newmatrix.extend([[matrix1[p][q] for q in range(n) if q!=i]])
            re+= (-1)**power * (matrix1[0][i]*determinan(n-1,newmatrix))
        return re
    else:
        return (matrix1[0][0]*matrix1[1][1])-(matrix1[0][1]*matrix1[1][0])
n=int(input())
matrix=[]
readmatrix(n,0)
printmatrix(n,0)
print(determinan(n,matrix))