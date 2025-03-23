import random
import time
import matplotlib.pyplot as plt
import numpy as np

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

sizes = list(range(10, 10001, 500))  # Sizes from 10 to 10,000 with steps to limit runtime
times = []

for n in sizes:
    arr = [random.randint(1, 1000000) for _ in range(n)]
    start_time = time.time()
    selection_sort(arr)
    end_time = time.time()
    times.append(end_time - start_time)

# Compute theoretical n^2 complexity
n_squared = [n**2 for n in sizes]

# Normalize n^2 for better comparison
n_squared = [val / max(n_squared) * max(times) for val in n_squared]

# Plot the results
plt.figure(figsize=(10, 5))
plt.plot(sizes, times, label='Selection Sort Time', color='b')
plt.plot(sizes, n_squared, label='O(n^2)', linestyle='dashed', color='r')
plt.xlabel('Number of Elements')
plt.ylabel('Time Taken (seconds)')
plt.title('Selection Sort Time Complexity vs O(n^2)')
plt.legend()
plt.grid()
plt.show()
