#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
// Dimar's Solution
using namespace std;

long long Kombinasi(int n, int r){
    if (n == r || r == 0){
        return 1;
    }else{
        int pembagi = 0;
        int batas = 0;
        if (r > (n - r)){
            batas = r;
            pembagi = n - r;
        }else{
            batas = n - r;
            pembagi = r;
        }

        long long atas = n, bawah = pembagi;
        for (int x = n - 1; x > batas; x--){
            atas *= x;
        }
        for (int x = pembagi - 1; x > 0; x--){
            bawah *= x;
        }

        return atas/bawah;
    }
}

unsigned long long FPB(unsigned long long a, unsigned long long b){
    if (a == 1 || b == 1){
        return 1;
    }else if (a == 0){
        return b;
    }else if (b == 0){
        return a;
    }else{
        if (a > b){
            return FPB(a % b, b);
        }else{
            return FPB(a, b % a);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t > 0){
        int n, k;
        cin >> n >> k;
        unsigned long long E = 0; 
        unsigned long long u = Kombinasi(n*n, k);
        unsigned long long U = u*u;
        if (k <= n*(n - 1)){
              for (int x = 0; x < k; x++){
                  long long k1 = Kombinasi(n*n - (x + 1), k - (x + 1));
                  long long k2 = Kombinasi(n, x + 1);
                  E += k1*k1*k2;
              }
              
              unsigned long long fpb = FPB(E, U);
              U /= fpb;
              E /= fpb;
              U %= 1000000007;
              E %= 1000000007;
              cout << (E*U) % 1000000007 << "\n";
        }else{
              cout << u << "\n";
        }
        
        t--;
    }
    
    return 0;
}