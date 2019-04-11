class Solution(object):
	def maxProfit(self, prices):
		"""
		:type prices: List[int]
		:rtype: int
		"""
		if not prices: return 0
		buy1, sell1, buy2, sell2 = -prices[0], 0, -prices[0], 0
		for i,v in enumerate(prices):
			if not i: continue
			buy1 = max(buy1, -v)
			sell1 = max(sell1, v + buy1)
			buy2 = max(buy2, sell1 - v)
			sell2 = max(sell2, v + buy2)
			print buy1, sell1, buy2, sell2
		return sell2

prices = [3,2,6,5,0,3]
s = Solution()
print (s.maxProfit(prices))