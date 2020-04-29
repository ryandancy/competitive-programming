// Simple range xor queries with a static segment tree in O(n log n + q log n).
// Can also be done with a BIT. Identical to RSQ except with XOR, and single element
// update would be identical too, using xor to remove too (or just recompute like
// with min).
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll st[4000001]; // quadruple size + 1 is safest
int n, o, q;

ll sum(int a, int b) {
  a += o, b += o;
  ll res = 0;
  while (a <= b) {
    if (a%2 == 1) res ^= st[a++];
    if (b%2 == 0) res ^= st[b--];
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
  
  // input the array in the leaves (they are their own xor)
  for (int i = 0; i < n; i++) cin>>st[o+i];
  
  // build the rest of the segment tree (combine=xor)
  for (int i = o/2; i > 0; i /= 2) {
    for (int j = i; j < 2*i; j++) {
      st[j] = st[2*j] ^ st[2*j+1];
    }
  }
  
  // process queries in O(q log n)
  int a, b;
  while (q--) {
    cin>>a>>b;
    cout<<sum(a-1, b-1)<<'\n';
  }
}
