from collections import defaultdict
n = int(input())
m = defaultdict(list)
rt = None
cs=[]
for i in range(n):
  s = input().split()
  cs.append(s[0])
  for t in s[3:]:
    m[t].append(s[0])
  if rt is None:
    rt = s[0]

bfs = [rt]
d = {rt: 1}
while bfs:
  a = bfs[0]
  del bfs[0]
  for nb in m[a]:
    if nb not in d:
      d[nb] = d[a]+1
      bfs.append(nb)

for c in sorted(cs):
  if c in d:
    print(d[c])
  else:
    print(0)
