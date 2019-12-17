// 1272D - Remove One Element
// The idea is to split the array into lengths of increasing subarrays,
// then see if we can combine the lengths.
// We find the l lengths in O(n), then do O(l) passes for the size of each
// length, trying to coalesce by removing peaks, and trying to coalesce by
// removing troughs. Total time complexity: O(n).
#include <bits/stdc++.h>
using namespace std;
int a[200000];
int sts[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ns = 1;
  sts[0] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i-1] >= a[i]) sts[ns++] = i;
  }
  sts[ns++] = n;
  int b = 1;
  for (int i = 1; i < ns; i++) {
    if (sts[i]-sts[i-1]>b) b = sts[i]-sts[i-1];
  }
  for (int i = 1; i < ns-1; i++) { // peaks
    if (a[sts[i]-2]<a[sts[i]]) {
      if (sts[i+1]-sts[i-1]-1>b) b = sts[i+1]-sts[i-1]-1;
    }
  }
  for (int i = 1; i < ns-1; i++) { // troughs
    if (a[sts[i]-1]<a[sts[i]+1]) {
      if (sts[i+1]-sts[i-1]-1>b) b = sts[i+1]-sts[i-1]-1;
    }
  }
  cout << b << "\n";
}
