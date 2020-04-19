#!/usr/bin/env python3

"""
Another simple utility to automatically generate+run test cases.
a.out is program to debug.
temp.py is test case generator.
valid.py is output validator, reading from inp.txt and o.txt.
"""

import os

while True:
  a = os.system('./temp.py')
  b = os.system('./a.out < inp.txt > o.txt')
  c = os.system('./valid.py > v.txt')
  if open('v.txt', 'r').read().strip() != 'OK':
    print('WA')
    break
  if a or b or c:
    print('Nonzero exit code:', a, b, c)
    break
