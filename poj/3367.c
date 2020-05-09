// Holy crap with the optimizations needed to get POJ to accept this!
// * scanf/printf
// * use manual array stacks/queues instead of std::stack and std::queue
// * rewrite the whole thing in C
// * use an array for the right element rather than an explicit malloc'd tree
// * populate the string backwards rather than printf each char from a stack
// Only after all of this would POJ not give TLE!
#include <stdio.h>
char s[20000];
char *r[20000] = {NULL};
char *st[20000]; int sts;
char *q[20000]; int ql, qr;
char rs[20000]; char *rsp;
int T; char *c, *rt;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    sts = ql = qr = 0;
    rsp = rs+20000;
    *--rsp = '\0';
    for (c = s; *c; c++) {
      if (*c >= 'A' && *c <= 'Z') {
        --sts;
        r[c-s] = st[--sts];
      }
      rt = st[sts++] = c;
    }
    q[qr++] = rt;
    while (qr - ql) {
      c = q[ql++];
      *--rsp = *c;
      if (*c >= 'A' && *c <= 'Z')  {
        q[qr++] = r[c-s];
        q[qr++] = c-1;
      }
    }
    printf("%s\n", rsp);
  }
}
