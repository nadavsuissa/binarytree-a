#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
/* Lets Assume Graph G is:

         1
      2__|__3
   4__|__5

Depth First Traversals: 
Inorder (Left, Root, Right) : 4 2 5 1 3 
Preorder (Root, Left, Right) : 1 2 4 5 3 
Postorder (Left, Right, Root) : 4 5 2 3 1
*/
namespace ariel
{
    template <typename Type>
    class BinaryTree
    {
        struct Node
        {
            Type data;
        };          // As of Now just Data Type T (General) For Test and Compile
        Node *root; // Easier to Call root This Way
        // Node Iterator For Scan Tree Nodes - Hence Under Node
        class Iterator
        {
        private:
            Node *n; // As of Now For Test Node is Construced of data of Type T (General)
        public:
            Iterator() {} // Empty Constructor For Tests
            // Override Operator --(++,*,!=,->,==)

            // NEQ Op
            bool operator!=(const Iterator &it2)
            {
                return false;
            }
            // Add Op
            Iterator &operator++()
            {

                return *this;
            }
            // (*)Op
            Type &operator*()
            {
                return n->data;
            }
            // -> Op
            Type *operator->()
            {
                return &(n->data);
            }
            // EQ Op
            bool operator==(const Iterator &it2)
            {
                return false;
            }
        };
        // Binary Tree Class :
    public:
        //Binary Tree Constructor - Initialize Empty Tree
        BinaryTree<Type>()
        {
            root = nullptr; // Nothing Connected Hence root is Null Pointer
        }
        // Binary Tree Builders: Connect to Parent from Right the Data to Add Node
        BinaryTree<Type> add_right(const Type &parent, const Type &datatoadd)
        {
            return *this;
        }
        // Binary Tree Builders: Connect to Parent from Left the Data to Add Node
        BinaryTree<Type> add_left(const Type &parent, const Type &datatoadd)
        {
            return *this; // Return Binary Tree Hence This
        }
        // Binary Tree Builders: Create Root Node & Add with Data
        BinaryTree<Type> add_root(const Type &datatoadd)
        {
            return *this; // Return Binary Tree Hence This
        }
        // Binary Tree Builders: Connect to Parent from Right the Data to Add Node

        // In order to Scan Via Iterator, I must have: Start Iterator and Fiish Iterator
        // For Every Type of Tree Scan I Need a Start & Finish
                Iterator begin() // Return Start Point It
        {
            return Iterator{};
        }

        Iterator end() // Return Finish Point It
        {
            return Iterator{};
        }
        Iterator begin_preorder()
        {
            return Iterator{}; // Return Start Point It
        }
        Iterator end_preorder() // Return Finish Point It
        {
            return Iterator{};
        }

        Iterator begin_inorder() // Return Start Point It
        {
            return Iterator{};
        }

        Iterator end_inorder() // Return Finish Point It
        {
            return Iterator{};
        }

        Iterator begin_postorder() // Return Start Point It
        {
            return Iterator{};
        }

        Iterator end_postorder() // Return Finish Point It
        {
            return Iterator{};
        }
        // Nothing Formal - Just an Elegent Way to Output
        friend std::ostream &operator<<(std::ostream &out, const BinaryTree<Type> &b)
        {
            return out;
        }
    };

}