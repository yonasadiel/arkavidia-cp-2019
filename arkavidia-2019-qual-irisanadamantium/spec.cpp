#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define MAXN 100000
#define MAXT 10

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
        CONS(arr.size() == 2*N);
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
        return true;
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
            "3",
            "1 2 3 1 2 3"
        });
        Output({
            "8"
        });
    }

    void SampleTestCase2() {
        Input({
            "3",
            "1 1 2 2 3 3"
        });
        Output({
            "42"
        });
    }

    void SampleTestCase3() {
        Input({
            "3",
             "1 2 1 2 3 3"
        });
        Output({
            "36"
        });
    }

    void BeforeTestCase() {
        arr.clear();
    }

    void TestGroup1() {
        CASE(N=MAXN, Variant1(arr,N));
        CASE(N=MAXN, Variant1(arr,N), Reverse(arr));
        CASE(N=MAXN, Variant2(arr,N));
        CASE(N=MAXN, Variant2(arr,N), Reverse(arr));
        for(int i = 1; i <= 6; i++){
            CASE(N=rnd.nextInt(1,MAXN), RandomArray(arr,N));
        }
    }

    void TestGroup2() {
        for(int i = 1; i <= 10; i++){
            CASE(N=rnd.nextInt(1,MAXN), RandomArray(arr,N));
        }
    }

    void TestGroup3() {
        for(int i = 1; i <= 10; i++){
            CASE(N=rnd.nextInt(1,MAXN), RandomArray(arr,N));
        }
    }

    void TestGroup4() {
        for(int i = 1; i <= 10; i++){
            CASE(N=rnd.nextInt(1,MAXN), RandomArray(arr,N));
        }
    }

    void TestGroup5() {
        for(int i = 1; i <= 10; i++){
            CASE(N=rnd.nextInt(1,MAXN), RandomArray(arr,N));
        }
    }

private:
    //1 1 2 2 3 3
    void Variant1(vector<int> &v, int N){
        for(int i = 1; i <= N; i++){
            v.push_back(i);
            v.push_back(i);
        }
    }

    //1 2 3 1 2 3
    void Variant2(vector<int> &v, int N){
        for(int i = 1; i <= N; i++){
            v.push_back(i);
        }
        for(int i = 1; i <= N; i++){
            v.push_back(i);
        }
    }

    void RandomArray(vector<int> &v, int N){
        Variant1(v, N);
        rnd.shuffle(v.begin(),v.end());
    }

    void Reverse(vector<int> &v){
        reverse(v.begin(),v.end());
    }
};
