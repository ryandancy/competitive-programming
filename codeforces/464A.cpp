// backtracking and crap in O(n^2)
#include <bits/stdc++.h>
using namespace std;
int b[1000], p, n;
bool attempt(int s, bool fc) {
  if (s==n) return !fc;
  int fb1=-1,fb2=-1;
  if (s>0)fb1=b[s-1];
  if (s>1)fb2=b[s-2];
  if (b[s]!=fb1&&b[s]!=fb2&&attempt(s+1,fc)) return true;
  b[s]++;
  while (b[s]<p&&(b[s]==fb1||b[s]==fb2))b[s]++;
  if (b[s]==p) return false;
  for (int i=s+1;i<n;i++)b[i]=0;
  return attempt(s+1,false);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>n>>p>>s;
  for (int i=0;i<n;i++) b[i]=s[i]-'a';
  if (attempt(0,true)) {
    for (int i=0;i<n;i++) {
      cout<<(char)(b[i]+'a');
    }
    cout<<'\n';
  } else cout<<"NO\n";
}
