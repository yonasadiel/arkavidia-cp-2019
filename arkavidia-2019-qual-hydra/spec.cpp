#include <tcframe/spec.hpp>
using namespace tcframe;

#define MAXA 1e13
#define MAXGENERATE 1e10
#define BADX 870062193
#define MAXX 1e10
#define MAXN 100000
#define MAXT 10
#define MAXPRIME 1000005

class ProblemSpec : public BaseProblemSpec {
	protected:
		int T;
		long long X;
		int N;
		vector<long long> A;
		long long res;

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
			TimeLimit(4);
			MemoryLimit(256);
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

		void BeforeTestCases(){
		}

		void BeforeTestCase(){
			PreComputePrime();
			A.clear();
		}

		void TestGroup1(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(X=RandomNotPrime(), N=MAXN, RandomLarge(A, N));
			}
		}

		void TestGroup2(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(X=RandomNotPrime(), N=MAXN, AllVeryLarge(A, N));
			}
		}

		void TestGroup3(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(X=BADX, N=MAXN, RandomLarge(A, N));
			}
		}

		void TestGroup4(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(X=BADX, N=MAXN, AllVeryLarge(A, N));
			}
		}

		void TestGroup5(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(X=MAXX, N=MAXN, RandomLarge(A, N));
			}
		}

		void TestGroup6(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(X=MAXX, N=MAXN, AllVeryLarge(A, N));
			}
		}

		void TestGroup7(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(X=HugePrime(), N=MAXN, RandomLarge(A,N));
			}
		}

		void TestGroup8(){
			for (int i = 0; i < MAXT; ++i) {
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
				if (bit & 1){
					long long tmp = POW(Primes[cnt], rnd.nextInt(1,3));
					if (res > MAXGENERATE/tmp) return res;
					res *= tmp;
				}
				bit >>= 1;
				++cnt;
			}
			return res<=MAXGENERATE/2? res * 2LL : res;
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
			HugePrimes.clear();
			// Add Random Huges Prime
			// 9 digits
			HugePrimes.push_back(140113451);
			HugePrimes.push_back(320910911);
			HugePrimes.push_back(559093541);
			HugePrimes.push_back(678117071);
			HugePrimes.push_back(920294989);
			// 10 digits
			// HugePrimes.push_back(1100117911);
			// HugePrimes.push_back(2871870241);
			// HugePrimes.push_back(4230111679);
			// HugePrimes.push_back(6311879191);
			// HugePrimes.push_back(8137827037);
			// 11 digits
			// HugePrimes.push_back(29960801803);
			// HugePrimes.push_back(33568817999);
			// HugePrimes.push_back(54673117789);
			// HugePrimes.push_back(89899277981);
			// HugePrimes.push_back(96123282491);
			// 12 digits
			// HugePrimes.push_back(103868294641);
			// HugePrimes.push_back(115981820659);
			// HugePrimes.push_back(131293893743);
			// HugePrimes.push_back(437887772299);
			// HugePrimes.push_back(722038107701);
			// HugePrimes.push_back(987014682601);
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