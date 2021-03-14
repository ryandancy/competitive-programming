#include <bits/stdc++.h>
typedef long long ll;

// A segment tree supports arbitrary O(log n) range queries with O(n log n) setup.
// Ranges are stored like this: (number are indices).
//                    0      
//               /         \ 
//            1               2
//          /   \           /   \ 
//        3       4       5       6
//       / \     / \     / \     / \ 
//      7   8   9   10  11  12  13  14
// arr: 1   2   3   4   5   6   7   8
// "Bottom up" traversal is simpler but doesn't allow arbitrary node combining functions.
