#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include<cmath>

using namespace std;

bool isCont(int x1, int y1, int x2, int y2, int px, int py, int pr){
    int scont, econt;
    int sdis = pow(px - x1,2) + pow(py- y1,2);
    int edis = pow(px - x2,2) + pow(py- y2,2);
    scont = sdis > pow(pr,2) ? 0 : 1;
    econt = edis > pow(pr,2) ? 0 : 1;
    return scont + econt == 1 ? true : false;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int x1 ,y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int planet;
        int cnt = 0;
        cin >> planet;
        int px, py, pr;
        for(int i = 0; i < planet; i++){
            cin >> px >> py >> pr;
            if(isCont(x1,y1,x2, y2, px, py, pr)) cnt++;
        }
        cout << cnt << endl;
        cnt = 0;
    }
}