class Solution(object):
	def findAnagrams(self, s, p):
		"""
		:type s: str
		:type p: str
		:rtype: List[int]
		"""
		def to26based(ch): return ord(ch) - ord("a")
		res = []
		if len(s) < len(p): return []
		p_len = len(p)
		table, masks = [0 for _ in xrange(26)], [1 << i for i in xrange(26)]
		compare_value = 0
		for ch in p: table[to26based(ch)] += 1
		sliding_table = [0 for _ in xrange(26)]
		for i in xrange(p_len): sliding_table[to26based(s[i])] += 1
		for i in xrange(26): 
			if table[i] != 0 and table[i] != sliding_table[i]: 
				compare_value += masks[i]
		for i in xrange(p_len, len(s)):
			if compare_value == 0: res.append(i - p_len)
			idx_pre, idx_next = to26based(s[i-p_len]), to26based(s[i])
			sliding_table[idx_pre]-=1
			sliding_table[idx_next]+=1
			if compare_value & masks[idx_pre] > 0 and sliding_table[idx_pre] == table[idx_pre]:
				compare_value -= masks[idx_pre]
			elif compare_value & masks[idx_pre] == 0 and sliding_table[idx_pre] != table[idx_pre]:
				compare_value += masks[idx_pre]
			if compare_value & masks[idx_next] > 0 and sliding_table[idx_next] == table[idx_next]:
				compare_value -= masks[idx_next]
			elif compare_value & masks[idx_next] == 0 and sliding_table[idx_next] != table[idx_next]:
					compare_value += masks[idx_next]
		if compare_value == 0: res.append(len(s) - p_len)
		return res
		
sol = Solution()
s, t = "dbcc", "abcd"
print sol.findAnagrams(s, t)

				
			