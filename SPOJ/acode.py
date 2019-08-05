#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""ACODE - Alphacode"""

import sys
sys.setrecursionlimit(6000)

memoized = {}
def combos_for_after(digits, n): # combos for the string after place value n
  if n in memoized:
    return memoized[n]
  
  if n >= len(digits):
    memoized[n] = 1
    return 1
  elif n == len(digits) - 1:
    memoized[n] = 0 if digits[n] == 0 else 1
    return memoized[n]
  elif digits[n] == 0:
    memoized[n] = 0
  elif digits[n] == 1:
    memoized[n] = combos_for_after(digits, n + 1) + combos_for_after(digits, n + 2)
  elif digits[n] == 2:
    if 0 <= digits[n + 1] <= 6:
      memoized[n] = combos_for_after(digits, n + 1) + combos_for_after(digits, n + 2)
    else:
      memoized[n] = combos_for_after(digits, n + 1)
  else:
    memoized[n] = combos_for_after(digits, n + 1)
  
  return memoized[n]

def do(digits):
  print(combos_for_after(digits, 0))

if __name__ == '__main__':
  while True:
    digits = input().strip()
    if digits == '0':
      break
    do(list(map(int, digits)))
    memoized = {}
