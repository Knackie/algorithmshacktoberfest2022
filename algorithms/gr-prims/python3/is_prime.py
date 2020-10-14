def is_prime(n):
    if n <= 1:
        return False
    else:
        d = 2
        primo = True
        while primo and d <= n/2:
            if n % d == 0:
                primo = False
            d += 1
        return primo


if __name__ == "__main__":
    n = int(input())
    ans = "Is prime" if is_prime(n) else "Isn't prime"
    print(ans)
