#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

#define MAXT 100
#define MAXN 100000
#define MAXW 100000
#define MINW -100000

class ProblemSpec : public BaseProblemSpec {
	protected:
		int N, T;
		vector<int> U, V, W;
		int res;

		void MultipleTestCasesConfig() {
			Counter(T);
			OutputPrefix("");
		}

		void InputFormat() {
			LINE(N);
			LINES(U, V, W) % SIZE(N-1);
		}

		void OutputFormat() {
			LINE(res);
		}

		void MultipleTestCasesConstraints() {
			CONS(1 <= T && T <= MAXT);
		}

		void GradingConfig() {
			TimeLimit(1);
			MemoryLimit(64);
		}

		void Constraints() {
			CONS(2 <= N && N <= 100000);
			CONS(eachElementBetween(U, 1, N));
			CONS(eachElementBetween(V, 1, N));
			CONS(eachElementBetween(W, MINW, MAXW));
			CONS(noSelfLoop(U, V));
			CONS(isConnected(N, U, V));
		}

	private:
		bool eachElementBetween(const vector<int>& v, int lo, int hi) {
			for (int x : v) {
				if (x < lo || x > hi) {
					return false;
				}
			}
			return true;
		}

		bool allAreEqual(const vector<int>& v) {
			for (int x : v) {
				if (x != v[0]) {
					return false;
				}
			}
			return true;
		}

		bool noSelfLoop(const vector<int>& u, const vector<int>& v) {
			for (int i = 0; i < u.size(); i++) {
				if (u[i] == v[i]) {
					return false;
				}
			}
			return true;
		}

		bool isConnected(int n, const vector<int>& u, const vector<int>& v) {
			vector<bool> isVisited(n+1);
			vector<vector<int>> adj(n+1);
			for (int i = 0; i < u.size(); i++) {
				adj[u[i]].push_back(v[i]);
				adj[v[i]].push_back(u[i]);
			}
			int numNodesVisited = 0;
			queue<int> q;
			q.push(1);
			while (!q.empty()) {
				int now = q.front();
				q.pop();
				if (isVisited[now]) {
					continue;
				}
				isVisited[now] = true;
				++numNodesVisited;
				for (int v : adj[now]) {
					q.push(v);
				}
			}
			return numNodesVisited == n;
		}
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
	void SampleTestCase1() {
		Input({
			"7\n3 4 9\n1 2 3\n2 7 2\n3 6 1\n2 3 8\n3 5 5"
		});
		Output({
			"36"
		});
	}

	void SampleTestCase2() {
		Input({
			"5\n1 2 -1\n2 3 2\n3 4 3\n4 5 -5"
		});
		Output({
			"-6"
		});
	}
	void BeforeTestCase() {
		U.clear();
		V.clear();
		W.clear();
	}

	void TestCases() {
		// Group 1a
		CASE(N = 2, U = {1}, V = {2}, W = {1});
		CASE(N = 21, randomTree(N, U, V), W.assign(N-1, 1000));

		for (int i = 0; i < 5; i++) {
			CASE(N = rnd.nextInt(2, 21),
				 randomTree(N, U, V),
				 W.assign(N-1, rnd.nextInt(1, 1000)));
		}

		// Group 1b
		CASE(N = 2, U = {1}, V = {2}, W = {-1});
		CASE(N = 21, randomTree(N, U, V), W.assign(N-1, -1000));

		for (int i = 0; i < 5; i++) {
			CASE(N = rnd.nextInt(2, 21),
				 randomTree(N, U, V),
				 W.assign(N-1, rnd.nextInt(-1000, -1)));
		}

		// Group 2
		CASE(N = 21, randomTree(N, U, V), randomWeight(N, W));
		for (int i = 0; i < 5; i++) {
			CASE(N = rnd.nextInt(2, 21),
				 randomTree(N, U, V),
				 randomWeight(N, W));
		}

		// Group 3a
		CASE(N = 2, randomTree(N, U, V), W.assign(N-1, rnd.nextInt(1, 1000)));
		CASE(N = 100000, randomTree(N, U, V), W.assign(N-1, 1000));
		CASE(N = 100000, randomTree(N, U, V), W.assign(N-1, 1000));
		for (int i = 0; i < 5; i++) {
			CASE(N = rnd.nextInt(2, 100000), 
				 randomTree(N, U, V),
				 W.assign(N-1, rnd.nextInt(1, 1000)));
		}

		// Group 3b
		CASE(N = 2, randomTree(N, U, V), W.assign(N-1, rnd.nextInt(-1000, -1)));
		CASE(N = 100000, randomTree(N, U, V), W.assign(N-1, -1000));
		CASE(N = 100000, randomTree(N, U, V), W.assign(N-1, -1000));
		for (int i = 0; i < 5; i++) {
			CASE(N = rnd.nextInt(2, 100000),
				 randomTree(N, U, V),
				 W.assign(N-1, rnd.nextInt(-1000, -1)));
		}

		// Group 4
		CASE(N = 2, randomTree(N, U, V), randomWeight(N, W));
		CASE(N = 100000, randomTree(N, U, V), randomWeight(N, W));
		CASE(N = 100000, randomTree(N, U, V), randomWeight(N, W));
		for (int i = 0; i < 5; i++) {
			CASE(N = rnd.nextInt(2, 100000),
				 randomTree(N, U, V),
				 randomWeight(N, W));
		}
	}

	private:
		// Fushar template code
		void randomWeight(int m, vector<int>& w, int minW = MINW, int maxW = MAXW) {
			for (int i = 1; i < m; i++) {
				w.push_back(rnd.nextInt(minW, maxW));
			}
		}

		void renumber(int n, vector<int>& u, vector<int>& v) {
			vector<int> permutation;
			for (int i = 1; i <= n; i++) {
				permutation.push_back(i);
			}
			rnd.shuffle(permutation.begin(), permutation.end());
			for (int i = 0; i < u.size(); i++) {
				u[i] = permutation[u[i]-1];
				v[i] = permutation[v[i]-1];
			}
		}

		void randomTree(int n, vector<int>& u, vector<int>& v) {
			for (int i = 2; i <= n; i++) {
				u.push_back(i);
				v.push_back(rnd.nextInt(1, i-1));
			}
			renumber(n, u, v);
		}
};