n, m, k = map(int, input().split())
desired = list(map(int, input().split()))
size = list(map(int, input().split()))
i, j, ans = 0, 0, 0

desired.sort()
size.sort()

while i < n and j < m:
	if abs(desired[i] - size[j]) <= k:
		ans += 1
		i += 1
		j += 1
	elif desired[i] > size[j]:
		j += 1
	else:
		i += 1
print(ans)

