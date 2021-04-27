n = int(input())
a = list(map(int,input().split()))

arr, ans = [], 1

for i in range(n):
	arr.append((a[i],i))

arr.sort()
for i in range(n-1):
	if arr[i][1] > arr[i+1][1]:
		ans += 1

print(ans);
