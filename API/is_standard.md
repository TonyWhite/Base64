# [Base64](Base64.md)::is_standard

## Description

Check if the encoded string respects the standard charset.

|Scope     |Parameters               |
|---------:|:------------------------|
|bool (1)  |`const std::string *enc` |

|Scope     |Description                                                |
|---------:|:----------------------------------------------------------|
|bool (1)  |Check if the encoded string respects the standard charset. |

## Parameters

|Parameter | Description                                          |
|:---------|:-----------------------------------------------------|
|enc       |Encoded data to Base64. It is always a `std::string`. |

## Return value

**bool**

Returns `true` if it is a standard encoding.

Returns `false` in all other cases.

## Examples

```C++
// Check if encoded data is standard encoding
#include <iostream>
#include <string>
#include "Base64.h"

int main() {
  // Init
  std::string enc, dec;

  // Check standard charset
  enc = "QUI+";
  std::cout << "enc: \"" << enc << "\"\n";
  std::cout << "Standard charset: ";
  if (Base64::is_standard(&enc)) std::cout << "YES";
  else std::cout << "NO";
  std::cout << "\n\n";

  // Check standard charset
  enc = "QUI-";
  std::cout << "enc: \"" << enc << "\"\n";
  std::cout << "Standard charset: ";
  if (Base64::is_standard(&enc)) std::cout << "YES";
  else std::cout << "NO";
  std::cout << std::endl;

  return 0;
}
```

Output

```
enc: "QUI+"
Standard charset: YES

enc: "QUI-"
Standard charset: NO
```