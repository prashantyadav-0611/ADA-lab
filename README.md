# ADA-lab

**LAB-1**


**PROGRAM 1**
**OBJECTIVE**= to find the first peak element in a given random one dimension array
**working**=This program finds a peak element in an array using a recursive binary search approach. The peak function calculates the middle index and checks if the middle element is smaller than its left or right neighbor. If so, it recursively searches the appropriate half of the array. If the middle element is greater than or equal to both neighbors, it is considered a peak, and its index is returned. The main function initializes an array, calls peak to find a peak index, and prints the result.
**output**= The code will give the index of the first peak element it will encounter
![1d peak](https://github.com/user-attachments/assets/96c56273-91cb-4235-be9c-bfd1e36967af)


**PROGRAM 2**
**OBJECTIVE**= to find the first peak element in a given random two dimension array
**working**=This program finds a peak element in a 2D matrix using a binary search approach. The `maximum` function finds the index of the maximum element in the given column. The `findpeak` function uses binary search on columns, checking if the maximum element in the middle column is smaller than its left or right neighbor. If so, it continues searching in the corresponding half; otherwise, it identifies the peak and prints its position. The `main` function initializes the matrix, takes user input, displays it, and calls `findpeak` to determine the peak element.
**output**=the code will print the index of the peak element.


**PROGRAM 3**
**OBJECTIVE**=To compute a raise to power b in logb time complexity
**working**=This program calculates the power of a number using exponentiation by squaring, which optimizes the process to O(log b) time complexity. The power function initializes result as 1 and iteratively squares a while halving b. If b is odd, it multiplies result by a. The main function takes user input for base and exponent, calls power, and prints the result.
**output**=a^b is calculated in logb time complexity


**PROGRAM 4**
**OBJECTIVE**=To generate a magice square of user entered order(odd).
**working**=This program generates an odd-order magic square using the Siamese method. The magicsquare function places numbers from 1 to n*n in a n×n grid, starting from the middle of the first row. Each number is placed one step diagonally up-left; if that position is occupied, it moves down instead. The display function prints the matrix. The main function takes user input for the order n, initializes the square with zeros, generates the magic square, and displays it.
**output**=enter the order of the magic square
5
15  8  1  24  17  
16  14  7  5  23  
22  20  13  6  4  
3  21  19  12  10  
9  2  25  18  11  

----------------------------------------------------------------------------------------------------------------------------------------------------------------

**LAB 2**

**PROGRAM 1**
**OBJECTIVE**=To analyze the time complexity of bubble sort with various input size.
**working**=This program analyzes the time complexity of Bubble Sort by sorting arrays of increasing sizes and plotting the execution time. The bubble_sort function implements the optimized Bubble Sort, which stops early if the array becomes sorted. The main loop generates random arrays, sorts them, and records the time taken. The results are plotted using matplotlib, comparing actual sorting times with the theoretical O(n²) complexity. The plot visually demonstrates how Bubble Sort scales with input size.
**output**=a graph displayig the time compexity vs input size along with theoritical n^2 graph.


**PROGRAM 2**
**OBJECTIVE**=To analyze the time complexity of HEAP sort with various input size.
**working**=his program analyzes the time complexity of Heap Sort by sorting arrays of increasing sizes and plotting the execution time. The heapify function maintains the heap property, and heap_sort first builds a max heap, then extracts the maximum element one by one. The main loop generates random arrays, sorts them, and records the execution time. The results are plotted using matplotlib, comparing actual sorting times with the theoretical O(n log n) complexity, showing Heap Sort's efficiency compared to quadratic sorting algorithms.
**output**=a graph displayig the time compexity vs input size along with theoritical nlogn graph.


**PROGRAM 3**
**OBJECTIVE**=To analyze the time complexity of inssert sort with various input size.
**working**=This program analyzes the time complexity of Insertion Sort by sorting arrays of increasing sizes and plotting the execution time. The insertion_sort function sorts an array by repeatedly shifting elements to insert each key in its correct position. The main loop generates random arrays, sorts them, and records the execution time. The results are plotted using matplotlib, comparing actual sorting times with the theoretical O(n²) complexity, illustrating Insertion Sort’s inefficiency for large inputs due to its quadratic growth.
**output**=a graph displayig the time compexity vs input size along with theoritical n^2 graph.


**PROGRAM 4**
**OBJECTIVE**=To analyze the time complexity of magic square generating code with various input size.
**working**=This program analyzes the time complexity of Magic Square Generation by constructing magic squares of increasing sizes and plotting the execution time. The magic_square function follows the Siamese method, placing numbers diagonally up-left and adjusting when a conflict occurs. The main loop generates magic squares of different sizes, measures execution time, and records the results. The execution time is plotted using matplotlib, comparing actual times with the theoretical O(n²) complexity, illustrating that filling an n × n matrix follows quadratic growth, confirming the O(n²) time complexity of the method.
**output**=a graph displayig the time compexity vs input size along with theoritical n^2 graph.


**PROGRAM 5**
**OBJECTIVE**=To analyze the time complexity of merge sort with various input size.
**working**=This program analyzes the time complexity of Merge Sort by sorting arrays of increasing sizes and plotting the execution time. The merge_sort function follows a divide-and-conquer approach, recursively splitting the array into halves, sorting them, and merging them back in sorted order. The main loop generates random arrays, sorts them, and records the execution time. The results are plotted using matplotlib, comparing actual sorting times with the theoretical O(n log n) complexity, illustrating Merge Sort’s efficiency compared to quadratic sorting algorithms.
**output**=a graph displayig the time compexity vs input size along with theoritical nlogn graph.


**PROGRAM 6**
**OBJECTIVE**=To analyze the time complexity of quick sort with various input size.
**working**=This program analyzes the time complexity of QuickSort by sorting arrays of increasing sizes and plotting the execution time. The quick_sort function recursively partitions the array using a pivot and sorts the left and right subarrays. The main loop generates random arrays, sorts them, and records execution time. The results are plotted using matplotlib, comparing actual sorting times with the theoretical O(n log n) complexity, illustrating QuickSort’s efficiency for large datasets.
**output**=a graph displayig the time compexity vs input size along with theoritical nlogn graph.


**PROGRAM 7**
**OBJECTIVE**=To analyze the time complexity of selection sort with various input size.
**working**=This program analyzes the time complexity of Selection Sort by sorting arrays of increasing sizes and plotting the execution time. The selection_sort function repeatedly finds the minimum element and swaps it with the current position, making it inefficient for large inputs due to its O(n²) complexity. The main loop generates random arrays, sorts them, and records execution time. The results are plotted using matplotlib, comparing actual sorting times with the theoretical O(n²) growth, clearly demonstrating its quadratic time complexity.
**output**=a graph displayig the time compexity vs input size along with theoritical n^2 graph.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

**LAB -3**

**PROGRAM 1**
**OBJECTIVE**=To write code to implement knapsnap problem and to find its solution by three criteria (profit,weigth,profit per unit weight) and find out which one is best for making maximum profit.
**working**=This C program implements and analyzes different strategies for solving the fractional knapsack problem using a greedy approach. The program generates 20 random items with random profits and weights, calculates their profit-to-weight ratios, and sorts them using Bubble Sort based on three different criteria: profit, weight, and profit-to-weight ratio. It then applies a greedy selection process to fill a knapsack of capacity 100, maximizing profit based on each sorting strategy. The maximum profit among the three approaches is determined and displayed for comparison.
**output**=
s.no  profit1 profit2    profit3   maxprofit
1     1194      1087       1194       1194
2     1418      1345       1461       1461
3     1283      997       1343       1343
4     1147      1038       1152       1152
5     1084      887       1099       1099
6     1288      1104       1302       1302
7     1443      1228       1473       1473
8     1481      1315       1498       1498
9     1431      1185       1435       1435
10     1204      1090       1251       1251.......

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

**LAB -4**

**PROGRAM 1**
**OBJECTIVE**=To find a conevx polygon using quick hull approach.
**working**=This C program implements the QuickHull algorithm to find the convex hull of a set of 2D points. It first determines the leftmost and rightmost points, then recursively finds points that form the convex hull by selecting the farthest point from a given line segment and dividing the problem into smaller subproblems. The orientation function checks whether a point lies on the left, right, or on a line, while the distance function calculates the perpendicular distance of a point from a line. The quickHull function recursively constructs the hull, and addPoint ensures uniqueness in the output. The final hull points are printed, making this algorithm efficient for computational geometry applications like collision detection and boundary estimation..
**output**=
Enter the number of points: 5
Enter coordinates of point 1: 2 2
Enter coordinates of point 2: 2 -2
Enter coordinates of point 3: -2 2
Enter coordinates of point 4: -2 -2
Enter coordinates of point 5: 0 0
Convex Hull points:
(2, -2)
(-2, 2)
(2, 2)


**PROGRAM 2**
**OBJECTIVE**=To check if a enterd poimt lies inside a triangle made by some other three points.
**working**=This C program determines whether a given point lies inside a triangle using the orientation method. The orientation function calculates the relative position of a point concerning a directed line segment, returning 1 for left, -1 for right, and 0 for collinear points. The InsideTriangle function computes the orientation of the test point with respect to each edge of the triangle and checks if all orientations are the same, indicating that the point is inside. The program takes user input for the triangle's vertices and the test point, then prints whether the point is inside or outside the triangle.
**output**=Enter coordinates of the first vertex (x1, y1): 7 8
Enter coordinates of the second vertex (x2, y2): 6 4 
Enter coordinates of the third vertex (x3, y3): 9 2
Enter coordinates of the point to check (x, y): 0 0
The point (0, 0) is OUTSIDE the triangle.


**PROGRAM 3**
**OBJECTIVE**= To perform matrix multiplication using divide and conquer approach.
**working**=This program performs recursive matrix multiplication using the divide-and-conquer approach. It initializes two 8x8 matrices, A and B, with predefined values and creates an empty result matrix C filled with zeros. The multiply function recursively divides the matrices into smaller submatrices and computes their products, accumulating the results in C. The base case of the recursion handles single-element multiplication. After completing the recursive multiplication, the program prints the original matrices and the resultant matrix C, which represents the product of A and B. This method effectively breaks down matrix multiplication into smaller computations, ensuring correctness through systematic submatrix processing
**output**=
Matrix A:
1 2 3 4 5 6 7 8 
2 3 4 5 6 7 8 1 
3 4 5 6 7 8 1 2 
4 5 6 7 8 1 2 3 
5 6 7 8 1 2 3 4
6 7 8 1 2 3 4 5
7 8 1 2 3 4 5 6
8 1 2 3 4 5 6 7

Matrix B:
8 7 6 5 4 3 2 1
7 6 5 4 3 2 1 8
6 5 4 3 2 1 8 7
5 4 3 2 1 8 7 6
4 3 2 1 8 7 6 5 
3 2 1 8 7 6 5 4
2 1 8 7 6 5 4 3
1 8 7 6 5 4 3 2

Resultant Matrix C (A x B):
120 148 168 180 184 180 168 148
148 120 148 168 180 184 180 168
168 148 120 148 168 180 184 180
180 168 148 120 148 168 180 184
184 180 168 148 120 148 168 180
180 184 180 168 148 120 148 168
168 180 184 180 168 148 120 148
148 168 180 184 180 168 148 120


**PROGRAM 4**
**OBJECTIVE**=To find the minimum and maximum element from an unsorted array using  D&C.
**wokring**=This program finds the minimum and maximum values in an array using the divide-and-conquer approach. The min_max function recursively divides the array into smaller subarrays until single-element cases are reached. It then compares and merges the results from the divided sections to determine the overall minimum and maximum values. The main function initializes an array, calls min_max with the full range, and prints the found minimum and maximum values. This method efficiently reduces the number of comparisons compared to a straightforward linear search.
**output**=
Max = 10
Min = 1


**PROGRAM 5**
**OBJECTIVE**= To find out number of triangles possible from given n points in space.
**wokring**=This program calculates the number of non-collinear triangles that can be formed from a given set of points. It first determines the total number of possible triangles using the combinatorial formula C(n,3)= n(n-1)(n-2)/6. Then, it iterates through all possible triplets of points and checks if they are collinear using the determinant method, which calculates the area of the triangle formed by the three points. If the area is zero, the points are collinear, and such triplets are excluded from the count. Finally, the program prints the number of valid non-collinear triangles.
**output**=
Enter the number of points: 6
Enter coordinates of point 1: 0 0
Enter coordinates of point 2: 2 2
Enter coordinates of point 3: 4 4
Enter coordinates of point 4: 6 7 
Enter coordinates of point 5: 9 1
Enter coordinates of point 6: 11 -5
Number of non-collinear triangles: 19


**PROGRAM 6**
**OBJEVTIVE**= To perform quick sort by an iterative approach.
**wokring**=This program implements an iterative version of the QuickSort algorithm using an explicit stack to manage recursion. It first generates a random unsorted array of user-defined size and then sorts it using QuickSort. The partition function selects the last element as the pivot and rearranges the array such that elements smaller than the pivot are on the left and larger ones are on the right. The QuickSort function (QSI) simulates recursive calls using a stack, always processing the smaller partition first to minimize stack usage. Finally, the sorted array is displayed.
**output**=Enter the number of elements: 15
Generated Unsorted Array: 5 40 73 52 8 69 44 82 0 4 61 20 36 3 18 
Sorted Array: 0 3 4 5 8 18 20 36 40 44 52 61 69 73 82

------------------------------------------------------------------------------------------------------------------------------------------------------------------

**LAB 5**

**PROGRAM 1**
**OBJECTIVE**= write a code solve activity selection problem with three different selection criteria (start time , end time ,duration) and to find out which methods genrates maximum efficiency.
**working**=This program solves the Activity Selection Problem by randomly generating 20 activities with start and end times and sorting them based on start time, end time, and duration to determine which method selects the maximum number of non-overlapping activities. The sort() function arranges activities based on a chosen criterion, while selectActivities() applies a greedy approach to count the maximum activities that can be performed. The program prints the number of activities selected by each method in a tabular format, highlighting the best approach. Sorting by end time usually yields the optimal solution, as it prioritizes the earliest finishing activities, maximizing the selection.
**output**=
s.no  By Start Time  By End Time  By Duration  Max Activities
1       7           8           3           8
2       8           8           4           8
3       6           7           4           7
4       8           8           5           8
5       5           8           4           8
6       7           7           1           7
7       7           9           7           9
8       6           6           1           6
9       7           8           6           8........


**PROGRAM 2**
**OBJECTIVE**= To implement Dijkstra algo. to find single source sortest path to all vertex of a graph.
**working**=This program implements Dijkstra's algorithm to find the Single Source Shortest Path (SSSP) in a randomly generated weighted graph of 6 vertices. The adjacency matrix (cost[][]) is created randomly, where edges with weights greater than 10 are treated as non-existent (assigned 99), and diagonal elements are 0 (self-loops). The sssp() function initializes distances, selects the vertex with the minimum distance, and updates distances iteratively. It prints the cost matrix and the shortest distances from the user-defined source vertex (0-5) to all other vertices. The algorithm follows a greedy approach, ensuring optimal shortest paths.
**output**=Cost Matrix:
 0  99  99   0  99  99  
99   0  99  10  99  99  
99  99   0  99   7  99  
99  99   4   0  99  99  
99  99   4  99   0  99  
 5  99   3  99  99   0  
Enter the source vertex (0-5): 3
Shortest distances from source vertex 3:
99  99  4  0  11  99  


**PROGRAM 3**
**OBJECTIVE**= To find median element of an unsorted array without sorting it.
**wokring**=This program finds the median of an unsorted array using the QuickSelect algorithm, which is a variation of QuickSort optimized for finding the k-th smallest element in O(n) average time complexity. The partition() function selects a pivot (last element) and partitions the array around it. The quickSelect() function recursively finds the middle element if the array length is odd, or the average of the two middle elements if even. The program then prints the computed median efficiently without fully sorting the array.
**output**=int arr[] = {12, 3, 5, 7, 19, 26, 13, 2, 10, 15};
median = 11


**PROGRAM 4**
**OBJECTIVE**=To perform matrix multiplication using stresons method.
**wokring**=This program implements Strassen’s Matrix Multiplication Algorithm, which is an efficient divide-and-conquer method for multiplying two square matrices in O(n^log7) ≈ O(n^2.81) time complexity, faster than the traditional O(n³) algorithm. It recursively splits matrices into quadrants, computes seven intermediate matrices (M1-M7) using addition and subtraction, and then reconstructs the result. The strassenMultiply() function handles this process, while addMatrix() and subtractMatrix() perform matrix operations. The program multiplies an 8x8 matrix with itself and prints the resultant matrix.
**output**=
Resultant Matrix C (A x B):
204 176 156 144 140 144 156 176
176 204 176 156 144 140 144 156
156 176 204 176 156 144 140 144
144 156 176 204 176 156 144 140
140 144 156 176 204 176 156 144
144 140 144 156 176 204 176 156
156 144 140 144 156 176 204 176
176 156 144 140 144 156 176 204

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

**LAB 6**

**PROGRAM 1**
**OBJECTIVE**=To find minimum spannig tree of a graph using krushkal's algorithm.
**working**=This program implements Kruskal’s Algorithm using a min-heap and Union-Find (Disjoint Set Union, DSU) to find the Minimum Spanning Tree (MST) of a graph. The edge list is stored in a min-heap, where heapify(), buildheap(), and delete_min() maintain order, ensuring the smallest edge is always selected first. The Union-Find structure with path compression (find()) and union by rank (uni()) efficiently detects and merges connected components while avoiding cycles. The algorithm iterates until it selects (V-1) edges for the MST, printing the edges and their total cost. With a complexity of O(E log E), it efficiently computes the MST for a given graph
**output**=Minimum Spanning Tree edges:
3 -- 4 (Cost: 1)
0 -- 2 (Cost: 2)
1 -- 0 (Cost: 3)
2 -- 3 (Cost: 4)
Total Minimum Cost: 10


**PROGRAM 2**
**OBJECTIVE**= To find the spanning tree of a graph using prims's algorithm.
**working**=This program implements Prim’s Algorithm to find the Minimum Spanning Tree (MST) of a graph using greedy selection. It maintains an array of minimum key values (key[]) to pick the next minimum-weight edge and a boolean array (mstSet[]) to track included vertices. The function findMinVertex() selects the vertex with the smallest key value that is not yet in the MST. The algorithm starts from vertex 0, updating key[] values for adjacent vertices and selecting V-1 edges to construct the MST. Finally, the selected edges and their weights are printed. With a complexity of O(V²), this approach efficiently computes the MST for dense graphs. 
**Output**=
Edge    Weight
0 - 1   2
1 - 2   3
0 - 3   6
1 - 4   5

------------------------------------------------------------------------------------------------------------------------------------------------------------------
**LAB-7**

**PROGRAM 1**
**OBJECTIVE**=To find shortest path from each node of a graph to each other node.
**working**=This program implements the Floyd-Warshall Algorithm to find the All-Pairs Shortest Path (APSP) in a weighted graph with V vertices. It initializes the distance matrix with given edge weights and iteratively updates the shortest distances between all pairs of vertices using an intermediate vertex k. If a shorter path is found via k, it updates dist[i][j] = dist[i][k] + dist[k][j]. The algorithm runs in O(V³) time complexity, making it efficient for small to medium-sized graphs. Finally, the shortest distance matrix is printed, where INF represents unreachable pairs.
**output**=Shortest distances between every pair of vertices:
   0    3    7    5 
   2    0    6    4 
   3    1    0    5 
   5    3    2    0 


**PROGRAM 2**
**OBJECTIVE**=To implement multistage graph and find the shortest distance between source and sink using front substitution method.
**working**=This program finds the shortest path in a Directed Acyclic Graph (DAG) from a source (vertex 0) to a destination (vertex N-1). It uses Dynamic Programming (DP) by storing the minimum distance (fdist[]) from each node to the destination and backtracking with path[] to reconstruct the path. It iterates  backward from the destination, updating the shortest known distance based on reachable nodes. The time complexity is O(N²) for dense graphs. The program outpus the minimum cost and the path taken.
  **output**=Minimum cost from source to destination: 8
Path: 0 2 6 7 


**PROGRAM 3**
**OBJECTIVE**= To find no. of stages in a given multistage graph.
**working**=This program determines the number of stages in a multistage graph by traversing the adjacency matrix representation of the graph. It starts from the source node (0) and follows edges to count the number of intermediate stages until reaching the sink node. The function findStages() iterates through the adjacency matrix and counts transitions between nodes. The result includes two extra stages: one for the source and one for the sink. The approach works for layered graphs but assumes a direct topological structure. The time complexity is O(N²) in the worst case.
**output**=Number of stages in the multistage graph: 5

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
