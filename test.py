import re
import collections
import bisect
import this
import random
import itertools

a = None

def my_func(arg1, *arg2, **arg3):
	global a
	if a is None:
		a = 3
	print(arg1, end = ',')
	for arg in arg2:
		print(arg, end = ',')
	print(arg3)
	
my_func(1, "abc", "cdef", abc = 54, cdef = 34)

print([i for i in map(lambda x : 5**x, range(1,33))])
print([i for i in range(0, 5)])

print(('b','1') < ('1', 'b'))


#raise SomeError

#assert 2+2 != 4, "Wrong Calculation"

class Employee(object):
	def classMet():
		print("In class method")
	pass

a = Employee();
a.name = "Marshal"
print(a.name)
#print("I'm {0}".format(a.name))
#print(3 * 'n')
print(Employee.classMet())


for i in range(5,0,-1): print(i)

def reverseTest(nums):
	nums.reverse()
	
def reverseTest2(nums):
	nums = nums[::-1]
	
def reverseSliceTest(nums):
	print(nums[2:4].reverse())
	
nums = [1,2,3,4,5]
nums2 = [1,2,3,4,5]
nums3 = [1,2,3,4,5]
reverseTest(nums)
reverseTest2(nums2)
reverseSliceTest(nums3)
print(nums)
print(nums2)
print(nums3)


for i in range(9):
	print(i)
	

print(sorted([1,2,3,5,3,2,1]))

a = [nums, nums2, nums3]
print(a)
nums.clear()
nums2.clear()
nums3.clear()
print(a)


print(list(map(lambda x:x+5, [1,2,3,4,5])))
print()


print(re.match(r"spam", "spama"))


for group, digit in re.findall(r'((.)\2*)', "1121121112"):
	print("{0} : {1}".format(group, digit))
	
#a = [0, 0, 0, 0, 0, 0]
#while a[-1] == 0: a.pop()

a = "".join(sorted("abc"))
print(a)

def anagrams(strs):
	count = collections.Counter([tuple(sorted(s)) for s in strs])
	return filter(lambda x: count[tuple(sorted(x))]>1, strs)
	
print(list(anagrams(["eat", "tea", "tan", "ate", "nat", "bat"])))

nums = [1,2,3]
nums.insert(1, [1,2,3,4])
print(nums)


def generator():
	for i in range(5):
		yield [1,1,1]

print([tuple(x) for x in generator()])

for i in reversed(range(0,5)):
	print(i)
a,* b = (1,2,3)
print(a)
print(b)

a = [[1,2,3],[1,2,3],[1,2,3]]
print(*a)

str = ""
a = [str.split(" ")]
print(a[-1])

a = [1,2,3,4,5]
b = [1,2,3]
for x in zip(a,b):
	print(x)
	
print("home//anbc".split("/"))

print(".".join(["1","2"]))

zhongwenstr = "测试"
print(zhongwenstr.encode())
a = [1,2,3,4]
print(a.__getitem__(3))
print([[1],2,3] < [[1,2],3])

dic = {1 : 1, 2 : 2, 3 : 3}
for x in dic:
#	del dic[x]
	print(dic)
	
a = [1,2,3,4,5]
d = {"a":1, "b":4, "c":8, "d":16}
def packingtest(*args, e = 0, a = 0, b = 0, c = 0, d = 0):
	print(args)
	print(d)
packingtest(*a)

a = ["a", "b"]
print(a[-1:])

a = collections.deque([1,2,3,4,5])
print(len(a))


a = [1,2,3,4,5]
for ttt in range(4):
	print(ttt)
	ttt += 1
print(ttt)


cc = collections.Counter()
cc.update([1])
cc.update([1])
print(cc)

st = set()
for i in range(len(a)):
	print(a[i], a[~i])
	
a = [1,1,1,3,5,7,9]
print(bisect.bisect_left(a, 2))


print(random.randrange(1,5))

print(2**24)

print(324006382 % 64 + 1)

print((2,) < (1,))

print(list((1,2,3)))

a, b = set([1,3,5,7,9]), set([2,3,5,7,8])
c = a ^ b
print(c)

# group by not sorted vs sorted
v = [1,2,3,4,5,6,7,8,9]
keygen = lambda x : x%2
v.sort(key = keygen)
print(v)
groups = []
for _, v in itertools.groupby(v,key=keygen):
	groups.append(list(v))
print(groups)

# generator
def my_gen(list):
	for v in list:
		yield v
lists = [1,2,3,4,5]
print([v for v in my_gen(lists)])

# *args and **kwargs
#def printlist(**kwargs):
#	for item in args:
#		print(item, end=" ")
#		
#	print(kwargs)
#printlist(1,2,3,4,5,a=1,b=2,c=3)

t = (0,1,2,3,4,5)
l = list(t)
print(l)
print(min(t))



a = [1,2,3,4,5]
b = 0 or None
c = None or 0
print(b, c)
print(a[:0 or None])
