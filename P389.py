import collections
class Solution(object):
	def findTheDifference(self, s, t):
		"""
		:type s: str
		:type t: str
		:rtype: str
		"""
		hash1 = collections.Counter(s)
		hash2 = collections.Counter(t)
		for k in hash2:
			if k not in hash1: return k
			elif hash2[k] != hash1[k]: return k
s = Solution()
print(s.findTheDifference("abc", "cbae"))