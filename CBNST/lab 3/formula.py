def falsi(x0, x1):
    x2 = x0 - ((x1-x0)/(f(x1)-f(x0))*f(x0))
    return x2

def f(x):
    result = x*x - 2*x - 8
    return result


#x0 = eval(input("input x0: "))
#x1 = eval(input("input x1: "))
#print(falsi(x0, x1))
