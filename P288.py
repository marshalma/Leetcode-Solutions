import collections

class ValidWordAbbr(object):
	def __init__(self, dictionary):
		"""
		initialize your data structure here.
		:type dictionary: List[str]
		"""
		self.table_words = set(dictionary)
		self.table_abbrev = collections.Counter()
		for word in dictionary:
			if len(word) <= 2: self.table_abbrev.update([word])
			else: self.table_abbrev.update([word[0] + str(len(word)-2) + word[-1]])

	def isUnique(self, word):
		"""
		check if a word is unique.
		:type word: str
		:rtype: bool
		"""
		if len(word) <= 2: str_test = word
		else: str_test = word[0] + str(len(word) - 2) + word[-1]
		return str_test not in self.table_abbrev or word in self.table_words and self.table_abbrev[str_test] == 1


dictionary = ["deer", "door", "cake", "card"]
s = ValidWordAbbr(dictionary)
print s.isUnique("make");