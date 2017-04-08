//  Program 3
//  BST.h
//  Binary Search Tree
//
//  Created by Brandon Reid on 8/1/16.
//
//

#ifndef BST_h
#define BST_h

#include "Node.h"

/*
 ============================================================================
 Class             : BST
 Private Variables : treeHeight, Root
 Description       : This Class manages the Binary Search String, keeps a 
 value of how high the tree is.
 ============================================================================
 */

class BST
{
private:
    int treeHeight;                                 // hold height value
public:
    BST();                                          // constructor
    ~BST();                                         // deconstructor
    int getTreeHeight() const;                      // getHeight
    void setTreeHeight(int heightSize);             // setHeight
    Node* setNewNode(int data);                     // setNewNode
    Node* MaxElm(Node* root);                       // FindMaxValue
    Node* MinElm(Node* root);                       // FindMinValue
    Node* addElement(Node* root, int data);         // insert
    Node* removeElement(Node* parent, int data);    // remove
    bool findElement(Node* root, int data);         // search
    int displayHeight(Node* root);                  // Height
    void reverseTree(Node* root);                   // reverse
    void printTreePreOrder(Node* root);             // print
    void printTreeInOrder(Node* root);              // in-order print
    void wipeTree(Node* node);                      // clear tree
    bool findInReverse(Node* root, int data);
};

typedef BST* BSTPtr;        // type def to communicate to class

#endif