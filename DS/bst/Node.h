template <typename T>
struct Node {
    T value;
    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

    Node(T value) : value(value), left(nullptr), right(nullptr), parent(nullptr) {}
};
