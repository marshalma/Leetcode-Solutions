#!/usr/bin/python
import collections

class Solution(object):
	def __init__(self):
		self.p = 0
		self.buffer = collections.deque()
		
	def read(self, buf, n, f):
		"""
		:type buf: Destination buffer (List[str])
		:type n: Maximum number of characters to read (int)
		:rtype: The number of characters read (int)
		"""
		_len, tmp = 0, [""] * 4
		while _len < n and self.buffer:
			buf[self.p + _len] = self.buffer.popleft()
			_len = _len+1
		while _len < n and len(self.buffer) != 0:
			tmp = [""] * 4
			this_num = read4(tmp, f)
			buf[self.p+_len: self.p+_len+this_num] = tmp
			_len += this_num
			if this_num == 0: 
				self.p += _len
				return _len
		if _len > n:
			for item in [x for x in tmp if len(x) > 0][n-_len:]:
				self.buffer.append(item)
		self.p += n
		return n

def read4(tmp, f):
	f.
	
f = open("P158test.txt", "r")
s = Solution()
buf = ['', '', '', '', '']
s.read(buf, 1)
s.read(buf, 2)