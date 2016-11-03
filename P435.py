from collections import defaultdict, deque
class Solution(object):
	def sequenceReconstruction(self, org, seqs):
		"""
		:type org: List[int]
		:type seqs: List[List[int]]
		:rtype: bool
		"""
		table = defaultdict(list)
		table2 = {v:i for i,v in enumerate(org)}
		for s in seqs:
			table[s[0]].append(s)
		q = deque()
		for v in table[org[0]]:
			q.append(v)
		while q:
			n = len(q[0])
			for i in xrange(1, n):
				if q[0][i] not in table: continue
				for v in table[q[0][i]]:
					if v[-1] == org[-1] and table2[q[0][i]] + len(v) == len(org): return True
					q.append(v)
			q.popleft()
		return False
		
s = Solution()
org = [4,1,5,2,3,6]
seqs = [[4,1,5,3],[5,2,3,6]]
print s.sequenceReconstruction(org, seqs) 