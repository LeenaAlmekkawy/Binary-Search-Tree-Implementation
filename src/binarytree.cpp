#include"../include/binarytree.h"
BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
   return newNode;
}
 
BstNode*  Insert (BstNode* root, int data)
{
    if(root == NULL)
    {
        //empty tree
        root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
 
bool Search(BstNode* root, int data)
{
    if(root == NULL)
        return false;
    else if(root->data == data)
          return true;
          // if data to be inserted is lesser, insert in left subtree
    else if(data <= root->data)
          return Search(root->left, data);
          // else, insert in right subtree
    else
          return Search(root->right, data);
 
}
 
int FindMin (BstNode* root)
{   if(root == NULL)
     {
          cout<<"Error: Tree is empty "<<endl;
          return -1;
     }
    BstNode* current = root;
    while(current ->left != NULL)
    {
        current = current->left;
    }
    return current->data;
}
 
int FindMax (BstNode* root)
{   if(root == NULL)
     {
          cout<<"Error: Tree is empty "<<endl;
          return -1;
     }
    BstNode* current = root;
    while(current ->right != NULL)
    {
        current = current->right;
    }
    return current->data;
}
 
int FindHeight (BstNode* root)
{
    if(root == NULL)
        return -1;
    return max(FindHeight(root->left), FindHeight(root->right)) +1;
}
 
void LevelOrder(BstNode *root)
{  //Time-Complexity = O(n)
   if(root == NULL)
        return;
   queue<BstNode*> Q;
   Q.push(root);
   while(!Q.empty())
   {
       BstNode* current = Q.front();
       cout<<current->data<<" ";
       if(current->left !=NULL)
          Q.push(current->left);
        if(current->right !=NULL)
          Q.push(current->right);
          Q.pop();  //removing the element at front
 
   }
}
 
void PreOrder(BstNode *root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
 
void InOrder(BstNode *root)
{
    if(root == NULL)
        return;
 
    PreOrder(root->left);
    cout<<root->data<<" ";
    PreOrder(root->right);
}
 
void PostOrder(BstNode *root)
{
    if(root == NULL)
        return;
 
    PreOrder(root->left);
    PreOrder(root->right);
    cout<<root->data<<" ";
}
 
bool IsBstUtil(BstNode *root, int minvalue , int maxvalue)
{
    //return true if BST, false otherwise
    if(root == NULL)
        return true;
    if(root->data > minvalue && root->data < maxvalue && IsBstUtil(root->left, minvalue , root->data) && IsBstUtil(root->right, root->data, maxvalue) )
         return true;
    else
        return false;
}
 
bool IsBinarySearchTree(BstNode *root)
{
    return IsBstUtil(root, INT_MIN, INT_MAX);
}
 
struct BstNode* Delete(struct BstNode *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL) {
			struct BstNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct BstNode *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct BstNode *temp = FindMin2(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}
 
BstNode* FindMin2(BstNode* root)
{
    while(root->left != NULL) root = root->left;
	return root;
}