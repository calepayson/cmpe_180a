#include <iostream>
#include <vector>

int main() {
    using std::cout;
    using std::endl;
    using std::vector;

    // One way of defining a vector.
    // push_back() pushes a value to the back of the vector.
    // vector<double> sample;
    // sample.push_back(0.0);
    // sample.push_back(1.1);
    // sample.push_back(2.2);

    // A more efficient way of defining a vector (if it's small)
    vector<double> sample = {0.0, 1.1, 2.2};

    // Use size() to return the size of the vector
    cout << "sample.size() = " << sample.size() << endl;

    // size() is super useful when looping through a vector
    int size = static_cast<int>(sample.size());  // Cast as an int to match type
    for (int i = 0; i < size; i++) {
        cout << sample[i] << endl;
    }

    return 0;
}
