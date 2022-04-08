#ifndef UTILITIES
#define UTILITIES

#include <queue>

void fill_qbin(std::queue<unsigned int> &qbin, unsigned int bin[], unsigned int bits);
unsigned int * fill_bin(unsigned int bin[], std::queue<unsigned int> &qbin, int bits);

unsigned int * append_bin(unsigned int bin1[], unsigned int &bin1_i, unsigned int bin2[], int bits);

unsigned int * empty_bin(unsigned int bin[], unsigned int bits);
void empty_qbin(std::queue<unsigned int> &qbin);

void copy_qbin(std::queue<unsigned int> qbin1, std::queue<unsigned int> &qbin2);

void print_bin(unsigned int bin[], int bits);
void print_qbin(std::queue<unsigned int> qbin, unsigned int bits);

unsigned int xor_(unsigned int bit1, unsigned int bit2);
void xor_qbin(std::queue<unsigned int> qbin1, std::queue<unsigned int> qbin2, std::queue<unsigned int> &qbin3);

unsigned int str_score(std::string str1);
bool is_printable(std::string str1);

void repeating_key_xor(std::queue<unsigned int> qbin1, std::queue<unsigned int> &qbin2, unsigned int cbin[], unsigned int cbits);

unsigned int * get_keybin(char key[], unsigned int cbin[], const size_t keylen);

#endif