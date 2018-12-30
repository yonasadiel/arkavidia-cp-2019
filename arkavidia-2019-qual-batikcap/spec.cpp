#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define pb push_back
#define ppb pop_back

#define MAXN 1000000
#define MAXT 100

class ProblemSpec : public BaseProblemSpec {
protected:
	int t;
	string a,b,s;

	void InputFormat() {
		LINE(a, b);
	}

	void OutputFormat() {
		LINE(s);
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
		CONS(1 <= a.length() && a.length() <= MAXN);
		CONS(1 <= b.length() && b.length() <= MAXN);
		CONS(isLower(a) && isLower(b));
	}
private:
	bool isLower(string s) {
		for (auto e:s) {
			if (e<'a' || e>'z') {
				return 0;
			}
		}
		return 1;
	}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({"ababab abab"});
	}

	void SampleTestCase2() {
		Input({"bbcdbbcd bbcd"});
	}

	void SampleTestCase3() {
		Input({"aaa bb"});
	}

	void BeforeTestCase() {
		a.clear();
		b.clear();
	}

	void TestGroup1() {
		CASE(RandomLarge(a, MAXN), b=a);
	}

	void TestGroup2() {
		CASE(EqualChar(a, MAXN), b=a);
	}

	void TestGroup3() {
		CASE(EqualChar(a, MAXN), EqualChar(b, rnd.nextInt(MAXN/10, MAXN)));
	}

	void TestGroup4() {
		CASE(EqualChar(a, 930930), b=a);
	}

	void TestGroup5() {
		CASE(EqualChar(a, 930930), b=a.substr(0, 870870));
	}

	void TestGroup6() {
		CASE(RandomLarge(a, MAXN), RandomLarge(b, rnd.nextInt(MAXN/10, MAXN)));
	}

	void TestGroup7() {
		for (int i=0;i<MAXT;++i) {
			CASE(RandomLimitChar(a, 2), RandomLimitChar(b, 2));
		}
	}

	void TestGroup8() {
		for (int i=0;i<MAXT;++i) {
			CASE(RandomLarge(a, MAXN/MAXT), RandomLarge(b, MAXN/MAXT));
		}
	}

	void TestGroup9() {
		CASE(Construct(a, 997, 997), b=a);
	}

	void TestGroup10() {
		CASE(Construct(a, 997, 997), b=a.substr(0, 997));
	}

	void TestGroup11() {
		for (int i=0;i<MAXT;++i) {
			CASE(Construct(a, rnd.nextInt(10, 100), rnd.nextInt(10, 100)), Construct(b, rnd.nextInt(10, 100), rnd.nextInt(10, 100)));
		}
	}

	void TestGroup12() {
		for (int i=0;i<MAXT;++i) {
			CASE(Generate(a, b, rnd.nextInt(1, 100)));
		}
	}

	void TestGroup13() {
		CASE(a="ababab", b="abab");
		CASE(a="bbcdbbcd", b="bbcd");
		CASE(a="aaa", b="bb");
		CASE(a="a", b="a");
		CASE(a="a", b="b");
		CASE(a="a", b="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
		CASE(a="a", b="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
		CASE(a="abcabcd", b="defdefdef");
		CASE(a="abab", b="abababababab");
		CASE(a="zyz", b="zyzyz");
		CASE(a="abacadae", b="abacad");
		CASE(a="bacadaea", b="bacada");
		for (int i=0;i<(MAXT-10)/2-1;++i) {
			CASE(RandomLarge(a, rnd.nextInt(500, 1000)), b=a);
		}
		for (int i=0;i<(MAXT-10)/2-1;++i) {
			CASE(RandomLarge(a, rnd.nextInt(500, 1000)), RandomLarge(b, rnd.nextInt(500, 1000)));
		}
	}

private:
	void RandomLarge(string& a, int n) {
		for (int i=0;i<n;++i) {
			a.pb('a' + rnd.nextInt(0, 25));
		}
	}

	void EqualChar(string& s, int n) {
		char c = 'a'+rnd.nextInt(0, 25);
		for (int i=0;i<n;++i) {
			s.pb(c);
		}
	}

	void RandomLimitChar(string& s, int k) {
		int n = rnd.nextInt(1, MAXN/MAXT/2);
		for (int i=0;i<n;++i) {
			s.pb('a'+rnd.nextInt(0, k-1));
		}
	}

	void Construct(string& s, int k, int n) {
		n *= k;
		for (int i=0;i<k;++i) {
			s.pb('a' + rnd.nextInt(0, 25));
		}
		for (int i=k;i<n;++i) {
			s.pb(a[i%k]);
		}
	}

	void Generate(string& a, string& b, int k) {
		int n,m;
		n = k*rnd.nextInt(10, 100);
		m = k*rnd.nextInt(10, 100);
		for (int i=0;i<k;++i) {
			a.pb('a' + rnd.nextInt(0, 25));
			b.pb(a.back());
		}
		for (int i=k;i<n;++i) {
			a.pb(a[i%k]);
		}
		for (int i=k;i<m;++i) {
			b.pb(b[i%k]);
		}
	}
};