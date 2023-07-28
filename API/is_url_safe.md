# [Base64](Base64.md)::is_url_safe

## Description

Check if the encoded string respects the URL safe charset.

|Scope     |Parameters               |
|---------:|:------------------------|
|bool (1)  |`const std::string *enc` |

|Scope     |Description                                                |
|---------:|:----------------------------------------------------------|
|bool (1)  |Check if the encoded string respects the URL safe charset. |

## Parameters

|Parameter | Description                                          |
|:---------|:-----------------------------------------------------|
|enc       |Encoded data to Base64. It is always a `std::string`. |

## Return value

**bool**

Returns `true` if it is a URL safe encoding.

Returns `false` in all other cases.

## Examples

```C++
// Check if encoded data is URL safe encoding
#include <iostream>
#include <string>
#include "Base64.hpp"

int main() {
  // Init
  std::string enc, dec;

  // Check URL safe charset
  enc = "QUI+";
  std::cout << "enc: \"" << enc << "\"\n";
  std::cout << "URL safe charset: ";
  if (Base64::is_url_safe(&enc)) std::cout << "YES";
  else std::cout << "NO";
  std::cout << "\n\n";

  // Check URL safe charset
  enc = "QUI-";
  std::cout << "enc: \"" << enc << "\"\n";
  std::cout << "URL safe charset: ";
  if (Base64::is_url_safe(&enc)) std::cout << "YES";
  else std::cout << "NO";
  std::cout << std::endl;

  return 0;
}
```

Output

```
enc: "QUI+"
URL safe charset: NO

enc: "QUI-"
URL safe charset: YES
```
