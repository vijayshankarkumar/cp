#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
    bool operator<(const Node& other) const {
        return val < other.val;
    }
};

void change(Node* root) {
    root->val = 1;
}

std::pair<int, int> lower_bound_upper_bound(const std::vector<int>& arr, int x) {
    int l = -1, r = arr.size();
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (x < arr[m]) {
            r = m;
        }
        else {
            l = m;
        }
    }
    return std::make_pair(l, r);
}

int meetings(const std::vector<int>& firstDay, const std::vector<int>& lastDay) {
    int n = firstDay.size();
    std::vector<std::pair<int, int> > meetings(n);

    for (int i = 0; i < n; ++i) {
        meetings[i] = {lastDay[i], firstDay[i]};
    }

    std::sort(meetings.begin(), meetings.end());

    int meetingsCount = 0;
    int lastMeetingDay = 0;

    for (int i = 0; i < n; ++i) {
        if (meetings[i].second > lastMeetingDay) {
            meetingsCount++;
            lastMeetingDay = meetings[i].first;
        }
    }

    return meetingsCount;
}

int main() {
    // std::vector<Node> v = {Node(4), Node(3), Node(5), Node(2), Node(1), Node(6)};
    // std::sort(v.begin(), v.end());
    // for (auto& it : v) {
    //     std::cout << it.val << ", ";
    // }
    // std::cout << std::endl;
    // std::priority_queue<Node> q(v.begin(), v.end());
    // while (!q.empty()) {
    //     std::cout << q.top().val << ", ";
    //     q.pop();
    // }
    // std::cout << std::endl;

    // Node* node = new Node(0);
    // std::cout << "node->val: " << node->val << std::endl;
    // change(node);
    // std::cout << "node->val: " <<  node->val << std::endl;

    // std::vector<int> f = {1, 1, 2};
    // std::vector<int> l = {1, 2, 2};
    // std::cout << "ans: " << meetings(f, l) << std::endl;

    std::cout << RAND_MAX << std::endl;
}
