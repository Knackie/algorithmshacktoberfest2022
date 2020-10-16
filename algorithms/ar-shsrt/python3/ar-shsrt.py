def shell_sort(nums):
    size = len(nums)

    # starting gap
    gap = size // 2

    while gap > 0:
        for x in range(gap, size):
            temp_val = nums[x]
            temp_position = x

            # sort everything in the gap
            while temp_position >= gap and nums[temp_position - gap] > temp_val:
                nums[temp_position] = nums[temp_position - gap]
                temp_position -= gap

            nums[temp_position] = temp_val

        # next gap to sort
        gap //= 2

    return nums


arr = [198, 65, 2, 3, 36, 200, 55, 4, 0]
print(f'pre shell sort: {arr}')
print(f'post shell sort: {shell_sort(arr)}')