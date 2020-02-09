// 1300B - Assigning to Classes
// The closest medians are just the two in the centre when sorted.
#include <bits/stdc++.h>
using namespace std;
int a[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    sort(a,a+2*n);
    cout << a[n]-a[n-1] << '\n';
  }
}
