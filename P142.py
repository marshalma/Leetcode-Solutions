class ListNode(object):
	def __init__(self, x):
		self.val = x
		self.next = None

class Solution(object):
	def detectCycle(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		if not head: return None
		
		# first find out a node that is inside the cycle
		node1, node2 = head, head.next
		while node1 and node2:
			if node1 == node2: return node1
			if node1.next: node1 = node1.next
			else: return None
			if node2.next and node2.next.next: node2 = node2.next.next
			else: return None
		if not node1 or not node2: return None
		
		# get the length of the cycle
		length = 1
		node2 = node1.next
		while node2 != node1:
			node2 = node2.next
			length += 1
		
		# find out the head of the cycle
		node1, node2 = head, head
		for _ in xrange(length):
			node2 = node2.next