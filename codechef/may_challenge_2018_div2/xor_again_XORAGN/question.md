About:
Chef recently discovered a function XOR(), which computes the XOR of all elements of a sequence:
XOR(a1..n)=a1⊕a2⊕⋯⊕an.
Chef has a sequence A with size N. He generated a new sequence B with size N2 using the following formula:
BiN+j+1=(Ai+1+Aj+1)∀0≤i,j<N.
Compute the value of XOR(B).

Input:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output:
For each test case, print a single line containing one integer — the answer to the problem.