n = 10000
is_prime = []


def sieve():
    for i in range(n+1):
        is_prime.append(1)
    is_prime[0] = 0
    is_prime[1] = 0
    i = 2
    while((i*i) <= n):
        if(is_prime[i]):
            for j in range((i*i), n+1, i):
                is_prime[j] = 0
        i += 1


sieve()
# enter start as well as end
start, end = map(int, input("Enter Range: ").split())
for i in range(start, end+1):
    if is_prime[i]:
        print(i, end=" ")  # printing prime numbers using sieve
print()

# Enter Range: 25 65
# 29 31 37 41 43 47 53 59 61
