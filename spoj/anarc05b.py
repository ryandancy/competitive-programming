#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""ANARC05B - The Double HeLiX"""

'''
Algorithm:

We iterate through the numbers in the first sequence, keeping track of their sum.
For each number, we binary search for the number in the second sequence.
If the number is found in the second sequence, we compare the current sum of the
numbers in the first sequence to the sum of the numbers in the second sequence
since the last intersection. The larger is added to the maximal path sum. The
common number is also added, since that is unavoidable. We then clear the running
sum of numbers in the second sequence to 0.

This algorithm works except for the numbers after the last intersection. To get
around this, we add a "flag" value greater than the maximum value of the elements
of the sequences (10000) to the end of both sequences in order to trigger the
intersection code. We then subtract the flag value from the final result.
'''

FLAG = 999999999

def binary_search(seq, num):
  # Binary search: return the index of num in seq, or -1 if it's not found
  lo = 0 # inclusive
  hi = len(seq) - 1 # inclusive
  while hi >= lo:
    guess_idx = (lo + hi) // 2
    guess = seq[guess_idx]
    if num == guess:
      return guess_idx
    elif num > guess:
      lo = guess_idx + 1
    elif num < guess:
      hi = guess_idx - 1
  return -1

def max_path(seq1, seq2):
  # Add a flag value for an intersection at the end
  seq1.append(FLAG)
  seq2.append(FLAG)
  
  max_sum = 0
  
  current_seq1_node = 0
  last_seq2_node_idx = 0
  for num in seq1:
    seq2_idx = binary_search(seq2, num)
    if seq2_idx == -1:
      current_seq1_node += num
    else:
      # Intersection: pick the higher-valued node
      current_seq2_node = sum(seq2[last_seq2_node_idx:seq2_idx])
      
      max_sum += num + max(current_seq1_node, current_seq2_node)
      
      last_seq2_node_idx = seq2_idx + 1
      current_seq1_node = 0
  
  # The FLAG was added as the final intersection - remove it
  return max_sum - FLAG

if __name__ == '__main__':
  try:
    while True:
      seq1 = input()
      if seq1 == '0':
        break
      
      # Ignore the length of the sequences
      seq1 = list(map(int, seq1.split()))[1:]
      seq2 = list(map(int, input().split()))[1:]
      print(max_path(seq1, seq2))
  except EOFError:
    pass
