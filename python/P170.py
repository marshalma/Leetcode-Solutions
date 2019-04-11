#!/usr/bin/python
import collections

class TwoSum(object):

	def __init__(self):
		"""
		initialize your data structure here
		"""
		self.hash_table = collections.Counter()
		self.cache = []

	def add(self, number):
		"""
		Add the number to an internal data structure.
		:rtype: nothing
		"""
		self.cache.append(number)
		

	def find(self, value):
		"""
		Find if there exists any pair of numbers which sum is equal to the value.
		:type value: int
		:rtype: bool
		"""
		if self.cache:
		    self.hash_table.update(self.cache)
		    self.cache = []
		
		for i in self.hash_table:
			if value - i in self.hash_table:
				if i != value - i: return True
				if self.hash_table[i] >= 2: return True
		return False

s = TwoSum()
s.add(0)
s.add(-1)
s.add(1)
print(s.find(0))