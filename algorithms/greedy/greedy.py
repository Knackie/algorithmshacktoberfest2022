
# // coin change 
denominations = [1, 2, 5, 10, 20, 50, 100]


def returnChange(change, denominations):
    # makes a list size of length denominations filled with 0
    toGiveBack = [0] * len(denominations)

    # goes backwards through denominations list
    # and also keeps track of the counter, pos.
    for pos, coin in enumerate(reversed(denominations)):
        # while we can still use coin, use it until we can't
        while coin <= change:
            change = change - coin
            toGiveBack[pos] += 1
    return(toGiveBack)
            
print(returnChange(30, denominations))






# // Fractional Knaksnap 
class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
 
def fractionalKnapsack(W, arr):
 
    # sorting Item on basis of ratio
    arr.sort(key=lambda x: (x.value/x.weight), reverse=True)
 

    finalvalue = 0.0
 
    # Looping through all Items
    for item in arr:
 
        if item.weight <= W:
            W -= item.weight
            finalvalue += item.value
 
        # If we can't add current Item, add fractional part
        else:
            finalvalue += item.value * W / item.weight
            break
    return finalvalue
 
 
# Driver's Code
if __name__ == "__main__":
 
    # Weight of Knapsack
    W = 50
    arr = [Item(60, 10), Item(100, 20), Item(120, 30)]
 
    # Function call
    max_val = fractionalKnapsack(W, arr)
    print ('Maximum value we can obtain = {}'.format(max_val))