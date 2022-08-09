# [Base64](Base64.md)::encode

## Description

Encode Base64 data from `txt` or `bin` and stores in `dec`. Optionally you can give charset and padding.

|Scope       |Parameters                                      |
|-----------:|:-----------------------------------------------|
|string (1)  |`const std::string *txt`<br>`std::string *enc`<br>`const std::string *charset = &Base64::STD_CHARSET`<br>`const bool padding = true`      |
|vector (2)  |`const std::vector<char> *bin`<br>`std::string *enc`<br>`const std::string *charset = &Base64::STD_CHARSET`<br>`const bool padding = true`|

|Scope       |Description                                                                   |
|-----------:|:-----------------------------------------------------------------------------|
|string (1)  |Encode data from `std::string` to Base64.                                     |
|vector (2)  |Encode data from `std::vector<char>` to Base64. Useful to encode binary data. |

## Parameters

|Parameter | Description                                                  |
|:---------|:-------------------------------------------------------------|
|txt       |Text to encode. It is always a `std::string`.                 |
|bin       |Data to encode. It is always a `vector<char>`.                |
|enc       |Encoded data to Base64. It is always a `std::string`.         |
|charset   |The charset to encode data. Default is `Base64::STD_CHARSET`. |
|padding   |Use padding to fill last encoded block. Default is `true`.    |

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
  std::string txt = "AB>";
  std::string enc;

  // Encode
  Base64::encode(&txt, &enc);

  // Print
  std::cout << "enc: [" << enc.size() << "] \"" << enc << "\"" << std::endl;

  return 0;
}
```

Output

```
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

```
enc: [4] "QUJD"
```

### With charset

```C++
// Encode string to Base64 with charset
#include <iostream>
#include <string>
#include "Base64.h"

int main() {
  // Init
  std::string txt, enc;
  txt = "AB>";

  // Encode with standard charset
  Base64::encode(&txt, &enc, &Base64::STD_CHARSET);

  // Print
  std::cout << "txt: \"" << txt << "\"" << std::endl;
  std::cout << "Standard charset: ";
  std::cout << "\"" << enc << "\"" << std::endl;

  // Encode with URL safe charset
  Base64::encode(&txt, &enc, &Base64::URL_CHARSET);

  // Print
  std::cout << "URL safe charset: ";
  std::cout << "\"" << enc << "\"" << std::endl;

  return 0;
}
```

Output

```
txt: "AB>"
Standard charset: "QUI+"
URL safe charset: "QUI-"
```

### With padding

```C++
// Encode string to Base64 with charset
#include <iostream>
#include <string>
#include "Base64.h"

int main() {
  // Init
  std::string txt, enc;
  txt = "A";

  // Encode with padding
  Base64::encode(&txt, &enc, &Base64::STD_CHARSET, true);

  // Print
  std::cout << "txt: \"" << txt << "\"" << std::endl;
  std::cout << "With padding: ";
  std::cout << "\"" << enc << "\"" << std::endl;

  // Encode without padding
  Base64::encode(&txt, &enc, &Base64::STD_CHARSET, false);

  // Print
  std::cout << "Without padding: ";
  std::cout << "\"" << enc << "\"" << std::endl;

  return 0;
}
```

Output

```
txt: "A"
With padding: "QQ=="
Without padding: "QQ"
```
