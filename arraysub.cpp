// ARRAYSUB - Subarrays
// Simple sliding window with priority queue

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int arr[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  cin >> k;
  
  priority_queue<pair<int, int> > q;
  int l = 0;
  for (int e = 0; e < k-1; e++) q.push({arr[e], e}); // only up to k-2 b/c k-1 is done in loop
  
  pair<int, int> cmax;
  while (l <= n-k) {
    q.push({arr[l+k-1], l+k-1});
    cmax = q.top();
    while (cmax.second < l) { // pop all at the top which aren't in the window anymore
      q.pop();
      cmax = q.top();
    }
    cout << cmax.first;
    l++;
    if (l <= n-k) cout << " ";
  }
  cout << endl;
}
