#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void print(std::vector<std::vector<int>>& memo, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
	    std::cout<< memo[i][j] << "   ";
	}
	std::cout << "\n" << std::endl;
    }
}


float cnt_accuracy(std::vector<std::vector<int>>& memo, int n, int m) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
	    if (memo[i][j] != -1) cnt++;
	}
    }

    return (float)cnt/(n*m);

}


/*std::string generateRandomString(size_t length) {
    const std::string charset =
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789";
    std::random_device rd; 
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> dist(0, charset.size() - 1);

    std::string randomString;
    for (size_t i = 0; i < length; ++i) {
        randomString += charset[dist(generator)];
    }

    return randomString;
}*/


int calculate_lcd(std::string& rand_st1, std::string& rand_st2, int i, int j, std::vector<std::vector<int>>& memo) {
    if (i < 0 || j < 0) {
        return 0;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (rand_st1[i] == rand_st2[j]) {
        memo[i][j] = 1 + calculate_lcd(rand_st1, rand_st2, i - 1, j - 1, memo);
    } else {
        memo[i][j] = std::max(
            calculate_lcd(rand_st1, rand_st2, i - 1, j, memo),
            calculate_lcd(rand_st1, rand_st2, i, j - 1, memo)
        );
    }

    return memo[i][j];
}



int main() {
    std::string rand_st1 = "acatgt"; 
    std::string rand_st2 = "ctgaat";

    int n = rand_st1.size();
    int m = rand_st2.size();
    std::vector<std::vector<int>> memo(n, std::vector<int>(m, -1));

    int lcs_length = calculate_lcd(rand_st1, rand_st2, n - 1, m - 1, memo);

    std::cout << "Length of Longest Common Subsequence: " << lcs_length << std::endl;

    print(memo, n , m );

    std::cout<< cnt_accuracy(memo, n , m) << std::endl;

    return 0;
}

