from collections import defaultdict
import bisect
class Solution(object):
	def maxKilledEnemies(self, grid):
		"""
		:type grid: List[List[str]]
		:rtype: int
		"""
		if not grid: return 0
		m, n = len(grid), len(grid[0])
		cols = [0 for i in xrange(n)]
		res = 0
		for i in xrange(m):
			for j in xrange(n):
				if not j or grid[i][j-1] == "W":
					rowhit = 0
					for k in xrange(j, n):
						if grid[i][k] == "W": break
						rowhit += 1 if grid[i][k] == "E" else 0
				if not i or grid[i-1][j] == "W":
					cols[j] = 0
					for k in xrange(i, m):
						if grid[k][j] == "W": break
						cols[j] += 1 if grid[k][j] == "E" else 0
				if grid[i][j] == "0":
					res = max(res, rowhit + cols[j])
		return res
s = Solution()
inp = ["0", "E", "E", "E", "E", "W"]
print s.maxKilledEnemies(inp)