//  Program 3
//  Node.cpp
//  Binary Search Tree
//
//  Created by Brandon Reid on 8/1/16.
//

#include "Node.h"

/*
 ============================================================================
 Function    : cmds()
 Parameters  : nothing
 Return      : nothing
 Description : prints commands for user
 ============================================================================
 */

void cmds()
{
    cout << endl;
    cout << "+---\033[1;31mCommands\033[0m---+\n"
         << "| \033[1;31mAdd\033[0m          |\n"
         << "| \033[1;31mRemove\033[0m       |\n"
         << "| \033[1;31mSearch\033[0m       |\n"
         << "| \033[1;31mPrint\033[0m        |\n"
         << "| \033[1;31mReverse\033[0m      |\n"
         << "| \033[1;31mHeight\033[0m       |\n"
         << "| \033[1;31mCommands\033[0m     |\n"
         << "| \033[1;31mClear\033[0m        |\n"
         << "| \033[1;31mQuit\033[0m         |\n"
         << "+--------------+\n";
}

/*
 ============================================================================
 Function    : cmd()
 Parameters  : nothing
 Return      : cmd (string)
 Description : command line to take in user input
 ============================================================================
 */

string cmd()
{
    string cmd;             // delcare string for user cmd
    
    cout << endl;			// endline before printing new cmd line
    cout << "cmd> ";		// output cmd line
    getline(cin, cmd);		// get user input
    
    return cmd;             // return string input by user
}

/*
 ============================================================================
 Function    : cnvrt()
 Parameters  : string incmd
 Return      : enum value
 Description : converts user input to an enum value for switch statement
 ============================================================================
 */

cmdCode cnvrt(string const& incmd)
{
    if (incmd == "add") return addnode;             // to enum value 0
    if (incmd == "remove") return removenode;		// to enum value 1
    if (incmd == "search") return search;           // to enum value 2
    if (incmd == "print") return print;             // to enum value 3
    if (incmd == "reverse") return reverse;         // to enum value 4
    if (incmd == "height") return height;           // to enum value 5
    if (incmd == "commands") return commands;       // to enum value 6
    if (incmd == "quit") return exitprog;           // to enum value 7
    if (incmd == "clear") return clear;             // to enum value 8
    else return invalid;                            // default
}

/*
 ============================================================================
 Function    : clrScreen()
 Parameters  : nothing
 Return      : nothing
 Description : works same as clear in linux terminal
 ============================================================================
 */

void clrScreen()
{
    cout << "\033[2J\033[1;1H";		// ASCII escape codes to clear screen
}

/*
 ============================================================================
 Function    : clrBuffer()
 Parameters  : nothing
 Return      : nothing
 Description : clear cin buffer
 ============================================================================
 */

void clrBuffer()
{
    cin.ignore();
    cin.clear();
}

/*
 ============================================================================
 Function    : intro()
 Parameters  : nothing
 Return      : nothing
 Description : intro for the user
 ============================================================================
 */

void intro()
{
    cout << endl << "\033[0;32mWelcome! Please refer to the README for more information.\033[0m" << endl;
    cout << "\033[0;32mType one of the desired commands to get started.\033[0m" << endl;
}