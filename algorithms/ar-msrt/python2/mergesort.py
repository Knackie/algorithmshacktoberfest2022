def merge(arr,lb,ub,m):
    #length of left and right subarrays
    n1,n2 = m - lb + 1,ub - m
    #temp arrays storing left and right partions respectively
    L,R = arr[lb : lb+n1],arr[m+1 : m+1+n2]
    
    #merging temp arrays back to arr
    i,j = 0,0 #initial indices of left  and right subarrays respectively
    k = lb # intial index of merged array 
    while(i<n1 and j<n2):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i+=1
        else:
            arr[k] = R[j]
            j+=1
        k+=1
    # Checking if any element was left in both the subarrays
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
 
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort(arr,lb,ub):
    if(lb < ub):
        mid = lb + (ub-lb)//2
        #same as (ub+lb)/2 but avoids overflow for large values
        #print("-->",lb,ub,mid) 
        merge_sort(arr,lb,mid) #left half
        merge_sort(arr,mid+1,ub) #right half
        '''repeated calling of merge_sort till atomic values are reached i.e.
        individual elements'''

        merge(arr,lb,ub,mid)
  

if __name__ == '__main__':
    lst = [int(i) for i in raw_input("Enter elements seperated by space :").split()]
    merge_sort(lst,0,len(lst)-1)
    print"After merge sort new list is:-\n",lst
