#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 3) {
        cout << "Error: Please provide number of rows and columns" << endl;
        return 1;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    srand(time(NULL));

    ofstream fp("random-20000-8000.txt");

    if (!fp.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Generating random values and writing to file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fp << rand() % 256 << " ";
        }
        fp << endl;
    }

    fp.close();

    cout << "File generated successfully!" << endl;

    return 0;
}
