class Solution(object):
	def lexicalOrder(self, n):
		"""
		:type n: int
		:rtype: List[int]
		"""
		res = []
		for i in range(1, 10):
			if i > n: break
			res.append(i)
			sub_res = self.lexical_sub(n, i)
			res += sub_res
		return res
			
	def lexical_sub(self, n, pre):
		pre, res = pre * 10, []
		if pre > n: return []
		for i in range(10):
			this_num = pre + i
			if this_num > n: break
			res.append(this_num)
			sub_res = self.lexical_sub(n, this_num)
			res += sub_res
		return res

s = Solution()
print(s.lexicalOrder(5264)[4739])