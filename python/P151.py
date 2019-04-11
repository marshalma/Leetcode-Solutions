class Solution(object):
	def reverseWords(self, s):
		"""
		:type s: str
		:rtype: str
		"""
		word_list = s.lstrip().rstrip().split()
		word_list.reverse()
		return " ".join(word_list)
		
s = Solution()
print(s.reverseWords("  this is a nice day.  "))