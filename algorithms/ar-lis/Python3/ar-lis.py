seq=list(map(int,input().split()))
ans=0
count=1
length=len(seq)
if length==0:
    ans=0
elif length==1:
    ans=1
else:
    for i in range(1,length):
        if seq[i]>seq[i-1]:
            count+=1
        else:
            ans=max(ans,count)
            count=1
    ans=max(ans,count)
print(ans)


