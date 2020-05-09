import math

def decimalToBinary(num,arr):
    if num > 1:                         #This function converts decimal number
        decimalToBinary(num // 2,arr)   #to binary and prints it
    arr.append(num%2)

binDec = []
binExp = []
frac = []
number = float(input("Enter any decimal number: "))
sbit = 0 if number > 0 else 1
number = abs(number)
intg = int(number)
prec = number - intg
decimalToBinary(intg,binDec)

flag = 0
y1 = prec
if intg>0:
    for i in range(1,50): 
        y1 *= 2
        y = int(y1)
        frac.append(y)
        y1-=y
else :
    for i in range(1,50):
        y1 *= 2
        y = int(y1)
        if flag==0 and y==1 :
            moved = i
            flag = 1
        elif flag==1 :
            frac.append(y)
        y1-=y

exp = len(binDec) + 126 if intg > 0 else 127 - moved

decimalToBinary(exp,binExp)
if exp < 128 :
    binExp.insert(0,0)

binExp.insert(0,sbit)
binDec.pop(0)
binExp.extend(binDec)
x = 32 - len(binExp)
binExp.extend(frac[0:x])
j=0
for i in binExp:
    print(i,end='')
    j+=1
    if j==4 :
        print(end=' ')
        j=0

