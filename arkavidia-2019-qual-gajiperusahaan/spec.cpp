#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

typedef long long ll;

#define pb push_back
#define ppb pop_back

#define MAXN 1000000000000000000
#define MAXT 100

class ProblemSpec : public BaseProblemSpec {
protected:
	int t;
	ll n, res;

	void InputFormat() {
		LINE(n);
	}

	void OutputFormat() {
		LINE(res);
	}

	void GradingConfig() {
		TimeLimit(1);
		MemoryLimit(64);
	}

	void MultipleTestCasesConfig() {
		Counter(t);
	}

	void MultipleTestCasesConstraints() {
		CONS(1 <= t && t <= MAXT);
	}

	void Constraints() {
		CONS(1 <= n && n <= MAXN);
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({"2"});
	}

	void SampleTestCase2() {
		Input({"3"});
	}

	void SampleTestCase3() {
		Input({"5"});
	}

	void TestCases() {
		for (ll i=1;i<=10;++i) {
			CASE(n=i);
		}
		for (ll i=1;i<=10;++i) {
			CASE(n=rnd.nextInt(1, MAXT));
		}
		for (ll i=MAXN;i>MAXN-10;--i) {
			CASE(n=i);
		}
		for (ll i=1;i<=10;++i) {
			CASE(n=MAXN-rnd.nextInt(0, MAXT-1));
		}
		for (ll i=1;i<=60;++i) {
			CASE(n=rnd.nextLongLong(MAXT+1, MAXN-MAXT));
		}
	}
};