def countcombo(coins, n, sum):#using DP approach, google for more
    if (sum == 0):
        return 1
    if (sum < 0):
        return 0
    if (n <= 0):
        return 0
    return countcombo(coins, n - 1, sum) + countcombo(coins, n, sum-coins[n-1])

if __name__=="__main__":
    coin_arr = [int(i) for i in raw_input("Enter unique(non repeating ) coins seperated by space :").split()]
    #removing duplicates if any
    coin_arr = list(set(coin_arr))
    s = int(raw_input("\nEnter needed sum : "))
    print"\n\nAll possible coin change for enter sum ",s," is ",countcombo(coin_arr,len(coin_arr),s)

