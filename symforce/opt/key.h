#pragma once

#include <limits>
#include <ostream>
#include <stdint.h>

#include <lcmtypes/sym/key_t.hpp>

namespace sym {

/**
 * Key type for Values. Contains a letter plus an integral subscript and superscript.
 * Can construct with a letter + sub, letter + sub + super, but not letter + super.
 *
 * TODO(hayk): Consider an abstraction where Key contains a type enum.
 */
class Key {
 public:
  using subscript_t = int64_t;
  using superscript_t = int64_t;

  static constexpr char kInvalidLetter = static_cast<char>(0);
  static constexpr subscript_t kInvalidSub = std::numeric_limits<subscript_t>::min();
  static constexpr superscript_t kInvalidSuper = std::numeric_limits<superscript_t>::min();

  Key(const char letter, const subscript_t sub, const superscript_t super)
      : letter_(letter), sub_(sub), super_(super) {}
  Key(const char letter, const subscript_t sub) : Key(letter, sub, kInvalidSuper) {}
  Key(const char letter) : Key(letter, kInvalidSub, kInvalidSuper) {}
  Key() : Key(kInvalidLetter, kInvalidSub, kInvalidSuper) {}

  Key(const key_t& key) : Key(key.letter, key.subscript, key.superscript) {}

  char Letter() const {
    return letter_;
  }

  subscript_t Sub() const {
    return sub_;
  }

  superscript_t Super() const {
    return super_;
  }

  key_t GetLcmType() const {
    key_t key;
    key.letter = letter_;
    key.subscript = sub_;
    key.superscript = super_;
    return key;
  }

  bool operator==(const Key& other) const {
    return (other.letter_ == letter_) && (other.sub_ == sub_) && (other.super_ == super_);
  }

  /**
   * Return true if a is LESS than b, in dictionary order of the tuple (letter, sub, super).
   */
  static bool LexicalLessThan(const Key& a, const Key& b);

  /**
   * Implementation of the Compare spec for use in containers
   */
  struct LexicalCompare {
    bool operator()(const Key& a, const Key& b) const {
      return LexicalLessThan(a, b);
    }
  };

 protected:
  char letter_;
  subscript_t sub_;
  superscript_t super_;
};

}  // namespace sym

/**
 * Print implementation for Key.
 *
 * Examples
 *     Key('C', 13) -> "C_13"
 *     Key('f') -> "f"
 *     Key('f', 32, 2) -> "f_32_2"
 *     Key('A', -2, 123) -> "A_n2_123"
 *     Key() -> "NULLKEY"
 */
std::ostream& operator<<(std::ostream& os, const sym::Key& key);
std::ostream& operator<<(std::ostream& os, const sym::key_t& key);

namespace sym {
namespace internal {

/**
 * Implementation of tuple hashing.
 *
 * Reference:
 *     https://stackoverflow.com/questions/2590677/how-do-i-combine-hash-values-in-c0x
 */
inline void hash_combine(std::size_t& seed) {}

template <typename T, typename... Rest>
inline void hash_combine(std::size_t& seed, const T& v, Rest... rest) {
  std::hash<T> hasher;
  seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
  hash_combine(seed, rest...);
}

}  // namespace internal
}  // namespace sym

/**
 * Hash function for Key.
 */
namespace std {

template <>
struct hash<sym::Key> {
  std::size_t operator()(const sym::Key& key) const {
    std::size_t ret = 0;
    sym::internal::hash_combine(ret, key.Letter(), key.Sub(), key.Super());
    return ret;
  }
};

template <>
struct hash<sym::key_t> {
  std::size_t operator()(const sym::key_t& key) const {
    std::size_t ret = 0;
    sym::internal::hash_combine(ret, key.letter, key.subscript, key.superscript);
    return ret;
  }
};

}  // namespace std
