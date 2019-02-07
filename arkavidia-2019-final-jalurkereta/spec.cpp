#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define MAXN 4999 //MAXN = (MAXM-1)/2
#define MAXT 10

class ProblemSpec : public BaseProblemSpec
{
  protected:
    int T, N, M, result;
    vector<char> tipe;
    vector<int> a, b, c;

    void InputFormat()
    {
        LINE(N, M);
        LINES(tipe, a, b, c) % SIZE(N);
    }

    void OutputFormat()
    {
        LINE(result);
    }

    void GradingConfig()
    {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void MultipleTestCasesConfig()
    {
        Counter(T);
        OutputPrefix("");
    }

    void MultipleTestCasesConstraints()
    {
        CONS(1 <= T && T <= MAXT);
    }

    void Constraints()
    {
        CONS(1 <= N <= MAXN);
        CONS(1 <= M <= MAXN);
        CONS(allElementBetween(a, N, 1, M));
        CONS(allElementBetween(b, N, 1, M));
        CONS(allElementBetween(c, N, 1, M));
        CONS(allElementBetween(tipe, N, 'A', 'B'));
        CONS(nodeCheck(N,M,a,b,c));
    }

  private:
    bool allElementBetween(vector<int> arr, int N, int a, int b)
    {
        for (int i = 0; i < N; i++)
        {
            if (arr[i] < a or arr[i] > b)
                return false;
        }
        return true;
    }

    bool allElementBetween(vector<char> arr, int N, char a, char b)
    {
        for (int i = 0; i < N; i++)
        {
            if (arr[i] < a or arr[i] > b)
                return false;
        }
        return true;
    }

    bool nodeCheck(int N, int M, vector<int> a, vector<int> b, vector<int> c){
        int cek[M+5];
        for(int i = 0; i < M; i++)cek[i] = 0;
        for(int i = 0; i < N; i++){
            cek[a[i]-1]++;
            cek[b[i]-1]++;
            cek[c[i]-1]++;
        }

        for(int i = 0; i < M; i++){
            if(cek[i]<= 0 || cek[i] > 2)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
  protected:
    void SampleTestCase1()
    {
        Input({"4 9",
               "A 1 2 3",
               "A 3 4 5",
               "A 6 7 9",
               "B 5 7 8"});
        Output({"5"});
    }

    void BeforeTestCase()
    {
        a.clear();
        tipe.clear();
        b.clear();
        c.clear();
    }

    void TestGroup1()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(N+2+(N-1)/2, N*2+1), createPlanarGraphWithList(M, N, tipe, a, b, c));
        }
    }

    void TestGroup2()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(N+2+(N-1)/2, N*2+1), createPlanarGraphWithList(M, N, tipe, a, b, c));
        }
    }

    void TestGroup3()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(N+2+(N-1)/2, N*2+1), createPlanarGraphWithList(M, N, tipe, a, b, c));
        }
    }

    void TestGroup4()
    {
        for (int i = 0; i < MAXT; i++)
        {
            CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(N+2+(N-1)/2, N*2+1), createPlanarGraphWithList(M, N, tipe, a, b, c));
        }
    }

  private:
    void createPlanarGraphWithList(int N, int M, vector<char> &t, vector<int> &a, vector<int> &b, vector<int> &c)
    {
        vector<int> v;
        int maxNum, totalEdge;
        maxNum = totalEdge = 0;
        v.push_back(0);
        vector<tuple<int,int,int,int> > temp;
        while(totalEdge < M){
            for(int i = 0; i < v.size() && maxNum < N && totalEdge < M; i++){
                //printf("%d %d\n", maxNum, totalEdge);
                if(rnd.nextInt(0,4) == 0){
                    if((maxNum == N-1 || rnd.nextInt(0,1) == 0)){
                        if((M-totalEdge)*2+1 == N-maxNum){
                            if(i == 0){
                                int x = v[i];
                                v.erase(v.begin()+i);
                                maxNum++;
                                v.insert(v.begin()+i,maxNum);
                                maxNum++;
                                auto it = make_tuple('A',maxNum-1,x,maxNum);
                                temp.push_back(it);    
                                totalEdge += 1;
                            } else if(i == v.size()-1){
                                int x = v[i];
                                v.erase(v.begin()+i);
                                maxNum++;
                                v.insert(v.begin()+i,maxNum);
                                maxNum++;
                                auto it = make_tuple('A',maxNum-1,maxNum,x);
                                temp.push_back(it);    
                                totalEdge += 1;                         
                            }
                        } else if(v.size() > 1 && i != v.size()-1){
                            int x = v[i];
                            int y = v[i+1];
                            v.erase(v.begin()+i);
                            v.erase(v.begin()+i);
                            maxNum++;
                            v.insert(v.begin()+i,maxNum);
                            auto it = make_tuple('A',maxNum,x,y);
                            temp.push_back(it); 
                            totalEdge += 1;                     
                        }
                    } else if(v.size() == 1 || (M-totalEdge)+2+(M-totalEdge-1)/2 < N-maxNum){
                        int x = v[i];
                        v.erase(v.begin()+i);
                        maxNum++;
                        v.insert(v.begin()+i,maxNum);
                        maxNum++;
                        v.insert(v.begin()+i,maxNum);
                        auto it = make_tuple('B',maxNum-1,maxNum,x);
                        temp.push_back(it);
                        totalEdge += 1;
                    }
                }
            }
        }
        //rnd.shuffle(temp.begin(),temp.end());
        for(int i = 0; i < temp.size(); i++){
            int x,y,z,tipe;
            auto it = temp[i];
            tie(tipe,x,y,z) = it;
            t.push_back(tipe);
            a.push_back(x+1);
            b.push_back(y+1);
            c.push_back(z+1);
        }
    }
};
