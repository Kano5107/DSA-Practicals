#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> queue;

    // 1. Add critical patient at front
    queue.insert(queue.begin(), 101);

    // Print queue
    for (int x : queue)
        cout << x << " ";
    cout << endl;

    // 2. Add routine patient at end
    queue.push_back(102);

    for (int x : queue)
        cout << x << " ";
    cout << endl;

    // 3. Insert patient at a specific position
    int patient = 103;
    int position = 1;

    if (position <= queue.size()) {
        queue.insert(queue.begin() + position, patient);
    } else {
        cout << "Invalid position!" << endl;
    }

    for (int x : queue)
        cout << x << " ";
    cout << endl;

    return 0;
}