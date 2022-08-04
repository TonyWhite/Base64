# Base64

## Summary

* [Description](#description)
* [Constructors](#constructors)
* [Fields](#fields)
* [Functions](#functions)
* [Details](#details)
* [Examples](#examples)

___

## Description

C++ Source for Base64.

## Constructors

This class has no constructor.

## Fields

|Type                       |Field                 |Description    |
|:--------------------------|:---------------------|:--------------|
|`static const std::string` |[CHARSET](CHARSET.md) |Base64 charset |

## Functions

|Type         |Function            |Description        |
|:------------|:-------------------|:------------------|
|`static void`|[decode](decode.md) |Decode from Base64 |
|`static void`|[encode](encode.md) |Encode to Base64   |


## Examples

```C++
//g++ Test.cpp Base64.cpp -o test
#include <iostream>
#include <string>
#include <vector>
#include "Base64.h"

// Dump buffer to standard out
void dump_buffer(std::string description, std::vector<char> *buffer) {
  std::cout << description << ": [" << buffer->size() << "] {";
  for (int i=0; i<buffer->size(); i++) {
    std::cout << (unsigned short)buffer->at(i);
    if (i<buffer->size()-1) {
      std::cout << ",";
    }
  }
  std::cout << "}" << std::endl;
}

// Dump string to standard out
void dump_string(std::string description, std::string *txt) {
  std::cout << description << ": [" << txt->size() << "] \"" << *txt << "\"" << std::endl;
}

// Test String conversion
void test_string() {
  // Init
  std::string txt = "ABC";
  std::string enc;
  std::string dec;
  
  // Work
  Base64::encode(&txt, &enc);
  Base64::decode(&enc, &dec);
  
  // Print
  dump_string("txt", &txt);
  dump_string("enc", &enc);
  dump_string("dec", &dec);
  
  // Print success
  std::cout << "success: ";
  if (txt == dec) std::cout << "YES";
  else std::cout << "NO";
  std::cout << std::endl;
}

// Test binary conversion
void test_binary() {
  // Init
  std::vector<char> bin;
  bin.push_back('A');
  bin.push_back('B');
  bin.push_back('C');
  std::string enc;
  std::vector<char> dec;
  
  // Work
  Base64::encode(&bin, &enc);
  Base64::decode(&enc, &dec);
  
  // Print
  dump_buffer("bin", &bin);
  dump_string("enc", &enc);
  dump_buffer("dec", &dec);
  
  // Print success
  std::cout << "success: ";
  if (bin == dec) std::cout << "YES";
  else std::cout << "NO";
  std::cout << std::endl;
}

// Start test
int main() {
  test_string();
  std::cout << std::endl;
  test_binary();
  return 0;
}
```

Output

```shell
txt: [3] "ABC"
enc: [4] "QUJD"
dec: [3] "ABC"
success: YES

bin: [3] {65,66,67}
enc: [4] "QUJD"
dec: [3] {65,66,67}
success: YES
```
