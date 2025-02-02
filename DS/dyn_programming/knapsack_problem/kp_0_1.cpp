#include <iostream>
#include <vector>
#include <algorithm>

void print(const std::vector<std::vector<int>>& arr) {
    for (const auto& row : arr) {
        for (size_t j = 0; j < row.size(); ++j) {
            if (row[j] < 10)
                std::cout << row[j] << "  |";
            else
                std::cout << row[j] << " |";
        }
        std::cout << std::endl;
    }
}

void get_selected_items(std::vector<std::vector<int>> & mem , std::vector<int>& weights, std::vector<int>& vals, int capacity, int n) {

    int i = n-1;
    int j = capacity;


    while ( mem[i-1][j] != 0 ) {
	if ( mem[i][j]!= mem[i-1][j] ) {
	    std::cout << i << " th element ( w = " << weights[i]  << " , v = " << vals[i] << " ) " << std::endl;
	    j -= weights[i];
	    i -= 1;
	} else {
	    --i;
	}
        	
    }  
    std::cout << i << " th element ( w = " << weights[i]  << " , v = " << vals[i] << " )" << std::endl;
}

int calc_knapsack_val( int capacity, std::vector<int>& vals, std::vector<int>& weights) {
    int n = vals.size();
    std::vector<std::vector<int>> memArray(n, std::vector<int>(capacity + 1, 0));


    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= capacity; ++j) {
	    if ( j >= weights[i]) {
	        memArray[i][j] = std::max(memArray[i-1][j],memArray[i-1][j-weights[i]] + vals[i]);
	    } else {
	        memArray[i][j] = memArray[i-1][j];
	    }
	}
    }

    print(memArray);
    get_selected_items(memArray, weights, vals, capacity, n);
    return memArray[n-1][capacity];
}




int main() {
    
    int capacity = 7;

    std::vector<int> vals = {0, 2, 2, 4, 5, 3};
    std::vector<int> weights = {0, 3, 1, 3, 4, 2};

    int items = vals.size();

    int result = calc_knapsack_val(capacity, vals, weights); 
    std::cout << "Result: " << result << std::endl;

    return 0;
}

