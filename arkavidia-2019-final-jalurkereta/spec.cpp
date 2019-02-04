#include <bits/stdc++.h>
#include <tcframe/spec.hpp>
using namespace std;
using namespace tcframe;

#define MAXN 10000
#define MAXT 10

class ProblemSpec : public BaseProblemSpec {
protected:
    int T, N, M, result;
    vector<pair<int,pair<int,pair<int,int> > > > arr;

    void InputFormat() {
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
        CONS(1 <= M <= MAXN);
        CONS(allElementBetween(arr,M,1,N));
        CONS(isPlanar(arr,N));
    }

private:
    bool allElementBetween(vector<pair<int,pair<int,pair<int,int> > > > arr, int M, int a, int b){
        for(int i = 0; i < M; i++){
            if(arr[i].second.first < a or arr[i].second.first > b)return false;
            if(arr[i].second.second.first < a or arr[i].second.second.first > b)return false;
            if(arr[i].second.second.second < a or arr[i].second.second.second > b)return false;
            if(arr[i].first < 1 or arr[i].first > 2)return false;
        }
        return true;
    }

    bool isPlanar(vector<pair<int,pair<int,pair<int,int> > > > arr, int N){
        vector<vector<int>  > v;
        v.resize(N);
        generateAdjList(v,arr);
        return true;
        //Todo
    }

    void generateAdjList(vector<vector<int> > &v, vector<pair<int,pair<int,pair<int,int> > > > arr){
        for(int i = 0; i < arr.size(); i++){
            int x = arr[i].second.first;
            int y = arr[i].second.second.first;;
            int z = arr[i].second.second.second;
            x--;
            y--;
            z--;
            if(arr[i].first == 1){
                v[x].push_back(y);
                v[x].push_back(z);
            } else {
                v[y].push_back(z);
                v[x].push_back(z);
            }
        }
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "4 9",
            "1 1 2 3",
            "1 3 4 5",
            "1 6 7 9",
            "2 5 7 8"
        });
        Output({
            "4"
        });
    }

    void BeforeTestCase() {
        arr.clear();
    }

    void TestCases() {
        //Todo
    }

private:
    void createPlanarGraphWithList(int N, vector<pair<int,pair<int,pair<int,int> > > > &arr){
        vector<int> v;
        int maxNum;
        maxNum = 0;
        v.push_back(0);
        vector<tuple<int,int,int,int> > temp;
        while(maxNum < N){
            for(int i = 0; i < v.size() && maxNum < N; i++){
                if(rnd.nextInt(0,4) == 0){
                    if(v.size() > 1 && i != v.size()-1 && (maxNum == N-1 || rnd.nextInt(0,1) == 0)){
                        int x = v[i];
                        int y = v[i+1];
                        v.erase(v.begin()+i);
                        v.erase(v.begin()+i);
                        maxNum++;
                        v.insert(v.begin()+i,maxNum);
                        auto it = make_tuple(1,maxNum,x,y);
                        temp.push_back(it);
                    } else {
                        int x = v[i];
                        v.erase(v.begin()+i);
                        maxNum++;
                        v.insert(v.begin()+i,maxNum);
                        maxNum++;
                        v.insert(v.begin()+i,maxNum);
                        auto it = make_tuple(2,maxNum-1,maxNum,x);
                        temp.push_back(it);
                    }
                }
            }
        }

        for(int i = 0; i < temp.size(); i++){
            int x,y,z,tipe;
            auto it = temp[i];
            tie(tipe,x,y,z) = it;
            arr.push_back(make_pair(tipe,make_pair(x,make_pair(y,z))));
        }
    }
};
