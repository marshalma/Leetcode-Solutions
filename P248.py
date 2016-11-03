import bisect
class Solution(object):
	def __init__(self):
		self.all_naive_result = [[], ["0", "1", "8"], ["00", "11", "69", "88", "96"]]
		self.all_result = [[], ["0", "1", "8"], ["11", "69", "88", "96"]]

	def strobogrammaticInRange(self, low, high):
		"""
		:type low: str
		:type high: str
		:rtype: int
		"""
		while len(self.all_result) < len(high) + 1:
			naive_result = [(ss[0] + prev + ss[1]) for ss in self.all_naive_result[2] for prev in self.all_naive_result[-2]]
			self.all_naive_result.append(naive_result)
			self.all_result.append([x for x in naive_result if x[0] != "0"])
		if low > high: return 0
		sub_1, sub_2 = bisect.bisect_left(self.all_result[len(low)], low), len(self.all_result[len(high)]) - bisect.bisect(self.all_result[len(high)], high)
		res = - sub_1 - sub_2
		for i in range(len(low), len(high)+1):
			res += len(self.all_result[i])
		return res
		
s = Solution()
print s.strobogrammaticInRange("0", "1000")