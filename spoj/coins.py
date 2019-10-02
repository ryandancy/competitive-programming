#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""COINS - Bytelandian gold coins"""

# Simple DP

memoized = {1: 1, 0: 0}
def value(n):
  if n not in memoized:
    memoized[n] = max(n, value(n//2) + value(n//3) + value(n//4))
  return memoized[n]

if __name__ == '__main__':
  try:
    while True:
      n = int(input())
      print(value(n))
  except EOFError:
    pass
