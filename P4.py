import bisect

class Solution(object):
	def findMedianSortedArrays(self, nums1, nums2):
		"""
		:type nums1: List[int]
		:type nums2: List[int]
		:rtype: float
		"""
		s1, e1, s2, e2 = 0, len(nums1)-1, 0, len(nums2)-1
		count, target = 0, (len(nums1) + len(nums2) - 1) // 2
		while True:
			mid1 = (s1+e1) // 2
			idx1 = bisect.bisect_left(nums2, nums1[mid1] , s2, e2)
			idx2 = bisect.bisect_right(nums2, nums1[mid1], s2, e2)
			count = idx1 + mid1
			if count < target: s1 = mid1+1
			elif count > target: e1 = mid1
			else:
				if (len(nums1) + len(nums2)) % 2 == 1: return nums
			
nums1 = [1,2,3,4,5,6,7,8,9]
nums2 = [2,3,4,6,7,9,10,15]
s = Solution()
print s.findMedianSortedArrays(nums1, nums2)