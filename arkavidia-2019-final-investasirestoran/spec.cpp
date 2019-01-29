// by: Dicky Novanto

#include <tcframe/spec.hpp>
using namespace tcframe;

const int MAXTC = 10;
const int MAXN = 200;
const int MAXP = 1000000000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int T;
    int n,m,p;
    vector<int> placeList;
    vector<long long> ans;

    void InputFormat() {
        LINE(n, m, p);
        LINE(placeList);
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
        CONS(eachElementBetween(placeList, 1,MAXN));
        CONS(m == placeList.size());
        CONS(1 <= p && p <= MAXP);
        CONS(isAllDifferent(placeList));
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

    bool isAllDifferent(const vector<int>& v) {
        bool a[MAXN + 23];
        memset(a, false, sizeof a);
        for(int x: v){
            if(a[x]){
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
            "7 3 3",
            "1 4 2"
        });
        Output({
            "1 11"
        });
    }

    void BeforeTestCase(){
        placeList.clear();
    }

    void TestGroup1() {
    	for(int i=1;i<=MAXTC;i++){
    		CASE(generateOneFood());
    	}
    }

    void TestGroup2() {
        for(int i=1;i<=MAXTC;i++) {
            CASE(generateAllExistFood(i));
        }
    }

    void TestGroup3() {
        for(int i=1;i<=MAXTC;i++) {
            CASE(generateCaseMustWaitForFood());
        }
    }

    void TestGroup4() {
        for(int i=1;i<=MAXTC;i++){
            CASE(generateRandom());
        }
    }


private:
    void generateOneFood() {
        n = rnd.nextInt(1, MAXN);
        m = 1;
        p = rnd.nextInt(1, MAXP);
        int bil = rnd.nextInt(1, n);
        placeList.push_back(bil);
    }

    void generateAllExistFood(int idx) {
        n = MAXN;
        m = n;
        if(idx == 1){
            p = MAXP;    
        }else{
            p = rnd.nextInt(1, MAXP);    
        }
        for(int i=1;i<=m;i++){
            placeList.push_back(i);
        }
        random_shuffle(placeList.begin(), placeList.end());
    }

    void generateCaseMustWaitForFood() {
        n = MAXN;
        m = rnd.nextInt(1, n);
        int selisih = n - m;
        p = m + rnd.nextInt(1, 10);
        for(int i=1;i<=m;i++) {
            placeList.push_back(i);
        }
        random_shuffle(placeList.begin(), placeList.end());
    }

    void generateRandom() {
        n = rnd.nextInt(1, MAXN);
        m = rnd.nextInt(1, n);
        p = rnd.nextInt(1, MAXP);
        set<int> s;
        set<int>::iterator it;
        while(s.size() < m){
            int bil = rnd.nextInt(1, n);
            if(s.count(bil)){continue;}
            s.insert(bil);
        }
        for(it = s.begin(); it != s.end(); it++){
            placeList.push_back(*it);
        }
        random_shuffle(placeList.begin(), placeList.end());
    }

};