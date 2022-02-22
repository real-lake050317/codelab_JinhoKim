#include <iostream>
#include <cstring>
using namespace std;

void rabinkarp(string ws, string ps){
    int wsSize = ws.size(), psSize = ps.size();
    int wsHash = 0, psHash = 0, pwr = 1;
    
    for (int i = 0; i<=wsSize-psSize; i++){
        if (!i){
            for (int j = 0; j<psSize; j++){
                wsHash += ws[psSize - 1 - j] * pwr;
                psHash += ps[psSize - 1 - j] * pwr;
                if (j<psSize - 1) pwr *= 3;
            }
        }
        else wsHash = 3 * (wsHash - ws[i - 1] * pwr) + ws[psSize - 1 + i];
        if (wsHash == psHash) {
            bool isFind = true;
            for (int j = 0; j<psSize; j++){
                if (ws[i+j] != ps[j]){
                    isFind = false;
                    break;
                }
            }
            if (isFind) {
                cout << wsHash << " " << psHash << endl;
                cout << i + 1 << "번째에서 발견" << "\n";
            }
        }
    }
}

int main(){
    string ws = "AABDCDABD";
    string ps = "ABD";
    rabinkarp(ws, ps);
    
    return 0;
}
