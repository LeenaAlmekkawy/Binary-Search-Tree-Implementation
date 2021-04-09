struct BstNode
{
    int data;
    BstNode* left;
    BstNode* right;
};
 
BstNode* GetNewNode(int data);
 
BstNode*  Insert(BstNode* root, int data);
 
bool Search(BstNode* root, int data);
 
int FindMin(BstNode* root);
 
int FindMax(BstNode* root);
 
int FindHeight(BstNode* root);
 
void LevelOrder(BstNode *root);
 
void PreOrder(BstNode *root);
 
void InOrder(BstNode *root);
 
void PostOrder(BstNode *root);
 
bool IsBstUtil(BstNode *root, int minvalue, int maxvalue);
 
bool IsBinarySearchTree(BstNode *root);
 
BstNode*  Delete(BstNode* root, int data);
 
struct Node* Delete(struct Node *root, int data);
 
BstNode* FindMin2(BstNode* root);