def quickselect(arr, l, h):
    if l == h:
        return arr[l]
    pivot = arr[h]
    i = l
    for j in range(l, h):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[h] = arr[h], arr[i]
    if i == k-1:
        return arr[i]
    elif i < k-1:
        return quickselect(arr, i + 1, h)
    else:
        return quickselect(arr, l, i - 1)


if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    k = 5
    print(quickselect(arr, 0, len(arr) - 1))
