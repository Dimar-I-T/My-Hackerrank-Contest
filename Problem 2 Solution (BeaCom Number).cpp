#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
// Dimar's Solution
using namespace std;

int PembagiTerbesar(int n){
      int batas = floor(sqrt(n));
      int hasil = 0;
      for (int x = 2; x <= batas; x++){
            if (n % x == 0){
                  hasil = n / x;
                  break;
            }
      }
      
      if (hasil == 0){
            hasil = 1;
      }
      return hasil;
}

int main(){
      int t;
      cin >> t;
      while (t > 0){
            int ABK[3];
            cin >> ABK[0] >> ABK[1] >> ABK[2];
            int A = ABK[0], B = ABK[1], K = ABK[2];
            int a = PembagiTerbesar(A), b = 		 PembagiTerbesar(B);
            vector<int> vA, vB;
            for (int x = 1; x <= a; x++){
                  vA.push_back(x * A);
            }
            for (int x = 1; x <= b; x++){
                  vB.push_back(x * B);
            }
            
            vector<int> minVA, minVB;
            minVA.push_back(vA[0]);
            minVB.push_back(vB[0]);
            for (int x = 1; x < vA.size(); x++){
                  int bD1 = to_string(vA[x]).length();
                  int bD0 = to_string(vA[x - 1]).length();
                  if (bD1 != bD0){
                        minVA.push_back(vA[x]);
                  }
            }
            for (int x = 1; x < vB.size(); x++){
                  int bD1 = to_string(vB[x]).length();
                  int bD0 = to_string(vB[x - 1]).length();
                  if (bD1 != bD0){
                        minVB.push_back(vB[x]);
                  }
            }
            vector<long long> gabungan;
            for (int x = 0; x < minVA.size(); x++){
                  for (int y = 0; y < minVB.size(); y++){
                        gabungan.push_back(stoll(to_string(minVA[x]) + to_string(minVB[y])));
                        gabungan.push_back(stoll(to_string(minVB[y]) + to_string(minVA[x])));
                  }
            }
            
            sort(gabungan.begin(), gabungan.end());
            long long hasil = 0;
            for (int x = 0; x < gabungan.size(); x++){
                  if (to_string(gabungan[x]).length() == K){
                        hasil = gabungan[x];
                        break;
                  }
            }
            
            cout << hasil;
            cout << "\n";
            t--;
      }
      return 0;
}