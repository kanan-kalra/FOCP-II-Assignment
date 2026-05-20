#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed random number generator
    srand(time(0));

    string name;
    cout << "Enter student name: ";
    cin >> name;

    // Creative but believable excuses with {name} placeholder
    vector<string> excuses = {
        "{name} was unable to complete the homework because of a sudden power outage at home.",
        "{name} could not attend class yesterday due to a medical check-up that could not be rescheduled.",
        "{name} missed the assignment deadline because their internet connection was down during submission time.",
        "{name} was absent as they had to accompany a family member to the hospital.",
        "{name} could not finish the project because their laptop stopped working unexpectedly.",
        "{name} was late to class due to heavy traffic caused by road construction.",
        "{name} missed school because of severe weather conditions in their area.",
        "{name} could not participate as they were representing the school in another academic competition.",
        "{name} was unable to complete the homework because of an urgent family responsibility.",
        "{name} missed the deadline due to technical difficulties while uploading the assignment."
    };

    // Pick a random excuse
    int index = rand() % excuses.size();
    string excuse = excuses[index];

    // Replace {name} with actual input
    size_t pos = excuse.find("{name}");
    while (pos != string::npos) {
        excuse.replace(pos, 6, name);
        pos = excuse.find("{name}", pos + name.length());
    }

    cout << excuse << endl;

    return 0;
}
