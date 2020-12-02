#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 


int main(int argc, char *argv[])
{
  std::cout << "Day 2" << std::endl;

  // Read puzzle input from a file
  std::fstream input;
  input.open("./day2.input", std::ios::in);

  if (input.is_open()) {
    std::string line;
    std::string delimiter1 = ": ";
    std::string delimiter2 = " ";
    std::string delimiter3 = "-";
    std::string password;
    char character;
    int occurances_min;
    int occurances_max;
    int occurances;
    int valid_passwords = 0;
    int valid_passwords_two = 0;
    while (getline(input, line)) {
      std::cout << "      LINE: " << line << std::endl;

      password = line.substr(line.find(delimiter1) + delimiter1.size(), line.size());
      std::cout << "  PASSWORD: " << password << std::endl;

      line = line.substr(0, line.find(delimiter1));

      character = line.substr(line.find(delimiter2) + delimiter2.size(), line.size())[0];
      std::cout << " CHARACTER: " << character << std::endl;

      line = line.substr(0, line.find(delimiter2));
      
      std::string::size_type sz;

      occurances_max = std::stoi(line.substr(line.find(delimiter3) + delimiter3.size(), line.size()), &sz);
      std::cout << "       MAX: " << occurances_max<< std::endl;

      occurances_min = std::stoi(line.substr(0, line.find(delimiter3)), &sz);
      std::cout << "       MIN: " << occurances_min << std::endl;

      occurances = std::count(password.begin(), password.end(), character);
      std::cout << "OCCURANCES: " << occurances << std::endl;

      if (occurances >= occurances_min && occurances <= occurances_max) {
        std::cout << "-->    ONE: VALID" << std::endl;
        valid_passwords++;
      } else {
        std::cout << "-->    ONE: NOT VALID" << std::endl;
      }

      std::cout << "     FIRST: " << password[occurances_min-1] << std::endl;
      std::cout << "    SECOND: " << password[occurances_max-1] << std::endl;

      if ((password[occurances_min-1] == character &&
           password[occurances_max-1] != character) ||
          (password[occurances_min-1] != character &&
           password[occurances_max-1] == character)) {
        std::cout << "-->    TWO: VALID" << std::endl;
        valid_passwords_two++;

      } else {
        std::cout << "-->    TWO: NOT VALID" << std::endl;
      }

      std::cout << "-------------" << std::endl;
    }
    input.close();

    std::cout << "Part one: VALID PASSWORDS: " << valid_passwords << std::endl;
    std::cout << "Part two: VALID PASSWORDS: " << valid_passwords_two << std::endl;
    return 0;
  } else {
    std::cout << "No file day2.input exists!" << std::endl;
    return 1;
  }

}
