
  UN-ORDERED MAP/GRAPH

  This program will be used as
  a utility to refrence to in
  2100 to tree list implimentation
  
  other ways: stl map, set, maplist etc
  
  refrences:
  http://www.bogotobogo.com/cplusplus/binarytree.php
  https://www.youtube.com/watch?v=COZK7NATh4k
  http://www.cprogramming.com/tutorial/lesson18.html
  
        root
        /  \
    child  child
      /     \
   leaf    leaf
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// set up Nodes as you would a link list
// but now we will have a pointer going left and right
struct Tree
{
    char data;
    Tree* left;
    Tree* right;
};

Tree* getNewNode(char data)
{
    Tree* newNode = new Tree();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
}

Tree* insert(Tree* root, char data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

/* Tree Minimum */
Tree* minTree(Tree* node)
{
	if(node == NULL) return NULL;
	while(node->left) 
	    node = node->left;
	return node;
}

/* Tree Maximum */
Tree* maxTree(Tree* node)
{
	while(node->right) 
	    node = node->right;
	return node;
}

Tree* Delete(Tree* root, char data)
{
    if (root == NULL) return root;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
           
        }
        else if ( root->left == NULL)
        {
            Tree* temp = root;
            root = root->right;
            delete temp;
            
        }
        else if ( root->right == NULL)
        {
            Tree* temp = root;
            root = root->left;
            delete temp;
           
        }
        else
        {
            Tree* temp = minTree(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}



void printTreeSortOrder(Tree* root)
{
    if (root == NULL) return;
    
    printTreeSortOrder(root->left);
    cout << root->data << " ";
    printTreeSortOrder(root->right);
}

void printTreePreOrder(Tree* root)
{
    if (root == NULL) return;
    
    cout << root->data << " ";
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);   
}

void printTreePostOrder(Tree* root)
{
    if (root == NULL) return;
    
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    cout << root->data << " ";
}

bool search(Tree* root, char data)
{
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data <= root->data) return search(root->left, data);
    else return search(root->right, data);
    
}

bool isBST(Tree* root)
{
    static int lastData = INT_MIN;
    if (root == NULL) return false;
    
    isBST(root->left);
    
    if(lastData < root->data)
    {
        lastData = root->data;
    }
    else
    {
        cout << "Not a Binary Search Tree :( " << endl;
        return false;
    }
    
    isBST(root->right);
    return true;
    
}

int treeSize(Tree* root)
{
    if (root == NULL) return 0;
    else
        return treeSize(root->left) + 1 + treeSize(root->right);
}

int maxDepth(Tree* root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    
    return leftDepth > rightDepth ?
                            leftDepth + 1 : rightDepth + 1;
}

int minDepth(Tree* root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    return leftDepth < rightDepth ?
                            leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(Tree* root)
{
    if (maxDepth(root)-minDepth(root) <= 1)
        return true;
    else
        return false;
}

int getLevel(Tree* root, int elm, int level)
{
    if (root == NULL) return 0;
    if (elm == root->data)
        return level;
    else if (elm < root->data)
        return getLevel(root->left, elm, level+1);
    else
        return getLevel(root->right, elm, level+1);
}

void levelPrint(Tree* node, vector<vector<char> > &elm, int level)
{
    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL)
    {
        elm[level].push_back(node->data);
        return;
    }
    
    elm[level++].push_back(node->data);
    levelPrint(node->left, elm, level);
    levelPrint(node->right, elm, level);
}

void clear(Tree* node)
{
    if (node != NULL)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

int main ()
{
    Tree* root = NULL;
    char the_char;
    vector<vector<char> > elm; 

    cout << "Running Tree function sequences... " << endl << endl;

    root = insert(root, 'C');
    root = insert(root, 'A');
    root = insert(root, 'D');
    root = insert(root, 'B');
    root = insert(root, 'F');
    root = insert(root, 'W');
    root = insert(root, 'V');
    root = insert(root, 'G');
    root = insert(root, 'E');
    
    /*
     root = root->insert(root, 1);
     root = root->insert(root, 2);
     root = root->insert(root, 3);
     root = root->insert(root, 4);
     root = root->insert(root, 5);
     root = root->insert(root, 6);
     root = root->insert(root, 7);
     root = root->insert(root, 8);
     root = root->insert(root, 9);
     
     cout << "Tree PreOrder: ";
     printTreePreOrder(root); cout << endl;
     */
    
    if (isBST(root) == true)
    {
        cout << "Sequences indicate this is a Binary Search Tree! " << endl;
    }
    
    if (isBalanced(root) == false)
    {
        cout << "Non-Balanced Tree! " << endl;
    }
    
    cout << "# of Nodes in Tree: ";
    cout << treeSize(root) << endl;
    
    cout << "Tree's Max depth(# of Nodes): ";
    cout << maxDepth(root) << endl;
    
    cout << "Tree's min depth(# of Nodes): ";
    cout << minDepth(root) << endl;
    
    int mxDepth = maxDepth(root);
    elm.resize(mxDepth+1);
    int level = 0;
    
    levelPrint(root, elm, level);
    cout << "Tree Levels: " << endl;
    
    for (int i = 0; i <= mxDepth; i++)
    {
        cout << "level " << i << ": ";
        
        for (int j = 0; j < elm[i].size(); j++)
        {
            cout << elm[i][j] << " ";
        }
        
        cout << endl;
    }
    
    cout << "Enter char you would like to search: ";
    cin  >> the_char;
    cin.ignore();
    
    if (search (root, the_char) == true) cout << "Found\n";
    else cout << "Not found\n";
    
    cout << "Pre-Order: ";
    printTreePreOrder(root); cout << endl;
    cout << "Post-Order: ";
    printTreePostOrder(root); cout << endl;
    cout << "Sorted Order: ";
    printTreeSortOrder(root); cout << endl;
    
    cout << "Enter char you would like to delete: ";
    cin  >> the_char;
    cin.ignore();
    
    Delete(root, the_char);
    
    cout << "Sorted Order: ";
    printTreeSortOrder(root); cout << endl;
    
    cout << "Clearing memory... " << endl;
    clear(root);
	return 0; 
}
