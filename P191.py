#!/usr/bin/python

class Solution(object):
	def hammingWeight(self, n):
		"""
		:type n: int
		:rtype: int
		"""
		tester, count = 1, 0
		for _ in xrange(32):
			if tester & n != 0: 
				count += 1
				tester <<= 1
		return count
		
s = Solution()
print s.hammingWeight(2)