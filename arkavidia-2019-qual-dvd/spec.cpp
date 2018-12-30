#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define ull unsigned long long
#define MAXN 1000000000
#define MAXT 1000

class ProblemSpec : public BaseProblemSpec {
protected:
    int T, W, H, X1, X2, Y1, Y2;
    string result;

    void InputFormat() {
        LINE(W, H, X1, Y1, X2, Y2);
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
        CONS(1 <= W <= MAXN);
        CONS(1 <= H <= MAXN);
        CONS(1 <= X1 <= W);
        CONS(1 <= X2 <= W);
        CONS(1 <= Y1 <= H);
        CONS(1 <= Y2 <= H);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 10 2 4 3 6"
        });
        Output({
            "YAY"
        });
    }

    void TestCases() {
        for(int i = 0; i < 100; i++){
            CASE(W=MAXN,H=MAXN,randomize(X1,X2,Y1,Y2,W,H));
        }
        for(int i = 0; i < 10; i++){
            CASE(W=rnd.nextInt(1,MAXN), H=rnd.nextInt(1,MAXN), Variant1(X1,X2,Y1,Y2,W,H,1));
        }

        for(int i = 0; i < 10; i++){
            CASE(W=rnd.nextInt(1,MAXN), H=rnd.nextInt(1,MAXN), Variant1(X1,X2,Y1,Y2,W,H,0));
        }

        for(int i = 0; i < 10; i++){
            CASE(W=rnd.nextInt(1,MAXN), H=rnd.nextInt(1,MAXN), Variant2(X1,X2,Y1,Y2,W,H,1));
        }

        for(int i = 0; i < 10; i++){
            CASE(W=rnd.nextInt(1,MAXN), H=rnd.nextInt(1,MAXN), Variant2(X1,X2,Y1,Y2,W,H,0));
        }

        for(int i = 0; i < 860; i++){
            CASE(W=rnd.nextInt(1,MAXN), H=rnd.nextInt(1,MAXN), randomize(X1,X2,Y1,Y2,W,H));
        }
    }

private:
    void randomize(int &X1, int &X2, int &Y1, int &Y2, int W, int H){
        X1 = rnd.nextInt(1,W);
        X2 = rnd.nextInt(1,W);
        Y1 = rnd.nextInt(1,H);
        Y2 = rnd.nextInt(1,H);
    }

    //Horizontal line, v for guarantee valid
    void Variant1(int &X1, int &X2, int &Y1, int &Y2, int W, int H, bool v){
        if(v){
            X1 = rnd.nextInt(0,1)*(W-1)+1;
            X2 = X1;
        } else {
            X1 = rnd.nextInt(1,W);
            X2 = X1;
        }
        Y1 = rnd.nextInt(1,H);
        Y2 = rnd.nextInt(1,H);
    }

    //Vertical line, v for guarantee valid
    void Variant2(int &X1, int &X2, int &Y1, int &Y2, int W, int H, bool v){
        X1 = rnd.nextInt(1,W);
        X2 = rnd.nextInt(1,W);
        if(v){
            Y1 = rnd.nextInt(0,1)*(H-1)+1;
            Y2 = Y1;
        } else {
            Y1 = rnd.nextInt(1,H);
            Y2 = Y1;
        }
    }    
};
