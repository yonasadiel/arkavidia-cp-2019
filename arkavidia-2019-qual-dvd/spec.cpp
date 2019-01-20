#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define ull unsigned long long
#define MINN 3
#define MAXN 1000000000
#define MAXV 1000000000
#define MAXT 1000

class ProblemSpec : public BaseProblemSpec {
protected:
    int T, W, H, WL, HL, X, Y, VX, VY;
    string result;

    void InputFormat() {
        LINE(W, H, WL, HL);
        LINE(X, Y, VX, VY);
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
        CONS(MINN <= W <= MAXN);
        CONS(MINN <= H <= MAXN);
        CONS(1 <= WL <= W);
        CONS(1 <= HL <= H);
        CONS(0 <= X && X <= W - WL);
        CONS(0 <= Y && Y <= H - HL);
        CONS(-MAXV <= VX <= MAXV);
        CONS(-MAXV <= VY <= MAXV);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "7 8 2 3",
            "1 2 4 4"
        });
        Output({
            "TIDAK"
        });
    }

    void SampleTestCase2() {
        Input({
            "7 4 1 1",
            "3 3 1 -1"
        });
        Output({
            "YA"
        });
    }

    void SampleTestCase3() {
        Input({
            "9 9 3 4",
            "6 3 1 -1"
        });
        Output({
            "YA"
        });
    }

    void TestGroup1() {
        // corner case

        // sudah di sisi, gerak
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = 0, Y = rnd.nextInt(0, H - HL),
            VX = 0, VY = rnd.nextInt(-MAXV, MAXV));
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = rnd.nextInt(0, W - WL), Y = 0,
            VX = rnd.nextInt(-MAXV, MAXV), VY = 0);
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = W - WL, Y = rnd.nextInt(0, H - HL),
            VX = 0, VY = rnd.nextInt(-MAXV, MAXV));
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = rnd.nextInt(0, W - WL), Y = H - HL,
            VX = rnd.nextInt(-MAXV, MAXV), VY = 0);

        // sudah di sudut, diem
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = 0, Y = H - HL,
            VX = 0, VY = 0);
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = W - WL, Y = H - HL,
            VX = 0, VY = 0);
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = 0, Y = 0,
            VX = 0, VY = 0);
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = W - WL, Y = 0,
            VX = 0, VY = 0);

        // diem, tapi di tengah
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = rnd.nextInt(0, W - WL), Y = rnd.nextInt(0, H - HL),
            VX = 0, VY = 0);

        // sudah di sisi, diem
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = 0, Y = rnd.nextInt(0, H - HL),
            VX = 0, VY = 0);
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = rnd.nextInt(0, W - WL), Y = 0,
            VX = 0, VY = 0);
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = W - WL, Y = rnd.nextInt(0, H - HL),
            VX = 0, VY = 0);
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = rnd.nextInt(1, W), HL = rnd.nextInt(1, H),
            X = rnd.nextInt(0, W - WL), Y = H - HL,
            VX = 0, VY = 0);

        // ukuran logo =  monitor
        CASE(
            W = rnd.nextInt(MINN, MAXN), H = rnd.nextInt(MINN, MAXN),
            WL = W, HL = H,
            X = 0, Y = 0,
            VX = rnd.nextInt(-MAXV, MAXV), VY = rnd.nextInt(-MAXV, MAXV));
    }

    void TestGroup2() {
        for(int i = 0; i < 100; i++) {
            CASE(
                W = MAXN,
                H = MAXN,
                WL = rnd.nextInt(1, W),
                HL = rnd.nextInt(1, H),
                X = rnd.nextInt(0, W - WL),
                Y = rnd.nextInt(0, H - HL),
                VX = rnd.nextInt(-MAXV, MAXV),
                VY = rnd.nextInt(-MAXV, MAXV));
        }

        for(int i = 0; i < 10; i++) {
            CASE(
                W = rnd.nextInt(MINN,MAXN), H = rnd.nextInt(MINN,MAXN),
                WL = rnd.nextInt(1, W - 1), HL = rnd.nextInt(1, H - 1);
                Variant1(X, Y, VX, VY, W, H, WL, HL, 1));
        }

        for(int i = 0; i < 10; i++) {
            CASE(
                W = rnd.nextInt(MINN,MAXN), H = rnd.nextInt(MINN,MAXN),
                WL = rnd.nextInt(1, W - 1), HL = rnd.nextInt(1, H - 1);
                Variant1(X, Y, VX, VY, W, H, WL, HL, 0));
        }

        for(int i = 0; i < 10; i++) {
            CASE(
                W = rnd.nextInt(MINN,MAXN), H = rnd.nextInt(MINN,MAXN),
                WL = rnd.nextInt(1, W - 1), HL = rnd.nextInt(1, H - 1);
                Variant2(X, Y, VX, VY, W, H, WL, HL, 1));
        }

        for(int i = 0; i < 10; i++) {
            CASE(
                W = rnd.nextInt(MINN,MAXN), H = rnd.nextInt(MINN,MAXN),
                WL = rnd.nextInt(1, W - 1), HL = rnd.nextInt(1, H - 1);
                Variant2(X, Y, VX, VY, W, H, WL, HL, 0));
        }

        for(int i = 0; i < 860; i++) {
            CASE(
                W = rnd.nextInt(MINN, MAXN),
                H = rnd.nextInt(MINN, MAXN),
                WL = rnd.nextInt(1, W),
                HL = rnd.nextInt(1, H),
                X = rnd.nextInt(0, W - WL),
                Y = rnd.nextInt(0, H - HL),
                VX = rnd.nextInt(-MAXV, MAXV),
                VY = rnd.nextInt(-MAXV, MAXV));
        }
    }

private:

    //Horizontal line, v for guarantee valid
    void Variant1(int &X, int &Y, int &VX, int &VY, int W, int H, int WL, int HL, bool v){
        X = v ? rnd.nextInt(0, 1) * (W - WL) : rnd.nextInt(1, W - WL - 1);
        VX = 0;
        Y = rnd.nextInt(0, H - HL);
        VY = rnd.nextInt(-MAXV, MAXV);
    }

    //Vertical line, v for guarantee valid
    void Variant2(int &X, int &Y, int &VX, int &VY, int W, int H, int WL, int HL, bool v) {
        X = rnd.nextInt(0, W - WL);
        VX = rnd.nextInt(-MAXV, MAXV);
        Y = v ? rnd.nextInt(0, 1) * (H - HL) : rnd.nextInt(1, H - HL - 1);
        VY = 0;
    }
};
