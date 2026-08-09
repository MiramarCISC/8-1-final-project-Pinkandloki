#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Stores information about one dog
struct Dog {
string name;
int age;
double weight;
};
// Displays the main menu
void showMenu() {
cout << "\n--- DOG CARE TRACKER ---\n";
cout << "1. Add a dog\n";
cout << "2. View dogs\n";
cout << "3. Show oldest dog\n";
cout << "4. Show heaviest dog\n";
cout << "5. Exit\n";
cout << "Enter your choice: ";
}

// Gets information for a new dog
Dog addDog() {
Dog newDog;

cout << "\nEnter dog's name: ";
cin >> newDog.name;

cout << "Enter dog's age: ";
cin >> newDog.age;

cout << "Enter dog's weight: ";
cin >> newDog.weight;

return newDog;
}

// Displays all dogs
void viewDogs(Dog dogs[], int count) {
if (count == 0) {
cout << "\nNo dogs have been added yet.\n";
return;
}

cout << "\n--- YOUR DOGS ---\n";

for (int i = 0; i < count; i++) {
cout << "Dog " << i + 1 << ": " << dogs[i].name << endl;
cout << "Age: " << dogs[i].age << endl;
cout << "Weight: " << dogs[i].weight << " lbs" << endl;
cout << endl;
}
}

// Saves dog information to a file
void saveDogs(Dog dogs[], int count) {
ofstream outFile("dogs.txt");

for (int i = 0; i < count; i++) {
outFile << dogs[i].name << endl;
outFile << dogs[i].age << endl;
outFile << dogs[i].weight << endl;
}

outFile.close();
}

// Loads dog information from a file
int loadDogs(Dog dogs[]) {
ifstream inFile("dogs.txt");
int count = 0;

while (count < 10 && inFile >> dogs[count].name) {
inFile >> dogs[count].age;
inFile >> dogs[count].weight;
count++;
}

inFile.close();
return count;
}

// Finds and displays the oldest dog
void showOldestDog(Dog dogs[], int count) {
if (count == 0) {
cout << "\nNo dogs have been added yet.\n";
return;
}

int oldest = 0;

for (int i = 1; i < count; i++) {
if (dogs[i].age > dogs[oldest].age) {
oldest = i;
}
}

cout << "\nOldest dog: " << dogs[oldest].name << endl;
cout << "Age: " << dogs[oldest].age << endl;
}

// Finds and displays the heaviest dog
void showHeaviestDog(Dog dogs[], int count) {
if (count == 0) {
cout << "\nNo dogs have been added yet.\n";
return;
}

int heaviest = 0;

for (int i = 1; i < count; i++) {
if (dogs[i].weight > dogs[heaviest].weight) {
heaviest = i;
}
}

cout << "\nHeaviest dog: " << dogs[heaviest].name << endl;
cout << "Weight: " << dogs[heaviest].weight << " lbs" << endl;
}
void sortDogsByAge(Dog dogs[], int count) {
for (int i = 0; i < count - 1; i++) {
for (int j = 0; j < count - i - 1; j++) {
if (dogs[j].age > dogs[j + 1].age) {
Dog temp = dogs[j];
dogs[j] = dogs[j + 1];
dogs[j + 1] = temp;
}
}
}
}
// Week 6: Demonstrates using a pointer with dog information
void demonstratePointer(Dog dogs[], int count) {
if (count > 0) {
Dog* dogPtr = &dogs[0];

cout << "\nPointer example - Dog: "
<< dogPtr->name << endl;
}
}
void demonstrateLinkedList();

void runDogCareTracker() {
Dog dogs[10];
int count = loadDogs(dogs);
int choice;

do {
showMenu();
cin >> choice;

switch (choice) {
case 1:
if (count < 10) {
dogs[count] = addDog();
count++;
saveDogs(dogs, count);
cout << "\nDog added successfully.\n";
} else {
cout << "\nDog list is full.\n";
}
break;

case 2:
viewDogs(dogs, count);
demonstratePointer(dogs, count);
sortDogsByAge(dogs, count);
demonstrateLinkedList();
break;

case 3:
showOldestDog(dogs, count);
break;

case 4:
showHeaviestDog(dogs, count);
break;

case 5:
cout << "\nGoodbye!\n";
break;

default:
cout << "\nInvalid choice. Try again.\n";
}

} while (choice != 5);
}

// Week 6: Pointers, Dynamic Memory, and Linked Lists
struct CareNode {
string activity;
CareNode* next;
};

void demonstrateLinkedList() {
CareNode* first = new CareNode{"Fed dog", nullptr};
CareNode* second = new CareNode{"Walked dog", nullptr};

first->next = second;

cout << "Care history: " << first->activity
<< ", " << first->next->activity << "\n";

delete second;
delete first;
}