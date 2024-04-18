#include <iostream>
#include <vector>

using namespace std;

int mod(int a, int b) {
    return (a % b + b) % b;
}

int maximum_happiness(const vector<int>& plates) {
    int n = plates.size();
    
    // Initialize a 2D DP array to store intermediate results
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: Compute happiness for each plate in its original position
    for (int i = 0; i < n; i++) {
        dp[0][i] = (plates[mod(i - 1, n)] == (plates[i] + 1) % n) || (plates[mod(i + 1, n)] == (plates[i] + 1) % n);
    }

    // Build up the DP table
    for (int start = 1; start < n; start++) {
        for (int i = 0; i < n; i++) {
            int current_plate = plates[mod(start + i, n)];
            int left_plate = plates[mod(start + i - 1, n)];
            int right_plate = plates[mod(start + i + 1, n)];

            dp[start][i] = max(dp[start][i], dp[start - 1][i]);
            
            if (current_plate == (left_plate + 1) % n || current_plate == (right_plate + 1) % n) {
                dp[start][i]++;
            }
        }
    }

    // Find the maximum happiness among all starting positions
    int max_happiness = 0;
    for (int i = 0; i < n; i++) {
        max_happiness = max(max_happiness, dp[n - 1][i]);
    }

    return max_happiness;
}

int main() {
    vector<int> plates = {1, 2, 0, 3};

    std::cout << maximum_happiness(plates) << std::endl;

    return 0;
}
