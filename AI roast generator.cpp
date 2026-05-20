#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    string name;
    cout << "Enter a name: ";
    cin >> name;

    // Roast templates with {name} placeholder
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "{name} thinks debugging is just staring at the screen until the bug feels guilty.",
        "{name} has so many bugs in their code, it should come with a free insect repellent.",
        "{name} compiles code just to see new error messages—it is their hobby.",
        "{name} is proof that copy-paste was invented for survival.",
        "{name} spends more time googling errors than actually coding.",
        "{name} thinks recursion is when you keep failing in loops.",
        "{name} writes code so confusing even AI refuses to read it.",
        "{name} believes semicolons are optional—like common sense.",
        "{name} once tried to optimize code and accidentally invented lag."
    };

    // Pick a random roast
    int index = rand() % roasts.size();
    string roast = roasts[index];

    // Replace {name} with actual input
    size_t pos = roast.find("{name}");
    if (pos != string::npos) {
        roast.replace(pos, 6, name);
    }

    cout << roast << endl;

    return 0;
}
