/***********************************************************
Application    : Password Retriever                         
Author(s)      : G0D-Developer & YashasDDev               
Version        : 3.4                                      
Copyright      : © 2021 G0D-Developer & YashasDDev        
Description    : Retrieve Passwords & Make New Ones         
***********************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>

using namespace std;

void setupWizard();

#define PURPLE cout << "\033[0;35m";
#define WHITE cout << "\033[0;37m";
#define RED cout << "\033[0;31m";
#define GREEN cout << "\033[0;32m";

  int _main();
  void setupWiizard();
  void accessKeys();
  void deleteKeys();
  void deleteAccount();
  void clearScreen();

  bool isLoggedIN () {

    string username, password, un, pw;
    
    WHITE
    cout << "Username: ";
    PURPLE
    cin >> username;
    WHITE
    cout << "Password: ";
    PURPLE
    cin >> password;
    WHITE

    ifstream read(username + ".js");
    getline (read, un);
    getline (read, pw);
    
    if ( un == username && pw == password ) {

      return true;

    } else {

      return false;

    }

  }

int login () {

  int choice;
  
  WHITE
  cout << "1. Register \n";
  cout << "2. Login \n";
  cin >> choice;

  if ( choice == 1 ) {

    string username, password;
    
    WHITE
    cout << "Username (must be all-caps): ";
    PURPLE
    cin >> username;
    WHITE
    cout << "Password (must be all-caps): ";
    PURPLE
    cin >> password;
    WHITE

    ofstream file;
    file.open(username + ".js");

    file << username << endl << password;
    file.close();

    login();

  } else if ( choice == 2 ) {

    bool status = isLoggedIN();

    if ( !status ) {
      
      RED
      cout << "Login Failed! \a \n";
      return 0;

    } else if ( status ) {
      
      GREEN
      cout << "Login Successful! \a \n \n";
      _main();

    }

  }

}


int main() {

  login();

}

int _main() {

  int choice;

  PURPLE
  cout << "1. Create New Passwords \n";
  sleep(1);
  cout << "2. Access Passwords \n";
  sleep(1);
  RED
  cout << "3. Delete Passwords \n";
  sleep(1);
  cout << "4. Delete Account \n";
  WHITE
  cin >> choice;

  if (choice == 1) {

    setupWizard();

  } else if (choice == 2) {

    accessKeys();

  } else if (choice == 3) {

    deleteKeys();

  } else if (choice == 4) {

    deleteAccount();

  } else {

    RED
    cout << "Invalid option!";
    WHITE
    return 0;

  }

}

void setupWizard() {

  string user_name;
  string password1Name, password2Name, password3Name;
  string password1, password2, password3;

  cout << "Username: ";
  cin >> user_name;

  cout << " < - - - Password Setup - - - > \n";
  cout << "Password One Name: ";
  cin >> password1Name;
  cout << "Password One: ";
  cin >> password1;

  cout << "Password Two Name: ";
  cin >> password2Name;
  cout << "Password Two: ";
  cin >> password2;

  cout << "Password Three Name: ";
  cin >> password3Name;
  cout << "Password Three: ";
  cin >> password3;

  ofstream knfile(user_name + "_key_names.dat");
  knfile << password1Name << endl;
  knfile << password2Name << endl;
  knfile << password3Name << endl;
  knfile.close();

  ofstream kfile(user_name + "_keys.dat");
  kfile << password1 << endl;
  kfile << password2 << endl;
  kfile << password3 << endl;
  kfile.close();
  
  sleep(3);
  clearScreen();

  GREEN
  cout << "Set up complete! \n";
  WHITE
  _main();

}

void accessKeys() {

  int rNum;

  string user_Name;
  string k1, k2, k3;
  string kn1, kn2, kn3;

  cout << "Username: ";
  cin >> user_Name;
  ifstream knread(user_Name + "_key_names.dat");
  getline(knread, kn1);
  getline(knread, kn2);
  getline(knread, kn3);

  ifstream kread(user_Name + "_keys.dat");
  getline(kread, k1);
  getline(kread, k2);
  getline(kread, k3);

  cout << "Which password do you want to retrieve? \n";
  cout << "1. " << kn1 << endl;
  cout << "2. " << kn2 << endl;
  cout << "3. " << kn3 << endl;
  cin >> rNum;

  if (rNum == 1) {

    PURPLE
    cout << "Password: " << k1 << endl;
    WHITE
    _main();

  } else if (rNum == 2) {

    PURPLE
    cout << "Password: " << k2 << endl;
    WHITE
    _main();

  } else if (rNum == 3) {

    PURPLE
    cout << "Password: " << k3 << endl;
    WHITE
    _main();

  } else {

    RED
    cout << "Invalid Option! \n";
    WHITE
    exit(0);

  }

}

void deleteKeys() {

  string _username;

  cout << "Username: ";
  cin >> _username;
  RED
  cout << "Deleting Keys...";
  remove((_username + "_keys.dat").c_str());
  remove((_username + "_key_names.dat").c_str());
  sleep(3);
  GREEN 
  cout << "Keys deleted successfully! \n";
  WHITE
  exit(0);

}

void deleteAccount() {

  string _userName;

  cout << "Username: ";
  cin >> _userName;
  RED
  cout << "Deleting Account... \n";
  remove((_userName + "_keys.dat").c_str());
  remove((_userName + "_key_names.dat").c_str());
  remove((_userName + ".txt").c_str());
  sleep(3);
  GREEN
  cout << "Account deleted successfully! \n";
  WHITE
  exit(0);

}

void clearScreen() {

  for (int c = 0; c < 10; c++) {

    cout << "\n\n\n\n\n\n\n\n\n\n";

  }

}
