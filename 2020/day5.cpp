#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


struct BoardingPass {
  int row;
  int column;
  int seatID;
};

BoardingPass printBoardingPass(BoardingPass boarding_pass) {
  std::cout << "ROW: " << boarding_pass.row << std::endl;
  std::cout << "COLUMN: " << boarding_pass.column << std::endl;
  std::cout << "SEAT_ID: " << boarding_pass.seatID << std::endl;
  return boarding_pass;
}

int partition(std::string text, char left, char right, int from, int to) {
  for (char &character: text) {
    std::cout << character << " : " << from << " - " << to << std::endl;
    if (left == character) {
      to = from - 1 + (to + 1 - from) / 2;
    } else if (right == character) {
      from = from + (to + 1 - from) / 2;
    } else {
      throw ("Wrong character in '" + text + "'. Expected '" + left + "' or '" + right + "'");
    }
  }
  std::cout << "= : " << from << " - " << to << std::endl;

  if (from == to) {
    return from;
  } else {
    throw ("Something went wrong partitioning '" + text + "'");
  }
}

BoardingPass parseBoardingPass(std::string line) {
  BoardingPass boarding_pass;
  
  // row
  std::string row = line.substr(0, 7);
  boarding_pass.row = partition(row, 'F', 'B', 0, 127);

  // column
  std::string column = line.substr(7, 9);
  boarding_pass.column = partition(column, 'L', 'R', 0, 7);


  boarding_pass.seatID = boarding_pass.row * 8 + boarding_pass.column;

  printBoardingPass(boarding_pass);
  std::cout << "-----------------" << std::endl;
  return boarding_pass;
}

std::vector<BoardingPass> getPuzzleInput(std::string input_file) {
  std::fstream input;
  std::vector<BoardingPass> boarding_passes;

  std::cout << "WORKS" << std::endl;
  try {
    input.open(input_file, std::ios::in);

    std::string line;

    while (getline(input, line)) {
      std::cout << "LINE: " << line << std::endl;
      boarding_passes.push_back(parseBoardingPass(line));
    }

  } catch(const std::ifstream::failure& e) {
    std::cout << "No file " << input_file << " exists!" << std::endl;
  }

  input.close();

  return boarding_passes;
}

int main(int argc, char *argv[]) {
  std::cout << "Day 5" << std::endl;

  int part_one = 0;
  int part_two = 0;
  std::vector<BoardingPass> boarding_passes;

  try {
    boarding_passes = getPuzzleInput("./day5.input");
    std::sort(
      boarding_passes.begin(),
      boarding_passes.end(),
      [ ](const BoardingPass& i, const BoardingPass& j) { return i.seatID < j.seatID; }
    );

    int i = 0;
    for(BoardingPass boarding_pass: boarding_passes) {
      if (boarding_pass.seatID > part_one) {
        part_one = boarding_pass.seatID;
      }
      if ((boarding_passes[i+1].seatID - boarding_pass.seatID) == 2) {
        part_two = boarding_pass.seatID + 1;
      }
      i++;
    }

    std::cout << "Part one = " << part_one << std::endl;
    std::cout << "Part two = " << part_two << std::endl;
  
    return 0;
  } catch(const std::exception& e) {
    std::cout << "Caught exception \"" << e.what() << "\"\n";
    return 1;
  }
}
