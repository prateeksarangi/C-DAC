def fibo(n):
	a = 0
	b = 1
	l = 0
	print(a)
	print(b)
	for i in range(n):
		l = a+b
		print(l)
		a = b
		b = l

fibo(20)

def fibo_rec(n):
	a = 0
	b = 1
	l = 0
	if n == 1:
		return 0
	elif n == 2:
		return 1
	else:
		return fibo_rec(n-1)+fibo_rec(n-2)

print('############')
print(fibo_rec(20))



