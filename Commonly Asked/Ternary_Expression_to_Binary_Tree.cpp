
// Convert Ternary Expression to Binary Tree problem
// more at https://practice.geeksforgeeks.org/problems/convert-ternary-expression-to-binary-tree/1


Node* util(string str, int& i)
{
    Node* root;
    root = new Node(str[i]);
    
    if(i==str.length()-1) return root;
    
    i++;
    
    if(str[i]=='?')
    {
        i++;
        root->left = util(str, i);
        
        i++;
        root->right = util(str, i);
        return root;
    }
    else return root;
    
}

Node *convertExpression(string str,int i)
{
    return util(str, i);
    
}
