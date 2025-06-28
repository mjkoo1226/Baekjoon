left = {}
right = {}

n = int(input())
root = ''

for i in range(n):
    A, B, C = input().split()
    left[A] = B
    right[A] = C

    if i == 0:
        root = A

def prepost(node):
    if node == '.':
        return
    
    print(node, end = '')
    prepost(left[node])
    prepost(right[node])

def inpost(node):
    if node == '.':
        return
    
    inpost(left[node])
    print(node, end = '')
    inpost(right[node])

def postpost(node):
    if node == '.':
        return
    
    postpost(left[node])
    postpost(right[node])
    print(node, end = '')

prepost(root)
print('')
inpost(root)
print('')
postpost(root)
