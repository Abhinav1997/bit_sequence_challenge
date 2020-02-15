#include <iostream>

// Assuming that `bit_mask` was the last bit that was already printed,
// print permutation number `n` of the remaining `bit_mask` permutations.
void print_permutation(uint64_t bit_mask, uint64_t n, bool reverse = false)
{
  if (bit_mask == 1) {
    // The least significant bit was already written.
    // Write a trailing new-line and return.
    std::cout << '\n';
    return;
  }
  // Update bit_mask to reflect the bit that we're going to write now.
  bit_mask >>= 1;
  // Reverse the remaining bits if we're in the second half.
  bool const second_half = n >= bit_mask;
  // Write 0 for the first half and 1 for the second half, possibly reversed.
  std::cout << (second_half == reverse ? '0' : '1');
  // Write the remaining bits.
  print_permutation(bit_mask, n & ~bit_mask, second_half);
}

int main()
{
  int const number_of_bits = 40;
  uint64_t const bit_mask = uint64_t(1) << number_of_bits;
  for (uint64_t i = 0; i < bit_mask; ++i)
    print_permutation(bit_mask, i);
}
