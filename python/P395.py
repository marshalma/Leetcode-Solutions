#!/usr/bin/python
import collections

class Solution(object):
	def longestSubstring(self, s, k):
		"""
		:type s: str
		:type k: int
		:rtype: int
		"""
		if not s: return 0
		hash1 = collections.Counter(s)
		hash2 = set([key for key in hash1 if hash1[key] < k])
		if not hash2: return len(s)
		if len(hash2) == len(hash1): return 0
		res, left = 0, 0
		for i in range(len(s)):
			if s[i] in hash2: 
				res = max(res, self.longestSubstring(s[left:i], k))
				left = i+1    
				continue
		res = max(res, self.longestSubstring(s[left:], k))
		return res
		
s = Solution()
print(s.longestSubstring("aaaaaaaaaaaaaaaabbbbbbbbbbbbaaaaaaabbbbbbbbbbbbcccccccccccdddddddddddddddddddeeeeeeeeeeeeeeefffffffffffffffgggggggggggggggggggghhhhhhhhhhhhhhhhiiiiiiiiiiiiiiiiiiiiiijjjjjjjjjjjjjjjjjjjjjjjjkkkkkkkkkkkkkkkkkkkk", 20))