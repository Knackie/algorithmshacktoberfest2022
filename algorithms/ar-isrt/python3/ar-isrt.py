def insertion_sort(input_list):
    len_list = len(input_list)
    for i in range(1, len_list):
        index = i
        # Making the value down to its position
        while index > 0 and input_list[index] < input_list[index-1]:
            # Swapping values
            input_list[index], input_list[index-1] = input_list[index-1], input_list[index]
            index -= 1
    return input_list


example = [1, 5, 2, 4, 6, 3]
print(insertion_sort(example))
