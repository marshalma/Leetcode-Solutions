class Solution(object):
	def isRectangleCover(self, rectangles):
		"""
		:type rectangles: List[List[int]]
		:rtype: bool
		"""
		min_x, min_y, max_x, max_y = min([i[0] for i in rectangles]), min([i[1] for i in rectangles]), max([i[2] for i in rectangles]), max([i[3] for i in rectangles])
		area = (max_x - min_x) * (max_y - min_y)
		def overlap(rec1, rec2):
			if rec2[0] <= rec1[0] < rec2[2] and rec2[1] <= rec1[1] < rec2[3]: return True
			if rec1[0] <= rec2[0] < rec1[2] and rec1[1] <= rec2[1] < rec1[3]: return True
			return False
		for rec in rectangles:
			area -= (rec[2] - rec[0]) * (rec[3] - rec[1])
		if area != 0: return False
		for rec in rectangles:
			for _rec in rectangles:
				if rec is _rec: continue
				if overlap(rec, _rec): return False
		return True
s = Solution()
rects = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
print(s.isRectangleCover(rects))