#!/usr/bin/python

class Solution(object):
	def toHex(self, num):
		"""
		:type num: int
		:rtype: str
		"""
		if num == 0: return "0"
		subres = []
		table = {0:"0", 1:"1", 2:"2", 3:"3", 4:"4", 5:"5",6:"6",7:"7",8:"8",9:"9",10:"a",11:"b",12:"c",13:"d",14:"e",15:"f"}
		while num:
			subres.append(table[num & 15])
			num >>= 4
			num &= 0x0fffffff
		return "".join(list(reversed(subres)))

s = Solution()
print s.toHex(2**30)