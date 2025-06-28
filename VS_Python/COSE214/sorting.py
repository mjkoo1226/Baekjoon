#############################################################################
# InsertSort Algorithm

def InsertionSort(A):
    for j in range(1, len(A)):
        key = A[j]
        i = j - 1
        while(i >= 0 and A[i] > key):
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = key
        
#############################################################################
# MergeSort Algorithm

import math

def Merge(A, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    left = [0] * (n1 + 1)
    right = [0] * (n2 + 1)
    
    for i in range(n1):
        left[i] = A[p + i]
    for j in range(n2):
        right[j] = A[q + j + 1]
    left[n1] = right[n2] = math.inf
    
    i = j = 0
    for k in range(p, r + 1):
        if left[i] <= right[j]:
            A[k] = left[i]
            i += 1
        else:
            A[k] = right[j]
            j += 1

def MergeSort(A, p, r):
    if p < r:
        q = int((p + r) / 2)
        MergeSort(A, p, q)
        MergeSort(A, q + 1, r)
        Merge(A, p, q, r)

#############################################################################
# Max-Heaplify Sort Algorithm

def swap(A, i, j):
    A[i], A[j] = A[j], A[i]

def MaxHeapify(A, i, heap_size):
    l = 2 * i + 1
    r = 2 * i + 2

    largest = i
    if l < heap_size and A[l] > A[largest]:
        largest = l
    if r < heap_size and A[r] > A[largest]:
        largest = r

    if largest != i:
        swap(A, i, largest)
        MaxHeapify(A, largest, heap_size)

def BuildMaxHeap(A):
    heap_size = len(A)
    for i in range(len(A) // 2 - 1, -1, -1):
        MaxHeapify(A, i, heap_size)

def HeapSort(A):
    BuildMaxHeap(A)
    heap_size = len(A)
    for i in range(len(A)-1, 0, -1):
        swap(A, 0, i)
        heap_size -= 1
        MaxHeapify(A, 0, heap_size)
        
#############################################################################
# Partition Sort Algorithm

import random

def swap(A, i, j):
    A[i], A[j] = A[j], A[i]

def Partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i = i + 1
            swap(A, i, j)
    swap(A, i + 1, r)
    return i + 1
            
def Randomized_Partition(A, p, r):
    i = random.randrange(p, r + 1)
    swap(A, r, i)
    return Partition(A, p, r)
    
def Randomized_Quicksort(A, p, r):
    if p < r:
        q = Randomized_Partition(A, p, r)
        Randomized_Quicksort(A, p, q - 1)
        Randomized_Quicksort(A, q + 1, r)
    
#############################################################################

nums = list(map(int, input().split()))
# InsertionSort(nums)
# MergeSort(nums, 0, len(nums) - 1)
# HeapSort(nums)
# Randomized_Quicksort(nums, 0, len(nums) - 1)
print(nums)