import random
import time
import matplotlib.pyplot as plt
import numpy as np

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

sizes = list(range(10, 10001, 500))  # Sizes from 10 to 10,000 with steps to limit runtime
times = []

for n in sizes:
    arr = [random.randint(1, 1000000) for _ in range(n)]
    start_time = time.time()
    merge_sort(arr)
    end_time = time.time()
    times.append(end_time - start_time)

# Compute theoretical n log n complexity
nlogn = [n * np.log2(n) for n in sizes]

# Normalize n log n for better comparison
nlogn = [val / max(nlogn) * max(times) for val in nlogn]

# Plot the results
plt.figure(figsize=(10, 5))
plt.plot(sizes, times, label='Merge Sort Time', color='b')
plt.plot(sizes, nlogn, label='O(n log n)', linestyle='dashed', color='r')
plt.xlabel('Number of Elements')
plt.ylabel('Time Taken (seconds)')
plt.title('Merge Sort Time Complexity vs O(n log n)')
plt.legend()
plt.grid()
plt.show()
