#include <math.h>
#include "./tree.hpp"

void Tree::add(int new_value)  {
  if(new_value > this->value) {
        if(right_child != nullptr) {
            this->right_child->add(new_value);
        } else {
            Tree::connect_right(this, new Tree(new_value));
        }
    } else {
        if(left_child != nullptr) {
            this->left_child->add(new_value);
        } else {
            Tree::connect_left(this, new Tree(new_value));
        }
    }
}

void Tree::rebalance_tree() {
    this->balance_tree();
    Tree::compute_balance_factors(this);
}


void Tree::balance_tree() {
    //first go to all nodes at bottom and balance them (by rotating or rotating left)
    if(this->right_child) {
        this->right_child->balance_tree();
    }

    if(this->left_child) {
        this->left_child->balance_tree();
    }

    if(this->balance_factor > 1) {
        this->rotate_right();
    } else if(this->balance_factor < -1) {
        this->rotate_left();
    }
}

void Tree::connect_right(Tree *root, Tree *right_child) {
    root->right_child = right_child;
    right_child->root = root;
}

void Tree::connect_left(Tree *root, Tree *left_child) {
    root->left_child = left_child;
    left_child->root = root;
}

void Tree::rotate_left() {
    Tree::connect_right(this->root, this->right_child);
    Tree::connect_right(this, this->right_child->left_child);
    Tree::connect_left(this->root->right_child, this);   
}

void Tree::rotate_right() {
    Tree::connect_left(this->root, this->left_child);
    Tree::connect_left(this, this->left_child->right_child);
    Tree::connect_right(this->root->left_child, this);
}

int Tree::get_balance_factor() {
    return this->balance_factor;
}

void Tree::compute_balance_factors(Tree *root) {
    root->right_depth = 0;
    root->left_depth = 0;

    if(root->right_child != nullptr) {
        compute_balance_factors(root->right_child);
        root->right_depth = std::fmax(abs(root->right_child->right_depth), abs(root->right_child->left_depth)) + 1;
    }

    if(root->left_child != nullptr) {
        compute_balance_factors(root->left_child);
        root->left_depth = std::fmax(abs(root->left_child->right_depth), abs(root->left_child->left_depth)) + 1;
    }

    root->balance_factor = root->left_depth - root->right_depth;
}