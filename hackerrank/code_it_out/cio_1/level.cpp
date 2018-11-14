#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstdbool>
#include <algorithm>
using namespace std;

void print_i_v(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

struct node{
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;

NODE new_node(int data){
    NODE temp = new(struct node);
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

NODE find_node(NODE root, int r_data){
    queue<NODE> q;
    q.push(root);
    while(!q.empty()){
        NODE curr = q.front();
        q.pop();
        if(curr->data == r_data){
            return curr;
        }else{
            //add both children if present
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
    return NULL;
}

NODE insert_rec(NODE root, int r_data, int f_data){ //root data, friend data
    if(root == NULL){
        root = new_node(r_data);
        root->left = new_node(f_data);
    }else{
        //find root with r_data
        NODE temp = find_node(root, r_data);
        // cout<<"found: "<<temp->data<< endl;  ////
        if(temp->left == NULL){
            temp->left = new_node(f_data);
        }else{
            temp->right = new_node(f_data);
        }
    }
    return root;
}

void display_in_order(NODE root){
    if(root == NULL){
        return;
    }else{
        display_in_order(root->left);
        cout<< root->data<< ' ';
        display_in_order(root->right);
    }
}

void traverse_down(NODE root, int level, bool& found){
    if(root == NULL) return;
    if(level == 0){
        found = true;
        cout<< root->data << " ";
    }else{
        traverse_down(root->left, level-1, found);
        traverse_down(root->right, level-1, found);
    }
}


void solve_up(NODE root, int source, vector<int> curr_path, vector<int>& path){
    if(root== NULL){
        return;
    }
    curr_path.push_back(root->data);
    if(root->data == source){
        path = curr_path;
        return;
    }else{
        solve_up(root->left, source, curr_path, path);
        solve_up(root->right, source, curr_path, path);
    }
    
}



int main(){
    int n; cin >> n;
    int a, b;
    NODE root = NULL;
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        root = insert_rec(root, a, b);
    }
    cin >> a >> b; //-1 -1
    cin >> a >> b;
    int source = a;
    int level = b;
    bool found_up = false, found_down = false;

    

    vector<int> curr_path;
    vector<int> path;
    solve_up(root, source, curr_path, path);
    reverse(path.begin(), path.end());
    
    if(path.size() > level){
        found_up = true;
        cout<< path[level] <<" ";
    }

    
    //traverse down
    NODE source_root = find_node(root, source);
    traverse_down(source_root, level, found_down);


    if(!found_up && !found_down){
        cout << "0";
    }


    // print_i_v(path);
    // display_in_order(root);
    return 0;
}