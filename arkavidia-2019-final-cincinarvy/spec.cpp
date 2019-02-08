#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace tcframe;

#define MAXT 100000
#define MAXVAL 1000000000

class ProblemSpec : public BaseProblemSpec {
private:

    template <class T>
    bool eachVectorElementBetween(const vector<T>& X, T lo, T hi) {
        for (T x : X)
            if (x < lo || x > hi)
                return false;
        return true;
    }

protected:
    int T;
    std::vector<int> d, x, y, vk, va;
    std::vector<std::string> ans;

    void InputFormat() {
        LINE(T);
        LINES(d, x, y, vk, va) % SIZE(T);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(T);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= T && T <= MAXT);
        CONS(d.size() == T);
        CONS(x.size() == T);
        CONS(y.size() == T);
        CONS(vk.size() == T);
        CONS(va.size() == T);
        CONS(eachVectorElementBetween<int>(d, 1, MAXVAL));
        CONS(eachVectorElementBetween<int>(x, 1, MAXVAL));
        CONS(eachVectorElementBetween<int>(y, 1, MAXVAL));
        CONS(eachVectorElementBetween<int>(vk, 1, MAXVAL));
        CONS(eachVectorElementBetween<int>(va, 1, MAXVAL));
        // CONS(ans == "YA" || ans == "TIDAK");
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
private:

protected:
    void SampleTestCase1(){
        Input({
            "3",
            "1 100 1 5 20",
            "1 10 20 10 5",
            "1 4 6 5 5"
        });
        Output({
            "YA",
            "TIDAK",
            "YA"
        });
    }

    void BeforeTestCase() {
        d.clear();
        x.clear();
        y.clear();
        vk.clear();
        va.clear();
    }

    void TestCases(){
        // 1
        CASE(
            T = MAXT,
            generate_random(MAXT, d, 1, MAXVAL),
            generate_random(MAXT, x, 1, MAXVAL),
            generate_random(MAXT, y, 1, MAXVAL),
            generate_random(MAXT, vk, 1, MAXVAL),
            generate_random(MAXT, va, 1, MAXVAL)
        );
        // 2
        CASE(
            T = MAXT,
            generate_random(MAXT, d, 1, MAXVAL),
            generate_random(MAXT, x, 1, MAXVAL),
            generate_random(MAXT, y, 1, MAXVAL),
            generate_random(MAXT, vk, 1, MAXVAL),
            generate_random(MAXT, va, 1, MAXVAL)
        );
        // 3
        CASE(
            T = MAXT,
            generate_random(MAXT, d, 1, 100),
            generate_random(MAXT, x, 1, 100),
            generate_random(MAXT, y, 1, MAXVAL),
            generate_random(MAXT, vk, 1, MAXVAL),
            generate_random(MAXT, va, 1, MAXVAL)
        );
        // 4
        CASE(
            T = MAXT,
            generate_random(MAXT, d, 1, 1000),
            generate_random(MAXT, x, 1, 1000),
            generate_random(MAXT, y, 1, MAXVAL),
            generate_random(MAXT, vk, 1, MAXVAL),
            generate_random(MAXT, va, 1, MAXVAL)
        );
        /* vk > va */
        // 5
        CASE(
            T = MAXT,
            generate_random(MAXT, d, 1, MAXVAL),
            generate_random(MAXT, x, 1, MAXVAL),
            generate_random(MAXT, y, 1, MAXVAL),
            generate_big_small(MAXT, vk, va, 1, MAXVAL)
        );
        // 6
        CASE(
            T = MAXT,
            generate_random(MAXT, d, 1, MAXVAL),
            generate_random(MAXT, x, 1, MAXVAL),
            generate_random(MAXT, y, 1, MAXVAL),
            generate_big_small(MAXT, vk, va, 1, MAXVAL)
        );
        /* va = vk */
        // 7
        CASE(
            T = MAXT,
            generate_random(MAXT, d, 1, MAXVAL),
            generate_random(MAXT, x, 1, MAXVAL),
            generate_random(MAXT, y, 1, MAXVAL),
            generate_random(MAXT, vk, 1, MAXVAL),
            va = vk
        );
        // 8
        CASE(
            T = MAXT,
            generate_random(MAXT, d, 1, MAXVAL),
            generate_random(MAXT, x, 1, MAXVAL),
            generate_random(MAXT, y, 1, MAXVAL),
            generate_random(MAXT, vk, 1, MAXVAL),
            va = vk
        );
    }

private:
    void generate_random(int N, std::vector<int> &v, int lo, int hi){
        for(int i=0;i<N;++i){
            v.push_back(rnd.nextInt(lo, hi));
        }
    }

    void generate_big_small(int N, std::vector<int> &v, std::vector<int> &w, int lo, int hi){
        for(int i=0;i<N;++i){
            int t1 = rnd.nextInt(lo, hi);
            int t2 = rnd.nextInt(lo, hi);
            while(t1 == t2){
                t2 = rnd.nextInt(lo, hi);
            }
            if(t1 < t2){
                std::swap(t1, t2);
            }
            v.push_back(t1);
            w.push_back(t2);
        }
    }
};