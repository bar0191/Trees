Binary Search Tree
Brandon Reid
8/2/2016

this program uses c++11 please use MAKEFILE to compile!

HOW TO RUN:

1. after unzipping file, cd to folder
2. once inside the folder use MAKEFILE
3. >make
4. >make run

** Reversal function is Bonus, run everything first before running that command **
If you add anything while the tree is reversed it could mess up the logic of the tree
I didn’t have the time to make functions to add and remove in reverse, it’s quite simple to implement..
But the bonus didn’t specify what to do after reversal?

Known Bugs:
- after reversal of the tree, the search function still goes left for the lowest value
— so i need to make another search function to only be used when the tree is reversed…
- UPDATE: Finished this

reflections:

- I found BST implementation with recursion was way easier for me to understand over the previous programs
- I really enjoy the implementation of Binary Search Trees, the code is simply and pretty.
- C++ has STL containers that use Red-Black Trees, which are similar to a BST, or 2-3-4 tree (map and set)
- I have recently used the STL container map to make an address book
