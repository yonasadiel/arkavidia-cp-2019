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
    //Return maximum index in a tree, 0-based
    int createBinaryTree(int leaf, vector<pair<int,int> > &v, vector<int> &leafV, int curIdx, bool isReverse){
        if(leaf == 1){
            leafV.push_back(curIdx);
            return curIdx;
        }
        int x = rnd.nextInt(1,leaf-1);
        int y = leaf-x;

        if(!isReverse)v.push_back(make_pair(curIdx,curIdx+1));
        else v.push_back(make_pair(curIdx+1,curIdx));
        int lastIdx = createBinaryTree(x, v, leafV, curIdx+1, isReverse);
        if(!isReverse)v.push_back(make_pair(curIdx,lastIdx+1));
        else v.push_back(make_pair(lastIdx+1,curIdx));
        lastIdx = createBinaryTree(y, v, leafV, lastIdx+1, isReverse);

        return lastIdx;
    }

    void permuteNum(int maxNum, vector<pair<int,int> > &v){
        map<int,bool> cek;
        map<int,int> temp;
        vector<int> pm;
        int cur = 0;
        for(int i = 0; i < v.size(); i++){
            cek[v[i].first] = true;
            cek[v[i].second] = true;
        }
        pm.resize(cek.size());
        for(int i = 0; i < pm.size(); i++){
            pm[i] = i;
        }
        rnd.shuffle(pm.begin(),pm.end());
        for(auto it = cek.begin(); it != cek.end(); ++it){
            temp[it->first] = pm[cur];
            cur++;
        }
        for(int i = 0; i < v.size(); i++){
            v[i].first = temp[v[i].first];
            v[i].second = temp[v[i].second];
        }
    }

    //Connect 2 binary tree given their leaf
    void connect(int N, vector<int> a, vector<int> b, vector<pair<int,int> > &v){
        assert(a.size() == b.size());
        map<int,int> val;
        for(int i = 0; i < N; i++)val[i] = i;
        for(int i = 0; i < b.size(); i++){
            val[b[i]] = a[i];
        }
        for(int i = 0; i < v.size(); i++){
            v[i].first = val[v[i].first];
            v[i].second = val[v[i].second];
        }
    }

    //Create 2 binary tree, and join their leaf to create a planar graph
    void createPlanarGraph(int leaf, vector<pair<int,int> > &v){
        vector<int> leaftemp1,leaftemp2;
        int maxNum = createBinaryTree(leaf, v, leaftemp1, 0, 0);
        maxNum = createBinaryTree(leaf, v, leaftemp2, maxNum+1, 1);
        connect(maxNum+1, leaftemp1, leaftemp2, v);
        permuteNum(v);
    }
};
