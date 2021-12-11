#include <bits/stdc++.h>
using namespace std;
#define NODE_AMOUNT 100

int leader[NODE_AMOUNT];
int size[NODE_AMOUNT];

void initialize() {
    for (int i = 0; i < NODE_AMOUNT; i++) {
        leader[i] = i;
        size[i] = 1;
    }
}

int set_find(int index) {
    if (index == leader[index]) {
        return index;
    }
    return leader[index] = set_find(leader[index]);
}

void set_union(int a, int b) {
    int a_leader = set_find(a);
    int b_leader = set_find(b);

    if(a_leader != b_leader) {
        size[a_leader] += size[b_leader];
        leader[a_leader] = b_leader;
    }
}

int main() {
    initialize();
    int n = 4;
    vector<string> queryType;
    queryType.push_back("friend");
    queryType.push_back("total");
    vector<int> student1{1, 2};
    vector<int> student2{2, 3};

    vector<int> return_vec;
    for (int i = 0; i < queryType.size(); i++) {
        if (queryType[i] == "friend") {
            set_union(student1[i], student2[i]);
        } else if (queryType[i] == "total") {
            int result = size[student1[i]] + size[student2[i]];
            return_vec.push_back(result);
            cout << result;
        }
    }
}