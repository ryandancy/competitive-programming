// 466C - Number of Ways
// The sum of the subarrays is always S/3 where S is the sum of the whole array
// We precompute for each i, the number of suffixes of the array with sum equal
// to S/3 and starting at i or greater.
// Then we iterate to find prefixes with sum S/3; on finding prefix ending at i, we add
// the number of suffixes starting at i+2 or greater.
// If we find a prefix and a suffix with at least 1 element in between, the remainder
// *must* have the same sum since prefix and suffix are both S/3 and sum of whole array is S.
// In this way we obtain an O(n) solution.

#include <iostream>

using namespace std;

typedef long long ll;

int arr[500000];
ll sums[500001]; // number of suffixes of array with sum S/3 from i to n

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  
  // looking for sum/3, so sum not divisible by 3 can't have any
  if (sum % 3 != 0) {
    cout << "0\n";
    return 0;
  }
  
  ll find = sum / 3;
  
  // precompute suffixes
  ll fend = 0;
  sums[n] = 0;
  for (int i = n-1; i >= 0; i--) {
    fend += arr[i];
    sums[i] = sums[i+1];
    if (fend == find) sums[i]++;
  }
  
  // on each prefix, add relevant suffixes
  ll res = 0, fbeg = 0;
  for (int i = 0; i < n-2; i++) {
    fbeg += arr[i];
    if (fbeg == find) res += sums[i+2];
  }
  
  cout << res << endl;
}
