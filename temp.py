#!/usr/bin/env python
from random import randint
s = set()
with open('inp.txt', 'w') as f:
  f.write('100\n')
  for _ in range(100):
    a = randint(-30000, 30000)
    while a in s:
      a = randint(-30000, 30000)
    s.add(a)
    f.write(str(a) + '\n')
