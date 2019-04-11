import collections

class Solution(object):
	def firstUniqChar(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		hash = collections.Counter(s)
		for i,c in enumerate(s):
			if hash[c] == 1: return i
		return -1

s = Solution()
print(s.firstUniqChar("aabbcc"))