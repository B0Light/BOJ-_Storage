#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;

void dfs(int thisPos, vector<int>& v, vector<bool>& chk){
    if(chk[thisPos]) return;
    chk[thisPos] = true;
    dfs(v[thisPos], v, chk);
}

void chkdfs(vector<int>& v){
    int cnt = 0; 
    vector<bool> chk(v.size(), false);
    for(int i = 0; i < v.size(); i++){
        if(!chk[i]){
            dfs(i,v,chk);
            cnt++;
        }
    }
    cout<<((cnt == 1) ? 0 : cnt) << "\n";
}

int main(){
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    chkdfs(v);
}