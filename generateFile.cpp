#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char **argv)
{
    int rows, cols;

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);
    
    srand(time(NULL));
    
    ofstream fp("randomValues.txt");

    if (!fp.is_open()) {
        cout << "Error opening file" << endl;
        exit(-1);
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