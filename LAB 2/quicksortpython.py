import random
import time
import matplotlib.pyplot as plt
import numpy as np

def partition(arr, low, high):
    pivot = arr[low]
    i = low
    j = high
    
    while True:
        while i < high and arr[i] <= pivot:
            i += 1
        while j > low and arr[j] > pivot:
            j -= 1
        
        if i >= j:
            break
        arr[i], arr[j] = arr[j], arr[i]
    
    arr[low], arr[j] = arr[j], arr[low]
    return j

def quick_sort(arr, low, high):
    if low < high:
        pivot = partition(arr, low, high)
        quick_sort(arr, low, pivot - 1)
        quick_sort(arr, pivot + 1, high)

sizes = list(range(10, 100001, 1000))  # Sizes from 10 to 100000 with steps to optimize runtime
times = []

for n in sizes:
    arr = [random.randint(1, 1000000) for _ in range(n)]
    start_time = time.time()
    quick_sort(arr, 0, n - 1)
    end_time = time.time()
    times.append(end_time - start_time)

# Compute theoretical x log x complexity
xlogx = [n * np.log2(n) for n in sizes]

# Normalize x log x for better comparison
xlogx = [val / max(xlogx) * max(times) for val in xlogx]

# Plot the results
plt.figure(figsize=(10, 5))
plt.plot(sizes, times, label='QuickSort Time', color='b')
plt.plot(sizes, xlogx, label='O(n log n)', linestyle='dashed', color='r')
plt.xlabel('Number of Elements')
plt.ylabel('Time Taken (seconds)')
plt.title('QuickSort Time Complexity vs O(n log n)')
plt.legend()
plt.grid()
plt.show()
