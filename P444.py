from collections import defaultdict, deque
class Solution(object):
	def sequenceReconstruction(self, org, seqs):
		"""
		:type org: List[int]
		:type seqs: List[List[int]]
		:rtype: bool
		"""
		table = defaultdict(list) # first ele in each seq : a list of all seqs that contains that ele
		table2 = {v:i for i,v in enumerate(org)} # ele : pos
		for s in seqs:
			table[s[0]].append(s)
		q = deque()
		for v in table[org[0]]:
			q.append(v)
		while q:
			n = len(q[0])
			for i in xrange(1, n+1):
				if q[0][i] not in table: continue
				thislist = table[q[0][i]]
				if thislist[-1] == org[-1]: return True
				q.append(thislist)
			q.popleft()
		return False
		
s = Solution()
org = [1,2,3]
seqs = [[1,2],[2,3]]
print s.sequenceReconstruction(org, seqs)