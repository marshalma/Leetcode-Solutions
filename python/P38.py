class Solution(object):
	def countAndSay(self, n):
		"""
		:type n: int
		:rtype: str
		"""
		if n == 1: return "1"
		res = []
		str = self.countAndSay(n-1)
		for i in range(len(str)):
			num = str[i]
			count = 1
			while i+1 < len(str) and str[i+1] == str[i]: i, count = i+1, count+1
			i += 1
			res.append("{0}{1}".format(count, num))
		return "".join(res)
s = Solution()
s.countAndSay(3)