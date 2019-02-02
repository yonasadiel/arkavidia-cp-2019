#include <tcframe/spec.hpp>
using namespace tcframe;

#define MAXT 10
#define MAXN 20
#define MINN 2
#define MAXM 100000

class ProblemSpec : public BaseProblemSpec {
private:
    template <class T>
    bool eachVectorElementBetween(const vector<T>& X, T lo, T hi) {
        for (const T &x : X)
            if (x < lo || x > hi)
                return false;
        return true;
    }

    bool eachVectorElementValidChar(const vector<char> v){
        for(char c : v){
            if(!(c=='x' || c=='X' || c=='y' || c=='Y' || c=='z' || c=='Z'))
                return false;
        }
        return true;
    }

protected:
    int n, m, T;
    vector<int> p;
    vector<char> c;
    long long ans;

    void InputFormat() {
        LINE(n, m);
        LINES(c, p) % SIZE(m);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void MultipleTestCasesConfig() {
        Counter(T);
        OutputPrefix("");
    }

    void MultipleTestCasesConstraints() {
        CONS(1 <= T && T <= MAXT);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(MINN <= n <= MAXN);
        CONS(1 <= m <= MAXM);
        CONS(eachVectorElementBetween(p, 1, n));
        CONS(eachVectorElementValidChar(c));
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3 2",
            "Y 2",
            "y 1"
        });
        Output({
            "4"
        });
    }

    void SampleTestCase2() {
        Input({
            "2 3",
            "x 2",
            "Y 1",
            "z 1"
        });
        Output({
            "30"
        });
    }

    void BeforeTestCase(){
        c.clear();
        p.clear();
    }
    
    /* n = 2 */
    void TestGroup1(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 2,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 3 */
    void TestGroup2(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 3,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 4 */
    void TestGroup3(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 4,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 5 */
    void TestGroup4(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 5,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 6 */
    void TestGroup5(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 6,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 7 */
    void TestGroup6(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 7,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 8 */
    void TestGroup7(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 8,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 9 */
    void TestGroup8(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 9,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 10 */
    void TestGroup9(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 10,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 11 */
    void TestGroup10(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 11,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 12 */
    void TestGroup11(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 12,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 13 */
    void TestGroup12(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 13,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 14 */
    void TestGroup13(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 14,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 15 */
    void TestGroup14(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 15,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 16 */
    void TestGroup15(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 16,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 17 */
    void TestGroup16(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 17,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 18 */
    void TestGroup17(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 18,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 19 */
    void TestGroup18(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 19,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* n = 20 */
    void TestGroup19(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = 20,
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    /* random */
    void TestGroup20(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = rnd.nextInt(MINN, MAXN),
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    void TestGroup21(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = rnd.nextInt(MINN, MAXN),
                m = rnd.nextInt(1, MAXM),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    void TestGroup22(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = rnd.nextInt(MINN, MAXN),
                m = rnd.nextInt(1, 10000),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

    void TestGroup23(){
        for(int i=0;i<MAXT;++i){
            CASE(
                n = rnd.nextInt(MINN, MAXN),
                m = rnd.nextInt(1, 100),
                generateChar(c, m),
                generateIndex(p, n, m)
            );
        }
    }

private:
    char randChar(){
        char arr[] = {'x', 'X', 'y', 'Y', 'z', 'Z'};
        return arr[rnd.nextInt(0, 5)];
    }
    void generateChar(vector<char> &c, int m){
        for(int i=0;i<m;++i)
            c.push_back(randChar());
    }
    void generateIndex(vector<int> &p, int n, int m){
        for(int i=0;i<m;++i){
            p.push_back(rnd.nextInt(MINN, n));
        }
    }
};