#include <iostream>
#include <vector>

class heap {

private:
    std::vector<int> data;
    void minHeapify(int idx);
    
public:
    heap();
    heap(std::vector<int> _data);
    int peek();
    void pop();
    void insert(int val);
    ~heap();
};

heap::heap() {}

heap::heap(std::vector<int> _data): data(_data) {
    for (int i = data.size() / 2; i >= 0; i--) {
        minHeapify(i);
    }
    for (auto& it : data) std::cout << it << ", ";
    std::cout << std::endl;
}

int heap::peek() {
    return data.empty() ? 0 : data.front();
}

void heap::pop() {
    std::swap(data.front(), data.back());
    data.pop_back();
    minHeapify(0);
}

void heap::insert(int val) {
    data.push_back(val);
    std::swap(data.front(), data.back());
    minHeapify(0);
}

void heap::minHeapify(int idx) {
    int smallest = idx;
    if (2 * idx + 1 < data.size() && data[2 * idx + 1] < data[idx]) {
        smallest = 2 * idx + 1;
    }
    if (2 * idx + 2 < data.size() && data[2 * idx + 2] < data[smallest]) {
        smallest = 2 * idx + 2;
    }

    if (smallest != idx) {
        std::swap(data[smallest], data[idx]);
        minHeapify(smallest);
    }
}

heap::~heap() { }


int main() {
    std::vector<int> arr = {6, 5, 4, 3, 2, 1};
    heap hp(arr);
    std::cout << hp.peek() << std::endl;
    hp.pop();
    std::cout << hp.peek() << std::endl;
    hp.pop();
    std::cout << hp.peek() << std::endl;
    hp.insert(1);
    std::cout << hp.peek() << std::endl;
    return 0;
}
