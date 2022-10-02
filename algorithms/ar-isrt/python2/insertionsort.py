arr = [int(i) for i in raw_input("Enter elements seperated by space : ").split()]

for i in range(1,len(arr)):
    j = i-1
    key = arr[i]
    while(arr[j]>key and j>=0):
        arr[j+1] = arr[j]
        j-=1
    if(j != i-1):
        arr[j+1] = key;

print"\n\nfinal array is ",arr;

