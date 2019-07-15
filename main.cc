#include <iostream>
#include "./tree.hpp"
using namespace std;

int main(int argc, char** argv) {

    Tree *a = new Tree(5);
    a->add(10);
    a->add(100);
    a->add(11);
    a->add(1);
    a->add(-5);
    a->add(6);
    
    std::cout << a->value << std::endl; //5
    std::cout << a->right_child->value << std::endl; //10
    std::cout << a->right_child->right_child->value << std::endl; //100
    std::cout << a->right_child->right_child->left_child->value << std::endl; //11
    std::cout << a->left_child->value << std::endl; //1
    std::cout << a->left_child->left_child->value << std::endl; //-5
    std::cout << a->right_child->left_child->value << std::endl; //6
    cout << "jj" << endl;

    return 0;
}