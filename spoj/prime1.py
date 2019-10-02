#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""PRIME1 - Prime Generator"""

from math import sqrt, ceil

# Read the input
cases = int(input())
bounds = [tuple(map(int, str.split(input()))) for _ in range(cases)]

# Handle the case where lower=1 by just incrementing lower
for bi, (lower, upper) in enumerate(bounds):
  if lower == 1:
    bounds[bi] = (2, upper)

# Find the top bound of everything
top_bound = max(upper for lower, upper in bounds)
k = int(sqrt(top_bound))

# Shifted sieve of Eratosthenes (see https://stackoverflow.com/a/19641049/8468108)
a = [True for _ in range(k - 1)] # sieve for primes < sqrt(top_bound)
bs = [[True for _ in range(upper - lower + 1)] for lower, upper in bounds] # sieves for primes in ranges

for i in range(2, k + 1):
  if a[i-2]:
    # regular sieve
    for j in range(i*i, k + 1, i): # i*i because 2*i, 3*i, ..., (i-1)*i already filtered out
      a[j-2] = False
    
    # sieve through each range at the same time
    for bi, (lower, upper) in enumerate(bounds):
      for j in range(max(i*ceil(lower/i), i*i), upper + 1, i):
        bs[bi][j-lower] = False

# Print it out
for bi, (lower, upper) in enumerate(bounds):
  b = bs[bi]
  for n, is_prime in enumerate(b):
    if is_prime:
      print(n + lower)
  if bi != len(bounds) - 1:
    print()
