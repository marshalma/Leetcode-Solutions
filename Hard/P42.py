
class Solution(object):
	def trap(self, height):
		"""
		:type height: List[int]
		:rtype: int
		"""
		left, right = 0, len(height)-1
		left_max, right_max = 0, 0
		res = 0
		while left < right:
			if height[left] < height[right]:
				if height[left] < left_max: res += left_max - height[left]
				else: left_max = height[left]
				left += 1
				
			else:
				if height[right] < right_max: res += right_max - height[right]
				else: right_max = height[right]
				right -= 1
		return res
		
height = [0,1,0,2,1,0,1,3,2,1,2,1]
s = Solution()
print s.trap(height)