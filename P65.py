import re

class Solution(object):
	def isNumber(self, s):
		s = s.rstrip(' ').strip(' ')
		return len(s) > 0 and re.match("^(-|\+)?((\d+)|((\d)*(\.)(\d)+)|((\d)+(\.)(\d)*))(e(-|\+)?(\d)+)?$", s) is not None
	
s = Solution()
print(s.isNumber("+.8"))