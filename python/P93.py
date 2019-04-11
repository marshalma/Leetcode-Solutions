#def restoreSubProc(s, n):
#	len_s, res = len(s), []
#	if len_s < n or len_s > n * 3: return []
#	if n == 0: return [[]]
#	for i in range(3):
#		if i+1 > len_s: break
#		num = int(s[0:i+1])
#		if num >= 255: break;
#		subres = restoreSubProc(s[i+1:], n-1)
#		print(n, subres)
#		for sr in subres:
#			res.append([str(num)] + sr)
#		if num == 0: break
#	return res
#subres, res = restoreSubProc("1111", 4), []
#for sr in subres:
#	res.append(".".join(sr))
#print(res)

class Solution(object):
	def restoreIpAddresses(self, s):
		self.res, self.path, self.s, res = [], [], s, []
		self.restoreSubProc(0)
		for r in self.res:
			res.append(".".join(r))
		return res
		
	
	def restoreSubProc(self, start):
		if len(self.path) == 4:
			if start == len(self.s):
				self.res.append(self.path[:])
			return
		
		if self.s[start] == "0":
			self.path.append("0")
			self.restoreSubProc(start+1)
			self.path.pop()
			return
		for i in range(3):
			if start + i + 1 > len(self.s): break
			num = int(self.s[start:start+i+1])
			if num > 255: break
			self.path.append(str(num))
			self.restoreSubProc(start+i+1)
			self.path.pop()
s = Solution()
print(s.restoreIpAddresses("2552550135"))