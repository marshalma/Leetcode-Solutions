class Solution(object):
	def maxRotateFunction(self, A):
		"""
		:type A: List[int]
		:rtype: int
		"""
		sum_of_A, n = sum(A), len(A)
		subres = 0
		for i in range(n):
			subres += i * A[i]
		res = subres
		for i in range(n-1,-1,-1):
			subres = subres + sum_of_A - n * A[i]
			res = max(res, subres)
		return res
		
A = [4,3,2,6,7,4,5]
s = Solution()
print(s.maxRotateFunction(A))