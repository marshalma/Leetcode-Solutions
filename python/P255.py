#!/usr/bin/python
class Solution(object):
	def verifyPreorder(self, preorder):
		"""
		:type preorder: List[int]
		:rtype: bool
		"""
		st, cur = [], -2**31
		for v in preorder:
			if v < cur: return False
			while st and st[-1] < v:
				cur = st.pop()
			st.append(v)
		return True
s = Solution()
_list = [6,4,1,2,5,3]
print s.verifyPreorder(_list)