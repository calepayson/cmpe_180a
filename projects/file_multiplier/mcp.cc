#include <string.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

void print_usage(char s[]);
bool create_new_file(const string &file_name);

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
            source_file = argv[++i];
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
            target_files.push_back(argv[++i]);
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

    ifstream source(source_file);
    if (!source.is_open()) {
        cerr << "Failed to open " << source_file << '!' << endl;
        return 1;
    }

    for (auto it = target_files.begin(); it != target_files.end(); ++it) {
        if (!create_new_file(*it)) {
            return 1;
        }
        ofstream temp(*it);
        if (!temp.is_open()) {
            cerr << "Failed to open " << *it << '!' << endl;
            return 1;
        }

        source.clear();
        source.seekg(0, std::ios::beg);
        string line;

        while (std::getline(source, line)) {
            temp << line << endl;
        }

        temp.close();
    }

    source.close();
    return 0;
}

void print_usage(char s[]) {
    cerr << "Usage:" << endl;
    cerr << s << " -s <source file> -t <target file>" << endl;
    cerr << "Note: You may provide multiple target files but you must use a "
            "target flag for each"
         << endl;
}

bool create_new_file(const string &file_name) {
    std::ifstream check_file(file_name);
    if (check_file.good()) {
        cerr << "Target file " << file_name << " already exists" << endl;
        check_file.close();
        return false;
    }
    check_file.close();

    std::ofstream new_file(file_name);
    if (!new_file.good()) {
        cerr << "Failed to create " << file_name << endl;
        return false;
    }

    new_file.close();
    return true;
}
