#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define MAXN 100000
#define MAXT 100

class ProblemSpec : public BaseProblemSpec {
protected:
    int T, N, result;
    vector<int> arr;

    void InputFormat() {
        LINE(N);
        LINE(arr % SIZE(2*N));
    }

    void OutputFormat() {
        LINE(result);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void MultipleTestCasesConfig() {
        Counter(T);
        OutputPrefix("");
    }

    void MultipleTestCasesConstraints() {
        CONS(1 <= T && T <= MAXT);
    }

    void Constraints() {
        CONS(1 <= N <= MAXN);
        CONS(arr.size() == 2*MAXN);
        CONS(isValid(arr,N));
    }

private:
    bool isValid(vector<int> arr, int N){
        if(!allElementBetween(1,N,2*N, arr))return false;

        int cek[2*N+5];
        for(int i = 0; i <= 2*N; i++)cek[i] = 0;

        for(int i = 0; i < 2*N; i++){
            if(cek[arr[i]] == 2)return false;
            cek[arr[i]]++;
        }
        return res;
    }

    bool allElementBetween(int a, int b, int N, vector<int> arr){
        for(int i = 0; i < N; i++){
            if(arr[i] < a or arr[i] > b)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3
             1 2 3 1 2 3"
        });
        Output({
            "8"
        });
    }

    void SampleTestCase1() {
        Input({
            "3
             1 1 2 2 3 3"
        });
        Output({
            "42"
        });
    }

    void SampleTestCase1() {
        Input({
            "3
             1 2 1 2 3 3"
        });
        Output({
            "36"
        });
    }

    void TestCases() {
        CASE(L = 1, R = 2);

        for (long long i = 0; i <= 100; i++)
            for (long long j = 0; j <= 100; j++)
                CASE(L = 1 + i, R = 1000000000000000000 - j);

        for (long long i = 0; i <= 10; i++)
            for (long long j = 0; j <= 10; j++)
                CASE(L = 144115188075855871 + i, R = 288230376151711743 - j);

        for (long long i = 0; i <= 10; i++)
            for (long long j = 0; j <= 10; j++)
                CASE(L = 159202181970746799 + i, R = 529566899057755602 - j);

        for (long long i = 0; i <= 1000; i++)
            for (long long j = 0; j <= 100; j++)
                CASE(L = 297379960876591172 + i, R = 801972410549895275 - j);
    }
};
