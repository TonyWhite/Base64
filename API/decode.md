# [Base64](Base64.md)::decode

## Description
Decode from Base64

|Scope       |Parameters                                      |
|-----------:|:-----------------------------------------------|
|string (1)  |`const std::string *enc, std::string *dec`      |
|vector (2)  |`const std::string *enc, std::vector<char> *dec`|

|Scope       |Description                                    |
|-----------:|:----------------------------------------------|
|string (1)  |Decode data from Base64 to `std::string`.       |
|vector (2)  |Decode data from Base64 to `std::vector<char>`. Useful to decode binary data. |

## Parameters

|Parameter | Description                                                      |
|:---------|:-----------------------------------------------------------------|
|enc       |Base64 encoded data. It is always a `std::string`.                |
|dec       |Decoded data from Base64. Can be `std::string` or `vector<char>`. |

## Return value

None.

## Examples

### With string

```C++
// Decode Base64 to string
#include <iostream>
#include <string>
#include "Base64.h"

int main() {
  // Init
  std::string enc = "QUJD";
  std::string dec;
  
  // Decode
  Base64::decode(&enc, &dec);
  
  // Print
  std::cout << "dec: [" << dec.size() << "] \"" << dec << "\"" << std::endl;
  
  return 0;
}
```

Output

```shell
dec: "ABC"
```

### With vector

```C++
// Decode Base64 to vector<char>
#include <iostream>
#include <vector>
#include "Base64.h"

int main() {
  // Init
  std::string enc = "QUJD";
  std::vector<char> dec;
  
  // Decode
  Base64::decode(&enc, &dec);
  
  // Print
  std::cout << "dec: [" << dec.size() << "] {";
  for (long unsigned int i=0; i<dec.size(); i++) {
    std::cout << (unsigned short)dec.at(i);
    if (i<dec.size()-1) std::cout << ",";
    else std::cout << "}" << std::endl;
  }
  
  return 0;
}
```

Output

```shell
dec: [3] {65,66,67}
```
