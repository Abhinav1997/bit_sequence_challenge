#include <array>
#include <iostream>

enum class Direction {
  kForward,
  kReverse
};

void bit_sequence(const int& bit_count, int bit_array[], const int& SIZE, const Direction& direction = Direction::kForward) {
  if (bit_count == 0) {
    for (size_t index = 0; index < SIZE; ++index)
      std::cout << bit_array[index];
    std::cout << '\n';
    return;
  }
  if (direction == Direction::kForward) {
    bit_array[SIZE - bit_count] = 0;
    bit_sequence(bit_count - 1, bit_array, SIZE, Direction::kForward);
    bit_array[SIZE - bit_count] = 1;
    bit_sequence(bit_count - 1, bit_array, SIZE, Direction::kReverse);
  } else if (direction == Direction::kReverse) {
    bit_array[SIZE - bit_count] = 1;
    bit_sequence(bit_count - 1, bit_array, SIZE, Direction::kForward);
    bit_array[SIZE - bit_count] = 0;
    bit_sequence(bit_count - 1, bit_array, SIZE, Direction::kReverse);
  }
}

int main() {
  int bit_count;
  std::cout << "Enter bit count: ";
  std::cin >> bit_count;
  int bit_array[bit_count];
  bit_sequence(bit_count, bit_array, bit_count);
  return 0;
}
