def whichrow(l,k,n,m):
    low = 0
    high = n - 1
    while low <= high:
        mid1 = low + (high + 1 - low) // 3
        mid2 = low + (2 * (high + 1 - low)) // 3
        if k >= l[mid1][0] and k <= l[mid1][m - 1]:
            return mid1
        elif k >= l[mid2][0] and k <= l[mid2][m - 1]:
            return mid2
        elif k > l[mid2][m - 1]:
            low = mid2 + 1
        elif k < l[mid1][0]:
            high = mid1 - 1
        elif k > l[mid1][m - 1] and k < l[mid2][0] and mid1+1!=mid2:
            low, high = mid1 + 1, mid2 - 1
        else:
            return
def ternary(x1,n,l):
    low=0
    high=len(l[x1])-1
    while low<=high:
        mid1=low+(high+1-low)//3
        mid2=low+ (2*(high+1-low))//3
        if n==l[x1][mid1]:
            while True:
                if mid1==0:
                    break
                if l[x1][mid1-1]==l[x1][mid1]:
                    mid1-=1
                else:
                    break
            if x1!=0 and mid1==0 and l[x1][mid1]==l[x1-1][len(l[x1])-1]:
                return ternary(x1-1,n,l)
            return (x1,mid1)
        elif n==l[x1][mid2]:
            while True:
                if mid2==0:
                    break
                if l[x1][mid2-1]==l[x1][mid2]:
                    mid2-=1
                else:
                    break
            if x1!=0 and mid2==0 and l[x1][mid2]==l[x1-1][len(l[x1])-1]:
                return ternary(x1-1,n,l)
            return (x1,mid2)
        elif n>l[x1][mid2]:
            low=mid2+1
        elif n<l[x1][mid1]:
            high=mid1-1
        elif n>l[x1][mid1] and n<l[x1][mid2]:
            low , high = mid1+1 , mid2-1
        else:
            return "NO"
n=int(input())
m=n
l=[]
for i in range(n):
    l.extend([list(map(int,input().split()))]) #it must be guaranteed that input is a sorted matrix!
k=int(input())
try:
    x1=whichrow(l,k,n,m)
    if x1!=None:
        x1,x2=ternary(x1,k,l)
        if x2!=None:
            print(x1,x2)
        else:
            print("NO")
    else:
        print("NO")
except:
    print("NO")