#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <string>

class Hash_table {
private:
    std::vector<std::string> vec;
    std::vector<std::string> vec1;

    std::function<int(const std::string&)> hashFunc;

    int length = 0;
    int length1 = 0;
    const float threshold = 0.6;
    const int bucket_size = 20; 
    bool intermediate_state = 0;
    int rehash_index = 0;

    void insert(std::vector<std::string>& vec_, const std::string& s ) {
        int h = hashFunc(s) % vec_.size();
        std::cout << "Inserting string: " << s << " | Hash value: " << h << std::endl;
        
        while (!vec_[h].empty()) {
            ++h;
            if (h == vec_.size()) h = 0;
        }

        vec_[h] = s;
	if (vec_ == vec) ++length;
        if (vec_ == vec1) ++length1;
    }

public:
    Hash_table(size_t size, std::function<int(const std::string&)> hashFunction)
        : vec(size), hashFunc(hashFunction) {}


    void insert(const std::string& s) {
	float load_factor = calc_load_factor();
        std::cout << "Current load factor: " << load_factor << std::endl;

        if (load_factor > threshold) { 
            intermediate_state = true;
            std::cout << "Load factor exceeded threshold. Rehashing initiated." << std::endl;
            std::cout << "String causing rehash: " << s << std::endl;

            vec1.resize(vec.size() * 2);
	}

	// Tested normal rehash function also:
        //if ( load_factor > threshold ) {
	  //  intermediate_state = 1;
            //std::cout << "--------------------------------- \n" << std::endl;
            //std::cout << "re-hash" << std::endl;
            //std::cout << "--------------------------------- \n" << std::endl;
	    //std::cout << "length is : " << length << std::endl;

	    //normal_rehash();
	    

	    //std::cout << "length after rehash is : " << length << std::endl;
	//}

        	
	if (intermediate_state) { 
	    insert(vec1, s);
            lazy_rehash();
	} else { 
	    insert(vec, s);
	}

    }

    int search(const std::string& s) {
        if (vec.empty() && vec1.empty()) {
      	    std::cout << "Hash tables are empty. Element not found." << std::endl;
	    return -1;
	}

	int h = vec.empty() ? -1 : hashFunc(s) % vec.size();
	int h1 = vec1.empty() ? -1 : hashFunc(s) % vec1.size();

        std::cout << "Searching for string: " << s 
                  << " | Hash value in vec: " << h 
                  << " | Hash value in vec1: " << h1 << std::endl;

        if (!vec.empty()) {
           int orig_h = h;
           while(vec[orig_h]!= s) {
	      ++orig_h;
	      if (orig_h == vec.size() - 1 ) orig_h = 0; 
	      if (orig_h == h) break;  
	   }

            if (vec[orig_h] == s) {
                std::cout << "Found in vec at index: " << orig_h << std::endl;
                return orig_h;
            }
        }

        if (!vec1.empty()) {
           int orig_h1 = h1;
           while(vec1[orig_h1]!= s) {
	      ++orig_h1;
	      if (orig_h1 == vec1.size() - 1 ) orig_h1 = 0;  
	      if (orig_h1 == h1) break;  
	   }

            if (vec1[orig_h1] == s) {
                std::cout << "Found in vec1 at index: " << orig_h1 << std::endl;
                return orig_h1;
            }
	}

        std::cout << "Element not found: " << s << std::endl;
        return -1;
    }

    float calc_load_factor () {
        return (float)length/vec.size();
    } 

    void normal_rehash() {
        std::vector<std::string> vec1(vec.size() * 2);
        int old_length = length;
	length = 0;
        for (const std::string& s : vec) {
            if (!s.empty()) { 
                insert(vec1, s);
            }
        }

	length = old_length;

        vec = std::move(vec1);
    }


    void lazy_rehash() {
        std::cout << "Performing lazy rehash..." << std::endl;
        std::cout << "Rehash index: " << rehash_index << std::endl;

        for (int i = rehash_index; i < std::min(rehash_index + bucket_size, static_cast<int>(vec.size())); ++i) {
            if (!vec[i].empty()) {
                insert(vec1, vec[i]);
                vec[i].clear();
            } else {
		++rehash_index;
	        std::cout << "Empty ----" << std::endl;
	    }
        }

        rehash_index += bucket_size;
        if (rehash_index >= vec.size()) {
            intermediate_state = false;
            vec = std::move(vec1);
            length = length1;
            length1 = 0;
            std::cout << "Lazy rehash completed. Transitioned to new vector." << std::endl;
        }
    }

    void print() {
        std::cout << "Hash table contents (vec):" << std::endl;
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << "Index " << i << ": " << vec[i] << std::endl;
        }

        if (intermediate_state) {
            std::cout << "Hash table contents (vec1):" << std::endl;
            for (size_t i = 0; i < vec1.size(); ++i) {
                std::cout << "Index " << i << ": " << vec1[i] << std::endl;
            }
        }
    }

    //Recursive approach caused Seg fault
    void print_all_runs() {
        int m = 0;
        int sum = 0;

        for (size_t ind = 0; ind < vec.size(); ++ind) {
            if (!vec[ind].empty()) {
                ++sum; 
            } else if (sum > 0) {
                m += sum;
                std::cout << "Index is: " << ind << " Run is: " << sum << " Monitor: " << m << std::endl;
                sum = 0; 
            }
        }

        if (sum > 0) {
            m += sum;
            std::cout << "Index is: " << vec.size() << " Run is: " << sum << " Monitor: " << m << std::endl;
        }
    }


    void prim_clustering_monitoring() {
        for (const auto& s: vec) {
	    if (s.empty()) std::cout<< "*"; 
	    else std::cout << " ";
	}
	std::cout << "\n";
    }


    
    /* normal_rehash();
    lazy_rehash();
    
    remove;*/

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

    for (int i = 1; i <= 350; ++i) {
        strings.push_back("String_" + std::to_string(i));
    }

    Hash_table h1(500, example_hashing);


    for (const auto& str : strings) {
	std::cout << "--------------------------" << std::endl;
        h1.insert(str);
    }


    std::cout << "Hash Table with example_hashing:" << std::endl;
    h1.print();
    std::cout << "Load factor is : " << h1.calc_load_factor() << std::endl;


    //std::cout << "Hash Table search value :" << std::endl;
    //std::cout << "index val in vec is " << h1.search("String_16") << std::endl;

    //h1.print_all_runs();
    
    h1.prim_clustering_monitoring();  


    return 0;
}

