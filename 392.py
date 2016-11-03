#!/usr/bin/python

class Solution(object):
	def isSubsequence(self, s, t):
		"""
		:type s: str
		:type t: str
		:rtype: bool
		"""
		j = 0
		for i,ch in enumerate(s):
			if j >= len(t): return False
			while j < len(t) and t[j] != ch: j += 1
			j += 1
		return True

s = Solution()
print s.isSubsequence("abc ", "ahebgdc ")