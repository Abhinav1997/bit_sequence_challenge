#include <array>
#include <iostream>

enum class Direction_ {
  kForward,
  kReverse
};

class Direction {
 private:
  Direction_ direction_;

 public:
  Direction(Direction_ direction) : direction_(direction) { }

  Direction operator!() const {
    Direction inverse(direction_ == Direction_::kForward ? Direction_::kReverse : Direction_::kForward);
    return inverse;
  }

  friend bool operator==(Direction const& d1, Direction const& d2) { return d1.direction_ == d2.direction_; }
  friend bool operator==(Direction const& d1, Direction_ d2) { return d1.direction_ == d2; }
  friend bool operator==(Direction_ d1, Direction const& d2) { return d1 == d2.direction_; }
  friend bool operator!=(Direction const& d1, Direction const& d2) { return d1.direction_ != d2.direction_; }
  friend bool operator!=(Direction const& d1, Direction_ d2) { return d1.direction_ != d2; }
  friend bool operator!=(Direction_ d1, Direction const& d2) { return d1 != d2.direction_; }

  void print_on(std::ostream& os) const
  {
    switch (direction_) {
      case Direction_::kForward:
        os << "kForward";
        break;
      case Direction_::kReverse:
        os << "kReverse";
        break;
    }
  }

  friend std::ostream& operator<<(std::ostream& os, Direction const& directory) {
    directory.print_on(os);
    return os;
  }
};

void bit_sequence(int bit_count, int bit_array[], int size, Direction direction = Direction_::kForward) {
  if (bit_count == 0) {
    for (int index = 0; index < size; ++index)
      std::cout << bit_array[index];
    std::cout << '\n';
    return;
  }
  int bit = (direction == Direction_::kForward) ? 0 : 1;
  std::cout << "direction = " << direction << std::endl;
  bit_array[size - bit_count] = bit;
  bit_sequence(bit_count - 1, bit_array, size, Direction_::kForward);
  bit_array[size - bit_count] = 1 - bit;
  bit_sequence(bit_count - 1, bit_array, size, Direction_::kReverse);
}

int main() {
  int bit_count;
  std::cout << "Enter bit count: ";
  std::cin >> bit_count;
  int bit_array[bit_count];
  bit_sequence(bit_count, bit_array, bit_count);
  return 0;
}
