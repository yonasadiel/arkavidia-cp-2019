#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    string ans1, ans2;

    void InputFormat() {
        //
    }

    void OutputFormat() {
        LINE(ans1, ans2);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void MultipleTestCasesConfig() {
        //
    }

    void MultipleTestCasesConstraints() {
        //
    }

    void Constraints() {
        //
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void TestCases() {
        CASE();
    }
};
