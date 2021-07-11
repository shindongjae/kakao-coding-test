//nodeinfo에 몇번째인지를 확인하여 value를 저장한후
//y값을 기준으로 compare함수를 이용하여 정렬한다 만약에 y값이 같은경우 x값을 기준으로 정렬하여 이진트리 노드순서대로 정렬한다.
//y값을 이용하여 root로부터 몇번떨어져있는지 계산하여 저장한다.(만약에 앞에꺼와 y값이 다르다면 +1한값을 높이로 저장한다.)
//nodelist를 만들어서 value값을 저장한뒤, level-1만큼 x값에 따라서 아래로 이동한뒤에 마지막에 x값에 따라 노드를 저장
//tree를 만든후에 전위순회, 후위순회 수행하여 그값을 vector에 저장.


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> pre;
vector<int> post;

class Node {
public:
    int x;
    int value;
    Node* lchi, * rchi;
    Node() { x = 0;value = 0;lchi = nullptr; rchi = nullptr; }
};

bool compare(vector<int> node1, vector<int> node2) {
    if (node1[1] > node2[1])
        return true;
    else if (node1[1] == node2[1])
        if (node1[0] < node2[0])
            return true;
    return false;
}

void preorder(Node* node) {
    pre.push_back(node->value);

    if (node->lchi!=nullptr) {
        preorder(node->lchi);
    }
    if (node->rchi!=nullptr) {
        preorder(node->rchi);
    }
}

void postorder(Node* node) {
    if (node->lchi!=nullptr) {
        postorder(node->lchi);
    }
    if (node->rchi!=nullptr) {
        postorder(node->rchi);
    }

    post.push_back(node->value);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    //y값이 클수록 부모노드이고, 순서가 값이 된다. 같은레벨 같은 y값
    vector<vector<int>> answer;

    for (int i = 0;i < nodeinfo.size();i++)
        nodeinfo[i].push_back(i + 1);

    stable_sort(nodeinfo.begin(), nodeinfo.end(), compare);

    int current = 0;
    nodeinfo[0].push_back(current);
    for (int i = 1;i < nodeinfo.size();i++)
    {
        if (nodeinfo[i - 1][1] == nodeinfo[i][1])
            nodeinfo[i].push_back(current);
        else {
            current++;
            nodeinfo[i].push_back(current);
        }
    }

    //nodeinfo의 x,y,value,root와의 거리
    Node* root = new Node();
    root->value = nodeinfo[0][2];//root
    root->x = nodeinfo[0][0];
    vector<Node*> nodelist(10010);
    for (int i = 0;i < nodelist.size();i++)
        nodelist[i] = new Node();

    
    
    for (int i = 1;i < nodeinfo.size();i++)
    {
        nodelist[i]->value = nodeinfo[i][2];
        nodelist[i]->x = nodeinfo[i][0];
        Node* tmp = root;
        for (int j = 0;j < nodeinfo[i][3] - 1;j++) {
            if (tmp->lchi == nullptr)
                tmp = tmp->rchi;
            else if (tmp->rchi == nullptr)
                tmp = tmp->lchi;
            else {
                if (nodeinfo[i][0] < tmp->x)
                    tmp = tmp->lchi;
                else
                    tmp = tmp->rchi;
            }
        }
        if (nodeinfo[i][0] < tmp->x)
            tmp->lchi = nodelist[i];
        else
            tmp->rchi = nodelist[i];
        
        
    }
    preorder(root);
    postorder(root);
    
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
