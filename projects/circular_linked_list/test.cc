#include <iostream>
#include <sstream>
#include <string>

#include "CircularLinkedList.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

float test_compilation();
float test_constructor();
float test_push();
float test_peek();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        float total = 0;
        cout << "-------------" << endl;
        cout << "- FULL TEST -" << endl;
        cout << "-------------" << endl;
        total += test_compilation();
        cout << "#####################################" << endl;
        total += test_constructor();
        cout << "#####################################" << endl;
        total += test_push();
        cout << "#####################################" << endl;
        total += test_peek();
        cout << "#####################################" << endl;
        cout << "TOTAL SCORE: " << total << '!' << endl;
        cout << "#####################################" << endl;

        return 0;
    }

    string command = static_cast<string>(argv[1]);
    if (command == "compilation") {
        test_compilation();
    } else if (command == "constructor") {
        test_constructor();
    } else if (command == "push") {
        test_push();
    } else if (command == "peek") {
        test_peek();
    } else {
        cerr << "Usage " << argv[0] << " <test_name>" << endl;
        cerr << "Supported tests:" << endl;
        cerr << " - compilation" << endl;
        cerr << " - constructor" << endl;
        cerr << " - push" << endl;
        cerr << " - peek" << endl;
        return 1;
    }

    return 0;
}

float test_compilation() {
    cout << "TEST: Compilation" << endl;
    cout << "STATUS: SUCCESS!" << endl;
    cout << "TOTAL: 10/10!" << endl;
    return 10;
}

float test_constructor() {
    cout << "TEST: Constructor" << endl;
    cout << "--------------------------" << endl;
    CircularLinkedList c_list;
    c_list.push(1, ClockWise);
    cout << "Expected: {1}" << endl;
    cout << "Got:      " << c_list << endl;
    cout << "--------------------------" << endl;

    std::stringstream ss;
    ss << c_list;
    bool success = (ss.str() == "{1}");

    float points = success ? 11.25 : 0;
    cout << "STATUS: " << (success ? "SUCCESS!" : "FAILURE!") << endl;
    cout << "TOTAL: " << points << "/11.25!" << endl;

    return points;
}

float test_push() {
    cout << "TEST: Push" << endl;
    cout << "--------------------------" << endl;
    CircularLinkedList c_list;
    c_list.push(1, ClockWise);
    c_list.push(2, ClockWise);
    c_list.push(-1, ClockWise);
    cout << "Expected: {1, -1, 2}" << endl;
    cout << "Got:      " << c_list << endl;
    cout << "--------------------------" << endl;

    std::stringstream ss;
    ss << c_list;
    bool success = (ss.str() == "{1, -1, 2}");

    float points = success ? 11.25 : 0;
    cout << "STATUS: " << (success ? "SUCCESS!" : "FAILURE!") << endl;
    cout << "TOTAL: " << points << "/11.25!" << endl;

    return points;
}

float test_peek() {
    cout << "TEST: Peek" << endl;
    cout << "--------------------------" << endl;
    CircularLinkedList c_list;
    c_list.push(1, ClockWise);
    c_list.push(2, ClockWise);
    c_list.push(-1, ClockWise);
    cout << "Expected: 1" << endl;
    cout << "Got:      " << c_list.peek() << endl;
    cout << "--------------------------" << endl;

    bool success = c_list.peek() == 1;

    float points = success ? 11.25 : 0;
    cout << "STATUS: " << (success ? "SUCCESS!" : "FAILURE!") << endl;
    cout << "TOTAL: " << points << "/11.25!" << endl;

    return points;
}
