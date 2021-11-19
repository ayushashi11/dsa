from math import sqrt
MAX = 1000000.0

def dist(p1, p2):
	return sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) + \
				(p1[1] - p2[1])*(p1[1] - p2[1]))

def cost(points, i, j, k):
	p1 = points[i]
	p2 = points[j]
	p3 = points[k]
	return dist(p1, p2) + dist(p2, p3) + dist(p3, p1)

def mTC(points, i, j):
	
	# There must be at least three points between i and j
	# (including i and j)
	if (j < i + 2):
		return 0
		
	# Initialize result as infinite
	res = MAX
	
	# Find minimum triangulation by considering all
	for k in range(i + 1, j):
		res = min(res, (mTC(points, i, k) + \
						mTC(points, k, j) + \
						cost(points, i, k, j)))
	
	return round(res, 4)

points = [[0, 0], [1, 0], [2, 1], [1, 2], [0, 2]]
n = len(points)
print(mTC(points, 0, n-1))