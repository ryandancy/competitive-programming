#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin>>s, s!="0") {
    int n=s.size();
    ll dp=0, ldp=1, lldp;
    for (int i=0;i<n;i++){
      if (s[i]!='0') dp+=ldp;
      if (i>0&&(s[i-1]=='1'||(s[i-1]=='2'&&s[i]>='0'&&s[i]<='6'))) dp+=lldp;
      lldp=ldp, ldp=dp, dp=0;
    }
    cout<<ldp<<'\n';
  }
}
