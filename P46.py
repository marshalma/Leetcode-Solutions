#!/usr/bin/ruby
def permute(nums):
	if len(nums) == 1: return [nums]
	subres = permute(nums[1:])
	res = []
	
	for i in range(len(subres)):
		for j in range(len(subres[i])+1):
			res.append(subres[i][:])
			res[-1].insert(j,nums[0])
	return res
	
print(permute([1,2,3]))