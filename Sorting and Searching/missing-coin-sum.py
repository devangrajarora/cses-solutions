n = int(input())
a = sorted(list(map(int,input().split())))

currSum = 0
for i in range(n):
	if currSum + 1 < a[i]:
		break
	currSum += a[i]

print(currSum+1)