#include <iostream>
#include <limits>

class PathFinder {
private:
    static const int rows = 10;
    static const int cols = 10;
    const int (*arr)[cols];
    int memo[rows][cols];

    void init_memo() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                memo[i][j] = -1;
            }
        }
    }

    int find_min_path(int i, int j) {
	 if ( j == cols - 1 ) return arr[i][j];

	 if ( memo[i][j] != -1) return memo[i][j]; // For memorization
						  
	 int right = find_min_path(i, j + 1);
	 int down = find_min_path((i + 1) % rows, j + 1 );
	 int up = find_min_path((i - 1 + rows) % rows, j + 1);

	 return memo[i][j] = arr[i][j] + std::min(up, std::min(right, down)); 
    }

public:
    PathFinder(const int inpArr[rows][cols]) : arr(inpArr) { 
        init_memo();
    }

    void get_opt_path() {
        int min_cost = std::numeric_limits<int>::max();
        
        for (int i = 0; i < rows; ++i) {
            min_cost = std::min(min_cost, find_min_path(i, 0));
        }

        std::cout << "Minimum Path Cost: " << min_cost << std::endl;
    }
};

int main() {
    const int rows = 10;
    const int cols = 10;

    int arr[rows][cols] = {
        {12, 45, 6, 89, 3, 23, 5, 7, 90, 1},
        {4, 23, 7, 9, 31, 65, 8, 9, 21, 4},
        {32, 78, 45, 7, 89, 12, 34, 5, 78, 9},
        {3, 65, 87, 9, 21, 3, 76, 98, 4, 67},
        {89, 2, 34, 23, 56, 78, 90, 11, 54, 23},
        {76, 98, 1, 6, 8, 9, 21, 43, 32, 78},
        {5, 67, 89, 3, 23, 5, 78, 9, 11, 5},
        {2, 76, 98, 31, 65, 8, 90, 21, 32, 7},
        {9, 45, 6, 89, 12, 3, 56, 7, 90, 4},
        {65, 87, 90, 2, 4, 32, 76, 9, 4, 6}
    };

    PathFinder p(arr);
    p.get_opt_path();

    return 0;
}

