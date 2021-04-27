import math
a = [1688888888888888889, 158888888888888889, 14888888888888889, 1388888888888889, 128888888888889, 11888888888889, 1088888888889, 98888888889, 8888888889, 788888889, 68888889, 5888889, 488889, 38889, 2889, 189, 9, 0]
ans = []

def func(k):
	digitCnt, i = 18, 0
	while k < a[i]:
		i += 1
		digitCnt -= 1

	st = 10**(digitCnt-1)-1
	digitGap = k - a[i]

	if digitGap == 0:
		ans.append(9)
		return

	digit = digitGap - int(digitGap / digitCnt)*digitCnt
	numGap = math.ceil(digitGap / digitCnt)
	# print(float(digitGap / digitCnt), numGap)
	st += numGap
	# print(digitGap, numGap, st)
	# digit = digitGap - (numGap)*digitCnt
	# digit = (digitCnt-1) - ((numGap*digitCnt) - digitGap) 
	print(digit, len(str(st)))
	ans.append(str(st)[digit-1])

Q = int(input())
for q in range(Q):
	k = int(input())
	func(k)

for num in ans:
	print(num)