#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll A,B,C;
  cin>>A>>B>>C;
  ld a=A,b=B,c=C;
  if (A==0) {
    if (B==0) {
      if (C==0) {
        printf("-1\n"); return 0;
      } else {
        printf("0\n"); return 0;
      }
    }
    printf("1\n%.10Lf\n",-c/b);
    return 0;
  }
  ll D=B*B-4*A*C;
  if (D>0) {
    ld d=D;
    if (a>0)printf("2\n%.10Lf\n%.10Lf\n",(-b-sqrtl(d))/(2*a),(-b+sqrtl(d))/(2*a));
    else printf("2\n%.10Lf\n%.10Lf\n",(-b+sqrtl(d))/(2*a),(-b-sqrtl(d))/(2*a));
  } else if (D==0) {
    printf("1\n%.10Lf\n",-b/(2*a));
  } else {
    printf("0\n");
  }
}
