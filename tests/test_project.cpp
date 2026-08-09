#include "project.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Runs the Dog Care Tracker with test input
string runTrackerWithInput(string input) {
istringstream testInput(input);
ostringstream testOutput;

streambuf* oldInput = cin.rdbuf(testInput.rdbuf());
streambuf* oldOutput = cout.rdbuf(testOutput.rdbuf());

runDogCareTracker();

cin.rdbuf(oldInput);
cout.rdbuf(oldOutput);

return testOutput.str();
}

void testViewDogs() {
string output = runTrackerWithInput("2\n5\n");

assert(output.find("Venom") != string::npos);
assert(output.find("Thor") != string::npos);
assert(output.find("Loki") != string::npos);
}
void testOldestDog() {
string output = runTrackerWithInput("3\n5\n");

assert(output.find("Venom") != string::npos);
}
void testHeaviestDog() {
string output = runTrackerWithInput("4\n5\n");

assert(output.find("Thor") != string::npos);
}
void testPointer() {
string output = runTrackerWithInput("2\n5\n");

assert(output.find("Pointer example - Dog: Venom") != string::npos);
}
void testFileIO() {
string output = runTrackerWithInput("2\n5\n");

assert(output.find("Venom") != string::npos);
assert(output.find("Thor") != string::npos);
assert(output.find("Loki") != string::npos);
}
void testMenuBasics() {
string output = runTrackerWithInput("5\n");

assert(output.find("DOG CARE TRACKER") != string::npos);
assert(output.find("1. Add a dog") != string::npos);
assert(output.find("5. Exit") != string::npos);
}
void testInvalidChoice() {
string output = runTrackerWithInput("9\n5\n");

assert(output.find("Invalid choice. Try again.") != string::npos);
}
int main() {
testViewDogs();
testOldestDog();
testHeaviestDog();
testPointer();
testFileIO();
testMenuBasics();
testInvalidChoice();

cout << "All Dog Care Tracker tests passed!" << endl;
return 0;
}

