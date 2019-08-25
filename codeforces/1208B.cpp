// 1208B - Uniqueness
// At each index, we find the minimum size of segment to remove.
// Written during Manthan Codefest '19.
#include <bits/stdc++.h>
using namespace std;
int arr[2050];
unordered_set<int> seen;
unordered_map<int, int> nu, c;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i =0;i<n;i++) {
    cin >> arr[i];
    if (seen.count(arr[i])) {
      nu[arr[i]] = (nu[arr[i]]==0?2:nu[arr[i]]+1);
    }
    else seen.insert(arr[i]);
  }
  if (nu.size()==0) {cout << "0\n"; return 0;}
  int b=n;
  for (int s=0;s<n;s++) {
    bool m=false; c.clear(); int okc=0;
    for (int i=s;i<n;i++) {
      if (!nu.count(arr[i])) continue;
      c[arr[i]]++;
      if (c.size()==nu.size()) {
        m=true;
      }
      if (c[arr[i]]==nu[arr[i]]-1) okc++;
      if (okc==nu.size()&&m) {
        b=min(b, i-s+1);
        break;
      }
    }
  }
  cout << b << "\n";
}
