def ispal(t):
  return t==t[::-1]
def main(s):
  if len(set(s))==1:
    return "Impossible"
  for i in range(1,len(s)):
    if s[i:]+s[:i] != s and ispal(s[i:]+s[:i]):
      return 1
  if len(s)%2==1 and len(set(s[:len(s)//2]+s[len(s)//2+1:]))==1:
    return "Impossible"
  return 2
print(main(input()))
