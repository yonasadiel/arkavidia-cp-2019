// by: Dicky Novanto

#include <tcframe/spec.hpp>
using namespace tcframe;

const int MAXTC = 10;
const int MAXN = 1000;
const int MAXQ = 1000;
const int MAXBANYAK = 1000;
const int MAXHARGA = 1000000;
const int MAXBANYAKBELI = 1000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int T;
    int n,q;
    vector<int> banyak, harga, banyakOrangBeli, ans;

    void InputFormat() {
        LINE(n, q);
        LINES(banyak, harga) % SIZE(n);
        LINES(banyakOrangBeli) % SIZE(q);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(q);
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
        CONS(1 <= T && T <= MAXTC);
    }

    void Constraints() {
        CONS(1 <= n && n <= MAXN);
        CONS(1 <= q && q <= MAXQ);
        CONS(eachElementBetween(banyak, 1, MAXBANYAK));
        CONS(eachElementBetween(harga, 1, MAXHARGA));
        CONS(eachElementBetween(banyakOrangBeli, 1, MAXBANYAKBELI));
        CONS(containBanyakEquals1(banyak));
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

    bool containBanyakEquals1(const vector<int>& v) {
        for(int x: v){
            if(x == 1){
                return true;
            }
        }
        return false;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "7 3",
            "1 1000",
            "2 2500",
            "3 3300",
            "4 3900",
            "5 4700",
            "6 6400",
            "7 7500",
            "3",
            "7",
            "12"
        });
        Output({
            "3000",
            "6700",
            "11400"
        });
    }

    void BeforeTestCase(){
        banyak.clear();
        banyakOrangBeli.clear();
        harga.clear();
        ans.clear();
    }

    void TestGroup1() {
        CASE(generateAllEquals1());
        CASE(generateGreedyCaseWA());
    }

    void TestGroup2() {
        CASE(generateMaxValueTC1());
        CASE(generateMaxValueTC2());
    }

    void TestGroup3() {
        for(int i=1;i<=MAXTC;i++){
            CASE(generateTcTLEPotential());    
        }
    }

    void TestGroup4() {
        for(int i=1;i<=MAXTC;i++){
            CASE(generateRandom());
        }
    }

private:
    void generateAllEquals1() {
        n = 1;
        q = 3;
        for(int i=0;i<n;i++){
            banyak.push_back(1);
            harga.push_back(1);    
        }
        for(int i=1;i<=q;i++){
            banyakOrangBeli.push_back(i);
        }
    }

    void generateGreedyCaseWA() {
        n = 3;
        q = 1000;
        banyak.push_back(1);
        harga.push_back(2);
        banyak.push_back(5);
        harga.push_back(13);
        banyak.push_back(7);
        harga.push_back(12);

        for(int i=1;i<=q;i++){
            banyakOrangBeli.push_back(i);
        }
        
    }

    void generateMaxValueTC1(){
        n = 1;
        q = 1;
        banyak.push_back(1);
        harga.push_back(MAXHARGA);
        banyakOrangBeli.push_back(MAXBANYAKBELI);
    }

    void generateMaxValueTC2(){
        n = MAXN;
        q = MAXQ;
        for(int i=1;i<=n;i++){
            banyak.push_back(i);
            harga.push_back(MAXHARGA);
        }
        for(int i=1;i<=q;i++){
            banyakOrangBeli.push_back(i);
        }
    }

    void generateTcTLEPotential() {
        n = MAXN;
        q = MAXQ;

        int cnt = 1;//for satisfying constraint there exist K = 1
        int p = rnd.nextInt(1, MAXHARGA);
        banyak.push_back(cnt);
        harga.push_back(p);
        for(int i=2;i<=n;i++) {
            cnt = rnd.nextInt(1, MAXBANYAK);
            p = rnd.nextInt(1, MAXHARGA);
            banyak.push_back(cnt);
            harga.push_back(p);
        }

        for(int i=1;i<=q;i++){
            banyakOrangBeli.push_back(i);
        }
    }

    void generateRandom() {
        n = rnd.nextInt(1,MAXN);
        q = MAXQ;
        int cnt = 1;
        int p = rnd.nextInt(1, MAXHARGA);
        banyak.push_back(cnt);
        harga.push_back(p);
        for(int i=2;i<=n;i++){
            cnt = rnd.nextInt(1, MAXBANYAK);
            p = rnd.nextInt(1, MAXHARGA);
            banyak.push_back(cnt);
            harga.push_back(p);   
        }
        for(int i=1;i<=q;i++){
            banyakOrangBeli.push_back(i);
        }
    }
};