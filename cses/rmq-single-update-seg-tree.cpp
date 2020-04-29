// Single update + range min queries with a segment tree in O(n log n + q log n).
// CAN'T actually be done (as easily) with a BIT.
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll st[4000001]; // double size + 1
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

void update(int a, ll v) {
  a += o;
  st[a] = v;
  a /= 2;
  while (a > 0) {
    st[a] = min(st[2*a], st[2*a+1]);
    a /= 2;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin>>n>>q;
  
  // compute offset of leaves
  o=1;
  while (o<n) o*=2;
  
  // input the array in the leaves (they are their own min)
  // we *could* use update here to skip the building part
  for (int i = 0; i < n; i++) cin>>st[o+i];
  
  // build the rest of the segment tree (combine=min)
  for (int i = o/2; i > 0; i /= 2) {
    for (int j = i; j < 2*i; j++) {
      st[j] = min(st[2*j], st[2*j+1]);
    }
  }
  
  // process queries in O(q log n)
  int t, a, b;
  while (q--) {
    cin>>t>>a>>b;
    if (t==1) {
      update(a-1, b);
    } else {
      cout<<get_min(a-1, b-1)<<'\n';
    }
  }
}
