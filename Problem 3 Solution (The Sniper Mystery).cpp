#include<iostream>
#include<cmath>
#include<numeric>
#include<vector>
// Dimar's Solution
using namespace std;

int main() {
      int bK;
      cin >> bK;
      while (bK > 0){
            double n, v, t, sp;
            cin >> n >> v >> t >> sp;
            vector<double> sudut(n);
            int idx = 0;
            for (int x = 0; x < n; x++){
                  cin >> sudut[x];
                  if (floor(sudut[x]) == floor(atan(sp/(v*t))*180/M_PI)){
                        idx = x + 1;
                  }
            }
            cout << idx << "\n";
            bK--;
      }
}