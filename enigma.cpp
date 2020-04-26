#include <string>
#include <iostream>
#include <vector>
#include<boost/algorithm/string.hpp>
#include <algorithm>

using namespace std;

vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

vector<char> rightWheelStart = {'3', '5', 'H', 'E', 'F', 'G', 'D', 'Q', '8', 'M', '2', 'K', 'L', 'J', 'N', 'S', 'U', 'W', 'O', 'V', 'R', 'X', 'Z', 'C', 'I', '9', 'T', '7', 'B', 'P', 'A', '0', '1', 'Y', '6', '4'};

vector<char> middleWheelStart = {'0', 'L', 'X', '1', '2', '8', 'H', 'B', '3', 'N', 'R', 'O', 'K', 'D', 'T', '7', 'C', '6', 'P', 'I', 'V', 'J', '4', 'A', 'U', 'W', 'M', 'E', '9', '5', 'Q', 'S', 'Z', 'G', 'Y', 'F'};

vector<char> leftWheelStart = {'2', 'Y', 'Z', '0', '1', 'A', 'W', 'I', 'P', 'K', 'S', 'N', '3', 'T', 'E', 'R', 'M', 'U', 'C', '5', 'V', '6', 'X', '7', 'F', 'Q', 'O', 'L', '4', '8', 'G', 'D', '9', 'B', 'J', 'H'};



vector <char> rotateWheel(vector<char> wheel){
        char last = wheel[wheel.size() - 1];
        wheel.pop_back();
        wheel.insert(wheel.begin(), last);

        return wheel;
}

string encrypt(string msg, vector<char> plugboard, vector<char> reflector){
        vector<char> rightWheel(rightWheelStart);
        vector<char> middleWheel(middleWheelStart);
        vector<char> leftWheel(leftWheelStart);

        string ciphertext = "";
        char current;
        int pos;
        vector<char>::iterator it;

        vector<char> msgChar(msg.begin(), msg.end());


        for(int i = 0; i < msgChar.size(); i++){
                //Plugboard
                it = find(alphabet.begin(), alphabet.end(), msgChar[i]);

                //Invalid character entered, exit function
                if(it == alphabet.end()){
                        return "";
                }

                pos = distance(alphabet.begin(), it);
                current = plugboard[pos];

                //Right wheel
                it = find(alphabet.begin(), alphabet.end(), current);
                pos = distance(alphabet.begin(), it);
                current = rightWheel[pos];

                //Middle Wheel
                it = find(alphabet.begin(), alphabet.end(), current);
                pos = distance(alphabet.begin(), it);
                current = middleWheel[pos];

                //Left Wheel
                it = find(alphabet.begin(), alphabet.end(), current);
                pos = distance(alphabet.begin(), it);
                current = leftWheel[pos];

                //Reflector
                it = find(alphabet.begin(), alphabet.end(), current);
                pos = distance(alphabet.begin(), it);
                current = reflector[pos];

                //Left Wheel
                it = find(leftWheel.begin(), leftWheel.end(), current);
                pos = distance(leftWheel.begin(), it);
                current = alphabet[pos];

                //Middle Wheel
                it = find(middleWheel.begin(), middleWheel.end(), current);
                pos = distance(middleWheel.begin(), it);
                current = alphabet[pos];

                //Right Wheel
                it = find(rightWheel.begin(), rightWheel.end(), current);
                pos = distance(rightWheel.begin(), it);
                current = alphabet[pos];

                //Plugboard
                it = find(plugboard.begin(), plugboard.end(), current);
                pos = distance(plugboard.begin(), it);
                current = alphabet[pos];

                ciphertext += current;

                //Rotate wheels
                rightWheel = rotateWheel(rightWheel);

                if(ciphertext.length() % 7 == 0){
                        middleWheel = rotateWheel(middleWheel);
                }

                if(ciphertext.length() % 5 == 0){
                        leftWheel = rotateWheel(leftWheel);
                }
        }

        return ciphertext;
}

string decrypt(string msg, vector<char> plugboard, vector<char> reflector){
        vector<char> rightWheel(rightWheelStart);
        vector<char> middleWheel(middleWheelStart);
        vector<char> leftWheel(leftWheelStart);

        string ciphertext = "";
        char current;
        int pos;
        vector<char>::iterator it;

        vector<char> msgChar(msg.begin(), msg.end());

        for(int i = 0; i < msgChar.size(); i++){
                //Plugboard
                it = find(alphabet.begin(), alphabet.end(), msgChar[i]);

                //Invalid character entered, exit function
                if(it == alphabet.end()){
                        return "";
                }

                pos = distance(alphabet.begin(), it);
                current = plugboard[pos];

                //Right wheel
                it = find(alphabet.begin(), alphabet.end(), current);
                pos = distance(alphabet.begin(), it);
                current = rightWheel[pos];

                //Middle Wheel
                it = find(alphabet.begin(), alphabet.end(), current);
                pos = distance(alphabet.begin(), it);
                current = middleWheel[pos];

                //Left Wheel
                it = find(alphabet.begin(), alphabet.end(), current);
                pos = distance(alphabet.begin(), it);
                current = leftWheel[pos];

                //Reflector
                it = find(reflector.begin(), reflector.end(), current);
                pos = distance(reflector.begin(), it);
                current = alphabet[pos];

                //Left Wheel
                it = find(leftWheel.begin(), leftWheel.end(), current);
                pos = distance(leftWheel.begin(), it);
                current = alphabet[pos];

                //Middle Wheel
                it = find(middleWheel.begin(), middleWheel.end(), current);
                pos = distance(middleWheel.begin(), it);
                current = alphabet[pos];

                //Right Wheel
                it = find(rightWheel.begin(), rightWheel.end(), current);
                pos = distance(rightWheel.begin(), it);
                current = alphabet[pos];

                //Plugboard
                it = find(plugboard.begin(), plugboard.end(), current);
                pos = distance(plugboard.begin(), it);
                current = alphabet[pos];

                ciphertext += current;

                //Rotate wheels
                rightWheel = rotateWheel(rightWheel);

                if(ciphertext.length() % 7 == 0){
                        middleWheel = rotateWheel(middleWheel);
                }

                if(ciphertext.length() % 5 == 0){
                        leftWheel = rotateWheel(leftWheel);
                }
        }

        return ciphertext;
}

int main(){
        string userIn = "0";
        string msg;

        cout << "********************" << "\n";
        cout << "***Enigma Machine***" << "\n";
        cout << "********************" << "\n";

        cout << "Enter the plugboard key (no spaces): ";
        string plugboardStr;
        cin >> plugboardStr;

        if(plugboardStr.length() != 36){
                cout << "Incorrect plugboard configuration" << "\n";
                return 0;
        }

        boost::to_upper(plugboardStr);
        vector<char> plugboard(plugboardStr.begin(), plugboardStr.end());

        cout << "Enter the reflector key (no spaces): ";
        string reflectorStr;
        cin >> reflectorStr;

        if(reflectorStr.length() != 36){
                cout << "Incorrect reflector configuration" << "\n";
                return 0;
        }

        boost::to_upper(reflectorStr);
        vector<char> reflector(reflectorStr.begin(), reflectorStr.end());

        while(userIn.compare("3") != 0){
                cout << "Enter one of the following numbered options: " << "\n";
                cout << "1. Encrypt Message" << "\n";
                cout << "2. Decrypt Message" << "\n";
                cout << "3. Exit" << "\n";

                cin >> userIn;

                if(userIn.compare("1") == 0){
                        cout << "Enter message: ";
                        cin >> msg;
                        boost::to_upper(msg);
                        string ciphermsg = encrypt(msg, plugboard, reflector);

                        if(ciphermsg.compare("") != 0){
                                cout << ciphermsg << "\n";
                        }
                        else{
                                cout << "Invalid message" << "\n";
                        }
                }
                else if(userIn.compare("2") == 0){
                        cout << "Enter message: ";
                        cin >> msg;
                        boost::to_upper(msg);
                        string origmsg = decrypt(msg, plugboard, reflector);

                        if(origmsg.compare("") != 0){
                                cout << origmsg << "\n";
                        }
                        else{
                                cout << "Invalid message" << "\n";
                        }
                }
                else if(userIn.compare("3") == 0){
                        cout << "Goodbye!" << "\n";
                }
                else{
                        cout << "Invalid input, try again." << "\n";
                }
        }
}