n = int(input())
a = sorted(list(map(int,input().split())))
midIdx, ans = int(n / 2), 0
mid = a[midIdx]

for num in a:
	ans += abs(num - a[midIdx])

print(ans)