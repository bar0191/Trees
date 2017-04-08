//  Program 3
//  BST.cpp
//  Binary Search Tree
//
//  Created by Brandon Reid on 8/1/16.
//
//

#include "BST.h"

/*
 ============================================================================
 Function    : BST()
 Parameters  : nothing
 Return      : nothing
 Description : Constructor for BST
 ============================================================================
 */

BST::BST()
{
    treeHeight = 0;
}

/*
 ============================================================================
 Function    : ~BST()
 Parameters  : nothing
 Return      : nothing
 Description : de-constructor for BST
 ============================================================================
 */

BST::~BST()
{
    
}

/*
 ============================================================================
 Function    : getTreeHeight()
 Parameters  : nothing
 Return      : treeHeight (private BST class value)
 Description : getter for BST TreeHeight
 ============================================================================
 */

int BST::getTreeHeight() const
{
    return treeHeight;
}

/*
 ============================================================================
 Function    : setTreeHeight()
 Parameters  : int heightSize
 Return      : nothing
 Description : setter for BST TreeHeight
 ============================================================================
 */

void BST::setTreeHeight(int heightSize)
{
    treeHeight = heightSize;
}

/*
 ============================================================================
 Function    : setNewNode()
 Parameters  : int data
 Return      : newNode
 Description : Used to create a new Node sack
 ============================================================================
 */

Node* BST::setNewNode(int data)
{
    Node* newNode = new Node();         // create new Node();
    
    // sets data and pointer values
    newNode->setData(data);
    newNode->setLeftChild(nullptr);
    newNode->setRightChild(nullptr);
    
    return newNode;                     // return new node sack
}

/*
 ============================================================================
 Function    : maxElm()
 Parameters  : Node* root
 Return      : root
 Description : Used as a traversal to traverse down the right subtree to find
 the maximum value in the tree, this function is used in the removal of a 
 interior node. Adds much more simplicity
 ============================================================================
 */

Node* BST::MaxElm(Node* root)
{
    // while pointer continues to go down the right subtree
    // make root equal to the value
    // essentially making its way down to the largest value
    while (root->getRightChild())
    {
        root = root->getRightChild();
    }
    
    return root;    // return largest value in the tree
}

/*
 ============================================================================
 Function    : minElm()
 Parameters  : Node* root
 Return      : root
 Description : Used exactly as maxElm() except goes down left subtree looking
 for min value in the tree
 ============================================================================
 */

Node* BST::MinElm(Node* root)
{
    // while pointer continues to go down the left subtree
    // make root equal to the value
    // essentially reaching the lowest value in the tree
    while (root->getLeftChild())
    {
        root = root->getLeftChild();
    }
    
    return root;    // return lowest value in the tree
}

/*
 ============================================================================
 Function    : addElement()
 Parameters  : Node* root, int data
 Return      : root
 Description : Recursive insert function to add new elements to the tree
 this function works by running the function over and over until each sub-
 problem is reached - refer to comments in the function
 ============================================================================
 */

Node* BST::addElement(Node* root, int data)
{
    // once the function finds a null spot to put new value
    //if statement will be satisfied, adding new Node sack
    
    if (root == nullptr)
    {
        root = setNewNode(data);
        
        return root;
    }
    
    // if data entered by user is less then or equal to value being pointed
    // to, continue to use recursion until null spot is reached
    if (data <= root->getData())
    {
        // continues to set pointer to next leftchild recursively
        // this will continue to recurse down the tree until if statement
        // is satisfied
        root->setLeftChild(addElement(root->getLeftChild(), data));
    }
    // if data is not less then or equal to, then it's greater than
    // so, continue to recurse down the right subtree
    else
    {
        // works same a if statement, except recursively down right subtree
        root->setRightChild(addElement(root->getRightChild(), data));
    }
    
    return root;
}

/*
 ============================================================================
 Function    : removeElement()
 Parameters  : Node* parent, int data
 Return      : parent
 Description : used to remove value specified by user
 function also works recursively down a specific subtree depending on value
 entered by the user. 
 before removing a node we have to know if the node has no children, one 
 child, or two children, or if it is the root node.
 I used the variable parent, so the function would be more simple for me to 
 understand.
 Since when deleting we have to know whether it is a parent or child
 ============================================================================
 */

Node* BST::removeElement(Node* parent, int data)
{
    // after finishing recursions successfully
    // this if statement will run
    if (parent == nullptr)
    {
        return parent;
    }
    
    // just as insert/remove functions
    // if data entered by user us less then parent being pointed to
    // continue to recurse down the left subtree
    if (data < parent->getData())
    {
        parent->setLeftChild(removeElement(parent->getLeftChild(), data));
    }
    // same as above except for the value greater then value being pointed to
    // will continue to recurse down the right subtree
    else if (parent->getData() < data)
    {
        parent->setRightChild(removeElement(parent->getRightChild(), data));
    }
    // once this else statement is reached that means the value should be found
    else // found element
    {
        // if parent has no children
        // left and right child is null
        // simply delete that parent/root
        if (parent->getLeftChild() == nullptr && parent->getRightChild() == nullptr)
        {
            delete parent;
            parent = nullptr;
        }
        // if parent has no left child (one child)
        // before deleting, must set prev value to rightchild
        else if (parent->getLeftChild() == nullptr)
        {
            Node* nodeToDelete = parent;
            
            parent = parent->getRightChild();
            
            delete nodeToDelete;
        }
        // if parent has no right child (one child)
        // same as above except for left child
        else if (parent->getRightChild() == nullptr)
        {
            Node* nodeToDelete = parent;
            
            parent = parent->getLeftChild();
            
            delete nodeToDelete;
        }
        // if parent has two children
        // most challenging, have to recursively swap the maxElm in the tree up to the parent
        else
        {
            Node* nodeToDelete = nullptr;
            
            nodeToDelete = MaxElm(parent->getLeftChild());
            
            parent->setData(nodeToDelete->getData());
            parent->setLeftChild(removeElement(parent->getLeftChild(), nodeToDelete->getData()));
        }
    }
    
    return parent;
    
}

/*
 ============================================================================
 Function    : findElement() & findInReverse()
 Parameters  : Node* root, int data
 Return      : bool value, true or false
 Description : Used to recursively search for element in the tree
 ============================================================================
 */

bool BST::findElement(Node* root, int data)
{
    // if this if statement is ran, tree was either empty
    // or value searched didn't exist in the tree
    if (root == nullptr)
    {
        return false;
    }
    
    // if data equals value in the tree
    // return tree
    if (data == root->getData())
    {
        return true;
    }
    
    // if and else statements will continue to run recursively until one of the
    // above if statements is satisfied
    
    // if data specified by user is less then current value being pointed to
    // continue to recurse down left subtree
    if (data <= root->getData())
    {
        return findElement(root->getLeftChild(), data);
    }
    // else data is greater then, so recurse down right subtree
    else
    {
        return findElement(root->getRightChild(), data);
    }
}

// same as above function just in reverse
bool BST::findInReverse(Node* root, int data)
{
    if (root == nullptr)
    {
        return false;
    }
    
    if (data == root->getData())
    {
        return true;
    }
    
    if (data <= root->getData())
    {
        return findInReverse(root->getRightChild(), data);
    }
    else
    {
        return findInReverse(root->getLeftChild(), data);
    }
}

/*
 ============================================================================
 Function    : displayHeight()
 Parameters  : Node* root
 Return      : treeHeight
 Description : Calculates height of tree, and returns it
 ============================================================================
 */

int BST::displayHeight(Node* root)
{
    int leftHeight  = 0;
    int rightHeight = 0;
        treeHeight  = 0;
    
    //if (root == nullptr || (root->left == nullptr && root->right == nullptr))
    // should add the above line
    if (root == nullptr)
    {
        return treeHeight;
    }
    
    // recursively move down left and right side together
    rightHeight = displayHeight(root->getRightChild());
    leftHeight  = displayHeight(root->getLeftChild());
    
    // compare left and right values
    if (rightHeight < leftHeight)
    {
        // increment tree height
        treeHeight = leftHeight + 1;
        
        return treeHeight;
    }
    // if rightHeight is greater then LeftHeight
    else
    {
        treeHeight = rightHeight + 1;
        
        return treeHeight;
    }
}

/*
 ============================================================================
 Function    : reverseTree()
 Parameters  : Node* root
 Return      : nothing
 Description : function will reverse right and left child in each subtree all
 the way up until root is reached
 ============================================================================
 */

void BST::reverseTree(Node* root)
{
    Node* nodeToReverse;
    
    // if statement will stop function after recursion is done
    if (root == nullptr)
    {
        return;
    }
    
    // recurse down left and right child together
    reverseTree(root->getLeftChild());
    reverseTree(root->getRightChild());
    
    // take in right child in subtree
    nodeToReverse = root->getRightChild();
    
    // set rightchild to leftchild
    // then set left child to right child value we took in before
    root->setRightChild(root->getLeftChild());
    root->setLeftChild(nodeToReverse);
}

/*
 ============================================================================
 Function    : printTreePreOrder()
 Parameters  : root
 Return      : nothing
 Description : prints tree in pre-order traversal
 ============================================================================
 */

void BST::printTreePreOrder(Node* root)
{
    
    if (root == nullptr)
    {
        return;
    }
    
    // meets root, then down left and then down right
    cout << root->getData() << " ";
    printTreePreOrder(root->getLeftChild());
    printTreePreOrder(root->getRightChild());
    
    
}

/*
 ============================================================================
 Function    : printTreeInOrder()
 Parameters  : root
 Return      : nothing
 Description : prints tree in-order traversal
 ============================================================================
 */

void BST::printTreeInOrder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }
    
    // goes down left then back up to root, and theen down to right
    printTreeInOrder(root->getLeftChild());
    cout << root->getData() << " ";
    printTreeInOrder(root->getRightChild());
}

/*
 ============================================================================
 Function    : wipeTree()
 Parameters  : node
 Return      : nothing
 Description : clear entire tree (STILL WORKING ON THIS)
 ============================================================================
 */

void BST::wipeTree(Node* node)
{
    if (node != nullptr)
    {
        wipeTree(node->getLeftChild());
        wipeTree(node->getRightChild());
        delete node;
    }
    
    
    
    
}