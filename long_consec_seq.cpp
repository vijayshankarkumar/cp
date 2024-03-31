#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutiveSeq(std::vector<int> arr) {
    if(arr.empty()) return 0;
    std::unordered_set<int> record(arr.begin(), arr.end());
    int res= 1;
    for(auto n: arr){
        if(!record.count(n)) continue;
        record.erase(n);
        int left= n-1, right= n+1;
        while(record.count(left)) record.erase(left--);
        while(record.count(right)) record.erase(right++);
        res= std::max(res, right-left-1);
    }
    return res;
}

int main() {
    return 0;
}