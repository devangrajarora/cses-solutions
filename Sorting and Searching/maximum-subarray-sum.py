n = int(input())
a = list(map(int,input().split()))
maxTillHere, ans = a[0], a[0]

for i in  range(1,n):
	maxTillHere = max(maxTillHere+a[i],a[i])
	ans = max(ans, maxTillHere)
print(ans)