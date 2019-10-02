#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""CFRAC - Continuous Fractions"""

from itertools import count

def continued_fraction(p, q):
  result = []
  while q != 0:
    n, m = divmod(p, q)
    result.append(n)
    p, q = q, m
  if result[-1] == 1:
    result = result[:-1]
  else:
    result[-1] -= 1
  return result # 1 on end is implied

def pretty_print(cfrac):
  from_right = [1] # positions of each's leftmost character from right (in reverse order)
  for n in reversed(cfrac):
    from_right.append(from_right[-1] + len(str(n)) + 3) # 3 for ".+."
  
  overall_width = from_right[-1]
  
  for i, n in enumerate(cfrac):
    fr = from_right[-i-1]
    next_width = from_right[-i-2]
    initial_dots = overall_width - fr + len(str(n)) + 3 + next_width//2
    if next_width % 2 == 0:
      initial_dots -= 1 # extra dot goes to the right
    print('.' * initial_dots + '1' + '.' * (overall_width - initial_dots - 1))
    print('.' * (overall_width - fr) + str(n) + '.+.' + '-' * (fr - len(str(n)) - 3))
  
  print('.' * (overall_width - 1) + '1')

for i in count(1):
  p, q = map(int, input().split())
  if (p, q) == (0, 0):
    break
  print('Case %d:' % i)
  print('%d / %d' % (p, q))
  pretty_print(continued_fraction(p, q))
