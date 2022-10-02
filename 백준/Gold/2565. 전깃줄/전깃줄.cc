#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

using namespace std;

int Max(int A, int B) { 
    return A > B ? A : B; 
}

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

class LCS{

private:
    vector <pair<int, int>> arr;
    int DP[101] = {0,};

public:
    void input(int N){
        int a, b;
        arr.push_back({0,0});
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            arr.push_back(make_pair(a, b));
        }
        sort(arr.begin(), arr.end(),cmp);
    }

    void sol(int N){
        int ans = 0; 
        for(int i = 1; i <= N; i++){
            DP[i] = 1;
            for(int j = 1; j < i; j++){
                if(arr[i].second > arr[j].second){
                    DP[i] = Max(DP[i], DP[j] + 1);
                }
            }
            ans = Max(DP[i], ans);
        }

        cout << N-ans << endl;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    LCS lcs;
    lcs.input(N);
    lcs.sol(N);
}