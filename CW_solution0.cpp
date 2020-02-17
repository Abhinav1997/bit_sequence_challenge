#include <iostream>

struct Permutation
{
 private:
  Permutation const& m_prefix;  // Leading prefix.
  int m_bit;                    // Final bit, or -1 if this permutation is empty.

 public:
  // Construct an empty permutation.
  Permutation() : m_prefix(*this), m_bit(-1) { }
  // Construct a Permutation "prefix + bit".
  Permutation(Permutation const& prefix, int bit) : m_prefix(prefix), m_bit(bit) { }

  static Permutation const s_empty;

  void add_bits_and_print_permutation_on(int extra_bits, std::ostream& os, bool reverse_extra_bits = false) const;

  // Printing to an ostream.
  void print_on(std::ostream& os) const;

  friend std::ostream& operator<<(std::ostream& os, Permutation const& prefix)
  {
    prefix.print_on(os);
    return os;
  }
};

void Permutation::print_on(std::ostream& os) const
{
  if (m_bit != -1)              // Not an empty prefix?
    os << m_prefix << m_bit;
  return;
}

void Permutation::add_bits_and_print_permutation_on(int extra_bits, std::ostream& os, bool reverse_extra_bits) const
{
  for (int bit = 0; bit <= 1; ++bit)
  {
    int const rbit = reverse_extra_bits ? 1 - bit : bit;
    if (extra_bits == 1)                // Is rbit the only extra bit we needed?
      os << *this << rbit << '\n';      // Print what we have.
    else
    {
      // Append one bit to the prefix.
      Permutation new_prefix(*this, rbit);
      // Recursively call print_on on the new prefix, requesting one less extra bits.
      new_prefix.add_bits_and_print_permutation_on(extra_bits - 1, os, bit);
    }
  }
}

Permutation const Permutation::s_empty;

int main()
{
  std::cout << "Enter the number of bits: ";
  int n;
  std::cin >> n;
  std::cout << n << std::endl;
  if (n > 0)
    Permutation::s_empty.add_bits_and_print_permutation_on(n, std::cout);
}
