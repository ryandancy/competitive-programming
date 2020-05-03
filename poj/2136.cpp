#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[26]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  for (int i=0;i<4;i++){
    string s;
    getline(cin, s);
    for (int j=0;j<s.size();j++) {
      char c=s[j];
      if (c>='A'&&c<='Z') a[c-'A']++;
    }
  }
  int mxv=a[0];
  for (int i=1;i<26;i++) {
    if (a[i]>mxv) {
      mxv=a[i];
    }
  }
  for (int v=mxv;v>0;v--) {
    queue<int> vs;
    for (int i=0;i<26;i++){
      if (a[i]>=v) {
        vs.push(i);
      }
    }
    int c=0;
    while (vs.size()) {
      int f=vs.front(); vs.pop();
      while (c<f) {
        cout<<"  ";
        c++;
      }
      cout<<"*";
      c++;
      if (vs.size())cout<<" ";
    }
    cout<<"\n";
  }
  cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n";
}
