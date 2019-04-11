class Solution(object):
	def lengthOfLongestSubstring(self, s):
		"""
		:type s: str
		:rtype: int
		"""
		if len(s) == 0: return 0
		last_appear = {}
		p, res = 0, 0
		for i,ch in enumerate(s):
		    if ch in last_appear:
		        p = last_appear[ch] + 1
		    last_appear[ch] = i
		    res = max(res, i - p + 1)
		return res
	
s = Solution()
print(s.lengthOfLongestSubstring("pwwkew"))