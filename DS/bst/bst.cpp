#include <iostream>
#include <limits>
#include <climits>
#include <queue>
#include <stack>
#include <vector>
#include "utils.h"

template <typename T>
class bst {
private:

    Node<T>* root;
    int length = 0;

    void destroy(Node<T>* tmp);
    void insert(Node<T>* tmp, T value);
    void print(Node<T>* tmp);

    Node<T>* search(Node<T>* tmp, T value); 
    Node<T>* find_min(Node<T>* tmp);
    Node<T>* find_max(Node<T>* tmp);
    void mirroring(Node<T>* tmp);
    void print_in_level_order(Node<T>* tmp);
    void mirroring_rec(Node<T>* tmp);
    void bst_to_vec(Node<T>* tmp, std::vector<T>& vec);
    Node<T>* batch_construction(const std::vector<int>& vec, int left, int right);
    void print_pre_order(Node<T>* tmp);
    float balanceness_ratio_calc(Node<T>* tmp);

public:
    bst();

    ~bst();

    void insert(T value);
    void print();
    Node<T>* search(T value); 
    Node<T>* find_min();
    Node<T>* find_max();
    bool is_bst();
    //bool is_bst(Node<T>* tmp, int min_val = std::numeric_limits<int>::min(), int max_val = std::numeric_limits<int>::max());
    bool remove(T value);
    void mirroring();
    void mirroring_rec();

    void batch_construction();
    void print_pre_order();
    T    pre_val(T val);
    float  balanceness_ratio_calc();
    //void bst<T>::delete_tree(Node<T>* tmp);
};

template <typename T>
bst<T>::bst() : root(nullptr) {}

template <typename T>
bst<T>::~bst() {
    if (root!=nullptr) ::delete_tree(root);
}

template <typename T>
void bst<T>::insert(Node<T>* tmp, T value) {
    if (value > tmp->value) {
        if (tmp->right == nullptr) {
	    ++length;
            tmp->right = new Node(value);
	    tmp->right->parent = tmp;
        } else {
            insert(tmp->right, value);
        }
    } else {
        if (tmp->left == nullptr) {
	    ++length;
            tmp->left = new Node(value);
	    tmp->left->parent = tmp;
        } else {
            insert(tmp->left, value);
        }
    }
}

template <typename T>
void bst<T>::insert(T value) {
    if (root == nullptr) {
        root = new Node(value);
    } else {
        insert(root, value);
    }
}


template <typename T>
void bst<T>::print(Node<T>* tmp) {
    if (tmp!=nullptr) {
        print(tmp->left);
        std::cout << tmp->value << std::endl;
	print(tmp->right);
    }
}

template <typename T>
void bst<T>::print() {
    print(root);
}

template <typename T>
Node<T>* bst<T>::search(Node<T>* tmp, T value) {
    if (tmp==nullptr) {
	return nullptr;
    } 
    if (value == tmp->value) {
        return tmp;
    } else if (value > tmp->value) {
        return search(tmp->right, value); 
    } else{
        return search(tmp->left, value);
    }
    return nullptr;
}

template <typename T>
Node<T>* bst<T>::search(T value) {
    return search(root,value);
}

template <typename T>
Node<T>* bst<T>::find_min(Node<T>* tmp) {
    Node<T>* t = tmp;
    while (t->left!=nullptr) {
        t = t->left;
    }
    return t;
}

template <typename T>
Node<T>* bst<T>::find_min() {
    if (root == nullptr) {
        throw std::invalid_argument("Tree is empty or invalid node");
    }
    return find_min(root);
}

template <typename T>
Node<T>* bst<T>::find_max(Node<T>* tmp) {
    Node<T>* t = tmp;
    while (t->right!=nullptr) {
        t = t->right;
    }
    return t;
}

template <typename T>
Node<T>* bst<T>::find_max() {
    if (root == nullptr) {
        throw std::invalid_argument("Tree is empty or invalid node");
    }
    return find_max(root);
}

//Implemented only for integer, needs further enhancements


template <typename T>
bool bst<T>::is_bst() {
    if (root == nullptr) return true; 

    return ::is_bst(root);
} 

template <typename T>
bool bst<T>::remove(T value) {
    Node<T>* tmp = search(value);
    if (tmp == nullptr) return false;
    bool f = 0;
    if (!tmp->right && !tmp->left) {

	std::cout << "Node to be deleted is leaf" << std::endl;
	Node<T>* t = tmp->parent;	
	if (t->value > tmp->value) {
	    f = 1;
	} 
	delete tmp;
	if (f) {
	    t->left = nullptr;
	} else {
	    t->right = nullptr;
	}
	--length;
	return true;
    } else if (!tmp->left) {
	std::cout << "Node to be deleted has only right child" << std::endl;
	tmp->parent->right = tmp->right;
	tmp->right->parent = tmp->parent;
	delete tmp;
	return true;
        	
    } else if (!tmp->right) {
	std::cout << "Node to be deleted has only left child" << std::endl;
	tmp->parent->left = tmp->left;
	tmp->left->parent = tmp->parent;
	delete tmp;
	return true;
        
    } else {
	std::cout << "Node to be deleted has both children" << std::endl;
        Node<T>* min_r = find_min(tmp->right);
        T val  = min_r->value;

	remove(min_r->value);
	tmp->value = val;

	return true;
    }

    return false;
}

template <typename T>
void bst<T>::mirroring(Node<T>* tmp) {
    std::queue<Node<T>*> q;
    q.push(tmp);

    while(!q.empty()) {
        Node<T>* curr = q.front();
        q.pop();
      
	Node<T>* t = curr->left;
	curr->left = curr->right;
	curr->right = t;
      
        if(curr->left != nullptr) q.push(curr->left);
        if(curr->right != nullptr) q.push(curr->right);
    }    
} 

template <typename T>
void bst<T>::print_in_level_order(Node<T>* tmp) {
    std::queue<Node<T>*> qq;
    qq.push(tmp);

    while(!qq.empty()) {
        Node<T>* curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
	    std::cout << "N ";
            continue;
        }

	std::cout << (curr->value) <<  " ";
        qq.push(curr->left);
        qq.push(curr->right);     
    }    
    std::cout << "\n";
} 

template <typename T>
void bst<T>::print_pre_order(Node<T>* tmp) {
    std::stack<Node<T>*> s;
    s.push(tmp);

    while(!s.empty()) {
        Node<T>* curr = s.top();
        s.pop();
	std::cout << (curr->value) <<  " ";
     
        if (curr->right) s.push(curr->right);
        if (curr->left)  s.push(curr->left);     
    }    
    std::cout << "\n";
} 


template <typename T>
void bst<T>::print_pre_order() {
    if (root == nullptr) return;

    print_pre_order(root);
}
template <typename T>
void bst<T>::mirroring() {
    if (root == nullptr) return;

    mirroring(root);    
    print_in_level_order(root);
} 

template <typename T>
void bst<T>::mirroring_rec(Node<T>* tmp) {
    if (tmp==nullptr) return;
     
    mirroring_rec(tmp->left);
    mirroring_rec(tmp->right);

    Node<T>* t = tmp->left;
    tmp->left = tmp->right;
    tmp->right = t;

} 

template <typename T>
void bst<T>::mirroring_rec() {
    if (root == nullptr) return;

    mirroring_rec(root);    
    print_in_level_order(root);
} 

template <typename T> 
void bst<T>::bst_to_vec(Node<T>* tmp, std::vector<T>& vec) {
    if (tmp!=nullptr) {
        bst_to_vec(tmp->left, vec);
        vec.push_back(tmp->value);        
	bst_to_vec(tmp->right, vec);
    }
}

template <typename T>
Node<T>* bst<T>::batch_construction(const std::vector<int>& vec, int left, int right) {
    if (left > right) return nullptr;

    int median_ind = left + (right - left) / 2;
    int median = vec[median_ind];
    Node<T>* t = new Node<T>(median);

    t->left = batch_construction(vec, left, median_ind - 1);
    t->right = batch_construction(vec, median_ind + 1, right);

    if (t->left) t->left->parent = t;
    if (t->right) t->right->parent = t;

    std::cout << "Median is " << median << std::endl;
    return t;
}

//Another approach of bacth construction. Not effective memory usage
/*template <typename T>
bst<T>* bst<T>::batch_construction(bst<T>* b1, std::vector<T>* vec) { 
    int median_ind =  vec->size()/2;
    T median_val = (*vec)[median_ind];
    
    if (median_ind != vec->size()) {
        b1->insert(median_val);
        std::vector<T> subvec1(vec->begin(), vec->begin() + median_ind);
        std::vector<T> subvec2(vec->begin() + median_ind + 1, vec->end());
        batch_construction(b1, &subvec1);
        batch_construction(b1, &subvec2);
    } 
    return b1;

}*/


template <typename T>
void bst<T>::batch_construction() {
    if (root == nullptr) return;
    std::vector<T> vec;
    bst_to_vec(root,vec);

    for (int value : vec) {
        std::cout << value << " ";
    }

    Node<T>* r = batch_construction(vec, 0, vec.size()-1 );
    std::cout << r->value << "r-> val" << std::endl;
    print_in_level_order(r);
    delete_tree(r); 
    return;
}


template <typename T>
T bst<T>::pre_val(T val) {
    std::cout << "Val is " << val << std::endl;
    if ( root == nullptr ) throw std::invalid_argument("Tree is empty or invalid node");
    Node<T>* tmp = search(val);
    
    if (tmp->left) {
	tmp = tmp->left;

	while (tmp->right!=nullptr) {
	   tmp = tmp->right;
	}

        return tmp->value;
	
    } else {
	while (tmp->parent!= nullptr && tmp != tmp->parent->right) {
	    tmp = tmp->parent;
	}
	if (tmp->parent == nullptr) throw std::runtime_error("This node has no predecessor.");
	return tmp->parent->value;
    }
    return 0;

}

template <typename T> 
float bst<T>::balanceness_ratio_calc(Node<T>* tmp) {
    std::queue<Node<T>*> q;
    int min_depth = INT_MAX;
    int max_depth = INT_MIN;

    q.push(tmp);
    while (!q.empty()) {
        Node<T>* n = q.front();
        q.pop();

	if (n->left!=nullptr) {
	    q.push(n->left);
	} 
	if (n->right!=nullptr) {
	    q.push(n->right);
	}

	if(n->right==nullptr && n->left == nullptr) {

	    int depth = 0;
            Node<T>* t = n;
	    while(t->parent != nullptr) {
	        ++depth;
		t = t->parent;
	    }
	    if (min_depth > depth) min_depth = depth;
	    if (max_depth < depth) max_depth = depth;
	}
    }
    
    std::cout << (float)min_depth/max_depth << "  the ratio is " << std::endl;
    return (float)min_depth/max_depth;

}


template <typename T> 
float bst<T>::balanceness_ratio_calc() {
    if (root == nullptr) return 0;
    
    return balanceness_ratio_calc(root);
}
