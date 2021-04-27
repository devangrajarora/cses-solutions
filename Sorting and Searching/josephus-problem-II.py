def solve():
	n, k = map(int, input().split())
	done = [ False for _ in range(n) ]
	pos, left = 0, n

	if n == 1:
		print(1)
		return


	while left > 0:

		# find next available
		for i in range(k):

			while done[pos]:
				pos = (pos + 1)%n
			if left == 1:
				print(pos+1, end=" ")
				return

			# skip next available
			pos = (pos + 1)%n

		#find next one
		while done[pos]:
			pos = (pos + 1)%n
		print(pos+1, end=" ")
		done[pos] = True
		left -= 1

solve()
print()