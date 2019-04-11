class Solution(object):
	def minCostII(self, costs):
		"""
		:type costs: List[List[int]]
		:rtype: int
		"""
		def find_min(arr, except_at = -1):
			res_i, res_v = -1, 2**31
			for i,v in enumerate(arr):
				if i == except_at: continue
				if v < res_v: res_i, res_v = i, arr[i]
			return res_v, res_i
		
		if not costs: return 0
		prev = [x for x in costs[0]]
		for i in xrange(1, len(costs)):
			v_min, i_min = find_min(prev)
			v_min2, i_min2 = find_min(prev, i_min)
			cur = [(x + (v_min if i != i_min else v_min2)) for i,x in enumerate(costs[i])]
			prev = cur
		return min(prev)
		
inp = [[1,2,3],[2,1,3],[3,1,2]]
s = Solution()
print s.minCostII(inp)