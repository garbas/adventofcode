#include <fstream>
#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>

// Read puzzle input from a file
std::vector<std::string> getPuzzleInput(std::string input_file) {

  std::fstream input;
  std::vector <std::string> input_lines;

  try {
    input.open(input_file, std::ios::in);

    std::string line;
    while (getline(input, line)) {
      input_lines.push_back(line);
    }

  } catch(const std::ifstream::failure& e) {
    std::cout << "No file " << input_file << " exists!" << std::endl;
  }

  input.close();

  return input_lines;

};


struct Slope {
  int left = 0;
  int right = 0;
  int down = 0;
  int up = 0;
};

enum PositionStatus {Open, Tree};

struct Position {
  int x = 0;
  int y = 0;
  PositionStatus status(std::vector<std::string> trees_slope) {
    if (y < trees_slope.size() && trees_slope[y][x % trees_slope[y].size()] == '#') {
      return Tree;
    }
    return Open;
  };
};

void downTheSlope(Position& position, Slope slope) {
  position.x += slope.right - slope.left;
  position.y += slope.down - slope.up;
}

int getTrees(std::vector<std::string> trees_slope, Slope slope) {
  Position position;
  int trees = 0;
  while (position.y < trees_slope.size()) {
    PositionStatus status = position.status(trees_slope);
    //std::cout << "(" << position.x << ", " << position.y << ") ";
    //std::cout << status << std::endl;
    if (status == Tree) {
      trees += 1;
    }
    downTheSlope(position, slope);
  }
  return trees;
};

int main(int argc, char *argv[])
{
  std::cout << "Day 3" << std::endl;

  std::vector <std::string> trees_slope;

  Slope slope1;
  slope1.right = 1;
  slope1.down = 1;

  Slope slope2;
  slope2.right = 3;
  slope2.down = 1;

  Slope slope3;
  slope3.right = 5;
  slope3.down = 1;

  Slope slope4;
  slope4.right = 7;
  slope4.down = 1;

  Slope slope5;
  slope5.right = 1;
  slope5.down = 2;

  try {
    trees_slope = getPuzzleInput("./day3.input");

    long trees1 = getTrees(trees_slope, slope1);
    long trees2 = getTrees(trees_slope, slope2);
    long trees3 = getTrees(trees_slope, slope3);
    long trees4 = getTrees(trees_slope, slope4);
    long trees5 = getTrees(trees_slope, slope5);

    std::cout << "Part one = " << trees2 << std::endl;
    std::cout << "Part two = " << trees1 * trees2 * trees3 * trees4 * trees5 << std::endl;
    return 0;
  } catch(const std::exception& e) {
    std::cout << "Caught exception \"" << e.what() << "\"\n";
    return 1;
  }
}
