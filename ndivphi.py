from sys import stdin
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103]

while True:
	value = stdin.readline()
	
	if value == '':
		break

	num = int(value)	
	result = 1
	for p in primes:
		temp = result * p
		if temp > num:
			break

		result = temp
	print result