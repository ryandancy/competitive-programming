#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin>>s;
  int n=s.size();
  if (n%2)return cout<<"No\n",0;
  stack<char> st;
  for (int i=0;i<n;i++){
    if (st.size()&&s[i]==st.top())st.pop();
    else st.push(s[i]);
  }
  cout<<(st.empty()?"Yes\n":"No\n");
}
