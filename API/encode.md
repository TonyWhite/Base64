# [Base64](Base64.md)::encode

## Description
Encode to Base64

|Scope       |Parameters                                      |
|-----------:|:-----------------------------------------------|
|string (1)  |`const std::string *txt, std::string *enc`      |
|vector (2)  |`const std::vector<char> *bin, std::string *enc`|

|Scope       |Description                                                                   |
|-----------:|:-----------------------------------------------------------------------------|
|string (1)  |Encode data from `std::string` to Base64.                                     |
|vector (2)  |Encode data from `std::vector<char>` to Base64. Useful to encode binary data. |

## Parameters

|Parameter | Description                                          |
|:---------|:-----------------------------------------------------|
|txt       |Text to encode. It is always a `std::string`.         |
|bin       |Data to encode. It is always a `vector<char>`.        |
|enc       |Encoded data to Base64. It is always a `std::string`. |

## Return value

None.

## Examples

### With string

```C++
// Encode string to Base64
#include <iostream>
#include <string>
#include "Base64.h"

int main() {
  // Init
  std::string txt = "ABC";
  std::string enc;
  
  // Encode
  Base64::encode(&txt, &enc);
  
  // Print
  std::cout << "enc: [" << enc.size() << "] \"" << enc << "\"" << std::endl;
  
  return 0;
}
```

Output

```shell
enc: [4] "QUJD"
```

### With vector

```C++
// Encode vector<char> to Base64
#include <iostream>
#include <vector>
#include "Base64.h"

int main() {
  // Init
  std::vector<char> bin;
  bin.push_back('A');
  bin.push_back('B');
  bin.push_back('C');
  std::string enc;
  
  // Encode
  Base64::encode(&bin, &enc);
  
  // Print
  std::cout << "enc: [" << enc.size() << "] \"" << enc << "\"" << std::endl;
  
  return 0;
}
```

Output

```shell
enc: [4] "QUJD"
```
