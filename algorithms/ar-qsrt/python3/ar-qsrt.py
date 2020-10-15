def partition(lst, low, high):
    idx = low - 1
    pivot = lst[high]
    for i in range(low, high):
        if lst[i] <= pivot:
            idx += 1
            lst[idx], lst[i] = lst[i], lst[idx]

    lst[idx + 1], lst[high] = lst[high], lst[idx + 1]
    return idx + 1

def quick_sort(lst, low, high):
    if low < high:
        pi = partition(lst, low, high)
        quick_sort(lst, low, pi - 1)
        quick_sort(lst, pi + 1, high)
    return lst


arr = [23, 76, 12, 7, 29, 43, 65, 1]
print(quick_sort(arr, 0, len(arr) - 1))