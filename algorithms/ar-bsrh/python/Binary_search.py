def binary_search(arr,n,key):
    low=0
    high=n-1
    while low<=high:
        mid=(low+high)//2
        if arr[mid]==key:
            return mid+1
        elif arr[mid]< key:
            low=mid+1
        else:
            high=mid-1
    return -1

if __name__ == "__main__":
    n=int(input('Enter number of Elements: '))
    arr=list(map(int,input('Enter data in sorted order: ').split()))[:n]
    key=int(input('Enter key to search: '))
    x=binary_search(arr,n,key)
    if x==-1:
        print('Element not found')
    else:
        print("Element found at position ",x)
