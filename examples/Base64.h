#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

class Base64 {
  public:
  static const std::string CHARSET; // Base64 charset
  
  static void decode(const std::string*, std::string*);       // Decode string from Base64
  static void decode(const std::string*, std::vector<char>*); // Decode vector from Base64
  
  static void encode(const std::string*, std::string*);       // Encode string to Base64
  static void encode(const std::vector<char>*, std::string*); // Encode vector to Base64
  
  
  private:
  // Base64 core
  static void decode(const char*, const long unsigned int, char*);        // Decode from Base64
  static void encode(const char*, const long unsigned int, std::string*); // Encode to Base64
  
  static inline bool isBase64(char); // Check for a valid Base64 char
  
  static inline long unsigned int predict_enc_len(const long unsigned int); // Predict length of encoded data
  static inline long unsigned int predict_dec_len(const std::string*);      // Predict length of decoded data
};

#endif
