#include <iostream>  // cin, cout, endl
#include <vector>    // vector

int main() {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::vector;

    vector<int> nums;

    cout << "Enter a list of positive numbers.\n"
         << "Place a negative number at the end." << endl;

    int num;
    cin >> num;
    while (num >= 0) {
        nums.push_back(num);
        cout << num << " added. nums.size() = " << nums.size() << endl;
        cin >> num;
    }

    cout << "You entered:" << endl;
    int size = static_cast<int>(nums.size());
    for (int i = 0; i < size; i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;

    return 0;
}
