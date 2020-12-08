#include <iostream>
#include <fstream>
#include <vector>
#include <map>


std::vector<std::vector<std::string>> parseInput(std::string input_file) {
  std::fstream input;

  std::vector<std::vector<std::string>> groups;
  try {
    input.open(input_file, std::ios::in);

    std::string line;
    std::vector<std::string> group;

    while (getline(input, line)) {
      if (line == "") {
        groups.push_back(group);
        group = {};
      } else {
        group.push_back(line);
      }
    }
    groups.push_back(group);

  } catch(const std::ifstream::failure& e) {
    std::cout << "No file " << input_file << " exists!" << std::endl;
  }

  input.close();

  return groups;
}

int main(int argc, char *argv[])
{
  std::cout << "Day 6" << std::endl;

  int part_one = 0;
  int part_two = 0;
  
  std::vector<std::vector<std::string>> groups;
  std::string temp = "";
  std::map<char, int> temp2;

  try {
    groups = parseInput("./day6.input");
    for(std::vector<std::string> group: groups) {
      for(std::string person: group) {
        std::cout << " - " << person << std::endl;
        for(char character: person) {
          size_t found = temp.find(character); 
          if (found == std::string::npos) {
            temp.push_back(character);
          } else {
            std::cout << "DUP: " << character << std::endl;
          }
          if (temp2.find(character) == temp2.end()) {
            temp2.insert({character, 0});
          }
          temp2[character] += 1;
        }
      }
      part_one += temp.size();
      std::cout << "FINAL: " << temp << std::endl;
      std::cout << "SIZE: " << temp.size() << std::endl;
      temp = "";
      std::cout << "GROUP SIZE: " << group.size() << std::endl;
      std::cout << "PER CHAR:" << std::endl;
      for(const auto &x: temp2) {
        std::cout << " - " << x.first << ": " << x.second;
        if (x.second == group.size()) {
          std::cout << " : COUNTED!";
          part_two += 1;
        }
        std::cout << std::endl;
      }

      temp2 = {};
      std::cout << "--------------------" << std::endl;
    }

    std::cout << "Part one = " << part_one << std::endl;
    std::cout << "Part two = " << part_two << std::endl;

    return 0;
  } catch(const std::exception& e) {
    std::cout << "Caught exception \"" << e.what() << "\"\n";
    return 1;
  }
}

