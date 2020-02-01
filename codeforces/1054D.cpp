// 1054D - Changing Array
// An equivalent task is to minimize the segments with an XOR of 0. Consider the partial XOR sums
// of the array. To invert a single partial sum, we can invert the corresponding array element and
// the next element, and so we can convert between inverted and not inverted partial sums with
// impunity (as there is no limit on the times we can invert). Furthermore, if a segment has an XOR
// sum of 0, then because XOR is its own inverse, the XOR of the partial sums corresponding to each
// end of the array will be 0; i.e., they will be equal. Then if we have x non-zero equal partial
// sums, we have x choose 2 = x(x-1)/2 ranges with an XOR sum of 0. Then, if we have c non-zero partial
// sums that are all either equal or inverted to each other, we can minimize the XOR-0 segments by
// minimizing x(x-1)/2 + y(y-1)/2 where x and y represent non-inverted and inverted partial sums.
// The solution turns out (using the Method of Lagrange from MATH 119) to be x = y = c/2.
// Therefore, we perform this optimization for each group of partial sums to get the minimum number
// of XOR-0 segments. A special case is required for 0, as if a partial sum is 0, then we must add
// an XOR-0 segments; if we have x partial sums equal to 0, then we add x(x+1)/2 partial sums.
// Another optimization exists: if we have c partial sums equal to 0 or 0b1111..., then by the blessing
// of David Harmsworth, the solution is x=(c-1)/2, y=(c+1)/2, where x and y are the number of 0 and
// 0b1111... partial sums respectively. The algorithm based on this is O(n log n) because of a sort.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nt(a) (~(a)&((1<<k)-1))
ll n, k;
ll p[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll a;
  cin >> n >> k;
  cin >> p[0];
  for (int i = 1; i < n; i++) {
    cin >> a;
    p[i] = p[i-1]^a;
  }
  for (int i = 0; i < n; i++) {
    if ((p[i]&(1<<(k-1)))!=0) p[i]=nt(p[i]);
  }
  sort(p,p+n);
  ll i=0;
  ll r=0;
  while (i<n) {
    ll q=p[i];
    ll c=0;
    while (i<n&&p[i]==q) c++, i++;
    if (q==0) {
      // x=000, y=111, minimize x(x+1)/2+y(y-1)/2 with constraint x+y=c => x=(c-1)/2, y=(c+1)/2
      ll y=(c+1)/2;
      ll x=c-y;
      r+=(x*(x+1)+y*(y-1))/2;
    } else {
      // x=0XX, y=1XX, minimize binom(x,2)+binom(y,2)=(x(x-1)+y(y-1))/2 with constraint x+y=c => x=y=c/2
      ll x=c/2;
      ll y=c-x;
      r+=(x*(x-1)+y*(y-1))/2;
    }
  }
  cout << ((n*(n+1))/2 - r) << '\n';
}
