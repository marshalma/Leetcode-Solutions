#!/usr/bin/python

def setZeroes(matrix):
	"""
	:type matrix: List[List[int]]
	:rtype: void Do not return anything, modify matrix in-place instead.
	"""
	def setColumnZero(matrix, idx, n):
		for i in range(n): matrix[i][idx] = 0
	def setRowZero(matrix, idx, n):
		for i in range(n): matrix[idx][i] = 0
	
	if len(matrix) == 0: return matrix
	m, n = len(matrix), len(matrix[0])
	first_col, first_row = True, True
	for i in xrange(m):
		if matrix[i][0] == 0:
			first_col = False
			break
	for i in xrange(n):
		if matrix[0][i] == 0:
			first_row = False
			break
	for i in xrange(m):
		for j in xrange(n):
			if matrix[i][j] == 0: 
				matrix[i][0] = 0
				matrix[0][j] = 0
	for i in xrange(1,n):
		if matrix[0][i] == 0: setColumnZero(matrix, i, m)
	for i in xrange(1,m):
		if matrix[i][0] == 0: setRowZero(matrix, i, n)
	if first_col == False: setColumnZero(matrix, 0, m)
	if first_row == False: setRowZero(matrix, 0, n)
	


matrix = [[0,2,3],[1,2,0],[1,1,1]]
setZeroes(matrix)
print(matrix)