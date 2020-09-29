def initialise(n):
    global Parent
    Parent=[i for i in range(n+1)]
    global Size
    Size=[1 for i in range(n+1)]

def find(i):
    global Parent
    if Parent[i] == i:
        return i
    else:
        Parent[i] = find(Parent[i])
        return Parent[i]



def union(i, j):
    global Parent
    global Size
    iroot = find(i)
    jroot = find(j)
    if iroot == jroot:
        return
    isize = Size[iroot]
    jsize = Size[jroot]
    if isize < jsize:
        Parent[iroot] = jroot
        Size[jroot]+=Size[iroot]

    else:
        Parent[jroot] = iroot
        Size[iroot]+=Size[jroot]

n=int(input())
m=int(input())
initialise(n)

for i in range(m):
    a=int(input())
    b=int(input())
    union(a,b)

a = int(input())
b = int(input())
if find(a)==find(b):
    print("Same set")
else:
    print("Different set")

