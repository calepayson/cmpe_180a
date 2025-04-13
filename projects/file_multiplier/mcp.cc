#include <string.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void print_usage(char s[]);

int main(int argc, char *argv[]) {
    string source_file;
    vector<string> target_files;
    bool source_provided = false;
    bool target_provided = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
            // Error handling
            if (i + 1 == argc) {
                print_usage(argv[0]);
                return 1;
            } else if (strcmp(argv[i + 1], "-t") == 0) {
                print_usage(argv[0]);
                return 1;
            }

            // Logic
            source_file = argv[i++ + 1];
            source_provided = true;
        } else if (strcmp(argv[i], "-t") == 0) {
            // Error handling
            if (i + 1 == argc) {
                print_usage(argv[0]);
                return 1;
            } else if (strcmp(argv[i + 1], "-s") == 0) {
                print_usage(argv[0]);
                return 1;
            }

            // Logic
            target_files.push_back(argv[i++ + 1]);
            target_provided = true;
        }
    }

    if (!source_provided) {
        cerr << "No source file provided!" << endl;
        print_usage(argv[0]);
        return 1;
    }
    if (!target_provided) {
        cerr << "No target file provided!" << endl;
        print_usage(argv[0]);
        return 1;
    }

    cout << "Source file: " << source_file << endl;
    cout << "Target files: " << endl;
    for (auto it = target_files.begin(); it != target_files.end(); it++) {
        cout << *it << ", ";
    }
    cout << endl;

    return 0;
}

void print_usage(char s[]) {
    cerr << "Usage:" << endl;
    cerr << s << " -s <source file> -t <target file>" << endl;
    cerr << "Note: You may provide multiple target files but you must use a "
            "target flag for each"
         << endl;
}
