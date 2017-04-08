//  Program 3
//  main.cpp
//  Binary Search Tree
//
//  Created by Brandon Reid on 8/1/16.
//
//

#include "BST.h"

int main()
{
    NodePtr root = nullptr;     // typedef value to communicate with Node* class
    BST tree;                   // BST class object
    string input;               // string input from user
    int uInt = 0;                   // unique int entered by user
    char reverseAns;            // answer entered by user
    string intInput;
    
    
    intro();                    // run intro for user
    
    cmds();                     // print commands
    
    do
    {
        input = cmd();          // set input equaled to cmd() line input
        
        // transform user input to lower case
        transform(input.begin(), input.end(), input.begin(), tolower);
        
        // menu (switch statement)
        switch (cnvrt(input))
        {
            // add element
            case addnode: 
                // prompt user for unqiue unt
                cout << "Enter unique integer value you would like to add to the BST: ";
                cin  >> intInput;
                cin.ignore();
                
                // used as a check for any value other then integer
                if (!cin)
                {
                    cout << "\033[0;31mERROR: Value entered is not a unique integer value...\033[0m " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                
                uInt = stoi(intInput);
                
                // if value already exists in the tree, no dups - else add new value
                if (tree.findElement(root,uInt) == true)
                {
                    cout << "\033[0;31mERROR: Value already exists in the BST... \033[0m" << endl;
                }
                else
                {
                    root = tree.addElement(root, uInt);
                    cout << "\033[0;32mAdded: " << uInt << "\033[0m" << endl;
                }
                break;
            
            // remove element
            case removenode:
                // check if empty
                if (root == nullptr)
                {
                    cout << "BST is currently empty... " << endl;
                    break;
                }
                else
                {
                    // prompt user for input
                    cout << "Enter unique integer value you would like to remove from the BST: ";
                    cin  >> uInt;
                    cin.ignore();
                
                    // check for wrong input
                    if (!cin)
                    {
                        cout << "\033[0;31mERROR: Value entered is not a unique integer value...\033[0m " << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                
                    // if value does not exist in the tree, output error
                    if (tree.findElement(root, uInt) == false)
                    {
                        cout << "\033[0;31mERROR: Value entered is not in the BST...\033[0m " << endl;
                        break;
                    }
                    else
                    {
                        root = tree.removeElement(root, uInt);
                        cout << "\033[0;32mRemoved: " << uInt << "\033[0m" << endl;
                    }
                }
                break;
                
            // search element
            case search:
                // check if empty
                
                cout << "Is tree reversed? (y/n): ";
                cin  >> reverseAns;
                cin.ignore();
                
                reverseAns = tolower(reverseAns);
            
                
                if (reverseAns == 'y')
                {
                    
                    if (root == nullptr)
                    {
                        cout << "BST is currently empty... " << endl;
                        break;
                    }
                    else
                    {
                        // prompt user for input
                        cout << "\033[0;31mWarning: Only use reverse search after tree has been reversed.\033[0m" << endl << endl;
                        cout << "Enter unique integer value to be searched in the BST: ";
                        cin  >> uInt;
                        cin.ignore();
                    
                        if (!cin)
                        {
                            cout << "\033[0;31mERROR: Value entered is not a unique integer value...\033[0m" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                    
                        // if search finds value output true, otherwise false
                        if (tree.findInReverse(root, uInt) == true)
                        {
                            cout << "\033[0;32mTrue: " << uInt << "\033[0m" << endl;
                        }
                        else
                        {
                            cout << "\033[0;31mFalse: " << uInt << "\033[0m" << endl;
                        }
                    }
    
                }
                else if (reverseAns == 'n')
                {
                    if (root == nullptr)
                    {
                        cout << "BST is currently empty... " << endl;
                        break;
                    }
                    else
                    {
                    
                        // prompt user for input
                        cout << "Enter unique integer value to be searched in the BST: ";
                        cin  >> uInt;
                        cin.ignore();
                
                        // check for wrong input
                        if (!cin)
                        {
                            cout << "\033[0;31mERROR: Value entered is not a unique integer value...\033[0m" << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                
                        // cout true or false
                        if (tree.findElement(root, uInt) == true)
                        {
                            cout << "\033[0;32mTrue: " << uInt << "\033[0m" << endl;
                        }
                        else
                        {
                            cout << "\033[0;31mFalse: " << uInt << "\033[0m" << endl;
                        }
                    }
                }
                else
                {
                    cout << "\033[0;31mERROR: Invalid input was entered... Please try again.\033[0m" << endl;
                }
                break;
              
            // print tree
            case print:
                // check if empty
                if (root == nullptr)
                {
                    cout << "BST is currently empty... " << endl;
                    break;
                }
                else
                {
                    /*
                    cout << "Pre-Order Traversal: ";
                    tree.printTreePreOrder(root);
                    cout  << endl;
                    */
        
                    tree.printTreeInOrder(root);
                    cout << endl;
                }
                break;
                
            // reverse tree
            case reverse:
                if (root == nullptr)
                {
                    cout << "BST is currently empty..." << endl;
                    break;
                }
                else
                {
                    // prints elements before reversal
                    cout << "Reversing elements: ";
                    tree.printTreeInOrder(root);
                    cout << endl;
                    
                    // run reversal and output success
                    tree.reverseTree(root);
                    cout << "\033[0;32mReversal successful\033[0m" << endl << endl;
                    
                    // print new elements after reversal
                    cout << "Elements Reversed: ";
                    tree.printTreeInOrder(root);
                    cout << endl;
                    
                    // output warning
                    cout << "\033[0;31mWarning: Do not add/remove values while tree is reversed!\033[0m" << endl;
                }
                break;
                
            // tree height
            case height:
                if (tree.displayHeight(root) == 0)
                {
                    cout << "BST is currently empty... " << endl;
                    break;
                }
                else
                {
                    cout << "\033[0;32mHeight: " << tree.displayHeight(root) << "\033[0m" << endl;
                }
                break;
                
            // user commands
            case commands:
                cmds();
                break;
               
            // exitting program
            case exitprog:
                cout << "\033[0;32mThank you for using my BST! Goodbye!\033[0m" << endl;
                break;
              
            // clear terminal
            case clear:
                clrScreen();
                break;
               
            // error/default
            default:
                cout << "\033[0;31mERROR: Invalid input entered... Please try again.\033[0m" << endl;
                cin.clear();
                break;
        }
    } while (cnvrt(input) != exitprog);
    
    return 0;
}

