#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin>>T;
  for (ll t=1;t<=T;t++) {
    cout<<"Case #" << t << ": ";
    string s;
    cin>>s;
    // bool as=true;
    // for (char c:s) if (c!=s[0]) {as=false;break;}
    // if (as) {cout<<s<<'\n';continue;}
    for (int i=0;i<s.length();i++) {
      cout<<s[i];
      bool lb=true; char nx;
      for (int j=i+1;j<s.length();j++) if (s[j]!=s[i]) {lb=false;nx=s[j];break;}
      if (lb) continue;
      if (i<s.length()-1&&(s[i]<s[i+1]||(s[i]==s[i+1]&&s[i]<nx))) cout<<s[i];
    }
    cout<<'\n';
  }
}
