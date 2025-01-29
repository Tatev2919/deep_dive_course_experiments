#include <iostream>
#include <algorithm>
#include <limits>

class PathFinder {
private:
    static const int rows = 10;
    static const int cols = 10;
    const int (*arr)[cols];  
    int memo[rows][2];

    void init_memo() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < 2; ++j) {
                memo[i][j] = std::numeric_limits<int>::max();
            }
        }
    }

public:
    PathFinder(const int inpArr[rows][cols]) : arr(inpArr) { 
        init_memo(); 
    }

    void get_opt_path() {
        for (int i = 0; i < rows; ++i) {
            memo[i][0] = arr[i][0];
        }

	int k = 0;

        for (int j = 0; j < cols - 1; ++j) {
            for (int i = 0; i < rows; ++i) {
                memo[i][(k + 1) % 2] = std::numeric_limits<int>::max();
            }

            for (int i = 0; i < rows; ++i) {
                int up = (i - 1 + rows) % rows;
                int down = (i + 1) % rows;

		int mem_ind = (k + 1) % 2;

                memo[i][mem_ind] = std::min(memo[i][mem_ind], memo[i][k%2] + arr[i][j + 1]);
                memo[up][mem_ind] = std::min(memo[up][mem_ind], memo[i][k%2] + arr[up][j + 1]);
                memo[down][mem_ind] = std::min(memo[down][mem_ind], memo[i][k%2] + arr[down][j + 1]);

            }
	    k = (k + 1) % 2;
        }

        std::cout << "Final Memo Table:\n";

	print_memo();
        //print(memo);
	std::cout << "Get min: " << get_min() << std::endl; 
    }


    int get_min () {
	int m = memo[0][1];
        for (int i = 1; i < rows; ++i) {
	    if ( m > memo[i][1] ) m = memo[i][1];
        }
	return m;
    }

    void print_memo () {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < 2; ++j) {
		std::cout << memo[i][j] << "  "; 
	    }
	    std::cout << "\n";
	}
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
    p.print(arr);
    p.get_opt_path();

    return 0;
}

