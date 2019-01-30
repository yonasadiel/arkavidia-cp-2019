// by: Jehian Norman Saviero

#include <bits/stdc++.h>

using namespace std;
#define SQR(x) ((x)*(x))

int sign(long long A) {
	if (A > 0) return 1;
	else if (A == 0) return 0;
	else return -1;
}

bool same(int A, int B) {
	return A == B || A == 0 || B == 0;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		long long d, x, y, Vk, Va;
		scanf("%lld %lld %lld %lld %lld", &d, &x, &y, &Vk, &Va);
		// Vk * t - Va * t * cos(teta) = x ... (1)
		// Va * sin(teta) * t = y + d ... (2)
		// Re-elaborate equation (2)
		// (Va * sin(teta) * t)^2 = y^2 + 2 * y * d + d^2
		// (Va * sin(teta) * t)^2 = (Vk * t)^2 - 2 * Vk * t * x + x^2 ... (3)
		// Add (1) and (3) {yeah really (1) + (3)}
		// (Va * t)^2 - (Vk * t)^2 = y^2 + 2*y*d + d^2 + x^2 - 2 * Vk * t * x
		// (Va^2-Vk^2)*t^2 + 2*Vk*t*x - (y^2 + 2*y*d + d^2 + x^2) = 0
		long long A, B, C;
		A = SQR(Va)-SQR(Vk);
		B = Vk*x*2LL;
		C = -(SQR(y) + y*d*2LL + SQR(d) + SQR(x));
		if ((same(sign(A),sign(C)) && B >= sqrtl(llabs(A))*sqrtl(llabs(C))*2) || (!same(sign(A),sign(C)))) {
			puts("YA");
		} else {
			puts("TIDAK");
		}
	}
	return 0;
}