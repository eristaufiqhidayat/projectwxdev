#include <iostream>
#include <fstream>
#define FILENAME "test.ini"

using namespace std;

void writeFile()
{
  ofstream readFile(FILENAME);
  cout << "DATABASENAME : MYSQL";
  readFile.close();
}

void readFile()
{
  ifstream readFile(FILENAME);
  string Text;
  while(getline(readFile,Text)){
     cout<<Text;
  }
  readFile.close();
}

int main()
{
  writeFile();
  readFile();
}
