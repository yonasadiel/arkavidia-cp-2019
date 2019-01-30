import math
def SQR(x):
	return x * x

T = int(input())
for i in range(T):
	d, x, y, Vk, Va = [int(x) for x in input().split()]
	# Vk * t - Va * t * cos(teta) = x ... (1)
	# Va * sin(teta) * t = y + d ... (2)
	# Re-elaborate equation (2)
	# (Va * sin(teta) * t)^2 = y^2 + 2 * y * d + d^2
	# (Va * sin(teta) * t)^2 = (Vk * t)^2 - 2 * Vk * t * x + x^2 ... (3)
	# Add (1) and (3) {yeah really (1) + (3)}
	# (Va * t)^2 - (Vk * t)^2 = y^2 + 2*y*d + d^2 + x^2 - 2 * Vk * t * x
	# (Va^2-Vk^2)*t^2 + 2*Vk*t*x - (y^2 + 2*y*d + d^2 + x^2) = 0
	A = SQR(Va) - SQR(Vk);
	B = Vk*x*2;
	C = -(SQR(y) + y*d*2 + SQR(d) + SQR(x));
	if SQR(B) >= 4 * A * C:
		print('YA')
	else:
		print('TIDAK')