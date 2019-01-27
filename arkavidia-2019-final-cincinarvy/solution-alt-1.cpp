// by: Jehian Norman Saviero

#include <bits/stdc++.h>

using namespace std;
#define SQR(x) ((x)*(x))

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		double d, x, y, Vk, Va;
		scanf("%lf %lf %lf %lf %lf", &d, &x, &y, &Vk, &Va);
		// Vk * t - Va * t * cos(teta) = x ... (1)
		// Va * sin(teta) * t = y + d ... (2)
		// Re-elaborate equation (2)
		// (Va * sin(teta) * t)^2 = y^2 + 2 * y * d + d^2
		// (Va * sin(teta) * t)^2 = (Vk * t)^2 - 2 * Vk * t * x + x^2 ... (3)
		// Add (1) and (3) {yeah really (1) + (3)}
		// (Va * t)^2 - (Vk * t)^2 = y^2 + 2*y*d + d^2 + x^2 - 2 * Vk * t * x
		// (Va^2-Vk^2)*t^2 + 2*Vk*t*x - (y^2 + 2*y*d + d^2 + x^2) = 0
		double A, B, C;
		A = SQR(Va)-SQR(Vk);
		B = Vk*x*2.00;
		C = -(SQR(y) + y*d*2.00 + SQR(d) + SQR(x));
		if (SQR(B) >= A*C*4.00) {
			puts("YA");
		} else {
			puts("TIDAK");
		}
	}
	return 0;
}