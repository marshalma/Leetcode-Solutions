#!/usr/bin/python

from collections import defaultdict
class Solution(object):
	def reconstructQueue(self, people):
		"""
		:type people: List[List[int]]
		:rtype: List[List[int]]
		"""
		people.sort()
		keys = set()
		table = defaultdict(list)
		for p in people:
			keys.add(p[0])
			table[p[0]].append(p)
		
		keys_sort = list(sorted(keys))
		res = []
		for v in reversed(keys_sort):
			for p in table[v]:
				res.insert(p[1], p)
		return res
		
s = Solution()
q = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
print s.reconstructQueue(q)