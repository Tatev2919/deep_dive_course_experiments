#include <iostream>
#include <vector>
#include <string>

template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "===\n[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n===\n";
}

template <>
void printVector(const std::vector<std::string>& vec) {
    std::cout << "===\n[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "\"" << vec[i] << "\"";
        if (i != vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n===\n";
}

template <>
void printVector(const std::vector<char>& vec) {
    std::cout << "===\n[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "'" << vec[i] << "'";
        if (i != vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n===\n";
}

template <typename T1, typename T2>
void printVector(const std::vector<std::pair<T1, T2>>& vec) {
    std::cout << "===\n[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "(" << vec[i].first << ", " << vec[i].second << ")";
        if (i != vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n===\n";
}

int main() {
    std::vector<int> intVec = {5, 32, 14, 6};
    printVector(intVec);

    std::vector<std::string> strVec = {"hello", "kitty", "move", "on"};
    printVector(strVec);

    std::vector<char> charVec = {'f', 'h', 'Z', 'X'};
    printVector(charVec);

    std::vector<std::pair<std::string, int>> pairVec = {{"h", 22}, {"ptr", 7}, {"key", 84}};
    printVector(pairVec);

    return 0;
}
