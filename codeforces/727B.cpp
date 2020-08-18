// stupid annoying sloggish string manipulation
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  string s;
  cin>>s;
  int td=0,tc=0;
  for (int i=0;i<s.size();) {
    while (i<s.size()&&s[i]>='a'&&s[i]<='z') i++;
    list<int> pc, dg;
    int v=0, nd=0;
    while (i<s.size()&&!(s[i]>='a'&&s[i]<='z')) {
      if (s[i]=='.') {
        pc.push_back(v);
        dg.push_back(nd);
        v=0; nd=0;
      } else {
        v*=10;
        v+=s[i]-'0';
        nd++;
      }
      i++;
    }
    pc.push_back(v);
    dg.push_back(nd);
    int d=0,c=0;
    if (pc.size()>1&&dg.back()==2) {
      c=pc.back();
      pc.pop_back();
      dg.pop_back();
    }
    for (auto it=pc.begin();it!=pc.end();++it) {
      d*=1000;
      d+=*it;
    }
    tc+=c;
    td+=tc/100;
    tc%=100;
    td+=d;
  }
  list<int> l;
  if (td==0)l.push_back(0);
  while (td) {
    l.push_front(td%1000);
    td/=1000;
  }
  int i=0;
  for (auto it=l.begin();it!=l.end();++it,i++) {
    if (it==l.begin()) printf("%d",*it);
    else printf("%.3d",*it);
    if (i!=l.size()-1)printf(".");
  }
  if (tc!=0) {
    printf(".%.2d",tc);
  }
  printf("\n");
}
