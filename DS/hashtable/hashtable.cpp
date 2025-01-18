#include <iostream>
#include <list>
#include <vector>
#include <functional>
#include <cmath>
#include <string>

class Hash_table {
private:
    std::vector<std::list<std::string>> listOfLinkedLists;
    std::function<int(const std::string&)> hashFunc;

    bool check_lst(int h) {
        return !listOfLinkedLists[h].empty();
    }
public:
    Hash_table(size_t size, std::function<int(const std::string&)> hashFunction)
        : listOfLinkedLists(size), hashFunc(hashFunction) {}

    void insert(const std::string& s) {
        int h = hashFunc(s) % listOfLinkedLists.size();

        std::cout << "String is: " << s << " Hash value is: " << h << std::endl;

        listOfLinkedLists[h].push_back(s);
    }

    void print() {
        int i = 0;
        for (const auto& innerList : listOfLinkedLists) {
            std::cout << "Bucket " << i++ << ": ";
            for (const auto& val : innerList) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};

int example_hashing(const std::string& s) {
    int h = 0;
    int i = 1;
    for (char c : s) {
        h += std::pow(3, i) * static_cast<int>(c);
        ++i;
    }
    return h;
}

int simple_hashing(const std::string& s) {
    int h = 0;
    for (char c : s) {
        h += static_cast<int>(c);
    }
    return h;
}

int main() {
    std::vector<std::string> strings;

    for (int i = 1; i <= 20; ++i) {
        strings.push_back("String_" + std::to_string(i));
    }

    for (int i = 1; i <= 20; ++i) {
        strings.push_back("Strign_" + std::to_string(i));
    }

    Hash_table h1(40, example_hashing);

    for (const auto& str : strings) {
        h1.insert(str);
    }

    std::cout << "Hash Table with example_hashing:" << std::endl;
    h1.print();

    Hash_table h2(40, simple_hashing);

    for (const auto& str : strings) {
        h2.insert(str);
    }

    std::cout << "\nHash Table with simple_hashing:" << std::endl;
    h2.print();

    return 0;
}

