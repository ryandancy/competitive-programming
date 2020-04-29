// Add to a range, query a single element.
// We use a single segment tree with leaves being array values and higher nodes
// being lazy updates. Top-down updates (to update all segments) and go top-down
// to update a single element on each query. O(q log n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll st[800001]={0}; // leaves are real, above are lazy updates
int n, o, q;

inline void process_update(int c) { // for upper nodes
  if (c>=o) return;
  st[2*c]+=st[c];
  st[2*c+1]+=st[c];
  st[c] = 0;
}

void update(int a, int b, ll v, int l=0, int r=o-1, int c=1) {
  if (l>r||r<a||l>b) return;
  process_update(c);
  int m=(l+r)/2;
  if (a<=l&&r<=b) {
    st[c] += v;
  } else {
    if (a<=m) update(a, b, v, l, m, 2*c);
    if (b>m) update(a, b, v, m+1, r, 2*c+1);
  }
}

ll get(int x) {
  int l=0, r=o-1, c=1;
  while (l<r) {
    process_update(c);
    int m=(l+r)/2;
    c *= 2;
    if (x<=m) r=m;
    else l=m+1, c++;
  }
  return st[c];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>q;
  o=1;
  while (o<n) o*=2;
  for (int i=0;i<n;i++) cin>>st[o+i];
  while (q--) {
    int t;
    cin>>t;
    if (t==1) {
      int a, b; ll u;
      cin>>a>>b>>u;
      update(a-1, b-1, u);
    } else {
      int k;
      cin>>k;
      cout<<get(k-1)<<'\n';
    }
  }
}
