#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""ACMAKER - ACM (ACronymMaker)"""

def do(insignificants, acronym, words):
  # convert words to a list of letters in the acronym in each word, ignoring insignificant words
  swletters = [[letter for letter in word if letter in acronym] # "significant word letters"
                for word in words if word not in insignificants]
  
  # DP array: [letters from start of acronym][sword][letters from start of sword][this_word_ok]
  # -> ways to form that part of acronym; "sword" = significant word (a valid acronym!)
  dp = [[[[None, None] for _ in sword] for sword in swletters] for _ in acronym]
  def ways(soacronym=0, sword=0, soletters=0, this_word_ok=False):
    try:
      if soletters >= len(swletters[sword]):
        if not this_word_ok:
          # if we try to skip to the next word without taking one in this word, it's invalid
          return 0
        
        # skip to the next word
        return ways(soacronym, sword + 1, 0, False)
      
      if dp[soacronym][sword][soletters][this_word_ok] is not None:
        return dp[soacronym][sword][soletters][this_word_ok]
    except IndexError:
      # went off the end of the words
      return 0
    
    # here we add the combos for taking the letter, we add not those for not taking it later
    if acronym[soacronym] == swletters[sword][soletters]:
      if soacronym == len(acronym) - 1:
        # if we take the last letter in the acronym, we have to be on the last word
        dp[soacronym][sword][soletters][this_word_ok] = int(sword == len(swletters) - 1)
      else:
        # just advance to next letter
        dp[soacronym][sword][soletters][this_word_ok] = ways(soacronym + 1, sword, soletters + 1, True)
    else:
      # can't take the letter because it doesn't fit the acronym
      dp[soacronym][sword][soletters][this_word_ok] = 0
    
    # don't take this letter
    dp[soacronym][sword][soletters][this_word_ok] += ways(soacronym, sword, soletters + 1, this_word_ok)
    
    return dp[soacronym][sword][soletters][this_word_ok]
  
  num_ways = ways()
  if num_ways:
    print(acronym.upper(), 'can be formed in', num_ways, 'ways')
  else:
    print(acronym.upper(), 'is not a valid abbreviation')

if __name__ == '__main__':
  while True:
    num_insignificant = int(input())
    if num_insignificant == 0:
      # single 0 terminates input
      break
    insignificants = [input() for _ in range(num_insignificant)]
    
    while True:
      line = input()
      if line == 'LAST CASE': # terminates cases
        break
      
      acronym, *words = line.split()
      do(insignificants, acronym.lower(), words)
