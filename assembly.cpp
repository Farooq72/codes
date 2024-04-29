#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int assemblyLineScheduling(vector<vector<int>> a,vector<vector<int>> t,vector<int>e,vector<int>x){
    int n = a[0].size();

    vector<int>f1(n);
    vector<int>f2(n);

    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[1][0];

    for(int i=1;i<n;i++){
        f1[i] = min(f1[i-1]+a[0][i],f2[i-1]+t[1][i]+a[0][i]);
        f2[i] = min(f2[i-1]+a[1][i],f1[i-1]+t[0][i]+a[1][i]);
    }

    int mintime = min(f1[n-1] + x[0],f2[n-1]+x[1]);
    cout<<"mintime : "<<mintime;
}


int main(){
    vector<vector<int>> a = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    vector<vector<int>> t = {{0, 7, 4, 5}, {0, 9, 2, 8}};
    vector<int> e = {10, 12};
    vector<int> x = {18, 7};
    assemblyLineScheduling(a,t,e,x);
}