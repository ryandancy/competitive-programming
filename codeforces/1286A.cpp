// 1286A - Garland
// I wrote this during the contest but submitted an old version, sigh
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[100], p[100];
bool rc(pii& a, pii& b) {
  return (a.second-a.first<b.second-b.first);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = x;
    p[i] = (x==0?0:x%2+1);
  }
  int l[3] = {0};
  for (int i = 1; i <= n; i++) {
    bool c = false;
    for (int j = 0; j < n; j++) {
      if (a[j] == i) {c = true; break;}
    }
    if (!c) {
      l[i%2+1]++;
    }
  }
  if (l[1]+l[2]==n) {
    cout << (n==1?0:1) << '\n';
    return 0;
  }
  vector<pii> be;
  int ly=-1, li=-1; int rn=0;
  for (int i = 0; i < n; i++) {
    if (p[i]==0) {
      rn++;
    } else {
      if (rn>0) {
        if (ly != -1 && ly%2==p[i]%2) be.push_back({li,i});
        rn=0;
      }
      ly=p[i];
      li=i;
    }
  }
  sort(be.begin(),be.end(),rc);
  for (pii& x : be) {
    int o=p[x.first];
    if (l[o]>=(x.second-x.first-1)) {
      l[o]-=(x.second-x.first-1);
      for (int i = x.first+1; i <= x.second-1; i++) {
        p[i] = o;
      }
    }
  }
  rn=0;
  int o=p[0]; int k=0;
  for (; k < n && p[k]==0; k++) {
    rn++;
  }
  o=p[k];
  if (rn && l[o] >= rn) {
    l[o]-=rn;
    for (int i = 0; i < rn; i++) {
      p[i] = o;
    }
  }
  rn=0;
  o=p[n-1];
  for (k = n-1; k>=0 && p[k]==0; k--) {
    rn++;
  }
  o=p[k];
  if (rn && l[o] >= rn) {
    l[o] -= rn;
    for (int i = n-1; i > n-rn-1; i--) {
      p[i]=o;
    }
  }
  // be.clear();
  int cp=0;
  for (int i = 0; i < n-1; i++) {
    if (p[i] && p[i+1] && p[i] != p[i+1]) cp++;
  }
  ly=-1, li=-1, rn=0;
  for (int i = 0; i < n; i++) {
    if (p[i]==0) {
      rn++;
    } else {
      if (rn>0) {
        if (ly==-1) {
          cp++;
        } else if (ly%2==p[i]%2) cp+=2;
        else cp++;
        rn=0;
      }
      ly=p[i];
      li=i;
    }
  }
  if (p[n-1]==0)cp++;
  cout << cp << '\n';
}
