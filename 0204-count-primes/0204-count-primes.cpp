#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;  // No primes less than 2
        
        int cnt = 0;
        vector<int> a(n, 1);  // Initialize all elements to 1
        a[0] = 0;  // 0 is not a prime
        a[1] = 0;  // 1 is not a prime
        
        for (int i = 2; i * i < n; ++i) {
            if (a[i] == 1) {
                for (int j = i * i; j < n; j += i) {
                    a[j] = 0;  // Mark multiples of i as non-prime
                }
            }
        }
        
        // Count the number of primes
        for (int i = 0; i < n; ++i) {
            cnt += a[i];
        }
        
        return cnt;
    }
};
