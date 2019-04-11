import random

class Solution(object):

	def __init__(self, nums):
		"""
		
		:type nums: List[int]
		:type numsSize: int
		"""
		self.nums = nums
		

	def pick(self, target):
		"""
		:type target: int
		:rtype: int
		"""
		indices = [i for i,v in enumerate(self.nums) if target == v]
		return random.choice(indices)
		


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)

#from collections import defaultdict, Counter
#import random
#class Solution(object):
#	def __init__(self, nums):
#		self.table = defaultdict(list)
#		self.table2 = Counter(nums)
#		for i,num in enumerate(nums):
#			if num not in self.table: 
#				self.table[num] = [[i,i]]
#				continue
#			if i == self.table[num][-1][-1]+1: self.table[num][-1][-1] = i
#			else: self.table[num].append([i,i])
#		
#	def pick(self, target):
#		"""
#		:type target: int
#		:rtype: int
#		"""
#		total_count = self.table2[target]
#		ranges_alias = self.table[target]
#		random_num = random.randint(1, total_count)
#		for span in ranges_alias:
#			if random_num <= span[1] - span[0] + 1:
#				return span[0] + random_num - 1
#			random_num -= span[1] - span[0] + 1
		
s = Solution([1,2,3,3,3,5,2,6,4,2,5,4,6,2,3,4,5,7,6,5,4,2,4])
for _ in range(1000):
	print(s.pick(3))