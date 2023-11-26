#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // can be solved using DP
    // but actually it have a very smart equation to solve it
    // based on the fact that 3 * 3 > 2 * 2 * 2
    // so we need to break the number into 3s as much as possible
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int count_of_3s = n / 3;
        int remainder = n % 3;
        
        if (remainder == 0)                     // no remainder so we can just multiply the 3s
            return pow(3, count_of_3s);
        else if (remainder == 1)                // we need to borrow 1 from a 3 and make it 4 because 3 * 1 < 2 * 2
            return pow(3, count_of_3s - 1) * 4;
        else                                    // remainder == 2 so we can just multiply the 3s and the remainder
            return pow(3, count_of_3s) * 2;

        // we can notice that the solution is trying to break the number into 
        // as many 3s as possible then as much 2s as possible

    }
};


int main() {
    Solution s;
    cout << s.integerBreak(10) << endl;
}