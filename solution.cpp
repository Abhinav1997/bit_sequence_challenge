#include <iostream>

void bit_sequence(const uint8_t bit_count, const uint64_t num) {
  if (bit_count == 0) {
    std::cout << '\n';
    return;
  }
  bit_sequence(bit_count - 1, num >> 1);
  std::cout << ((num & 1) ? '1' : '0');
}

int main() {
  const uint8_t bit_count { 4 };
  const uint64_t total_values { 1 << bit_count };
  for (uint64_t num = 0; num < total_values; ++num)
    bit_sequence(bit_count, num ^ (num >> 1));
  return 0;
}
