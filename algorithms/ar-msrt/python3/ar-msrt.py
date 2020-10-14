def merge_list(input_list1, input_list2):
    if not input_list1:
        return input_list2
    elif not input_list2:
        return input_list1
    else:
        a, b = input_list1[0], input_list2[0]
        if a <= b:
            return [a] + merge_list(input_list1[1:], input_list2)
        else:
            return [b] + merge_list(input_list1, input_list2[1:])


def merge_sort(input_list):
    if not input_list:
        return input_list
    elif not input_list[1:]:
        return input_list
    else:
        n = len(input_list)
        begin, end = input_list[0: n//2], input_list[n//2:]
        return merge_list(merge_sort(begin), merge_sort(end))


example = [1, 5, 2, 4, 6, 3]
print(merge_sort(example))
