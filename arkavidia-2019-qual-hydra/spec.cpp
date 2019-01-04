#include <tcframe/spec.hpp>
using namespace tcframe;

#define MAXA 1e13
#define MAXGENERATE 1e10
#define BADX 152125131763605
#define MAXX 3e14
#define MAXN 100000
#define MAXT 100
#define MAXPRIME 1000005

class ProblemSpec : public BaseProblemSpec {
	protected:
		int T;
		long long X;
		int N;
		vector<long long> A;
		int res;

		void MultipleTestCasesConfig() {
			Counter(T);
			OutputPrefix("");
		}

		void InputFormat() {
			LINE(X,N);
			LINE(A % SIZE(N));
		}

		void OutputFormat() {
			LINE(res);
		}

		void GradingConfig() {
			TimeLimit(1);
			MemoryLimit(64);
		}

		void MultipleTestCasesConstraints() {
			CONS(1 <= T && T <= MAXT);
		}

		void Constraints() {
			CONS(1 <= N && N <= MAXN);
			CONS(1 <= X && X <= MAXX);
			CONS(isValid(A,N));
		}

	private:
		bool isValid(vector<long long>& A, int N) {
			bool valid = (A.size() == N);
			for (int i = 0; i < N && valid; ++i) {
				valid = (1 <= A[i]) && (A[i] <= MAXA);
			}
			return valid;
		}
};
	
class TestSpec : public BaseTestSpec<ProblemSpec> {
	protected:
		vector<long long> Primes;
		vector<long long> HugePrimes;
		bool isPrime[MAXPRIME];

		void SampleTestCase1() {
			Input({
				"2 3",
				"2 2 2"
			});
			Output({
				"3"
			});
		}

		void SampleTestCase2() {
			Input({
				"2 4",
				"1 2 3 4"
			});
			Output({
				"5"
			});
		}


		void BeforeTestCase() {
			A.clear();
		}


		void TestCases() {
			PreComputePrime();
			for (int i = 0; i < 100; ++i) {
				CASE(X=RandomNotPrime(), N=MAXN, RandomLarge(A, N));
			}
			for (int i = 0; i < 100; ++i) {
				CASE(X=RandomNotPrime(), N=MAXN, AllVeryLarge(A, N));
			}
			for (int i = 0; i < 100; ++i) {
				CASE(X=BADX, N=MAXN, RandomLarge(A, N));
			}
			for (int i = 0; i < 100; ++i) {
				CASE(X=BADX, N=MAXN, AllVeryLarge(A, N));
			}
			for (int i = 0; i < 100; ++i) {
				CASE(X=MAXX, N=MAXN, RandomLarge(A, N));
			}
			for (int i = 0; i < 100; ++i) {
				CASE(X=MAXX, N=MAXN, AllVeryLarge(A, N));
			}
			for (int i = 0; i < 100; ++i) {
				CASE(X=HugePrime(), N=MAXN, RandomLarge(A,N));
			}
			for (int i = 0; i < 100; ++i) {
				CASE(X=HugePrime(), N=MAXN, AllVeryLarge(A,N));
			}
		}

		long long POW(long long a, long long p) {
			long long res = 1;
			for (int i = 1; i <= p; ++i) {
				res *= a;
			}
			return res;
		}

		long long HugePrime() {
			int choose = rnd.nextInt(0, HugePrimes.size()-1);
			return HugePrimes[choose];
		}

		long long RandomNotPrime() {
			int bit = rnd.nextInt(1, 1 << 12);
			int cnt = 0;
			long long res = 1;
			while (bit) {
				if (bit & 1) res *= POW(Primes[cnt], rnd.nextInt(1,3));
				bit >>= 1;
				++cnt;
				if (res > MAXGENERATE) return res;
			}
			return res * 2LL;
		}

		void PreComputePrime() {
			std::fill_n(isPrime, sizeof(isPrime)/sizeof(isPrime[0]), true);
			isPrime[1] = isPrime[0] = false;
			for (int i = 2; i < MAXPRIME; ++i) {
				if (isPrime[i]) {
					Primes.push_back(i);
					for (int j = i + i; j < MAXPRIME; j += i) {
						isPrime[j] = false;
					}
				}
			}
			// Add Random Huges Prime
			// 12 digits
			HugePrimes.push_back(103868294641);
			HugePrimes.push_back(115981820659);
			HugePrimes.push_back(131293893743);
			HugePrimes.push_back(437887772299);
			HugePrimes.push_back(987014682601);
			// 13 digits
			HugePrimes.push_back(1014731220367);
			HugePrimes.push_back(1151544715333);
			HugePrimes.push_back(2771980960849);
			HugePrimes.push_back(8460000000847);
			// 14 digits
			HugePrimes.push_back(10083087720779);
			HugePrimes.push_back(11745292359967);
			HugePrimes.push_back(41182420705009);
			HugePrimes.push_back(91811782339663);
			// 15 digits
			HugePrimes.push_back(112272535095293);
			HugePrimes.push_back(115797848077099);
			HugePrimes.push_back(125673790649527);
			HugePrimes.push_back(246739592898529);
			HugePrimes.push_back(296483719234103);
		}

		void RandomLarge(vector<long long> &A, int N) {
			A.resize(N);
			for (int i = 0; i < N; ++i) {
				A[i] = rnd.nextLongLong(MAXA/10LL, MAXA);
			}
		}

		void AllVeryLarge(vector<long long> &A, int N) {
			A.resize(N);
			for (int i = 0; i < N; ++i) {
				A[i] = MAXA;
			}
		}
};