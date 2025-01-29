#include <iostream>
#include <cstdlib>

const int rows = 10; // `rows` and `cols` should be constant
const int cols = 10;

void print(int binaryArray[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (binaryArray[i][j] < 10) std::cout << binaryArray[i][j] << "  |"; 
	    else std::cout << binaryArray[i][j] << " |";
        }
        std::cout << std::endl;
    }

}

int cnt_ways(int array[rows][cols]) {
    int memArray[rows][cols];
    memArray[rows - 1][cols - 1] = !array[rows - 1][cols - 2] + !array[rows - 2][cols - 1];

    //std::cout << array[rows - 1][cols - 2] << "  array[rows - 1][cols - 2] " << array[rows - 2][cols - 1] << "array[rows - 2][cols - 1]"  << std::endl;
    //std::cout << memArray[rows - 1][cols - 1] << " memArray[rows - 1][cols - 1]" << std::endl;

    std::cout << "------------------------" << std::endl;
    //print(memArray);

    bool f = false;
    for (int i = cols - 1; i >= 0; --i) {
        if (memArray[rows - 1][i] == 1) f = true;
        if (!f) memArray[rows - 1][i] = 1;
        else memArray[rows - 1][i] = 0;
    }

    f = false;
    for (int i = rows - 1; i >= 0; --i) {
        if (memArray[i][cols - 1] == 1) f = true;
        if (!f) memArray[i][cols - 1] = 1;
        else memArray[i][cols - 1] = 0;
    }

    for (int i = rows - 2; i >= 0; --i) {
        for (int j = cols - 2; j >= 0; --j) {
            if (array[i][j]) memArray[i][j] = 0;
            else memArray[i][j] = memArray[i + 1][j] + memArray[i][j + 1];
        }
    }

    std::cout << "------------------------" << std::endl;
    print(memArray);
    return memArray[0][0];
}



int main() {
    double probability = 0.3;
    int binaryArray[rows][cols];

    std::srand(41);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            binaryArray[i][j] = (std::rand() / double(RAND_MAX)) < probability ? 1 : 0;
        }
    }

    print(binaryArray);

    int result = cnt_ways(binaryArray); // Capture the result
    std::cout << "Result: " << result << std::endl;

    return 0;
}

