class Solution(object):
	def lengthLongestPath(self, input):
		"""
		:type input: str
		:rtype: int
		"""
		st, list_in, list_in_strip, max_len = [], input.split("\n"), [], 0
		if not list_in: return 0
		for s in list_in:
			num = 0
			while num < len(s) and s[num] == "\t": num += 1
			list_in_strip.append((len(s)-num, num+1, True) if "." in s else (len(s)-num, num+1, False))
		st.append((0, 0))
		for v in list_in_strip:
			str_len, level, is_file = v
			while level <= st[-1][0]: st.pop()
			st.append((level, st[-1][1] + str_len + (0 if is_file else 1)))
			if is_file: max_len = max(max_len, st[-1][1])
				
		return max_len
	
s = Solution()
str = "dir\n\t"
print(s.lengthLongestPath(str))