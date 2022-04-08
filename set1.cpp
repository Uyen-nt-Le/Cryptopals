#include <iostream>
#include <string>
#include <queue>
#include <fstream>

#include "conversion.h"
#include "utilities.h"

void challenge1()
{
    std::cout << "-------------------------\n";
    std::cout << "Cryptopals Challenge 1\n";
    std::cout << "-------------------------\n";
    
    std::string hstr = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::string b64str = hex_to_base64(hstr);
    std::cout << b64str << '\n';
    std::cout << '\n';
}

void challenge2()
{
    std::cout << "-------------------------\n";
    std::cout << "Cryptopals Challenge 2\n";
    std::cout << "-------------------------\n";

    std::string hstr1 = "1c0111001f010100061a024b53535009181c";
    std::string hstr2 = "686974207468652062756c6c277320657965";
    std::string hstr3;

    std::queue<unsigned int> qbin1, qbin2, qbin3;
    hexstr_to_qbin(hstr1, qbin1);
    hexstr_to_qbin(hstr2, qbin2);
    xor_qbin(qbin1, qbin2, qbin3);
    hstr3 = qbin_to_hexstr(qbin3);
    std::cout << hstr1 << "\nXOR\n" << hstr2 << "\n=\n"<< hstr3 << '\n';
    std::cout << '\n';
}

void challenge3()
{
    std::cout << "-------------------------\n";
    std::cout << "Cryptopals Challenge 3\n";
    std::cout << "-------------------------\n";

    std::string encoded = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    std::queue<unsigned int> qbin1, qbin2;
    unsigned int cbin[8];
    std::string temp;
    std::string best_str;
    unsigned int best_score = 0;

    hexstr_to_qbin(encoded, qbin1);

    for (unsigned int i = 0; i <= 127; i++)
    {
        empty_bin(cbin, 8);
        empty_qbin(qbin2);
        dec_to_bin(i, cbin, 8);
        repeating_key_xor(qbin1, qbin2, cbin, 8);
        temp = qbin_to_str(qbin2);
        if(is_printable(temp))
        {
            if(str_score(temp) > best_score)
            {
                best_str = temp;
                best_score = str_score(temp);
            }
        }
    }
    std::cout << best_str << '\n';
    std::cout << '\n';
}

void challenge4()
{
    std::cout << "-------------------------\n";
    std::cout << "Cryptopals Challenge 4\n";
    std::cout << "-------------------------\n";

    std::ifstream encrypted_file("challfiles/chall4_encoded.txt");
    std::string encrypted_line = "";
    std::queue<unsigned int> qbin1, qbin2;
    unsigned int cbin[8];
    std::string temp;
    std::string best_str;
    unsigned int best_score = 0;

    while (getline(encrypted_file, encrypted_line))
    {
        empty_qbin(qbin1);
        hexstr_to_qbin(encrypted_line, qbin1);

        for (unsigned int i = 0; i <= 127; i++)
        {
            empty_bin(cbin, 8);
            empty_qbin(qbin2);
            dec_to_bin(i, cbin, 8);
            repeating_key_xor(qbin1, qbin2, cbin, 8);
            temp = qbin_to_str(qbin2);
            if(is_printable(temp))
            {
                if(str_score(temp) > best_score)
                {
                    best_str = temp;
                    best_score = str_score(temp);
                }
            }
        }
    }
    std::cout << best_str << '\n';
}

void challenge5()
{
    std::cout << "-------------------------\n";
    std::cout << "Cryptopals Challenge 5\n";
    std::cout << "-------------------------\n";

    std::string text_line = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    std::string encrypt_str = "";

    std::queue<unsigned int> qbin1, qbin2;

    char key[] = "ICE";
    const size_t keylen = sizeof(key)-1;
    unsigned int cbin[keylen*8];
    get_keybin(key, cbin, keylen);

    str_to_qbin(text_line, qbin1);
    repeating_key_xor(qbin1, qbin2, cbin, keylen*8);
    encrypt_str = qbin_to_hexstr(qbin2);
    for (size_t i = 0; i < encrypt_str.length(); i++)
    {
        std::cout << encrypt_str[i];
        if(i==74) {std::cout << '\n';}
    }
    std::cout << '\n';
}

void challenge6()
{
    std::cout << "-------------------------\n";
    std::cout << "Cryptopals Challenge 6\n";
    std::cout << "-------------------------\n";

    std::string str1 = "this is a test";
    std::string str2 = "wokka wokka!!!";
    std::queue<unsigned int> qbin1, qbin2;
    str_to_qbin(str1, qbin1);
    str_to_qbin(str2, qbin2);
}