#include <iostream>  // The input/output library in C++
#include <string>  // Library that allows us to use the string data type
#include <vector>  // A dynamic array container from the Standard Template Library to store "Common passwords"
#include <fstream>  // File handling library
#include <cmath>  // Mathematical functon library to calculates password entropy
#include <cctype> // Charactor testing library (islower, isupper....)

using namespace std;  // Allows us to use standard functions without writing std::

bool checkDictionary(string password)
{

    ifstream file ("common_passwords.txt");
    string word;

    while (file >> word)  // Read each word from the file until the file ends
    {
        if (password == word)
        {
            return true;
        }
    }
    return false;
}

double calculateEntropy(string password)
{
    int charset = 0;  // This variable represents the number of possible characters
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

    for(char c : password)
    {
        if (islower(c)) hasLower = true;
        else if (isupper(c)) hasUpper = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }

    // Estimating the number of possible characters that could appear in the password. for calculating Entropy
    if (hasLower) charset += 26;
    if (hasUpper) charset += 26;
    if (hasDigit) charset += 10;
    if (hasSpecial) charset += 32;
    /*
    Entropy ~ how many possible guesses an attacker must try. 
    Low entropy → easy to guess
    High entropy → very difficult to guess
    */
    return password.length() * log2(charset);
}

int main()
{
    string password;

    cout << "=============================\n";
    cout << "  PASSWORD STRENGTH CHECKER\n";
    cout << "=============================\n\n";

    cout << "Enter password : ";
    getline (cin, password);

    int score = 0;
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char c : password)
    {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else hasSpecial = true;
    }

    if (password.length() >= 8) score += 2;
    if (password.length() >= 12) score += 2;
    if (hasUpper) score += 2;
    if (hasLower) score += 1;
    if (hasDigit) score += 2;
    if (hasSpecial) score += 1;

    bool dictionaryMatch = checkDictionary(password);
    double entropy = calculateEntropy(password);

    cout << "\nPassword Score: " << score << "/10\n";
    cout << "Entropy: " << entropy << " bits\n";
    cout << "\nStrength: ";

    if(dictionaryMatch)
    {
        cout << "VERY WEAK (Common Password)\n";
    }
    else if(score <= 3)
    {
        cout << "WEAK\n";
    }
    else if(score <= 6)
    {
        cout << "MEDIUM\n";
    }
    else
    {
        cout << "STRONG\n";
    }

    cout << "\nSuggestions:\n";

    if(password.length() < 8)
        cout << "~ Use at least 8 characters\n";

    if(!hasUpper)
        cout << "~ Add uppercase letters\n";

    if(!hasLower)
        cout << "~ Add lowercase letters\n";

    if(!hasDigit)
        cout << "~ Add numbers\n";

    if(!hasSpecial)
        cout << "~ Add special characters\n";

    if(dictionaryMatch)
        cout << "~ Avoid common passwords to protect ur accounts\n";

    cout << endl;
    return 0;
}