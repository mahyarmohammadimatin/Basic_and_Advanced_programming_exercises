def generate(a, n,k,t):
    i=k-1
    c=0
    if len(t) == 1:
        while(i>=0):
            if t[0]+1==c:
                print(a)
                break
            c+=1
            while ( (i>=0) and (a[i]==n-k+i+1)):
                i=i-1
            if (i>=0):
                a[i]=a[i]+1
                for j in range(i+1, k):
                    a[j]=a[j-1]+1
                i=k-1
        return
    else:
        while (i >= 0):
            if t == a:
                print(c)
                break
            c += 1
            while ((i >= 0) and (a[i] == n - k + i + 1)):
                i = i - 1
            if (i >= 0):
                a[i] = a[i] + 1
                for j in range(i + 1, k):
                    a[j] = a[j - 1] + 1
                i = k - 1
        return
n=int(input("Enter the nember of set elements: "))
k=int(input("Enter the length of sub sets: "))
t=list(map(int,input().split()))
a=[i+1 for i in range(k)]
generate(a,n,k,t)