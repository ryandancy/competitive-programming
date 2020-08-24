s=input()
mx=eval(s)
m=[-1]+[i for i, v in enumerate(s) if v=='*']+[len(s)]
for i, a in enumerate(m):
  for b in m[i+1:]:
    t = s[:a+1] + '(' + s[a+1:b] + ')' + s[b:]
    mx=max(mx,eval(t))
print(mx)
