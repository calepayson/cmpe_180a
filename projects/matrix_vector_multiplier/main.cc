#include <unistd.h>  // For getopt()

#include <cstdio>    // For fopen()
#include <fstream>   // For ifstream
#include <iostream>  // For cerr, cout, endl, string
#include <vector>

bool read_matrix(std::ifstream &matrix_file,
                 std::vector<std::vector<int>> &matrix);

bool read_vector(std::ifstream &vector_file, std::vector<int> &vector);

bool matrix_vector_multiplication(std::vector<std::vector<int>> &matrix,
                                  std::vector<int> &vector,
                                  std::vector<int> &result);

void print_usage(const std::string &program_name);

int main(int argc, char *argv[]) {
    using std::cerr;
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ifstream;
    using std::string;

    // To pass to the print_usage() function
    string program_name = argv[0];

    int opt;
    string matrix_file_name;
    string vector_file_name;
    while ((opt = getopt(argc, argv, "m:v:")) != -1) {
        switch (opt) {
            case 'm':
                matrix_file_name = string(optarg);
                break;
            case 'v':
                vector_file_name = string(optarg);
                break;
            case '?':
                return 1;  // getopt() handles missing and invalid options
            default:
                print_usage(program_name);
                return 1;
        }
    }

    if (matrix_file_name.empty()) {
        cerr << "Missing matrix file argument.\n";
        print_usage(program_name);
        return 1;
    }
    if (vector_file_name.empty()) {
        cerr << "Missing vector file argument.\n";
        print_usage(program_name);
        return 1;
    }

    ifstream matrix_file;
    matrix_file.open(matrix_file_name);
    if (!matrix_file.is_open()) {
        cerr << "Unable to open file: " << matrix_file_name << endl;
        return 1;
    }
    std::vector<std::vector<int>> matrix;
    if (!read_matrix(matrix_file, matrix)) {
        return 1;
    }
    matrix_file.close();

    ifstream vector_file;
    vector_file.open(vector_file_name);
    if (!vector_file.is_open()) {
        cerr << "Unable to open file: " << vector_file_name << endl;
        return 1;
    }
    std::vector<int> vector;
    if (!read_vector(vector_file, vector)) {
        return 1;
    }
    vector_file.close();

    std::vector<int> result;

    if (!matrix_vector_multiplication(matrix, vector, result)) {
        cerr << "Unable to multiply: " << matrix[0].size()
             << "!=" << vector.size() << endl;
        return 1;
    }

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}

bool read_matrix(std::ifstream &matrix_file,
                 std::vector<std::vector<int>> &matrix) {
    using std::cerr;

    int m;
    int n;
    matrix_file >> m >> n;

    if (m <= 0 || n <= 0) {
        cerr << "Please provide positive integers for the matrix dimensions.\n";
        return false;
    }

    for (int i = 0; i < m; i++) {
        std::vector<int> vector;
        for (int j = 0; j < n; j++) {
            int num;
            matrix_file >> num;
            vector.push_back(num);
        }
        matrix.push_back(vector);
    }

    return true;
}

bool read_vector(std::ifstream &vector_file, std::vector<int> &vector) {
    using std::cerr;

    int size;
    vector_file >> size;

    if (size <= 0) {
        cerr << "Please provide a positive integer for the vector size.\n";
        return false;
    }

    for (int i = 0; i < size; i++) {
        int num;
        vector_file >> num;
        vector.push_back(num);
    }

    return true;
}

bool matrix_vector_multiplication(std::vector<std::vector<int>> &matrix,
                                  std::vector<int> &vector,
                                  std::vector<int> &result) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int vector_size = vector.size();

    if (vector_size != cols) {
        return false;
    }

    result.assign(rows, 0);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    return true;
}

void print_usage(const std::string &program_name) {
    using std::cerr;
    using std::endl;

    cerr << "Usage: \n"
         << program_name << " -m <matrix_file_name> -v <vector_file_name>\n";
}
