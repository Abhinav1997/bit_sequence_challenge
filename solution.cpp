#include <iostream>
#include <string>

enum class Direction {
  kForward,
  kReverse
};

void BitSequence(int bit_count, Direction direction = Direction::kForward, std::string bit_string = "") {
  if (bit_count == 0) {
    std::cout << bit_string << '\n';
    return;
  }
  if (direction == Direction::kForward) {
    BitSequence(bit_count - 1, Direction::kForward, bit_string + "0");
    BitSequence(bit_count - 1, Direction::kReverse, bit_string + "1");
  } else if (direction == Direction::kReverse) {
    BitSequence(bit_count - 1, Direction::kForward, bit_string + "1");
    BitSequence(bit_count - 1, Direction::kReverse, bit_string + "0");
  }
}

int main() {
  BitSequence(4);
  return 0;
}
