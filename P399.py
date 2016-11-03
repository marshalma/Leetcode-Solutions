#!/usr/bin/python

from collections import deque, defaultdict

class Solution(object):
	def calcEquation(self, equations, values, query):
		"""
		:type equations: List[List[str]]
		:type values: List[float]
		:type query: List[List[str]]
		:rtype: List[float]
		"""
		def bfs_search(all_equations, source, target, res):
			queue = deque([(source, 1.0)])
			visited = set([source])
			while queue:
				this_node, cur_calc_res = queue.popleft()
				for next_node in all_equations[this_node]:
					if next_node in visited: continue
					calc_res = cur_calc_res * all_equations[this_node][next_node]
					all_equations[source][next_node] = calc_res
					all_equations[next_node][source] = 1/calc_res
					if next_node == target:
						res.append(calc_res)
						return
					visited.add(next_node)
					queue.append((next_node, calc_res))
			res.append(-1.0)
		
		raw_nodes = []
		all_equations = defaultdict(dict)
		for i, e in enumerate(equations):
			raw_nodes += e
			all_equations[e[0]][e[1]] = float(values[i])
			all_equations[e[1]][e[0]] = 1.0 / values[i]
		nodes = set(raw_nodes)
		res = []
		for q in query:
			if q[0] not in nodes or q[1] not in nodes: res.append(-1.0)
			elif q[0] == q[1]: res.append(1.0)
			elif (q[0], q[1]) in all_equations: res.append(all_equations[q[0]][q[1]])
			else: bfs_search(all_equations, q[0], q[1], res)
		return res
				
s = Solution()
print(s.calcEquation([["a","b"],["c","d"]],[1,1],[["a","c"],["b","d"],["b","a"],["d","c"]]))