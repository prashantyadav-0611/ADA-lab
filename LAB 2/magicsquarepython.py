import time
import matplotlib.pyplot as plt
import numpy as np

def display(matrix):
    for row in matrix:
        print("  ".join(map(str, row)))
    print()

def magic_square(n):
    matrix = [[0] * n for _ in range(n)]
    row, col = 0, n // 2
    
    for num in range(1, n * n + 1):
        matrix[row][col] = num
        new_row, new_col = (row - 1 + n) % n, (col - 1 + n) % n
        
        if matrix[new_row][new_col] != 0:
            row = (row + 1) % n
        else:
            row, col = new_row, new_col
    
    return matrix

sizes = list(range(3, 2004, 10))  # Odd sizes from 3 to 2003 with step size 10
times = []

for n in sizes:
    start_time = time.time()
    magic_square(n)
    end_time = time.time()
    times.append(end_time - start_time)

# Compute theoretical O(n^2) complexity
n_squared = [n**2 for n in sizes]

# Normalize n^2 for better comparison
n_squared = [val / max(n_squared) * max(times) for val in n_squared]

# Plot the results
plt.figure(figsize=(10, 5))
plt.plot(sizes, times, label='Magic Square Time', color='b')
plt.plot(sizes, n_squared, label='O(n^2)', linestyle='dashed', color='r')
plt.xlabel('Order of Magic Square (n)')
plt.ylabel('Time Taken (seconds)')
plt.title('Magic Square Time Complexity vs O(n^2)')
plt.legend()
plt.grid()
plt.show()