// 600A - Extract Numbers
// Solved in ~20 minutes with 1 WA (sigh)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string x;
  cin >> x;
  string a, b;
  int i = 0, j;
  bool hn=false, hw=false;
  j = x.find_first_of(",;");
  if (j == string::npos) j = x.size();
  while (1) {
    string c = x.substr(i, j-i);
    bool f = false;
    for (char d : c) {
      if (d < '0' || d > '9') {f=true; break;}
    }
    if (!f&&c.size()>1&&c[0]=='0')f=true;
    if (c.size()==0)f=true;
    if (f) b += c, b += ',', hw=true;
    else a += c, a += ',', hn=true;
    i = j+1;
    if (i > x.size()) break;
    j = x.find_first_of(",;", i);
    if (j == string::npos||j<0) j = x.size();
  }
  a=a.substr(0, a.size()-1);
  b=b.substr(0, b.size()-1);
  if (hn) cout << '"' << a << '"' << endl;
  else cout << "-\n";
  if (hw) cout << '"' << b << '"' << endl;
  else cout << "-\n";
}
