#include <tcframe/spec.hpp>
using namespace tcframe;

#define MAXN 1e9
#define MAXA 1e9
#define MAXB 1e9
#define MAXQ 3e4
#define MAXT 10

class ProblemSpec : public BaseProblemSpec {
	protected:
		int T;
		int N, Q;
		long long A, B;
		vector<long long> L, R;
		vector<int> res;

		void MultipleTestCasesConfig() {
			Counter(T);
			OutputPrefix("");
		}

		void InputFormat() {
			LINE(N, A, B);
			LINE(Q);
			LINES(L, R) % SIZE(Q);
		}

		void OutputFormat() {
			LINES(res) % SIZE(Q);
		}

		void GradingConfig() {
			TimeLimit(4);
			MemoryLimit(512);
		}

		void MultipleTestCasesConstraints() {
			CONS(1 <= T && T <= MAXT);
		}

		void Constraints() {
			CONS(1 <= N && N <= MAXN);
			CONS(1 <= A && A <= MAXA);
			CONS(1 <= B && B <= MAXB);
			CONS(1 <= Q && Q <= MAXQ);
			CONS(isValid(L,R,Q));
		}

	private:
		bool isValid(vector<long long> &L, vector<long long> &R, int Q) {
			bool valid = (L.size() == Q) && (R.size() == Q);
			for (int i = 0; i < Q && valid; ++i) {
				valid = (1 <= L[i]) && (L[i] <= N)
						&& (1 <= R[i]) && (R[i] <= N)
						&& (L[i] <= R[i]);
			}
			return valid;
		}
};
	
class TestSpec : public BaseTestSpec<ProblemSpec> {
	protected:
		void SampleTestCase1() {
			Input({
				"5 1 2",
				"3",
				"1 2",
				"1 3",
				"2 5"
			});
			Output({
				"50",
				"500",
				"0"
			});
		}

		void SampleTestCase2() {
			Input({
				"20 100000001 999999999",
				"3",
				"1 4",
				"5 9",
				"1 10"
			});
			Output({
				"1000",
				"1",
				"4"
			});
		}

		void BeforeTestCases(){
		}

		void BeforeTestCase(){
			L.clear();
			R.clear();
		}

		// Get Random 1 digit only
		void TestGroup1(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(N=MAXN, A=rnd.nextLongLong(1,MAXA), B=rnd.nextLongLong(1,MAXB), Q=MAXQ, RandomPickOne(L,R));
			}
		}

		// Sliding Window size MAXQ
		void TestGroup2(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(N=MAXN, A=rnd.nextLongLong(1,MAXA), B=rnd.nextLongLong(1,MAXB), Q=MAXQ, SlidingWindow(L,R));
			}
		}
		
		// Fixed size pick digit but random position
		void TestGroup3(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(N=MAXN, A=rnd.nextLongLong(1,MAXA), B=rnd.nextLongLong(1,MAXB), Q=MAXQ, FixedSize(L,R,rnd.nextInt(1000,N-1000000)));
			}
		}

		// Random size pick digit and also random position
		void TestGroup4(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(N=MAXN, A=rnd.nextLongLong(1,MAXA), B=rnd.nextLongLong(1,MAXB), Q=MAXQ, RandomAll(L,R));
			}
		}

		// Get All Digit Repeated
		void TestGroup5(){
			for (int i = 0; i < MAXT; ++i) {
				CASE(N=MAXN, A=rnd.nextLongLong(1,MAXA), B=rnd.nextLongLong(1,MAXB), Q=MAXQ, GetAll(L,R));
			}
		}

		void SlidingWindow(vector<long long> &L, vector<long long> &R) {
			for (int i = 1; i <= Q; ++i) {
				L.push_back(i);
				R.push_back(N-Q+i);
			}
		}

		void FixedSize(vector<long long> &L, vector<long long> &R, int size_window) {
			for (int i = 0; i < Q; ++i) {
				L.push_back(rnd.nextInt(1,N-size_window));
				R.push_back(L.back()+size_window);
			}
		}

		void GetAll(vector<long long> &L, vector<long long> &R) {
			for (int i = 0; i < Q; ++i) {
				L.push_back(1);
				R.push_back(N);
			}
		}

		void RandomPickOne(vector<long long> &L, vector<long long> &R) {
			for (int i = 0; i < Q; ++i) {
				L.push_back(rnd.nextInt(1,N));
				R.push_back(L.back());
			}
		}

		void RandomAll(vector<long long> &L, vector<long long> &R) {
			for (int i = 0; i < Q; ++i) {
				L.push_back(rnd.nextInt(1,N));
				R.push_back(rnd.nextInt(L.back(),N));
			}
		}
};