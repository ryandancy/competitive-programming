// 1283D - Christmas Trees
// Just assign to each side of each tree in order until we can't anymore.
// To avoid looping over ones that can't have any left, we represent it
// as a list and remove ones with no possible spaces left. O(n+m).
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef long long ll;
ll tp[200000];
ll lp[200000]={0}, rp[200000]={0}, l[200000]={0}, r[200000]={0};
list<int> ls;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int nt, nh;
  cin >> nt >> nh;
  for (int i = 0; i < nt; i++) cin >> tp[i];
  sort(tp,tp+nt);
  for (int i = 0; i < nt; i++) {
    if (i==0) lp[i] = INF;
    else lp[i] = (tp[i] - tp[i-1]) / 2;
    if (i==nt-1) rp[i] = INF;
    else rp[i] = (tp[i+1] - tp[i] - 1) / 2;
    ls.push_back(i);
  }
  int hl=nh;
  auto it = ls.begin();
  auto e = ls.end();
  while (hl) {
    int s = *it;
    if (lp[s]) lp[s]--, l[s]++, hl--;
    if (hl && rp[s]) rp[s]--, r[s]++, hl--;
    if (!lp[s] && !rp[s]) {
      it = ls.erase(it);
      e = ls.end();
    } else ++it;
    if (it == e) it = ls.begin();
  }
  ll rs = 0;
  for (int i = 0; i < nt; i++) {
    rs += l[i]*(l[i]+1)/2;
    rs += r[i]*(r[i]+1)/2;
  }
  cout << rs << '\n';
  for (int i = 0; i < nt; i++) {
    for (int j = l[i]; j > 0; j--) {
      cout << tp[i]-j << ' ';
    }
    for (int j = 1; j <= r[i]; j++) {
      cout << tp[i]+j << ' ';
    }
  }
  cout << '\n';
}
