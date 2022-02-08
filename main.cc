#include <iostream>
#include <vector>
using namespace std;
void die(){cout << "BAD INPUT!\n"; exit(1);}
string convertNumber(int digit) {
  if (digit == 0) return "ling ";
  if (digit == 1) return "yi ";
  if (digit == 2) return "er ";
  if (digit == 3) return "san ";
  if (digit == 4) return "si ";
  if (digit == 5) return "wu ";
  if (digit == 6) return "liu ";
  if (digit == 7) return "qi ";
  if (digit == 8) return "ba ";
  if (digit == 9) return "jiu ";
  return "ERROR";
}

string mandarinTranslation(int number) {
  string retval;
  if (!number) return "ling";
  unsigned int thousands = number / 1000;
  if (thousands > 10) {
    retval += convertNumber(thousands/10);
    retval += "wan ";
    retval += convertNumber(thousands%10);
    retval += "qian "; 
  }
  else if (thousands == 10)
    retval += "wan ";
  else if (thousands > 0) {
    retval += convertNumber(thousands);
    retval += "qian ";
  }
  number %= 1000;
  unsigned int hundreds = number / 100;
  if (hundreds){
    retval += convertNumber(hundreds);
    retval += "bai ";
  }
  number %= 100;
  unsigned int tens = number / 10;
  if (tens) {
    if (tens == 1)
      retval += "shi ";
    else {
      retval += convertNumber(tens);
      retval += "shi ";
    }
  }

  number %= 10;
  if (number) 
    retval += convertNumber(number);

  retval.pop_back();
  return retval;
}

int main() {
    cout << "Enter a number to convert to mandarin.\n";
    int number = 0;
    cin >> number;
    if (!cin or number > 99999 or number < 0) die(); 
    cout << "The number " << number << " translates to \""
      << mandarinTranslation(number) << "\" in Mandarin." << endl;
}
