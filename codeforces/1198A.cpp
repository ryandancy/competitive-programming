// 1198A - MP3
// First, note that the order of the elements does not matter.
// Also, the range of the elements (0 <= a_i <= 10^9) is too large to use a
// regular counting array, but instead we can sort the elements in O(n log n) time
// and count the number of equal elements next to each other in each block of equal elements.
// We build a "unique" array - we maintain an index u into an array unq (initialized to 0s),
// and for each i in a_i, we increment u only if a_i != a_{i-1}, then increment unq[u].
// For example, if a = [1, 1, 1, 2, 3, 3, 4, 4, 5], unq = [3, 1, 2, 2, 1].
// We then binary search for the largest value of K such that n*ceil(log2(K)) <= 8*I and
// use a sliding window to find the contiguous subarray of size K with the largest sum.
// Then the minimal number of elements to discard is n minus that largest sum.
// Overall, O(n log n).

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll arr[400000];
int unq[400000] = {0};

inline ll clog2(ll x) { // ceil(log_2(x))
  return 64 - __builtin_clzll(x) - ((x&(x-1)) == 0); // subtract 1 if power of 2
}

int main() {
  ll n, I;
  cin >> n >> I;
  I *= 8;
  
  if (n*clog2(n) <= I) {
    cout << "0\n";
    return 0;
  }
  
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr+n); // O(n log n)
  
  // build unique array - O(n)
  ll u = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && arr[i] != arr[i-1]) u++;
    unq[u]++;
  }
  // u is now max unique index, inclusive
  
  if (n*clog2(u+1) <= I) {
    cout << "0\n";
    return 0;
  }
  
  // find max value - O(log u) binary search
  // (in a real competition I'd just use O(u) brute-force search)
  ll l = 0, r = u+1;
  ll needed = -1;
  while (l <= r) {
    ll mid = (l+r)/2;
    ll v = n*clog2(mid);
    ll v1 = n*clog2(mid+1);
    if (v <= I && v1 > I) {
      needed = mid;
      break;
    } else if (v1 <= I) {
      l = mid+1;
    } else { // v > I
      r = mid;
    }
  }
  
  if (needed == -1) {
    // probably this?
    cout << "0\n";
    return 0;
  }
  
  // find subarray of size needed with largest sum - O(n) sliding window
  ll sum = 0;
  for (int i = 0; i < needed; i++) {
    sum += unq[i];
  }
  ll maxsum = sum;
  for (int i = 1; i < n-needed; i++) {
    sum -= unq[i-1];
    sum += unq[i+needed-1];
    maxsum = max(maxsum, sum);
  }
  
  // min possible changed is n - max possible same
  cout << n-maxsum << "\n";
}
