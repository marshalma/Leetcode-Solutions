#!/usr/bin/python

class Solution(object):
	def multiply(self, A, B):
		"""
		:type A: List[List[int]]
		:type B: List[List[int]]
		:rtype: List[List[int]]
		"""
		m, n, t = len(A), len(A[0]), len(B[0])
		res = [[0 for _ in xrange(t)] for __ in xrange(m)]
		for i in xrange(n):
			for j in xrange(t):
				if B[i][j] == 0: continue
				for k in xrange(m):
					res[k][j] += A[k][i] * B[i][j]
					print res
		return res
		
s = Solution()
A = [[1,0,0],[-1,0,3]]
B = [[7,0,0],[0,0,0],[0,0,1]]

print s.multiply(A, B)