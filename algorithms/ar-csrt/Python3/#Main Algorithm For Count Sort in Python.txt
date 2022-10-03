#Main Algorithm For Count Sort in Python or any Other Language

countingSort(array, size)
  max <- find largest element in array
  initialize count array with all zeros
  for j <- 0 to size
    find the total count of each unique element and 
    store the count at jth index in count array
  for i <- 1 to max
    find the cumulative sum and store it in count array itself
  for j <- size down to 1
    restore the elements to array
    decrease count of each element restored by 1


#Pseudo Implementation for COUNT Sort By Animesh Tiwari
countingsort(num):
    #Initializing the array
    #Find out the max element
    for i in range 0 to k:
        THEN do c[i] = 0
    #Finding out the no of occurences
    for i in range 0 to n:
        THEN do c[num[i]]=c[num[i]]+1
    #Calculating the cumulative sum
    for j in range len(list):
        THEN do c[i] = c[i] + c[i-1]
    #Sorting the array
    for j=n-1 to 0:
        THEN do res]-1]=num[i]
        c[num[i]]-=1
        i=i-1
#Taking Input array
data=[1,7,4,8]
Bring the input data from the user and do the above calculations
print countingsort(num)


