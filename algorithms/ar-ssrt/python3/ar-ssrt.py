def selection_sort(input_list):
    len_list = len(input_list)
    for i in range(len_list-1):
        # Finding the lowest value
        lower_index = i
        for j in range(i+1, len_list):
            if input_list[j] < input_list[lower_index]:
                lower_index = j

        # Swapping values
        input_list[i], input_list[lower_index] = input_list[lower_index], input_list[i]

    return input_list


example = [1, 5, 2, 4, 6, 3]
print(selection_sort(example))
