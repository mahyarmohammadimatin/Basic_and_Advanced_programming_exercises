def max(n):
    max,sum,i=0,0,0
    for j in range (len(n)):
        sum+=n[j]
        if(sum>max):
            max=sum
            start=i
            end=j
        elif sum <0:
            i=j+1
            sum=0
    return(max, start, end)
n=list(map(int,input().split()))
print(max(n))