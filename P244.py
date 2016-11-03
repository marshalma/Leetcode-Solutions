#!/usr/bin/python

class WordDistance(object):
	def __init__(self, words):
		"""
		initialize your data structure here.
		:type words: List[str]
		"""
		ht = {}
		for i,item in enumerate(words):
			if item in ht: ht[item].append(i)
			else: ht[item] = [i]
		self.n = len(words)
		self.ht = ht
		

	def shortest(self, word1, word2):
		"""
		Adds a word into the data structure.
		:type word1: str
		:type word2: str
		:rtype: int
		"""
		
		l1, l2 = self.ht[word1], self.ht[word2]
		i1, i2 = 0, 0
		res = abs(l1[0] - l2[0])
		while i1 != len(l1) and i2 != len(l2):
			res = min(res, abs(l1[i1] - l2[i2]))
			if l1[i1] < l2[i2]: i1 += 1
			else: i2 += 1
		return res

w = WordDistance(["practice", "makes", "perfect", "coding", "makes"])
print(w.shortest("coding", "practice"))
print(w.shortest("makes", "coding"))