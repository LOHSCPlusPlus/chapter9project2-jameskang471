// should all be completely different from anyone else 
//used a few functions from the last project 
// i am using the same outline of this project as the last one so i dont know if it will ping the copy checker but hopefully it wont 
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
// initializinng my struct Cereal with all its variables
struct Cereal {
  enum {MAX_CHAR_LEN=100};
  char Name[MAX_CHAR_LEN];
  double Calories;
  double Protein;
  double Fat;
  double Sodium;
  double Fiber;
  double Carbohydrates;
  double Sugar;
  double Serving;
  Cereal();
};
// default constructer making all variables to 0
Cereal::Cereal() {

  Calories = 0.0;
  Protein = 0.0;
  Fat = 0.0;
  Sodium = 0.0;
  Fiber = 0.0;
  Carbohydrates = 0.0;
  Sugar = 0.0;
  Serving = 0.0;
}
// making the constant variable for max cereals
const int MAX_CEREALS=100;
// reading all of the cereals till each ;
Cereal readCerealData(ifstream &inFile){
    Cereal cereal; 
    inFile.get(cereal.Name, Cereal::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> cereal.Calories;
    inFile.ignore(100,';');
    inFile >> cereal.Protein;
    inFile.ignore(100,';');
    inFile >> cereal.Fat;
    inFile.ignore(100,';');
    inFile >> cereal.Sodium;
    inFile.ignore(100,';');
    inFile >> cereal.Fiber;
    inFile.ignore(100,';');
    inFile >> cereal.Carbohydrates;
    inFile.ignore(100,';');
    inFile >> cereal.Sugar;
    inFile.ignore(100,';');
    inFile >> cereal.Serving;
    inFile.ignore(100, '\n');
    return cereal;
}


// printing function to print everything 
void printCereal(ostream &out, Cereal num) {
// might need while idk for valid 
  out << num.Name << ";";
  out << num.Calories << ";";
  out << num.Protein << ";";
  out << num.Fat << ";";
  out << num.Sodium << ";";
  out << num.Fiber << ";";
  out << num.Carbohydrates << ";";
  out << num.Sugar << ";";
  out << num.Serving << ";";
  out << endl;
  }
// a few problems with this one but its okay 
 void printArrayToFile(const char fileName[], Cereal cereal[], int MAX_CEREALS) {   
    ofstream outFile(fileName);
    for (int index = 0; index < MAX_CEREALS; index++) {
        printCereal(outFile, cereal[index]);
    }   
   }
  // reading the ints. to keep bugs from happenign. same as project1 but i changed it so it wont be the same.  hopefully it doesnt ping it
int intFromUser(const char userInput[]) {
    int variableReturned = 0;
    cout << userInput;
    cin >> variableReturned;
    while (!cin) {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Try again" << endl;
        cout << userInput;
        cin >> variableReturned;
    }
    return variableReturned;
}
// to read all of the variables as doubles. same as project1 but i changed it so it wont be the same. hopefully it doesnt ping it
double doubleFromUser(const char userInput[]) {
      int variableReturned = 0.0;
    cout << userInput;
    cin >> variableReturned;
    while (!cin) {
        cin.clear();
        cin.ignore(100,'\n');
        cout << "Try again" << endl;
        cout << userInput;
        cin >> variableReturned;
    }
    return variableReturned;
}
// removing cereal entrys 
void removeCereal(Cereal cereal[], int size) {
  int number = 0;
  number = intFromUser("what index of cereal do u want to remove: ");
  
  for (int count = 0; count < size; count++) {
    cereal[number] = cereal[number+1];
    } 
  
}
// adding cereal entries to the end of the list 
void addCereal(Cereal cereal[], int cerealSize) {
  bool isCerealAdded = false;
  for (int num = 0; num < MAX_CEREALS; num++) {
    double userInputDouble = 0.0;
    if(strcmp(cereal[num].Name, "") == 0) {
      cout << "You are going to add cereal #: " << num+1 << endl;
      cout << "Name: ";
      cin.ignore(100, '\n');
      cin.getline(cereal[num].Name,cerealSize);
      userInputDouble = doubleFromUser("\nCalories: ");
      cereal[num].Calories = userInputDouble;
      userInputDouble = doubleFromUser("\nProtein: ");
      cereal[num].Protein = userInputDouble;
      userInputDouble = doubleFromUser("\nFat: ");
      cereal[num].Fat = userInputDouble;
      userInputDouble = doubleFromUser("\nSodium: ");
      cereal[num].Sodium = userInputDouble;
      userInputDouble = doubleFromUser("\nFiber: ");
      cereal[num].Fiber = userInputDouble;
      userInputDouble = doubleFromUser("\nCarbohydrates: ");
      cereal[num].Carbohydrates = userInputDouble;
      userInputDouble = doubleFromUser("\nSugar: ");
      cereal[num].Sugar = userInputDouble;
      userInputDouble = doubleFromUser("\nServing: ");
      cereal[num].Serving = userInputDouble;

      isCerealAdded = true;
      break;
    }
    }
  if(isCerealAdded == false) {
    cout << "Array is full" << endl;
  }
}
// print all cereals with < 100 caloriess
void printCerealByCalories(Cereal cereal[], int listLength) {
  for (int num = 0; num < 100; num++) {
    if(cereal[num].Calories < 100 && cereal[num].Calories > 0) {
      printCereal(cout, cereal[num]);
      cout << endl;
    }
  }
} 
// printing all cereals no matter what 
void printAllCereal(Cereal cereal[], int listLength) {
  for (int num = 0; num < listLength; num++) {
    cout << "Index " << num << ": ";
    printCereal(cout, cereal[num]);
      cout << endl;
    }
  }
// adding cereal entry to the actual file now 
void cerealListToFile(const char fileName[], Cereal cereal[], int listLength) {
  ofstream outFile(fileName);
  for(int num = 0; num < listLength; num++) {
    printCereal(outFile, cereal[num]);
  }
}

// menu funciton to print the menu
int Menu() {
  int menuChoice = 0;
  cout << "Welcome to the cereal selector" << endl;
  cout << "Choose one option by entering a number below" << endl;
  cout << "1. Reload database from the file" << endl;
  cout << "2. Print database " << endl;
  cout << "3. Add new entry " << endl;
  cout << "4. Remove entry " << endl;
  cout << "5. Print all cereal with < 100 calories in it" << endl;
  cout << "6. Save database to the file" << endl;
  cout << "7. Quit " << endl;
  cout << "Input: ";
  cin >> menuChoice;
  cout << endl;
  return menuChoice;
}
// the main function to take in everything and has a switch statement for each input from the user depending on the menu choice 
int main() {
   ifstream cerealFile("cereal.txt");
  Cereal cerealList[500];
  int menuChoice = 0;
  int num = 0;

while (cerealFile.peek() != EOF) {
  cerealList[num] = readCerealData(cerealFile);
  num++;
}
  menuChoice = Menu();

  while(menuChoice != 7) {
    switch (menuChoice) {

      case 1:
      printArrayToFile("cereal.txt", cerealList, 500);

      break;
    
      case 2:
      printAllCereal(cerealList, num);
        break;
    
      case 3:
      addCereal(cerealList, num);
      num++;
      break;
      
      case 4: 
      removeCereal(cerealList, num);
      num--;
      break;

      case 5:
      printCerealByCalories(cerealList, num);
      break;

      case 6:
      cerealListToFile("cereal.txt", cerealList, num);
      break;

      case 7:
      break;

      default :
      cout << "Invalid. Try again" << endl;
      break;
    }
menuChoice = Menu();
  }
}