#!/usr/bin/env python3

"""
Simple utility to automatically generate+run test cases, comparing bf.out and a.out's output.
bf.out is brute force program.
a.out is program to debug.
temp.py is test case generator.
Taken mostly from https://codeforces.com/blog/entry/44493.
"""

import os

while True:
  os.system('./temp.py')
  os.system('./bf.out > bf.txt')
  os.system('./a.out > a.txt')
  if open('./bf.txt').read() != open('./a.txt').read():
    print('WA')
    break
