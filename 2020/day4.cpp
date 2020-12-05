#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using Passport = std::map<std::string, std::string>;

std::vector<std::string> split(std::string text, std::string separator) {
  int separatorIndex;
  std::string item;
  std::vector<std::string> items;
  while(text.find(separator) != std::string::npos) {
     separatorIndex = text.find(separator);
     item = text.substr(0, separatorIndex);
     if (item != "") {
       items.push_back(item);
     }
     text = text.substr(separatorIndex + 1, text.length());
  }
  if (text != "") {
    items.push_back(text);
  }
  return items;
}

Passport toPassport(std::string text) {
  Passport passport;
  std::vector<std::string> fields = split(text, " ");
  std::vector<std::string> fieldItems;

  for(const std::string field: fields) {
      fieldItems = split(field, ":");
      if (fieldItems.size() == 2) {
        passport.insert({fieldItems[0], fieldItems[1]});
      }
  }

  return passport;
}

Passport printPassport(Passport passport) {
  for(auto elem: passport) {
     std::cout << elem.first << ": " << elem.second << "\n";
  }
  return passport;
}

bool isIntRange(std::string field, int from, int to) {
  std::string::size_type sz;
  try {
    int byr = std::stoi (field, &sz);
    if (byr >= from && byr <= to) {
      return true;
    }
    return false;
  } catch(...) {
    return false;
  }
  return false;
}

bool stringInArray(std::string value, std::vector<std::string> array) {
  return std::find(array.begin(), array.end(), value) != array.end();
}

bool charInString(char value, std::string array) {
  return std::find(array.begin(), array.end(), value) != array.end();
}

bool endsWith(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

const std::vector<std::string> EyeColors = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
const std::string HexCodes = "0123456789abcdef";

bool isHexColor(std::string text) {
  if (text.size() == 7 && text[0] == '#') {
    std::string code = text.substr(1, text.size());
    for (int i = 0; i < code.size(); ++i) {
      if (!charInString(code[i], HexCodes)) {
        return false;
      }
    }
    return true;
  }
  return false;
}

bool isValidPassport(Passport passport, bool extra_security = false) {
  if (passport.count("byr") &&
      passport.count("iyr") &&
      passport.count("eyr") &&
      passport.count("hgt") &&
      passport.count("hcl") &&
      passport.count("ecl") &&
      passport.count("pid")) {
    if (extra_security) {
      if ( // byr (Birth Year) - four digits; at least 1920 and at most 2002.
           isIntRange(passport["byr"], 1920, 2002) &&
           // iyr (Issue Year) - four digits; at least 2010 and at most 2020.
           isIntRange(passport["iyr"], 2010, 2020) &&
           // eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
           isIntRange(passport["eyr"], 2020, 2030) &&
           // hgt (Height) - a number followed by either cm or in:
           //     If cm, the number must be at least 150 and at most 193.
           //     If in, the number must be at least 59 and at most 76.
           ((endsWith(passport["hgt"], "cm") &&
             isIntRange(passport["hgt"].substr(0, passport["hgt"].size() - 2), 150, 193)
             ) || 
            (endsWith(passport["hgt"], "in") &&
             isIntRange(passport["hgt"].substr(0, passport["hgt"].size() - 2), 59, 76)
             )
            ) &&
           // hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
           isHexColor(passport["hcl"]) &&

           // ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
           stringInArray(passport["ecl"], EyeColors) &&

           // pid (Passport ID) - a nine-digit number, including leading zeroes.
           (passport["pid"].size() == 9 && isIntRange(passport["pid"], 0, 999999999))
         ) {
        return true;
      }

      // Exaplain
      if (extra_security) {
        std::cout << "NOT VALID (extra_security):" << std::endl;
        if (!isIntRange(passport["byr"], 1920, 2002)) {
          std::cout << " - byr (Birth Year) invalid!" << std::endl;
        }
        if (!isIntRange(passport["iyr"], 2010, 2020)) {
          std::cout << " - iyr (Issue Year) invalid!" << std::endl;
        }
        if (!isIntRange(passport["eyr"], 2020, 2030)) {
          std::cout << " - eyr (Expiration Year) invalid!" << std::endl;
        }
        if (!((endsWith(passport["hgt"], "cm") &&
               isIntRange(passport["hgt"].substr(0, passport["hgt"].size() - 2), 150, 193)
               ) || 
              (endsWith(passport["hgt"], "in") &&
               isIntRange(passport["hgt"].substr(0, passport["hgt"].size() - 2), 59, 76)
               )
             )
            ) {
          std::cout << " - hgt (Height) invalid!" << std::endl;
        }
        if (!isHexColor(passport["hcl"])) {
          std::cout << " - hcl (Hair Color) invalid!" << std::endl;
        }
        if (!stringInArray(passport["ecl"], EyeColors)) {
          std::cout << " - ecl (Eye Color) invalid!" << std::endl;
        }
        if (!(passport["pid"].size() == 9 && isIntRange(passport["pid"], 0, 999999999))) {
          std::cout << " - pid (Passport ID) invalid!" << std::endl;
        }
      }

      return false;
    }

    return true;
  }

  // Exaplain
  std::cout << "NOT VALID:" << std::endl;
  if (!passport.count("byr")) {
    std::cout << " - byr (Birth Year) missing!" << std::endl;
  }
  if (!passport.count("iyr")) {
    std::cout << " - iyr (Issue Year) missing!" << std::endl;
  }
  if (!passport.count("eyr")) {
    std::cout << " - eyr (Expiration Year) missing!" << std::endl;
  }
  if (!passport.count("hgt")) {
    std::cout << " - hgt (Height) missing!" << std::endl;
  }
  if (!passport.count("hcl")) {
    std::cout << " - hcl (Hair Color) missing!" << std::endl;
  }
  if (!passport.count("ecl")) {
    std::cout << " - ecl (Eye Color) missing!" << std::endl;
  }
  if (!passport.count("pid")) {
    std::cout << " - pid (Passport ID) missing!" << std::endl;
  }

  return false;
}

// Read puzzle input from a file
std::vector<Passport> getPuzzleInput(std::string input_file) {
  std::fstream input;
  std::vector<Passport> passports;

  try {
    input.open(input_file, std::ios::in);

    std::string line;
    std::string text = "";

    while (getline(input, line)) {
      if (line != "") {
        text += " " + line;
      }
      if (line == "" && text != "") {
        passports.push_back(toPassport(text));
        text = "";
      }
    }
    if (line == "" && text != "") {
      passports.push_back(toPassport(text));
      text = "";
    }

  } catch(const std::ifstream::failure& e) {
    std::cout << "No file " << input_file << " exists!" << std::endl;
  }

  input.close();

  return passports;
}

int main(int argc, char *argv[]) {
  std::cout << "Day 4" << std::endl;

  int part_one = 0;
  int part_two = 0;
  std::vector<Passport> passports;

  try {
    passports = getPuzzleInput("./day4.input");
    std::cout << "Number of passports: " << passports.size() << std::endl;
    for(const Passport passport: passports) {
      printPassport(passport);
      std::cout << "Length: " << passport.size() << std::endl;
      if (isValidPassport(passport)) {
        part_one++;
      }
      if (isValidPassport(passport, true)) {
        part_two++;
      }
      std::cout << "----------------" << std::endl;
    }

    std::cout << "Part one = " << part_one << std::endl;
    std::cout << "Part two = " << part_two << std::endl;
    return 0;
  } catch(const std::exception& e) {
    std::cout << "Caught exception \"" << e.what() << "\"\n";
    return 1;
  }
}
