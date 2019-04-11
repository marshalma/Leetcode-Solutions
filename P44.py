#!/usr/bin/python

class Solution(object):
	def trap(self, height):
		"""
		:type height: List[int]
		:rtype: int
		"""
		def subtrap(height, start):
			if start == len(height): return 0
			res = 0
			highest_idx = start
			for i in xrange(start+1, len(height)):
				if height[i] >= height[highest_idx]:
					for j in xrange(highest_idx, i):
						res += height[highest_idx]-height[j]
					highest_idx = i
			else:
				res += subtrap(height, highest_idx+1)
			return res
					
		return subtrap(height, 0)

s = Solution()
print s.trap([0,1,0,2,1,0,1,3,2,1,2,1,0])