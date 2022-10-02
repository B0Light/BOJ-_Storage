#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;

        int cnt = 0;
        int left = 0;
        int right = str.length() - 1;
        bool chk = true;

        for (; left <= right; left++, right--){
            cnt++;
            if(str[left] != str[right]){
                chk = false;
                break;
            }
        }
        cout << (chk ? 1 : 0) << " " << (chk && str.length() % 2 == 0 ? cnt + 1 : cnt) << "\n";
    }
}