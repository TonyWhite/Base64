#include "Base64.h"

////////////
// PUBLIC //
////////////

// Valid charset
const std::string Base64::CHARSET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "abcdefghijklmnopqrstuvwxyz"
                                    "0123456789+/";

// Encode string to Base64
void Base64::encode(const std::string *txt, std::string *enc) {
  Base64::encode(&((*txt)[0]), txt->size(), enc);
}

// Decode string from Base64
void Base64::decode(const std::string *enc, std::string *dec) {
  dec->resize(Base64::predict_dec_len(enc));
  Base64::decode(&((*enc)[0]), enc->size(), &((*dec)[0]));
}

// Encode binary to Base64
void Base64::encode(const std::vector<char> *bin, std::string *enc) {
  Base64::encode(&((*bin)[0]), bin->size(), enc);
}

// Decode binary from Base64
void Base64::decode(const std::string *enc, std::vector<char> *dec) {
  dec->resize(Base64::predict_dec_len(enc));
  Base64::decode(&((*enc)[0]), enc->size(), &((*dec)[0]));
}

/////////////
// PRIVATE //
/////////////

// Check if c is a valid Base64 char
inline bool Base64::isBase64(char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

// Predict encode length
inline long unsigned int Base64::predict_enc_len(const long unsigned int src_len) {
  long unsigned int blk_mod = src_len % 3;
  long unsigned int enc_len = (((src_len - blk_mod) / 3) * 4);
  if (blk_mod > 0) enc_len+=4;
  return enc_len;
}

// Predict decode length
inline long unsigned int Base64::predict_dec_len(const std::string *enc) {
  long unsigned int enc_len = enc->find_last_not_of('=')+1;
  long unsigned int blk_mod = enc_len % 4;
  long unsigned int dec_len = (((enc_len - blk_mod) / 4) * 3);
  if (blk_mod > 0) dec_len+=blk_mod-1;
  return dec_len;
}

// Encode chars to Base64
void Base64::encode(const char *src, const long unsigned int src_len, std::string *enc) {
  // Reserve space
  enc->reserve(Base64::predict_enc_len(src_len));
  
  // Encode a block every 3 bytes
  unsigned short block = 0;
  for (long unsigned int i=0; i<src_len; i++) {
    if (++block == 3) {
      block = 0;
      enc->push_back(Base64::CHARSET[ (src[i-2] >> 2) & 0b111111 ]);
      enc->push_back(Base64::CHARSET[ ((src[i-2] << 4) | (src[i-1] >> 4)) & 0b111111 ]);
      enc->push_back(Base64::CHARSET[ ((src[i-1] << 2) | (src[i] >> 6)) & 0b111111 ]);
      enc->push_back(Base64::CHARSET[ src[i] & 0b111111 ]);
    }
  }
  
  // Encode last incomplete block
  if (block > 0) { // Some bytes left
    enc->push_back(Base64::CHARSET[ (src[src_len-block] >> 2) & 0b111111 ]);
    if (block == 1) { // 2 bytes left
      enc->push_back(Base64::CHARSET[ (src[src_len-block] << 4) & 0b111111 ]);
      enc->push_back('=');
    }
    else { // 1 byte left
      enc->push_back(Base64::CHARSET[ ((src[src_len-block] << 4) | (src[src_len-1] >> 4)) & 0b111111 ]);
      enc->push_back(Base64::CHARSET[ (src[src_len-1] << 2) & 0b111111 ]);
    }
    enc->push_back('=');
  }
}

// Decode chars from Base64
void Base64::decode(const char *enc, const long unsigned int enc_len, char *dec) {
  long unsigned int i;
  char buffer[4];
  unsigned short block = 0;
  long unsigned int dec_len = 0;
  for (i=0; i<enc_len; i++) {
    if (! Base64::isBase64(enc[i])) break;
    buffer[block++] = Base64::CHARSET.find(enc[i]);
    switch (block) {
      case 2:
        dec[dec_len++] = ((buffer[0] & 0b00111111) << 2) | ((buffer[1] & 0b00110000) >> 4);
        break;
      case 3:
        dec[dec_len++] = ((buffer[1] & 0b00001111) << 4) | ((buffer[2] & 0b00111100) >> 2);
        break;
      case 4:
        block = 0;
        dec[dec_len++] = ((buffer[2] & 0b00000011) << 6) | (buffer[3] & 0b00111111);
        break;
    }
  }
}
