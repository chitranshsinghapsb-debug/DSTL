#include <iostream>
#include <vector>
#include <utility>

class MaxPriorityQueue {
private:
    std::vector<int> tree;

    // Sift down an element to restore max-heap property
    void siftDown(int idx) {
        int size = tree.size();
        while (true) {
            int largest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < size && tree[left] > tree[largest]) {
                largest = left;
            }
            if (right < size && tree[right] > tree[largest]) {
                largest = right;
            }

            if (largest == idx) break;

            std::swap(tree[idx], tree[largest]);
            idx = largest;
        }
    }

    // Sift up an element to restore max-heap property
    void siftUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (tree[parent] >= tree[idx]) {
                break;
            }
            std::swap(tree[parent], tree[idx]);
            idx = parent;
        }
    }

public:
    // Option 1: Insert value and restore heap property
    void insert(int value) {
        tree.push_back(value);
        siftUp(tree.size() - 1);
    }

    // Option 6: Append value at the end without heapifying
    void addWithoutHeapify(int value) {
        tree.push_back(value);
    }

    // Option 2: Build max heap from current array in O(n)
    void buildHeap() {
        for (int i = (static_cast<int>(tree.size()) / 2) - 1; i >= 0; --i) {
            siftDown(i);
        }
    }

    // Option 4: Extract and remove the maximum element
    void deleteHighestPriority() {
        if (tree.empty()) {
            std::cout << "Priority Queue is empty\n";
            return;
        }

        std::cout << "Deleted: " << tree.front() << "\n";
        tree[0] = tree.back();
        tree.pop_back();

        if (!tree.empty()) {
            siftDown(0);
        }
    }

    // Option 3: Display current heap elements
    void display() const {
        if (tree.empty()) {
            std::cout << "(empty)\n";
            return;
        }
        for (int val : tree) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    MaxPriorityQueue pq;
    int choice = 0;
    int value = 0;

    do {
        std::cout << "\n--- Priority Queue Menu ---\n"
                  << "1. Insert\n"
                  << "2. Heapify (Build Heap)\n"
                  << "3. Display\n"
                  << "4. Delete Highest Priority\n"
                  << "5. Exit\n"
                  << "6. Add Without Heapify\n"
                  << "Enter choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Exiting.\n";
            break;
        }

        switch (choice) {
            case 1:
                std::cout << "Enter value: ";
                std::cin >> value;
                pq.insert(value);
                break;

            case 2:
                pq.buildHeap();
                std::cout << "Heapified successfully\n";
                break;

            case 3:
                pq.display();
                break;

            case 4:
                pq.deleteHighestPriority();
                break;

            case 5:
                std::cout << "Exiting...\n";
                break;

            case 6:
                std::cout << "Enter value: ";
                std::cin >> value;
                pq.addWithoutHeapify(value);
                break;

            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
