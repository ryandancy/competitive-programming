from sys import exit

n, K, p = map(float, input().split())
n=int(n)
K=int(K)

def sk(k):
  if (k==0): return -float('inf')
  return (1-p)**k-1/k

def s(k):
  if (k==0): return -float('inf')
  return k*(1-p)**k-1

vs = list(map(sk, range(0, K+1)))
vs[0]=vs[1]=-float('inf')

mx=max(vs)
if mx<=0:
  print(n)
  exit(0)

q=sorted(list(range(2, K+1)), key=sk, reverse=True)

ml=q[0]
if n%ml==0:
  print(n-n*sk(ml))
  exit(0)

dp = [0, 0]
for i in range(2, 2000):
  bst=0
  for j in range(1,i):
    bst=max(bst,dp[j]+dp[i-j])
  if s(i)>=0:
    bst=max(bst,s(i))
  dp.append(bst)

if n<=2000:
  print(n-dp[n])
  exit(0)

nml=(n-2000)//ml+((n-2000)%ml!=0)
v=nml*s(ml) + dp[n-nml*ml]
print(n-v)
