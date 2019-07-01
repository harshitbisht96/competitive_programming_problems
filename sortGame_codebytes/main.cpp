#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *left,*right;
    Node(){
        left=NULL;right=NULL;
    }
};

void printSpiral(Node *root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);
    bool flag=true;
    stack<int> s;
    while(!q.empty()){

        Node* current = q.front();
        q.pop();

        if(current==NULL){
            q.push(NULL);
            if(!flag){
                while(!s.empty()){
                    cout << s.top()<<" ";s.pop();
                }
            }
            flag=!flag;
            if(q.front()==NULL){
                break;
            }

            continue;
        }

        if(flag)
            cout << current->data<<" ";
        else
            s.push(current->data);

        if(current->left != NULL)q.push(current->left);

        if(current->right != NULL)q.push(current->right);


    }

}

void createTree(Node* root){
    cin >> root->data;
    string flag;
    cin >> flag;
    if(flag=="true"){
        root->left = new Node();
        createTree(root->left);
    }
    cin >> flag;
    if(flag=="true"){
        root->right = new Node();
        createTree(root->right);
    }

}



int main() {
    Node *root = new Node();
    createTree(root);
    printSpiral(root);
}
