from itertools import zip_longest

class Solution(object):
	def validWordSquare(self, words):
		transpose = list(zip_longest(*words, fillvalue = None))
		return transpose == list(zip_longest(*transpose, fillvalue = None))
		
s = Solution()
test = ["abcd","bnrt","crm","dt"]
print(s.validWordSquare(test))