#include "bst.cpp"

int main() {
    bst<int> b;

    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(7);
    b.insert(3);
    b.insert(18);
    b.insert(17);
    b.insert(29);

    std::cout << "Binary Search Tree created." << std::endl;
    b.print_pre_order();

    b.print();
    std::cout << "Search the existing value 10: " << b.search(10)->value << std::endl;
    std::cout << "Search not existing value 17: " << b.search(27) << std::endl;

    std::cout << " --------------------- " <<std::endl;

    std::cout << "Find the minimum value of the tree: " << b.find_min()->value << std::endl;
    std::cout << " --------------------- " <<std::endl;
    std::cout << "Find the maximum value of the tree: " << b.find_max()->value << std::endl;
    std::cout << " --------------------- " <<std::endl;

    b.print();
    std::cout << b.is_bst() << std::endl;

    Node<int>* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    std::cout << "Testing is bst function. Result is: " << is_bst(root) << std::endl;
    
    delete_tree(root); 
         
    // Implemented only for testing the is_bst function
    Node<int>* root1 = new Node(4);
    root1->left = new Node(10);
    root1->right = new Node(5);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    std::cout << "Testing not bst tree detection. Result is : "<< is_bst(root1) << std::endl;
    delete_tree(root1); 

    std::cout << "Testing bst node deletion part" << std::endl;
    b.print();
    
    std::cout << "Remove leaf node : 29 " << std::endl;
    b.remove(29);
    b.print();

    b.print();
    std::cout << "Delete node 15 " << std::endl;
    b.remove(15);

    b.print();
    std::cout << "---------------------" << std::endl;

    b.insert(14);
    b.insert(15);
    b.insert(16);

    b.print();

    std::cout << "Delete node 17" << std::endl;
    b.remove(17);
    b.print();

    b.insert(6);
    b.insert(9);
    std::cout << "---------------------" << std::endl;
    b.print();

    std::cout << "Delete node 5 from main" << std::endl;
    b.remove(5);
    b.print();


    /*std::cout << "BST mirroring iterative approach" << std::endl;
    b.mirroring();

    b.print();
    std::cout << "BST mirroring recursive approach" << std::endl;
    b.mirroring_rec();
    std::cout << "---------------------" << std::endl;
    b.print();*/


    std::cout << "---------------------" << std::endl;
    std::cout << "---------------------" << std::endl;
    
    b.batch_construction();

    std::cout << "    10" << std::endl;
    std::cout << "   /   \\" << std::endl;
    std::cout << "  6     15" << std::endl;
    std::cout << " / \\   /  \\" << std::endl;
    std::cout << "3   7 14  16" << std::endl;
    std::cout << "     \\      \\" << std::endl;
    std::cout << "      9      18" << std::endl;
    

    b.print();
    b.print_pre_order();
    return 0;
}
