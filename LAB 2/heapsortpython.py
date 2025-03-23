import random
import time
import matplotlib.pyplot as plt
import numpy as np

def heapify(arr, n, i):
    largest = i  # Initialize largest as root
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

sizes = list(range(10, 10001, 500))  # Sizes from 10 to 10,000 with steps to limit runtime
times = []

for n in sizes:
    arr = [random.randint(1, 1000000) for _ in range(n)]
    start_time = time.time()
    heap_sort(arr)
    end_time = time.time()
    times.append(end_time - start_time)

# Compute theoretical n log n complexity
nlogn = [n * np.log2(n) for n in sizes]

# Normalize n log n for better comparison
nlogn = [val / max(nlogn) * max(times) for val in nlogn]

# Plot the results
plt.figure(figsize=(10, 5))
plt.plot(sizes, times, label='Heap Sort Time', color='b')
plt.plot(sizes, nlogn, label='O(n log n)', linestyle='dashed', color='r')
plt.xlabel('Number of Elements')
plt.ylabel('Time Taken (seconds)')
plt.title('Heap Sort Time Complexity vs O(n log n)')
plt.legend()
plt.grid()
plt.show()
