#include <iostream>
#include <vector>
using namespace std;

vector<int> deltaModulation(vector<int>& signal, int stepSize) {
    vector<int> modulated;
    int previousValue = 0;

    for (int i = 0; i < signal.size(); i++) {
        if (signal[i] > previousValue) {
            modulated.push_back(1);
            previousValue += stepSize;
        } else {
            modulated.push_back(0);
            previousValue -= stepSize;
        }
    }

    return modulated;
}

int main() {
    vector<int> signal = {0, 1, 3, 6, 8, 10, 7, 4, 1};
    int stepSize = 1;


    vector<int> modulatedSignal = deltaModulation(signal, stepSize);


    cout << "Modulated signal: ";
    for (int i = 0; i < modulatedSignal.size(); i++) {
        cout << modulatedSignal[i] << " ";
    }
    cout << endl;

    return 0;
}
