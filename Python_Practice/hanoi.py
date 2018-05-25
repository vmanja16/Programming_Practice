A = [1,2,3,4,5]
B = []
C = []

def moveDisk(fromPeg, toPeg):
    toPeg.append(fromPeg.pop())

def hanoi(n, fromPeg, toPeg, sparePeg):
    if (n==0):
        return
    hanoi(n-1, fromPeg, sparePeg, toPeg)
    moveDisk(fromPeg,toPeg)
    hanoi(n-1, sparePeg, toPeg, fromPeg)


    
