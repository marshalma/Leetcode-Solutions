class Solution(object):
	def canPartition(self, nums):
		"""
		:type nums: List[int]
		:rtype: bool
		"""
		summation = sum(nums)
		if summation % 2 != 0: return False
		nums.sort()
		target = summation // 2
		
		def dfs(nums, start, target):
			if target == 0: return True
			if start == len(nums): return False
			for i in xrange(start, len(nums)):
				if nums[i] > target: return False
				if dfs(nums, i+1, target-nums[i]): return True
			return False
		
		return dfs(nums, 1, target - nums[0])
		
s = Solution()
print s.canPartition([1,1])