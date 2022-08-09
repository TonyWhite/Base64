# [Base64](Base64.md)::decode

## Description

Decode Base64 data from `enc` and stores in `dec`. Optionally you can give charset.

|Scope       |Parameters                                                                                                  |
|-----------:|:-----------------------------------------------------------------------------------------------------------|
|string (1)  |`const std::string *enc`<br>`std::string *dec`<br>`const std::string *charset = &Base64::STD_CHARSET`       |
|vector (2)  |`const std::string *enc`<br>`std::vector<char> *dec`<br>`const std::string *charset = &Base64::STD_CHARSET` |

|Scope       |Description                                                                   |
|-----------:|:-----------------------------------------------------------------------------|
|string (1)  |Decode data from Base64 to `std::string`.                                     |
|vector (2)  |Decode data from Base64 to `std::vector<char>`. Useful to decode binary data. |

## Parameters

|Parameter | Description                                                           |
|:---------|:----------------------------------------------------------------------|
|enc       |Base64 encoded data. It is always a `std::string`.                     |
|dec       |Decoded data from Base64. Can be `std::string` or `std::vector<char>`. |
|charset   |The charset to decode data. Default is `Base64::STD_CHARSET`.          |

## Return value

**bool**

Returns `true` if no error occurs.

Returns `false` if the encoded string not respect the given encoding.

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

```
dec: [3] "ABC"
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

```
dec: [3] {65,66,67}
```

### With charset

```C++
// Decode Base64 to string with charset
#include <iostream>
#include <string>
#include "Base64.h"

int main() {
  // Init
  std::string enc, dec;
  bool success;
  enc = "QUI-";

  // Decode with standard charset
  success = Base64::decode(&enc, &dec, &Base64::STD_CHARSET);

  // Print
  std::cout << "enc: \"" << enc << "\"" << std::endl;
  std::cout << "Standard charset: ";
  if (success) std::cout << "true";
  else std::cout << "false";
  std::cout << std::endl;
  std::cout << "dec: \"" << dec << "\"" << "\n\n";

  // Decode with URL safe charset
  success = Base64::decode(&enc, &dec, &Base64::URL_CHARSET);

  // Print
  std::cout << "enc: \"" << enc << "\"" << std::endl;
  std::cout << "URL safe charset: ";
  if (success) std::cout << "true";
  else std::cout << "false";
  std::cout << std::endl;
  std::cout << "dec: \"" << dec << "\"" << std::endl;

  return 0;
}
```

Output

```
enc: "QUI-"
Standard charset: false
dec: "AB"

enc: "QUI-"
URL safe charset: true
dec: "AB>"
```
