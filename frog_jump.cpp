#include <iostream>
#include <vector>

bool helper(std::vector<int>& stones, int index, int jump){
    if(index == stones.size()-1){
        return true;
    }
    
    for(int i= index+1; i< stones.size(); i++){
        int gap= stones[i]- stones[index];
        if(gap >= jump-1 && gap <= jump+1){
            if(helper(stones, i, gap))
                return true;
        }
    }
    
    return index == stones.size()-1;
}

bool frogJump(std::vector<int>& stones) {
    return helper(stones, 0, 0);
}

int main() {
    //std::vector<int> pos = {0,1,3,5,6,8,12,17};
    std::vector<int> pos = {0,1,2,3,4,8,9,11};
    std::cout << frogJump(pos) << std::endl;
    return 0;
}
