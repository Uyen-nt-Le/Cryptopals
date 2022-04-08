#include <iostream>
#include <cmath>
#include <string>
#include <queue>

#include "utilities.h"

unsigned int hex_to_dec(char hex)
{
    unsigned int dec = 0;
    if (isdigit(hex)) {dec = hex - '0';} 
    else if (isalpha(hex)) {dec = tolower(hex) - 'a' + 10;}
    // else { std::cout << hex << " = HEX TO DEC ERROR\n"; }
    return dec;
}

unsigned int * dec_to_bin(unsigned int dec, unsigned int bin[], unsigned int bits)
{
    unsigned int n =  bits-1;
    for (size_t i = 0; i < bits; i++)
    {
        if (dec-pow(2,n) >= 0)
        {
            bin[i] = 1;
            dec -= pow(2,n);
        }
        n--;
    }
    if (dec != 0) { std::cout << "DEC TO BIN ERROR\n"; }
    return bin;
}

unsigned int bin_to_dec(unsigned int bin[], unsigned int bits)
{
    unsigned int dec = 0;
    unsigned int n = bits-1;
    for (size_t i = 0; i < bits; i++)
    {
        if (bin[i] == 1) {dec += pow(2,n);}
        n--;
    }
    return dec;
}

void hexstr_to_qbin(std::string hex, std::queue<unsigned int> &bin)
{
    unsigned int temp_bin[4];
    unsigned int temp_dec = 0;
    size_t len = hex.length();

    for (size_t i = 0; i < len; i++)
    {
        if(!isalpha(hex[i]) && !isdigit(hex[i])) {continue;}
        empty_bin(temp_bin, 4);
        temp_dec = hex_to_dec(hex[i]);
        dec_to_bin(temp_dec, temp_bin, 4);
        fill_qbin(bin, temp_bin, 4);
    }
}

void str_to_qbin(std::string str1, std::queue<unsigned int> &bin)
{
    unsigned int temp_bin[8];
    size_t len = str1.length();
    unsigned int temp_dec = 0;

    for (size_t i = 0; i < len; i++)
    {
        empty_bin(temp_bin, 8);
        dec_to_bin(str1[i], temp_bin, 8);
        fill_qbin(bin, temp_bin, 8);
    }
}

char dec_to_base64(unsigned int dec)
{
    char temp = 0;
    if (dec < 26) {temp = dec + 'A';} 
    else if (dec < 52) {temp = dec + 'a' - 26;}
    else if (dec < 62) {temp = dec + '0' - 52;}
    else if (dec == 62) {temp = '+';}
    else if (dec == 63) {temp = '/';}
    else {std::cout << "DEC TO BASE64 ERROR\n";}
    return temp;
}

char dec_to_hex(unsigned int dec)
{
    char temp = 0;
    if (dec < 10) {temp = dec + '0';}
    else if (dec <= 15) {temp = dec - 10 + 'a';}
    else {std::cout << "DEC TO HEX ERROR\n";}
    return temp;
}

std::string qbin_to_base64(std::queue<unsigned int> qbin)
{
    unsigned int temp_bin[6];
    unsigned int temp_dec = 0;
    std::string temp_str = "";
    while (!qbin.empty())
    {
        empty_bin(temp_bin, 6);
        fill_bin(temp_bin, qbin, 6);
        temp_dec = bin_to_dec(temp_bin, 6);
        temp_str += dec_to_base64(temp_dec);
    }
    return temp_str;
}

std::string qbin_to_hexstr(std::queue<unsigned int> qbin)
{
    unsigned int temp_bin[4];
    unsigned int temp_dec = 0;
    std::string temp_str = "";
    while (!qbin.empty())
    {
        empty_bin(temp_bin, 4);
        fill_bin(temp_bin, qbin, 4);
        temp_dec = bin_to_dec(temp_bin, 4);
        temp_str += dec_to_hex(temp_dec);
    }
    return temp_str;
}

std::string qbin_to_str(std::queue<unsigned int> qbin)
{
    unsigned int temp_bin[8];
    char temp_c = 0;
    std::string temp_str = "";
    while (!qbin.empty())
    {
        empty_bin(temp_bin, 8);
        fill_bin(temp_bin, qbin, 8);
        temp_c = bin_to_dec(temp_bin, 8);
        temp_str += temp_c;
    }
    return temp_str;
}

std::string hex_to_base64(std::string hex)
{
    std::queue<unsigned int> qbin;
    std::string base64 = "";
    hexstr_to_qbin(hex, qbin);
    base64 = qbin_to_base64(qbin);
    return base64;
}

