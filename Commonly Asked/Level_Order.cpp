
// function to find the level order traversal given a binary tree
// O(n) time complexity O(width) auxiliary space


/* A binary tree Node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


void util(vector<int> &res, queue<Node*> &q)
{
    while(!q.empty())
    {
        Node* curr=q.front();
        if(curr->left)  q.push(curr->left);
        if(curr->right) q.push(curr->right);
        res.push_back(curr->data);
        q.pop();
    }
}


vector<int> levelOrder(Node* node)
{
  vector<int> res;
  if(!node) return res;
  queue<Node*> q;
  q.push(node);
  util(res, q);
  return res;
}
