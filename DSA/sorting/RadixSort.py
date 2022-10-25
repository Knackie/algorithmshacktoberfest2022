# usr/bin/env python
import math

aList = [5,67,5,34,64,76,44,56,4,3,7,8,5]

def radixsort( aList ):
     RADIX = 10
     maxLength = False
     tmp , placement = -1, 1
     while not maxLength:
         maxLength = True
         # declare and initialize buckets
         buckets = [list() for _ in range( RADIX )]
         # split aList between lists
         for  i in aList:
             tmp = i / placement
             buckets[int(tmp % RADIX)].append( i )
             if maxLength and tmp > 0:
                 maxLength = False
         # empty lists into aList array
         a = 0
         for b in range( RADIX ):
               buck = buckets[b]
               for i in buck:
                   aList[a] = i
                   a += 1
         # move to next digit
         placement *= RADIX 


print(aList)
radixsort(aList)
print(aList)
