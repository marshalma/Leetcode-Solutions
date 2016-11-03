#!/usr/bin/python

class Solution(object):
	def decodeString(self, s):
		"""
		:type s: str
		:rtype: str
		"""
		self.res, self.i = [], 0
		def decodeRec(s):
			res = []
			while self.i < len(s):
				if s[self.i] == "]": 
					self.i += 1
					return res
				elif s[self.i].isalpha():
					res.append(s[self.i])
					self.i += 1
				elif s[self.i].isdigit():
					i = self.i
					while s[i].isdigit(): i += 1
					mul = int(s[self.i:i])
					self.i = i+1
					subres = decodeRec(s)
					res += mul * subres
			self.res += res
		decodeRec(s)
		return "".join(self.res)

s = Solution()
print(s.decodeString("2[abc]3[cd]ef"))