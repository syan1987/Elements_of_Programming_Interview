#include <iostream>
using namespace std;

void hanoi(int from, int to, int via, int num) {
    if (num == 0) return;

    hanoi(from, via, to, num-1);
    cout << "Move " << from << " to " << to << endl;
    hanoi(via, to, from, num-1);
}

int main() {
    int num;
    while (cin >> num) {
        hanoi(1, 2, 3, num);
    }
    return 0;
}
