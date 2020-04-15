#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  int ng=1;
  int l;
  cin>>l;
  for (int i=0;i<n-1;i++){
    int x;
    cin>>x;
    if (x!=l)ng++;
    l=x;
  }
  cout<<ng<<'\n';
}
