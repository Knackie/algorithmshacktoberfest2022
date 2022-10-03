def expo(base, exp):
    res=1
    while(exp>0):
        if(exp%2==1):
            res=res*base
        base=base*base
        exp=exp//2
    return res

x=int(input("Enter the base"))
y=int(input("Enter the exponent"))

print(x, "raised to power", y, "is",expo(x,y))
