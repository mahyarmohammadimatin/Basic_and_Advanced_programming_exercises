from fractions import Fraction
def readmatrix(n):
    matrix_z=[]
    for i in range(n):
        print("enter",i+1,"row:",end="")
        matrix_z+=[list(map(Fraction,input().split()))]
    print()
    matrix_j=list(map(Fraction,input("enter result matrix:").split()))
    return (matrix_z,matrix_j)
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
matrix_z,matrix_j=readmatrix(n)
d=determinan(n,matrix_z)
for i in range(n):
    newmatrix=[[0 for p in range(n)] for q in range(n)]
    for p in range(n):
        for q in range(n):
            if q==i:
                newmatrix[p][q]=matrix_j[p]
            else:
                newmatrix[p][q]=matrix_z[p][q]
    print("the %s result is:"%i , Fraction(determinan(n,newmatrix)/d))