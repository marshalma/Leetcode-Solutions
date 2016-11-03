class Codec:

	def encode(self, strs):
		"""Encodes a list of strings to a single string.
		
		:type strs: List[str]
		:rtype: str
		"""
		max_len = 0
		for s in strs:
			max_len = max(max_len, len(s))
		return (chr(0)*(max_len+1)).join([str(max_len), chr(0)*(max_len+1)] + strs)

	def decode(self, s):
		"""Decodes a single string to a list of strings.
		
		:type s: str
		:rtype: List[str]
		"""
		max_len_list = []
		for i in xrange(len(s)):
			if s[i] == chr(0): break
			max_len_list.append(s[i])
		max_len = int("".join(max_len_list))
		return_list = (chr(0)*max_len).split(s[(len(max_len_list) + max_len + 1):])
		
s = Codec()
t = Codec()
strs = ["abc", "bcd", "cde"]
print t.decode(s.encode(strs))