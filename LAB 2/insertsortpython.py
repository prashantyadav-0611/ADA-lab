import random
import time
import matplotlib.pyplot as plt
import numpy as np

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

sizes = list(range(10, 10001, 500))  # Sizes from 10 to 10,000 with steps to limit runtime
times = []

for n in sizes:
    arr = [random.randint(1, 1000000) for _ in range(n)]
    start_time = time.time()
    insertion_sort(arr)
    end_time = time.time()
    times.append(end_time - start_time)

# Compute theoretical n^2 complexity
n_squared = [n**2 for n in sizes]

# Normalize n^2 for better comparison
n_squared = [val / max(n_squared) * max(times) for val in n_squared]

# Plot the results
plt.figure(figsize=(10, 5))
plt.plot(sizes, times, label='Insertion Sort Time', color='b')
plt.plot(sizes, n_squared, label='O(n^2)', linestyle='dashed', color='r')
plt.xlabel('Number of Elements')
plt.ylabel('Time Taken (seconds)')
plt.title('Insertion Sort Time Complexity vs O(n^2)')
plt.legend()
plt.grid()
plt.show()
