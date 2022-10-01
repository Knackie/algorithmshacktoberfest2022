import sys

arr = []
minarr = sys.maxsize
print("Enter the number of elements : ")
n = int(input())
print("Enter the elements of array: ")
for i in range(0, n):
    num = int(input())
    arr.append(num)
    if num < minarr:
        minarr = num

print("Min element in array ", arr, " is ", minarr)
