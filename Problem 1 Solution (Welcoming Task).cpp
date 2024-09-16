#include <iostream>
// Dimar's Solution
using namespace std;

int main(){
      unsigned long long t;
      cin >> t;
      while (t > 0){
            unsigned long long a, b;
            cin >> a >> b;
            cout << a + b << "\n";
            t--;
      }
      return 0;
}