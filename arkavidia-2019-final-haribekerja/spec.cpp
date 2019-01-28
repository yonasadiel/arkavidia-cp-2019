// by: Dicky Novanto

#include <tcframe/spec.hpp>
using namespace tcframe;

const int MAXTC = 10;
const int MAXN = 100000;
const int MAXLANTAI = 1000000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int T;
    int n,q;
    vector<int> listLantai, ans;

    void InputFormat() {
        LINE(n);
        LINE(listLantai);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void MultipleTestCasesConfig() {
        Counter(T);
        OutputPrefix("");
    }

    void MultipleTestCasesConstraints() {
        CONS(1 <= T && T <= MAXTC);
    }

    void Constraints() {
        CONS(1 <= n && n <= MAXN);
        CONS(eachElementBetween(listLantai, 1, MAXLANTAI));
        CONS(n == listLantai.size());
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for(int x: v) {
            if(x < lo || x > hi){
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3",
            "5 14 15"
        });
        Output({
            "4 -1 12"
        });
    }

    void BeforeTestCase(){
        ans.clear();
        listLantai.clear();
    }

    void TestGroup1() {
    	for(int i=1;i<=MAXTC;i++){
    		CASE(generateAll(i));
    	}
    }

private:
    void generateAll(int akhir) {
    	n = MAXN;
        akhir *= MAXN;
        int awal = akhir - MAXN + 1;
        for(int i=awal;i<=akhir;i++){
        	listLantai.push_back(i);
        }
    }
};