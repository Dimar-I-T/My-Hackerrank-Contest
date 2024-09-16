#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<numeric>
// Dimar's Solution
using namespace std;

long long Faktorial(int n){
    if (n == 0 || n == 1){
        return 1;
    }else{
        return n*Faktorial(n - 1);
    }
}

long long Kombinasi(int n, int r){
    if (n == r){
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

long long K(int n, int p){
    int hasil = 0;
    for (int k = 1; k <= n; k++){
        int minplus = 1;
        if (k % 2 == 0){
            minplus = -1;
        }
        hasil += minplus * Kombinasi(n, k) * Kombinasi(p - (6*k + 1), n - 1);
    }

    return hasil;
}

int main(){
    int t;
    cin >> t;

    while (t > 0){
        int n, a, b;
        cin >> n >> a >> b;

        if (n == 1){
            cout << 1 << "\n";
        }else{
            long long UA = Kombinasi(a - 1, n - 1);
            long long UB = Kombinasi(b - 1, n - 1);
            long long bA = K(n, a);
            long long bB = K(n, b);
            long long hasilA = (UA - bA);
            long long hasilB = (UB - bB);
            unsigned long long hasil = hasilA*hasilB;
            cout << hasil << "\n";
        }
        t--;
    }
    
    return 0;
}