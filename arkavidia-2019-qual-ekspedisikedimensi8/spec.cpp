#include <tcframe/spec.hpp>
#include <cmath>
using namespace tcframe;

#define MAXCASE 5
#define MAXVALUE 100000
#define MAX_DIM 8
#define MAX_MUL 100000
#define MAX_QUERY 100

int prod(const vector<int>& v) {
    int res = 1;
    for (int x : v) res *= x;
    return res;
}

class ProblemSpec : public BaseProblemSpec {
protected:
    int T;
    int num_dim;
    int num_query;
    vector<int> dim_size;
    vector<int> value;
    vector<vector<int> > query;
    vector<long long> sum;

    void InputFormat() {
        LINE(num_dim);
        LINE(dim_size % SIZE(num_dim));
        LINE(value % SIZE(prod(dim_size)));
        LINE(num_query);
        LINES(query) % SIZE(2 * num_query);
    }

    void OutputFormat() {
        LINES(sum) % SIZE(num_query);
    }

    void MultipleTestCasesConfig(){
        Counter(T);
    }

    void MultipleTestCasesConstraints() {
        CONS(1 <= T && T <= MAXCASE);
    }

    void GradingConfig() {
        TimeLimit(10);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= num_dim && num_dim <= MAX_DIM);
        CONS(1 <= prod(dim_size) && prod(dim_size) <= MAX_MUL);
        CONS(dim_size.size() == num_dim);
        CONS(value.size() == prod(dim_size));
        CONS(eachElementBetween(value, -MAXVALUE, MAXVALUE));
        CONS(1 <= num_query && num_query <= MAX_QUERY);
        CONS(query.size() == 2*num_query);
        CONS(eachQueryBetweenDimensionSize(query, dim_size));
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
    bool eachQueryBetweenDimensionSize(const vector<vector<int> > &a, const vector<int>& dim){
        for(const vector<int> &x : a){
            if(x.size() != dim.size()){
                return false;
            }
            for(int i=0;i < (int)x.size();++i){
                if(1 > x[i] || x[i] > dim[i]){
                    return false;
                }
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
private:
    void generate_query(vector<vector<int> >& res, const vector<int>& dim_size) {
        for(int i=0;i<num_query;++i){
            vector<int> left, right;
            for(int j=0;j<num_dim;++j){
                int a = rnd.nextInt(1, dim_size[j]);
                int b = rnd.nextInt(1, dim_size[j]);
                left.push_back(min(a, b));
                right.push_back(max(a, b));
            }
            res.push_back(left);
            res.push_back(right);
        }
    }

    void generate_random_values(int num, vector<int>& res) {
        for(int i=0;i<num;++i){
            res.push_back(rnd.nextInt(-MAXVALUE, MAXVALUE));
        }
    }

    void generate_dim(vector<int>& dim_sizes){
        int tot = 1;
        for(int i=num_dim;i>=1;--i){
            int now = rnd.nextInt(1, (int)pow(1.0*MAX_MUL/tot, 1.0/i));
            tot *= now;
            dim_sizes.push_back(now);
        }
    }

protected:
    void SampleTestCase1() {
        Input({
            "1",
            "5",
            "1 2 3 4 5",
            "2",
            "1",
            "3",
            "2",
            "5"
        });
        Output({
            "6",
            "14"
        });
    }
    void SampleTestCase2() {
        Input({
            "2",
            "4 5",
            "1 2 7 5 4 -10 5 -1 -3 2 3 4 4 -8 11 -3 3 7 -1 9",
            "3",
            "1 2",
            "2 2",
            "3 3",
            "4 5",
            "3 2",
            "4 3"
        });
        Output({
            "7",
            "22",
            "18"
        });
    }

    void BeforeTestCase() {
        dim_size.clear();
        value.clear();
        for (int i=0; i<query.size(); i++) {
            query[i].clear();
        }
        query.clear();
        sum.clear();
    }

    void TestGroup1() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = 1,
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup2() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = 2,
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup3() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = 3,
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup4() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = 4,
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup5() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = 5,
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup6() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = 6,
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup7() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = 7,
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup8() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = 8,
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup9() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = rnd.nextInt(1, MAX_DIM),
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup10() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = rnd.nextInt(1, MAX_DIM),
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup11() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = rnd.nextInt(1, MAX_DIM),
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup12() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = rnd.nextInt(1, MAX_DIM),
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup13() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = rnd.nextInt(1, MAX_DIM),
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }

    void TestGroup14() {
        for(int i=0;i<MAXCASE;++i){
            CASE(
                num_dim = rnd.nextInt(1, MAX_DIM),
                generate_dim(dim_size),
                generate_random_values(prod(dim_size), value),
                num_query = rnd.nextInt(1, MAX_QUERY),
                generate_query(query, dim_size));
        }
    }
};