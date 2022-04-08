#ifndef CONVERSION
#define CONVERSION

#include <string>
#include <queue>

unsigned int hex_to_dec(char hex);
unsigned int bin_to_dec(unsigned int bin[], unsigned int bits);

unsigned int * dec_to_bin(unsigned int dec, unsigned int bin[], unsigned int bits);

char dec_to_base64(unsigned int dec);
char dec_to_hex(unsigned int dec);

void hexstr_to_qbin(std::string hex, std::queue<unsigned int> &bin);
void str_to_qbin(std::string str1, std::queue<unsigned int> &bin);

std::string qbin_to_base64(std::queue<unsigned int> qbin);
std::string qbin_to_hexstr(std::queue<unsigned int> qbin);
std::string qbin_to_str(std::queue<unsigned int> qbin);

std::string hex_to_base64(std::string hex);




#endif