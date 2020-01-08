// 1203C - Paint the Digits
// Any partition will have everything < some digit as 1 and everything > as 2.
// We put each position in a vector and then loop through each digit to see if
// we can partition on it. O(n). Took way too long to write.
#include <bits/stdc++.h>
using namespace std;
vector<int> a[10];
void av(int &i, int &c) {
  if (c >= a[i].size()-1) {
    i++; c=0;
    while (a[i].size()==0&&i<10) i++;
  } else c++;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < 10; i++) a[i].clear();
    bool ndc=true;
    for (int i = 0; i < n; i++) {
      int d = s[i]-'0';
      a[d].push_back(i);
      if (i<n-1&&s[i]>s[i+1]) ndc=false;
    }
    if (ndc) {
      for (int i = 0; i < n; i++) cout << '1';
      cout << '\n';
      continue;
    }
    int i=0;
    while (a[i].size()==0) i++;
    int c=0;
    for (int f = 1; f < n; f++) {
      bool ok=true;
      for (int j = 0; j < i-1;) {
        while (j<i-1&&a[j].size()==0)j++;
        if (j>=i-1){break;}
        int nxt=j+1;
        while (a[nxt].size()==0 && nxt<=i-1)nxt++;
        if (nxt>i-1){break;}
        if (a[j].back()>a[nxt].front()) {
          cout << "-\n";
          goto nxt;
        }
        j=nxt;
      }
      if (!ok) {av(i,c);continue;}
      for (int j = i+1; j < 9;) {
        while (a[j].size()==0&&j<9)j++;
        if (j>=9){break;}
        int nxt=j+1;
        while (nxt<=9&&a[nxt].size()==0)nxt++;
        if (nxt>9){break;}
        if (a[j].back()>a[nxt].front()) {
          ok=false;
          break;
        }
        j=nxt;
      }
      if (!ok) {av(i,c);continue;}
      int lst=i-1;
      while (lst>=0&&a[lst].size()==0)lst--;
      if (lst>=0 && a[lst].back()>a[i][c]) {
        av(i,c);
        continue;
      }
      int nxt=i+1;
      while (nxt<10&&a[nxt].size()==0)nxt++;
      if (nxt<10 && c>0 && a[i][c-1]>a[nxt].front()) {
        av(i,c);
        continue;
      }
      int q[10]={0};
      for (int j = 0; j < n; j++) {
        int d = s[j]-'0';
        if (d<i) cout << "1";
        else if (d>i) cout << "2";
        else if (q[d]>=c) cout << "1";
        else cout << "2";
        q[d]++;
      }
      cout << '\n';
      goto nxt;
    }
    cout << "-\n";
    nxt:;
  }
}
