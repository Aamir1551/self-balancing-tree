#ifndef AVL_TREE_TREE_H
#define AVL_TREE_TREE_H //check google styleguide for naming on guards

class Tree {

    public:
        Tree* left_child = nullptr;
        Tree* right_child = nullptr;
        Tree * root = nullptr;
        int balance_factor = 0; //balance_factor = left depth - right depth
        int value;
        int right_depth = 0;
        int left_depth = 0;
        Tree(int value): value(value) {};
        void add(int new_value);
        void balance_tree();
        int get_balance_factor();
        void rotate_right();
        void rotate_left();
        void rebalance_tree();
        static void connect_right(Tree *root, Tree *right_child);
        static void connect_left(Tree *root, Tree *left_child);
        static void compute_balance_factors(Tree *root);


};

#endif