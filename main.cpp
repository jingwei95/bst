#include <iostream>

using namespace std;
struct node{
    long long int key;
    node *left=NULL;
    node *right=NULL;
};

struct node *in(struct node *node1,long long int value){
    if(node1==NULL){
        node *newone = new node();
        newone->key=value;
        newone->left=newone->right=NULL;
        return newone;
    }else if(value<node1->key){
       node1->left=in(node1->left,value);
    }else if(value>node1->key){
            node1->right=in(node1->right,value);
    }
    return node1;
}
void fin(long long int needed,struct node *node2){
    if(node2->key==needed){
        return ;
    }
        if(needed<node2->key){
            cout<<"L";
            fin(needed,node2->left);
        }else if(needed>node2->key){
            cout<<"R";
            fin(needed,node2->right);
        }

}

int main()
{

    while(1){
        long long int numtest=0;
        long long int bst=0;
        cin>>numtest;
        if(numtest == 0){
            break;
        }
        cin>>bst;

        struct node *root=NULL;
        for(long long int i=0;i<numtest;i++){
            long long int current;
            cin>>current;
            if(i==0){
                root=in(root,current);
            }else{
            in(root,current);
            }
        }
        fin(bst,root);
        cout<<endl;

    }
    return 0;
}
