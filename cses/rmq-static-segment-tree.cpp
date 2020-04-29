// Simple range min queries with a static segment tree in O(n log n + q log n).
// Can also be done with a BIT.
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll st[4000001]; // quadruple size + 1 is safest
int n, o, q;

ll get_min(int a, int b) {
  a += o, b += o;
  ll res = st[a];
  while (a <= b) {
    if (a%2 == 1) res = min(res, st[a++]);
    if (b%2 == 0) res = min(res, st[b--]);
    a /= 2, b /= 2;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>n>>q;
  
  // compute offset of leaves
  o=1;
  while (o<n) o*=2;
  
  // input the array in the leaves (they are their own min)
  for (int i = 0; i < n; i++) cin>>st[o+i];
  
  // build the rest of the segment tree (combine=min)
  for (int i = o/2; i > 0; i /= 2) {
    for (int j = i; j < 2*i; j++) {
      st[j] = min(st[2*j], st[2*j+1]);
    }
  }
  
  // process queries in O(q log n)
  int a, b;
  while (q--) {
    cin>>a>>b;
    cout<<get_min(a-1, b-1)<<'\n';
  }
}
