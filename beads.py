#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""BEADS - Glass Beads"""

# Simple minimum search using Python's string manipulation and comparison functions
# Python allows string comparison with < and >, and apparently this is fast enough

N = int(input())
necklaces = [input() for _ in range(N)]

for necklace in necklaces:
  min_str = '~'
  min_idx = -1
  for i in range(len(necklace)):
    shifted = necklace[i:] + necklace[:i]
    if shifted < min_str:
      min_idx = i + 1
      min_str = shifted
  print(min_idx)
