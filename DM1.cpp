#include <iostream>
#include <vector>
using namespace std;

// Function for Delta Demodulation
vector<int> deltaDemodulation(vector<int>& modulatedSignal, int stepSize) {
    vector<int> demodulated;
    int previousValue = 0;  // Start with an initial value (can be set to 0)

    for (int i = 0; i < modulatedSignal.size(); i++) {
        if (modulatedSignal[i] == 1) {
            previousValue += stepSize;  // Move up by step size
        } else {
            previousValue -= stepSize;  // Move down by step size
        }
        demodulated.push_back(previousValue);
    }

    return demodulated;
}

int main() {
    vector<int> modulatedSignal = {0, 1, 1, 1, 1, 1, 0, 0, 0};  // Example modulated signal
    int stepSize = 1;  // Define the step size for the demodulation

    // Perform Delta Demodulation
    vector<int> demodulatedSignal = deltaDemodulation(modulatedSignal, stepSize);

    // Output the demodulated signal
    cout << "Demodulated signal: ";
    for (int i = 0; i < demodulatedSignal.size(); i++) {
        cout << demodulatedSignal[i] << " ";
    }
    cout << endl;

    return 0;
}
