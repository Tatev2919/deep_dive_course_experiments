#include <iostream>
#include <vector>
#include <algorithm>

int cnt = 0;
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

int calc_knapsack_val( int capacity, std::vector<int>& vals, std::vector<int>& weights, int n,std::vector<std::vector<int>>& memArray) {

    
    if (n == 0 || capacity == 0) {
        return 0; 
    }
   
    if (memArray[n][capacity] != -1) return memArray[n][capacity]; 
    std::cout << "N times: " << cnt << std::endl;
    cnt++;

    if (weights[n] > capacity) {
	
        memArray[n][capacity] = calc_knapsack_val(capacity, vals, weights, n - 1, memArray);
    } else {
        int inc_item = vals[n] + calc_knapsack_val(capacity - weights[n], vals, weights, n - 1, memArray);
	int excl_item = calc_knapsack_val(capacity, vals, weights, n - 1, memArray);

	memArray[n][capacity] = std::max(inc_item, excl_item);
    }
    
    return memArray[n][capacity];
}




int main() {
    
    int capacity = 7;

    std::vector<int> vals = {0, 20, 20, 40, 50, 30};
    std::vector<int> weights = {0, 3, 1, 3, 4, 2};
    int items = vals.size();


    std::vector<std::vector<int>> memArray(items, std::vector<int>(capacity + 1, -1));

    int result = calc_knapsack_val(capacity, vals, weights, items - 1 , memArray); 
    std::cout << "Result: " << result << std::endl;
    print(memArray);

    return 0;
}

