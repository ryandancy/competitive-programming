// FIBOSUM - Fibonacci Sum
// Let F(n) be the nth Fibonacci number and let P(n) be the sum of the 1st through nth Fibonacci numbers.
// Then it turns out that P(n) = F(n+2)-1.
// Thus F(N)+F(N+1)+...+F(M) = P(M)-P(N-1) = F(M+2)-F(N+1).
// We can calculate individual values F(n) in O(log n) by using matrices and powers,
// yielding overall O(T log M) time.

#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef long long ll;

struct mat { // 2x2 matrix
  ll tl, tr, bl, br;
  mat(ll tl, ll tr, ll bl, ll br) : tl(tl), tr(tr), bl(bl), br(br) {}
  mat operator*(mat rhs) {
    return mat(
      (this->tl*rhs.tl%MOD + this->tr*rhs.bl%MOD)%MOD,
      (this->tl*rhs.tr%MOD + this->tr*rhs.br%MOD)%MOD,
      (this->bl*rhs.tl%MOD + this->br*rhs.bl%MOD)%MOD,
      (this->bl*rhs.tr%MOD + this->br*rhs.br%MOD)%MOD);
  }
  mat operator^(int pow) {
    if (pow == 1) return *this;
    if (pow == 2) return (*this)*(*this);
    mat div2 = (*this)^(pow/2);
    div2 = div2*div2;
    if (pow % 2 == 1) div2 = div2 * (*this);
    return div2;
  }
};

ll fib(int n) {
  mat matrix = mat(0, 1, 1, 1)^n;
  return matrix.tr;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int T, N, M;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> N >> M;
    int res = (fib(M+2) - fib(N+1))%MOD;
    if (res < 0) res += MOD;
    cout << res%MOD << "\n";
  }
}
