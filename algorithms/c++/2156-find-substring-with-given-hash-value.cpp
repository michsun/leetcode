// https://leetcode.com/problems/find-substring-with-given-hash-value/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string subStrHash(string s, int p, int m, int k, int hashValue) {
        int n = s.size();
        p = p % m;
		int start; 
        long long hash = 0, pk = 1;
        
		// Initial hash calculated from the last k values of the string
        for (int i = 0; i < k; i++) {
			// Calculate power values using mod properties to prevent overflow
            if (i > 0) 
                pk = pk * p % m;
            hash = (hash + (s[n-k+i]-'a'+1) * pk) % m;
        }
        if (hash == hashValue)
            start = n-k;
        
		// Rolling hash in reverse order
        for (int i = n-k-1; i >= 0; i--) {
			// Subtract previous last character value s[i+k]*p(k-1) 
            hash = (hash - (s[i+k]-'a'+1)%m * pk ) % m ;
			
			// Above line can result in negative result, thus we add m to ensure positivity
			// Reminder that 3 ≡ -2 mod 5
            if (hash < 0) 
                hash += m; 
				
			// Multiple previous hash by p (and mod due to (3))
			// And the starting s[i] value and again mod
            hash = ( (hash * p) % m + (s[i]-'a'+1)%m ) % m;
            if (hash == hashValue)
                start = i;
        }
        return s.substr(start, k);
    }
};

int main() {

    return 0;
}