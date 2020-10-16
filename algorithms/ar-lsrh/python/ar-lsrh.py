def linear_search(arr, key):
    n = len(arr)
    for i in range(n):
        if arr[i] == key:
            return i
    return -1


arr = [1, 2, 5, 3, 7, 8, 89, 34, 23, 56, 99]
key = 1
ans = linear_search(arr, key)
if ans == -1:
    print("Key not found.")
else:
    print("Key " + str(key) + " found at index " + str(ans))
