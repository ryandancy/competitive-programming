// 1283C - Friends and Gifts
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
pii a[200001];
vector<int> of, os, no;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i].second = x;
    if (x != 0) a[x].first = i;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].first && !a[i].second) of.push_back(i);
    else if (!a[i].first && a[i].second) os.push_back(i);
    else if (!a[i].first && !a[i].second) no.push_back(i);
  }
  assert(of.size() == os.size());
  for (int i = 0; i < of.size()-(no.size()==1); i++) {
    a[os[i]].first = of[i];
    a[of[i]].second = os[i];
  }
  if (no.size()==1) {
    a[os[os.size()-1]].first = no[0];
    a[no[0]].second = os[os.size()-1];
    a[no[0]].first = of[of.size()-1];
    a[of[of.size()-1]].second = no[0];
  } else {
    for (int i = 0; i < no.size(); i++) {
      int nx = (i+1)%no.size();
      a[no[i]].second = no[nx];
      a[no[nx]].first = no[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i].second << ' ';
  }
  cout << '\n';
}
