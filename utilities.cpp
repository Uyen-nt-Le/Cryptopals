#include <iostream>
#include <queue>
#include <map>

#include "conversion.h"

void fill_qbin(std::queue<unsigned int> &qbin, unsigned int bin[], unsigned int bits)
{
    for (size_t i = 0; i < bits; i++) {qbin.push(bin[i]);}
}

unsigned int * fill_bin(unsigned int bin[], std::queue<unsigned int> &qbin, int bits)
{
    for (size_t i = 0; i < bits; i++)
    {
        bin[i] = qbin.front();
        qbin.pop();
    }
    return bin;
}

unsigned int * append_bin(unsigned int bin1[], unsigned int &bin1_i, unsigned int bin2[], int bits)
{
    for (size_t i = 0; i < bits; i++)
    {
        bin1[bin1_i] = bin2[i];
        bin1_i++;
    }
    return bin1;
}

unsigned int * empty_bin(unsigned int bin[], unsigned int bits)
{
    for (size_t i = 0; i < bits; i++) {bin[i] = 0;}
    return bin;
}

void empty_qbin(std::queue<unsigned int> &qbin)
{
    while(!qbin.empty()) {qbin.pop();}
}

void copy_qbin(std::queue<unsigned int> qbin1, std::queue<unsigned int> &qbin2)
{
    while (!qbin1.empty())
    {
        qbin2.push(qbin1.front());
        qbin1.pop();
    }
}

void print_bin(unsigned int bin[], int bits)
{
    for (size_t i = 0; i < bits; i++) {std::cout << bin[i];}
    std::cout << " ";
}

void print_qbin(std::queue<unsigned int> qbin, unsigned int bits)
{
    unsigned int count = 0;
    while (!qbin.empty())
    {
        std::cout << qbin.front();
        qbin.pop();
        count++;
        if (count == bits) 
        { 
            std::cout << " "; 
            count = 0;
        }
    }
}

unsigned int xor_(unsigned int bit1, unsigned int bit2)
{
    if (bit1 != bit2) {return 1;}
    else {return 0;}
}

void xor_qbin(std::queue<unsigned int> qbin1, std::queue<unsigned int> qbin2, std::queue<unsigned int> &qbin3)
{
    if(qbin1.size() != qbin2.size()) {std::cout << "BINARY QUEUE SIZES ARE UNEQUAL\n";}
    
    while (!qbin1.empty() || !qbin2.empty())
    {
        qbin3.push(xor_(qbin1.front(), qbin2.front()));
        qbin1.pop();
        qbin2.pop();
    }
}

unsigned int str_score(std::string str1)
{
    unsigned int score = 0;
    for (size_t i = 0; i < str1.length(); i++)
    {
        if (isalpha(str1[i])) {score += 4;}
        else if (isspace(str1[i])) {score += 3;}
        else if(isdigit(str1[i])) {score += 2;}
        else {score += 1;}
    }
    return score;
}

bool is_printable(std::string str1)
{
    // Unprintable characters: 1-6, 11, 12, 14-31, 127
    for (size_t i = 0; i < str1.length(); i++)
    {
        if ((1 <= str1[i] && str1[i] <= 6) || (str1[i] == 11) || (str1[i] == 12) || (14 <= str1[i] && str1[i] <= 31) || (str1[i] == 127))
        {
            return false;
        }
    }
    return true;
}

void repeating_key_xor(std::queue<unsigned int> qbin1, std::queue<unsigned int> &qbin2, unsigned int cbin[], unsigned int cbits)
{
    size_t i = 0;
    while (!qbin1.empty())
    {
        qbin2.push(xor_(qbin1.front(), cbin[i]));
        qbin1.pop();
        i++;
        if(i==cbits) {i=0;}
    }
}

unsigned int * get_keybin(char key[], unsigned int cbin[], const size_t keylen)
{
    unsigned int tempbin[8];
    unsigned int cbin_i = 0;
    for (size_t i = 0; i < keylen; i++)
    {
        empty_bin(tempbin, 8);
        dec_to_bin(key[i], tempbin, 8);
        append_bin(cbin, cbin_i, tempbin, 8);
    }
    return cbin;
}

unsigned int hamming_dist(std::queue<unsigned int> qbin1, std::queue<unsigned int> qbin2)
{
    if(qbin1.size() != qbin2.size()) {std::cout << "BINARY QUEUE SIZES ARE UNEQUAL\n";}
    
    unsigned int count = 0;
    while (!qbin1.empty() || !qbin2.empty())
    {
        if(xor_(qbin1.front(), qbin2.front()) == 1) {count++;}
        qbin1.pop();
        qbin2.pop();
    }
    return count;
    //CHECK IF THIS WORKS RIGHT
}