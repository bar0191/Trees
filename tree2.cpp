#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::cin;

class Node
{
private:
    int data;
    Node* leftChild;
    Node* rightChild;
public:
    Node() : data(0), leftChild(nullptr), rightChild(nullptr) {}
    ~Node() {}
    auto getData() const { return data; }
    auto getLeftChild() const { return leftChild; }
    auto getRightChild() const { return rightChild; }
    void setData(char dataValue) { data = dataValue; }
    void setLeftChild(Node* leftValue) { leftChild = leftValue; }
    void setRightChild(Node* rightValue) { rightChild = rightValue; }
};

class BST
{
private:
    int treeHeight;
    //Node* root;
public:
    BST() : treeHeight(0) {} //, root(nullptr) {}
    ~BST() {}
    auto getTreeHeight() const { return treeHeight; }
    //auto getRoot() const { return root; }
    void setTreeHeight(int heightSize) { treeHeight = heightSize; }
    //void setRoot(Node* rootValue) { root = rootValue; }
    
    auto setNewNode(int data)
    {
        Node* newNode = new Node();
        
        newNode->setData(data);
        newNode->setLeftChild(nullptr);
        newNode->setRightChild(nullptr);
        
        return newNode;
    }
    
    auto treeMaxElm(Node* root)
    {
        while (root->getRightChild())
        {
            root = root->getRightChild();
        }
        
        return root;
    }
    
    auto treeMinElm(Node* root)
    {
        while (root->getLeftChild())
        {
            root = root->getLeftChild();
        }
        
        return root;
    }
    auto addElement(Node* root, int data)
    {
        if (root == nullptr)
        {
            root = setNewNode(data);
            return root;
        }
        
        if (data <= root->getData())
        {
            root->setLeftChild(addElement(root->getLeftChild(), data));
        }
        else
        {
            root->setRightChild(addElement(root->getRightChild(), data));
        }
        
        return root;
    }
    
    auto removeElement(Node* parent, int data)
    {
        if (parent == nullptr)
        {
            return parent;
        }
        
        if (data < parent->getData())
        {
            parent->setLeftChild(removeElement(parent->getLeftChild(), data));
        }
        else if (parent->getData() < data)
        {
            parent->setRightChild(removeElement(parent->getRightChild(), data));
        }
        else // found element
        {
            if (parent->getLeftChild() == nullptr && parent->getRightChild() == nullptr)
            {
                delete parent;
                parent = nullptr;
            }
            else if (parent->getLeftChild() == nullptr)
            {
                Node* nodeToDelete = parent;
                parent = parent->getRightChild();
                delete nodeToDelete;
            }
            else if (parent->getRightChild() == nullptr)
            {
                Node* nodeToDelete = parent;
                parent = parent->getLeftChild();
                delete nodeToDelete;
            }
            else
            {
                Node* nodeToDelete = nullptr;
                nodeToDelete = treeMinElm(parent->getRightChild());
                parent->setData(nodeToDelete->getData());
                parent->setRightChild(removeElement(parent->getRightChild(), nodeToDelete->getData()));
            }
        }
        
        return parent;
            
    }
    
    bool findElement(Node* root, int data)
    {
        if (root == nullptr)
        {
            return false;
        }
        
        if (root->getData() == data)
        {
            return true;
        }
        
        
        if (data <= root->getData())
        {
            return findElement(root->getLeftChild(), data);
        }
        else
        {
            return findElement(root->getRightChild(), data);
        }
    }
    
    
    
    int displayHeight(Node* root)
    {
        int leftHeight = 0;
        int rightHeight = 0;
        treeHeight = 0;
        
        // should add OR if left and right are = to null
        if (root == nullptr)
        {
            return treeHeight;
        }
        
        rightHeight = displayHeight(root->getRightChild());
        leftHeight  = displayHeight(root->getLeftChild());
        
        //if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        
        if (rightHeight < leftHeight)
        {
            treeHeight = leftHeight + 1;
            return treeHeight;
        }
        else
        {
            treeHeight = rightHeight + 1;
            return treeHeight;
        }
    }
    
    void reverseTree(Node* root)
    {
        Node* temp;
        
        if (root == nullptr)
        {
            return;
        }
        
        reverseTree(root->getLeftChild());
        reverseTree(root->getRightChild());
        
        temp = root->getRightChild();
        root->setRightChild(root->getLeftChild());
        root->setLeftChild(temp);
    }
};

typedef Node* NodePtr;
typedef BST* TreePtr;

enum cmdCode { addnode, removenode, search, print, reverse, height, commands, exitprog, clear, invalid };

void printTreePreOrder(Node* node);
void printTreeSortOrder(Node* root);
string cmd();
cmdCode cnvrt(string const& incmd);
void cmds();
void clrScreen();
void clrBuffer();

int main()
{
    NodePtr root = nullptr;
    BST tree;
    string input;
    int uInt;
    
    cmds();

    do
    {
        input = cmd();
        
        switch (cnvrt(input))
        {
            case addnode:
                cout << "Enter unique integer value you would like to add to the BST: ";
                cin  >> uInt;
                cin.ignore();
                
                if (!cin)
                {
                    cout << "ERROR: Value entered is not a unique integer value... " << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                
                if (tree.findElement(root,uInt) == true)
                {
                    cout << "ERROR: Value already exists in the BST... " << endl;
                }
                else
                {
                    root = tree.addElement(root, uInt);
                }
                break;
            case removenode:
                cout << "Enter unique integer value you would like to remove from the BST: ";
                cin  >> uInt;
                cin.ignore();
                
                if (!cin)
                {
                    cout << "ERROR: Value entered is not a unique integer value... " << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                
                root = tree.removeElement(root, uInt);
                break;
            case search:
                cout << "Enter unique integer value to be searched in the BST: ";
                cin  >> uInt;
                cin.ignore();
                
                if (!cin)
                {
                    cout << "ERROR: Value entered is not a unique integer value... " << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                if (tree.findElement(root, uInt) == true)
                {
                    cout << "True: " << uInt << endl;
                }
                else
                {
                    cout << "False: " << uInt << endl;
                }
                break;
            case print:
                cout << "Tree PreOrder: ";
                printTreePreOrder(root);
                cout << endl;
                cout << "Tree SortOrder: ";
                printTreeSortOrder(root);
                cout << endl;
                break;
            case reverse:
                tree.reverseTree(root);
                break;
            case height:
                cout << "Height: " << tree.displayHeight(root) << endl;
                break;
            case commands:
                cmds();
                break;
            case exitprog:
                cout << "Thank you for using my BST! Goodbye! " << endl;
                break;
            case clear:
                clrScreen();
                break;
            default:
                cout << "ERROR: Invalid input entered... Please try again. " << endl;
                cin.clear();
                break;
        }
    } while (cnvrt(input) != exitprog);
    
    return 0;
}

void printTreePreOrder(Node* node)
{
    
    if (node == nullptr)
        return;
    
    cout << node->getData() << " ";
    printTreePreOrder(node->getLeftChild());
    printTreePreOrder(node->getRightChild());
    
    
}

void printTreeSortOrder(Node* root)
{
    if (root == NULL) return;
    
    printTreeSortOrder(root->getLeftChild());
    cout << root->getData() << " ";
    printTreeSortOrder(root->getRightChild());
}

void cmds()
{
    cout << endl;
    cout << "+---Commands---+\n"
         << "| Add          |\n"
         << "| Remove       |\n"
         << "| Search       |\n"
         << "| Print        |\n"
         << "| Reverse      |\n"
         << "| Height       |\n"
         << "| Commands     |\n"
         << "| Clear        |\n"
         << "| Quit         |\n"
         << "+--------------+\n";
}

string cmd()
{
    string cmd;             // delcare string for user cmd
    
    cout << endl;			// endline before printing new cmd line
    cout << "cmd> ";		// output cmd line
    getline(cin, cmd);		// get user input
    
    return cmd;             // return string input by user
}

cmdCode cnvrt(string const& incmd)
{
    if (incmd == "add") return addnode;		// to enum value 0
    if (incmd == "remove") return removenode;		// to enum value 2
    if (incmd == "search") return search;           // to enum value 4
    if (incmd == "print") return print;             // to enum value 5
    if (incmd == "reverse") return reverse;
    if (incmd == "height") return height;
    if (incmd == "commands") return commands;       // to enum value 6
    if (incmd == "quit") return exitprog;           // to enum value 7
    if (incmd == "clear") return clear;             // to enum value 8
    else return invalid;                            // default
}

void clrScreen()
{
    cout << "\033[2J\033[1;1H";		// ASCII escape codes to clear screen
}

void clrBuffer()
{
    cin.ignore();
    cin.clear();
}
