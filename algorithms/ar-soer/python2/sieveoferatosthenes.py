def sieveOfEratosthenes(n):#finds all prime numbers from 2 till n
    primes = [0,0] + [1]*(n-1)
    # 0 and 1 not prime
    p = 2
    while(p**2 <= n):
        if primes[p]:#if true
            for i in range(p**2, n+1, p):#update all multiples of p to 0
                primes[i] = 0;
        p+=1
    return primes


if __name__ == '__main__':
    #insert range
    n = int(raw_input("Enter range till which primes is required(>0) : "))
    ans = sieveOfEratosthenes(n)
    if(ans == [0]*(n+1)):
        print"no primes"
    else:
        for i in range(2,n+1):
            if ans[i]:
                print " ",i

    
