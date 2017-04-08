//  Program 3
//  Node.h
//  Binary Search Tree
//
//  Created by Brandon Reid on 8/1/16.
//
//

#ifndef Node_h
#define Node_h

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::transform;
using std::numeric_limits;
using std::streamsize;

/*
 ============================================================================
 Class             : Node
 Private Variables : data, leftChild, RightChild
 Description       : This Class provides Nodes to the BST
 ============================================================================
 */

class Node
{
private:
    int data;
    Node* leftChild;
    Node* rightChild;
public:
    // inline functions left in the class for simplicity
    Node() : data(0), leftChild(nullptr), rightChild(nullptr) {}
    ~Node() {}
    int getData() const { return data; }
    Node* getLeftChild() const { return leftChild; }
    Node* getRightChild() const { return rightChild; }
    void setData(int dataValue) { data = dataValue; }
    void setLeftChild(Node* leftValue) { leftChild = leftValue; }
    void setRightChild(Node* rightValue) { rightChild = rightValue; }
};

typedef Node* NodePtr;  // typedef Node Ptr to communicate to Node class

// enum values for menu in switch statement (main.cpp)
enum cmdCode { addnode, removenode, search, print, reverse, height, commands, exitprog, clear, invalid };

// basic user functions for main.cpp
void intro();
string cmd();
cmdCode cnvrt(string const& incmd);
void cmds();
void clrScreen();
void clrBuffer();

#endif