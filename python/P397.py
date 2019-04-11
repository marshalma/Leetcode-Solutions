class Solution(object):
	def integerReplacement(self, n):
		if n == 0: return 1
		if n == 1: return 0
		if n % 2 == 0: return self.integerReplacement(n // 2) + 1
		else: return min(self.integerReplacement(n+1), self.integerReplacement(n-1)) + 1
		
		
s = Solution()
print(s.integerReplacement(2))