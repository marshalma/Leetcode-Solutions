import collections
class Solution(object):
	def generatePalindromes(self, s):
		"""
		:type s: str
		:rtype: List[str]
		"""
		odd_ch, ch_collect, table = [], [], collections.Counter(s)
		for ch in table:
			if table[ch] % 2 == 1:
				odd_ch.append(ch)
				if len(odd_ch) == 2: return []
			ch_collect += [ch] * (table[ch] // 2)
		print ch_collect
			
		res = [""]
		for i,ch in enumerate(ch_collect):
			subres = res
			res = []
			for ssres in subres:
				for i in range(len(ssres)+1):
					res.append(ssres[:i] + ch + ssres[i:])
					if i < len(ssres) and ssres[i] == ch: break
		print res
		return [(x + odd_ch[0] + x[::-1]) for x in res] if len(odd_ch) > 0 else [(x + x[::-1]) for x in res]
s = Solution()
print s.generatePalindromes("aabbbcc")