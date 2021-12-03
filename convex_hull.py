from functools import partial

def Left_index(points):
	minn = 0
	for i in range(1,len(points)):
		if points[i][0] < points[minn][0]:
			minn = i
		elif points[i][0] == points[minn][0]:
			if points[i][1] > points[minn][1]:
				minn = i
	return minn

def orientation(p, q, r):
	val = (q[1] - p[1]) * (r[0] - q[0]) - \
		(q[0] - p[0]) * (r[1] - q[1])

	if val == 0:
		return 0
	elif val > 0:
		return 1
	else:
		return 2

def convexHull(points, n):
	if n < 3:
		return
	l = Left_index(points)
	hull = []
	p = l
	q = 0
	while(True):
		hull.append(p)
		q = (p + 1) % n
		for i in range(n):
			if(orientation(points[p],
						points[i], points[q]) == 2):
				q = i
		p = q
		if(p == l):
			break
	return [points[i] for i in hull]

def check_if_lies_on_border(points, point):
	ln = len(points)
	for i in range(ln):
		p1 = points[i]
		p2 = points[(i+1)%ln]
		if (p1==point or p2==point) or (p1[0]==p2[0]==point[0] and (p1[1]<point[1]<p2[1] or p2[1]<point[1]<p1[1])) or (p2[0]-p1[0]!=0 and point[0]-p1[0]!=0 and (point[1]-p1[1])/(point[0]-p1[0]) - (p2[1]-p1[1])/(p2[0]-p1[0]) == 0):
			return True
	return False


# Driver Code
points = eval(input())
vertices = convexHull(points, len(points))
print(points)
print(vertices)

check_if_lies_on_border = partial(check_if_lies_on_border, vertices)

print(*filter(check_if_lies_on_border, points))