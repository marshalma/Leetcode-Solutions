from collections import deque
class Vector2D(object):

	def __init__(self, vec2d):
		"""
		Initialize your data structure here.
		:type vec2d: List[List[int]]
		"""
		self.vec2d = vec2d
		self.p, self.q = 0, deque()
		self.hasNext()
		

	def next(self):
	    if self.q: return self.q.popleft()
	    else: return None
		

	def hasNext(self):
		"""
		:rtype: bool
		"""
		if self.q: return True
		while self.p < len(self.vec2d) and len(self.vec2d[self.p]) == 0: self.p += 1
		if self.p == len(self.vec2d): return False
		for v in self.vec2d[self.p]: self.q.append(v)
		self.p += 1
		return True
	

a = [[1,2],[3],[]]
s = Vector2D(a)
while s.hasNext(): 
	print(s.next())
