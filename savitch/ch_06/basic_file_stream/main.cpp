#include <fstream>
#include <string>

int main() {
    using namespace std;

    string first_name, last_name;
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("name.txt");
    in_stream >> first_name >> last_name;

    out_stream.open("secret_message.txt");
    out_stream << first_name << ' ' << last_name << " is a pretty cool guy.\n";

    in_stream.close();
    out_stream.close();

    return 0;
}
