#!/usr/bin/python

class Solution(object):
	def validUtf8(self, data):
		"""
		:type data: List[int]
		:rtype: bool
		"""
		def validate(idx, count, data):
			if idx + count >= len(data): return False
			for i in range(1, count+1):
				if 128 <= data[idx + i] < 196: continue
				return False
			return True
		
		i = 0
		new_data = map(lambda x: x%256, data)
		while i < len(new_data):
#			print new_data[i]
			if new_data[i] < 128: 
#				print 1
				i += 1
				continue
			if 128 <= new_data[i] < 196: return False
			if 196 <= new_data[i] < 224:
				if not validate(i, 1, data): return False
#				print 2
				i += 2
				continue
			if 224 <= new_data[i] < 240:
				if not validate(i, 2, data): return False
#				print 3
				i += 3
				continue
			if 240 <= new_data[i] < 248:
				if not validate(i, 3, data): return False
#				print 4
				i += 4
				continue
			return False
		return True
		
a = [194,155,231,184,185,246,176,131,161,222,174,227,162,134,241,154,168,185,218,178,229,187,139,246,178,187,139,204,146,225,148,179,245,139,172,134,193,156,233,131,154,240,166,188,190,216,150,230,145,144,240,167,140,163,221,190,238,168,139,241,154,159,164,199,170,224,173,140,244,182,143,134,206,181,227,172,141,241,146,159,170,202,134,230,142,163,244,172,140,191]
s = Solution()
print s.validUtf8(a)