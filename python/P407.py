#!/usr/bin/python

from heapq import heappush, heappop
class Solution:
	def trapRainWater(self, heights):
		# write your code here
		if not heights:
			return 0

		hq = []
		r_num, c_num, result = len(heights), len(heights[0]), 0
		visited = [[False for a in range(c_num)] for b in range(r_num)]

		#add outside into hq
		for i in xrange(r_num):
			heappush(hq, (heights[i][0], i, 0))
			heappush(hq, (heights[i][c_num-1], i, c_num-1))
			visited[i][0], visited[i][c_num-1] = True, True

		for i in xrange(1, c_num):
			heappush(hq, (heights[0][i], 0, i))
			heappush(hq, (heights[r_num-1][i], r_num-1, i))
			visited[0][i], visited[r_num-1][i] = True, True

		dx, dy = [1, -1, 0, 0], [0, 0, -1, 1]
		while hq:
			cur = heappop(hq)
			for x in range(4):
				xx = cur[1] + dx[x]
				yy = cur[2] + dy[x]

				if xx >= 0 and xx < r_num and yy >= 0 and yy < c_num and not visited[xx][yy]:
					visited[xx][yy] = True
					heappush(hq, (max(cur[0], heights[xx][yy]), xx, yy))
					result += max(0, cur[0] - heights[xx][yy])
		return result