class Solution(object):
	def lastRemaining(self, n):
		"""
		:type n: int
		:rtype: int
		"""
		if n <= 0: return 0
		list, flag = (1,n,1), False
		def len_list(inp):
			return (inp[2]+inp[1]-inp[0]) // inp[2]
		while list[0] != list[1]:
			length = len_list(list)
			if flag == False and length % 2 != 0:
				list = (list[0] + list[2], list[1] - list[2], list[2] * 2)
			elif flag == False and length % 2 == 0:
				list = (list[0] + list[2], list[1], list[2] * 2)
			elif flag == True and length % 2 != 0:
				list = (list[0] + list[2], list[1] - list[2], list[2] * 2)
			else:
				list = (list[0], list[1] - list[2], list[2] * 2)
				
			flag = not flag
		return list[0]
s = Solution()
print(s.lastRemaining(1000000))