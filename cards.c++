#include <iostream>
#include <vector>

const int MOD = 998244353;

int mod(int a, int b) {
    return (a % b + b) % b;
}

unsigned long count_configurations(const std::vector<unsigned long>& F, const std::vector<unsigned long>& B) {
    int N = F.size();
    const int MAX_STATE = 2;  // 0 for facing up, 1 for facing down

    // Initialize the dp array
    std::vector<std::vector<unsigned long>> dp(N, std::vector<unsigned long>(MAX_STATE, 0));

    // Base case: the first card can be in any state
    dp[0][0] = (F[0] != B[0]);  // 1 if facing up, 0 if facing down
    dp[0][1] = 1 - dp[0][0];

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < MAX_STATE; ++j) {
            // Transition when flipping the current card
            dp[i][j] = (dp[i][j] + dp[i - 1][1 - j]) % MOD;

            // Transition when not flipping the current card
            if (F[i] != B[i]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }

    // Sum up the number of ways for the last card to be in either state (facing up or down)
    return (dp[N - 1][0] + dp[N - 1][1]) % MOD;
}

int main() {
    std::vector<unsigned long> F = {1, 4, 3};
    std::vector<unsigned long> B = {2, 2, 4};

    std::cout << count_configurations(F, B) << std::endl;

    return 0;
}
