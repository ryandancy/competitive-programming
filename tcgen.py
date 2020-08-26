#!/usr/bin/env python3

"""
Simple utility to automatically generate+run test cases, comparing bf.out and a.out's output.
bf.out is brute force program.
a.out is program to debug.
temp.py is test case generator.
Taken mostly from https://codeforces.com/blog/entry/44493.
"""

import os
import time

TL = 1

while True:
  os.system('./temp.py')
  start = time.time()
  os.system('./bf.out > bf.txt')
  elbf = time.time() - start
  start = time.time()
  os.system('./a.out > a.txt')
  ela = time.time() - start
  print(elbf, ela)
  if elbf > TL:
    print('TLE: bf')
    break
  if ela > TL:
    print('TLE: a')
    break
  if open('./bf.txt').read() != open('./a.txt').read():
    print('WA')
    break
