#!/usr/bin/python
import collections
class LRUCache(object):

	def __init__(self, capacity):
		"""
		:type capacity: int
		"""
		self.ordered_table = collections.OrderedDict()
		self.capacity = capacity

	def get(self, key):
		"""
		:rtype: int
		"""
		if key in self.ordered_table:
			res = self.ordered_table[key]
			del self.ordered_table[key]
			self.ordered_table[key] = res
			return res
		return -1

	def set(self, key, value):
		"""
		:type key: int
		:type value: int
		:rtype: nothing
		"""
		if key in self.ordered_table:
			del self.ordered_table[key]
			self.ordered_table[key] = value
			return
		
		if len(self.ordered_table) == self.capacity:
			self.ordered_table.popitem(last=False)
		
		self.ordered_table[key] = value
		
# tests		
s = LRUCache(5)
s.set(1,5)
s.set(2,5)
s.set(3,5)
s.set(4,6)
s.set(5,5)
s.set(2,3)
s.set(100,4)
print(s.get(1))
print(s.ordered_table)