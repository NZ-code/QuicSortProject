# QuicSortProject
Position in sequence
Write and use a function (iterative or recursive) which finds a given element in the monotonically increasing OR decreasing sequence of (signed) integers. The function should return the index of the found element, or −1 if it doesn’t exist in the sequence.
(Indices in the sequence should be counted starting from 0)
Napisz i wykorzystaj funkcję (iteracyjną lub rekurencyjną) która szuka podanego elementu w monotonicznie rosnącej LUB malejącej sekwencji licz całkowitych (ze znakiem). Funkcja powinna zwrócić indeks, pod którym leży poszukiwany element w sekwencji, lub -1, jeśli element nie został odnaleziony.
(Indeksy są liczone zaczynając od 0)
Input
First line: m - number of test scenarios.
Next, for each test scenario, in consecutive lines:
n - number of elements in the sequence
the sequence itself (n numbers separated by spaces)
p - number of elements to be found
k0, ..., kp-1 - p elements to be found in the sequence.
Output
One line for each of p elements to be found for each of n test scenarios:
the index of the given element ki in the sequence, or -1 if ki was not found in the sequence.
Example
Input
3
5
5 4 3 2 1
1
5
10
1 2 4 8 16 32 64 128 256 512
2
128
129
5
-100 -50 -1 0 10000
1
-1

Output
0
7
-1
2
