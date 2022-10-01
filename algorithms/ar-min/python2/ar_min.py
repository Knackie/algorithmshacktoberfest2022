import sys

arr = []
minarr = sys.maxint
print "Enter the number of elements : "
n = int(input())
for i in xrange(0, n):
    num = int(input())
    arr.append(num)
    if num < minarr:
        minarr = num

print("Min element in array ", arr, " is ", minarr)
