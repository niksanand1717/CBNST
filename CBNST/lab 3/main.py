from formula import *

x0 = eval(input("enter x0: "))
x1 = eval(input("enter x1: "))

i = 1
while True:
    x2 = falsi(x0, x1)

    if f(x0)*f(x2)<0:
        x1 = x2
    else:
        x0 = x2

    print("Iteration",i,"\tx:",x2)

    if abs(f(x2))<=0.00001:break
    i=i+1
