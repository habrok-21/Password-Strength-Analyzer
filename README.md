Password Strength Analyzer (C++)

Hello everyone this project is a Password Strength Analyzer built in C++.
It evaluates a password based on multiple security criteria and provides a strength score along with entropy calculation.

Features :
~ Checks password length and rewards longer passwords
~ Detects uppercase, lowercase, numeric, and special characters
~ Checks against a dictionary of common passwords
~ Calculates password entropy to estimate unpredictability
~ Provides improvement suggestions for weak passwords

How It Works :
1) User enters a password.
2) The program evaluates character types and length.
3) It checks the password against common weak passwords.
4) Calculates entropy using ~ Entropy = Password Length × log2(Character Set Size)
5) Generates a score (0–10) and displays strength level (Weak, Medium, Strong).

Technologies Used :
~ it is purely build with he help of C++ core logic
~ Standard libraries like <iostream>, <string>, <vector>, <fstream>, <cmath>, <cctype>

How to RUn it :
g++ password_analyzer.cpp -o analyzer
.\password_analyzer
