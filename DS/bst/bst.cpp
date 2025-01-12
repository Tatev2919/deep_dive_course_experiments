#include <iostream>
#include <limits>
#include <queue>

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
        tmp->value = min_r->value;

        min_r->parent->left = nullptr;
        delete min_r;	
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

