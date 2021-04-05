#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node{
    int num;
    int x;
    node *left;
    node *right;

    node(int newNum, int newX){
        num = newNum;
        x = newX;
        left = NULL;
        right = NULL;
    }
};

void insert(node *cur, int newNum, int newX){
    node *newNode = new node(newNum, newX);
    
    while(cur){
        if(cur->x > newX){
            if(cur->left){
                cur = cur->left;   
            }else{
                cur->left = newNode;
                break;
            }
        }else{
            if(cur->right){
                cur = cur->right;   
            }else{
                cur->right = newNode;
                break;
            }
        }
    }
}

void preorder(node *cur, vector<int> &v){
    if(cur){
        v.push_back(cur->num);
        preorder(cur->left, v);
        preorder(cur->right, v);
    }
}

void postorder(node *cur, vector<int> &v){
    if(cur){
        postorder(cur->left, v);
        postorder(cur->right, v);
        v.push_back(cur->num);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<int, int>> info[100001];
    vector<int> pre;
    vector<int> post;
    int len = nodeinfo.size();
    int level = -1;
    node *root;

    for(int i=0;i<len;++i){
        info[nodeinfo[i][1]].push_back({i+1, nodeinfo[i][0]});
        level = max(level, nodeinfo[i][1]);
    }

    root = new node(info[level][0].first, info[level][0].second);
    for(int i=level-1;i>=0;--i){
        for(pair<int, int> p : info[i]){
            insert(root, p.first, p.second);
        }
    }
    
    preorder(root, pre);
    postorder(root, post);
    
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}
