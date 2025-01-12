#include <limits>
#include "Node.h"

template <typename T>
void delete_tree(Node<T>* node) {
    if (node) {
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
}

template <typename T>
bool is_bst(Node<T>* tmp, T min_val = std::numeric_limits<T>::min(), T max_val = std::numeric_limits<T>::max()) {
    if (!tmp) return true;

    if (tmp->value <= min_val || tmp->value >= max_val) {
        return false;
    }

    return is_bst(tmp->left, min_val, tmp->value) &&
           is_bst(tmp->right, tmp->value, max_val);
}
