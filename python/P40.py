def backTracking(candidates, target, path, res, start):
	if target == 0:
		res.append(path[:])
		return
	for i in range(start, len(candidates)):
		if i > start and candidates[i] == candidates[i-1]: 
			continue
		if candidates[i] > target:
			break
		path.append(candidates[i])
		backTracking(candidates, target - path[-1], path, res, i+1)
		path.pop()
		
candidates = [1,1]
candidates.sort()
res, path = [], []
backTracking(candidates, 2, path, res, 0)
print(res