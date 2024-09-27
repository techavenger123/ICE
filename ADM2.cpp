#include <iostream>
#include <vector>
using namespace std;

vector<int> adaptiveDeltaDemodulation(vector<int>& modulatedSignal, int initialStepSize, int stepAdjustmentFactor) {
    vector<int> demodulated;
    int previousValue = 0;
    int stepSize = initialStepSize;

    for (int i = 0; i < modulatedSignal.size(); i++) {
        if (modulatedSignal[i] == 1) {
            previousValue += stepSize;
        } else {
            previousValue -= stepSize;
        }
        demodulated.push_back(previousValue);
        stepSize += stepAdjustmentFactor;


        if (i > 0 && modulatedSignal[i] != modulatedSignal[i-1]) {
            stepSize = max(initialStepSize, stepSize - stepAdjustmentFactor);
        }
    }

    return demodulated;
}
int main() {
    vector<int> modulatedSignal = {0, 1, 1, 1, 1, 1, 0, 0, 0};
    int initialStepSize = 1;
    int stepAdjustmentFactor = 1;
    vector<int> demodulatedSignal = adaptiveDeltaDemodulation(modulatedSignal, initialStepSize, stepAdjustmentFactor);
    cout << "Adaptive Demodulated signal: ";
    for (int i = 0; i < demodulatedSignal.size(); i++) {
        cout << demodulatedSignal[i] << " ";
    }
    cout << endl;

    return 0;
}
