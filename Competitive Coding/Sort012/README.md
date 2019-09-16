# Sort Array of 0s, 1s and 2s

Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

## Solutions

### A. Bad_Sort.cpp

We count the number of elements of 0 1 and 2 respectively and output accordingly to their count.

This defeats the purpose of solving the problem where the array is already given and is needed to solve via Dutch flag problem. (3-way sorting)

### B. Good_sort.cpp

We solve the question by using dutch flag way. We keep pointers for 0s and 2s. We need to closely understand the relation between low , mid and high pointers.

 <--- 0 --- low --- 1 --- mid --- ? --- high --- 2 --- >

 The intricate complicacies of the problem are left for the reader to understand, given the code.

