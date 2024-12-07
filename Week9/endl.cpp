#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream myfile("example.txt");

    if (!myfile) {
        cerr << "File could not be opened." << endl;
        return 1;
    }

    // Using '\n' - no automatic flushing
    myfile << "This is line 1 using \\n.\n";
    // Simulate a crash before flushing
    cout << "Program crashed after \\n" << endl;
    // No flush happens here, so the content might still be in the buffer

    // Comment the next line to simulate a crash
    // abort();

    // Using 'endl' - automatic flushing happens here
    myfile << "This is line 2 using endl." << endl;
    cout << "Program crashed after endl" << endl;
    // Flushing occurs automatically with endl, so the content is written immediately

    // Simulate a crash again
    abort(); // Uncomment this to simulate a crash

    myfile.close(); // Normally closes and flushes
    return 0;
}
