//Binary Search Tree - Implementation in C++
#include <bits/stdc++.h>
using namespace std;
#include "binarytree.cpp"
 int main()
{
    BstNode* root = NULL; //Creating an empty tree
   root = Insert(root , 15);
   root = Insert(root , 10);
   root = Insert(root , 20);
   root = Insert(root , 25);
   root = Insert(root , 8);
   root = Insert(root , 12);
   int number;
   cout<<"Enter number be searched "<<endl;
   cin>>number;
   if(Search(root, number) == true)
      cout<<"Found"<<endl;
   else
      cout<<"Not Found"<<endl;
 
      cout<<"Max element is "<<FindMax(root)<<endl;
      cout<<"Min element is "<<FindMin(root)<<endl;
      cout<<"Max height is "<<FindHeight(root)<<endl;
      //height of tree is the number of edges in the longest path from root to leaf node
     cout<<"Level Order : "<<endl;
      LevelOrder(root);
      cout<<endl;
     cout<<"Pre Order : "<<endl;
      PreOrder(root);
      cout<<endl;
      cout<<"In Order : "<<endl;
      InOrder(root);
      cout<<endl;
      cout<<"Post Order : "<<endl;
      PostOrder(root);
      cout<<endl;
      if(IsBinarySearchTree(root))
        cout<<"YES"<<endl;
      else
         cout<<"NO"<<endl;
 
         root = Delete(root,15);
         root = Delete(root,10);
         cout<<"In Order : "<<endl;
         InOrder(root);
 
 
    return 0;
 
}