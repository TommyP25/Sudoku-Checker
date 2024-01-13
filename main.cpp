#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip> 

// Name: Thompson Pham
// NetID: TXP210003

using namespace std;

// Function which looks at each row to see if they contain 1-9 w/o a duplicate
string checkRow(char sudoIn[]){
    // Set base counter for each number 1-9 used in a row
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0,
    num8 = 0, num9 = 0, space = 0;
    char *ptr = sudoIn;
    char rowD[9] = "";
    // For loop to check all 9 rows
    for(int i = 0; i < 9; i++){
        // For loop to count how many times a number is used in a row
        for(int j = 0; j < 9; j++){
            if(*ptr == '1'){
                num1++;
            }
            if(*ptr == '2'){
                num2++;
            }
            if(*ptr == '3'){
                num3++;
            }
            if(*ptr == '4'){
                num4++;
            }
            if(*ptr == '5'){
                num5++;
            }
            if(*ptr == '6'){
                num6++;
            }
            if(*ptr == '7'){
                num7++;
            }
            if(*ptr == '8'){
                num8++;
            }
            if(*ptr == '9'){
                num9++;
            }
            if(*ptr == ' '){
                space++;
            }
            // Pointer moves through the row
            ptr = ptr + 1;
        }
        // If a number is used more than once in a row, cats the number to 
        // string rowD
        if(num1 > 1){
                strcat(rowD, "1");
            }else if(num2 > 1){
                strcat(rowD, "2");
            }else if(num3 > 1){
                strcat(rowD, "3");
            }else if(num4 > 1){
                strcat(rowD, "4");
            }else if(num5 > 1){
                strcat(rowD, "5");
            }else if(num6 > 1){
                strcat(rowD, "6");
            }else if(num7 > 1){
                strcat(rowD, "7");
            }else if(num8 > 1){
                strcat(rowD, "8");
            }else if(num9 > 1){
                strcat(rowD, "9");
            }
        // If a number isn't used more than once in a row, it will determine
        // if the row is solved or valid
        // A valid row will contain spaces, while a solved row contains no spaces
        if(num1 <= 1 && num2 <= 1 && num3 <= 1 && num4 <= 1 && num5 <= 1 &&
        num6 <= 1 && num7 <= 1 && num8 <= 1 && num9 <= 1){
            if(space > 1){
                strcat(rowD, "v");
            }else{
                strcat(rowD, "s");
            }
        }
        num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0,
        num8 = 0, num9 = 0, space = 0;
    }
    /* Returns string rowD which tells the program if a row is solved, valid, or
    contains multiples.
    The position the character is on the string represents the column, while the
    character represents if its valid, solved, or has multiples of a certain number from 1-9
    (Ex: ssss5ss7v
    Column 1, 2, 3, 4, 6, 7 are solved
    Column 5 is invalid with multiples of 5
    Column 8 is invalid with multiples of 7
    Column 9 is valid
    )
    */ 
    return rowD;
}

// Function which looks at each column to see if they contain 1-9 w/o a duplicate
string checkCol(char sudoIn[]){
    // Set base counter for each number 1-9 used in a column
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0,
    num8 = 0, num9 = 0, space = 0;
    char *ptr = sudoIn;
    char colD[9] = "";
    // For loop to check all 9 columns
    for(int i = 0; i < 9; i++){
        // For loop to count how many times a number is used in a column
        for(int j = 0; j < 9; j++){
            if(*ptr == '1'){
                num1++;
            }
            if(*ptr == '2'){
                num2++;
            }
            if(*ptr == '3'){
                num3++;
            }
            if(*ptr == '4'){
                num4++;
            }
            if(*ptr == '5'){
                num5++;
            }
            if(*ptr == '6'){
                num6++;
            }
            if(*ptr == '7'){
                num7++;
            }
            if(*ptr == '8'){
                num8++;
            }
            if(*ptr == '9'){
                num9++;
            }
            if(*ptr == ' '){
                space++;
            }
            // Pointer moves through column
            ptr = ptr + 9;
        }
        // If a number is used more than once in a column, cats the number to 
        // string colD
        if(num1 > 1){
                strcat(colD, "1");
            }else if(num2 > 1){
                strcat(colD, "2");
            }else if(num3 > 1){
                strcat(colD, "3");
            }else if(num4 > 1){
                strcat(colD, "4");
            }else if(num5 > 1){
                strcat(colD, "5");
            }else if(num6 > 1){
                strcat(colD, "6");
            }else if(num7 > 1){
                strcat(colD, "7");
            }else if(num8 > 1){
                strcat(colD, "8");
            }else if(num9 > 1){
                strcat(colD, "9");
            }
        // If a number isn't used more than once in a column, it will determine
        // if the column is solved or valid
        // A valid column will contain spaces, while a solved column contains no spaces
        if(num1 <= 1 && num2 <= 1 && num3 <= 1 && num4 <= 1 && num5 <= 1 &&
        num6 <= 1 && num7 <= 1 && num8 <= 1 && num9 <= 1){
            if(space > 1){
                strcat(colD, "v");
            }else{
                strcat(colD, "s");
            }
        }
        // Pointer moves back to the start of the current column
        // and then moves over to next column
        ptr = ptr - 81;
        ptr = ptr + 1;
        // Resets counter to prepare for next row
        num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0,
        num8 = 0, num9 = 0, space = 0;
    }
    // Returns string colD which tells the program if a column is solved, valid, or
    // contains multiples.
    return colD;
}

// Function which looks at each sector to see if they contain 1-9 w/o a duplicate
string checkGrid(char sudoIn[]){
    // Set base counter for each number 1-9 used in a column
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0,
    num8 = 0, num9 = 0, space = 0;
    char *ptr = sudoIn;
    char gridD[9] = "";
    // 2 For loops to check a nine sectors
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            // 2 For loops to count the 3x3 grid of how many times a number is used
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    if(*ptr == '1'){
                        num1++;
                    }
                    if(*ptr == '2'){
                        num2++;
                    }
                    if(*ptr == '3'){
                        num3++;
                    }
                    if(*ptr == '4'){
                        num4++;
                    }
                    if(*ptr == '5'){
                        num5++;
                    }
                    if(*ptr == '6'){
                        num6++;
                    }
                    if(*ptr == '7'){
                        num7++;
                    }
                    if(*ptr == '8'){
                        num8++;
                    }
                    if(*ptr == '9'){
                        num9++;
                    }
                    if(*ptr == ' '){
                        space++;
                    }
                    ptr = ptr + 1;
                }
                ptr = ptr + 6;
            }
        // If a number is used more than once in a sector, cats the number to 
        // string colD
        if(num1 > 1){
                strcat(gridD, "1");
            }else if(num2 > 1){
                strcat(gridD, "2");
            }else if(num3 > 1){
                strcat(gridD, "3");
            }else if(num4 > 1){
                strcat(gridD, "4");
            }else if(num5 > 1){
                strcat(gridD, "5");
            }else if(num6 > 1){
                strcat(gridD, "6");
            }else if(num7 > 1){
                strcat(gridD, "7");
            }else if(num8 > 1){
                strcat(gridD, "8");
            }else if(num9 > 1){
                strcat(gridD, "9");
            }
        // If a number isn't used more than once in a sector, it will determine
        // if the sector is solved or valid
        // A valid sector will contain spaces, while a solved sector contains no spaces
        if(num1 <= 1 && num2 <= 1 && num3 <= 1 && num4 <= 1 && num5 <= 1 &&
        num6 <= 1 && num7 <= 1 && num8 <= 1 && num9 <= 1){
            if(space > 1){
                strcat(gridD, "v");
            }else{
                strcat(gridD, "s");
            }
        }
        // Pointer goes back to the beginning of the current 3x3 gridD,
        // then moves over to the next grid
        ptr = ptr - 27;
        ptr = ptr + 3;
        // Resets counter to prepare for next sector
        num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0,
        num8 = 0, num9 = 0, space = 0;
        }
        ptr = ptr + 18;
    }
    // Returns string gridD which tells the program if a sector is solved, valid, or
    // contains multiples.
    return gridD;
}


int main()
{   
    // Gets files name from user
    string database;
    cout << "Input File Name: ";
    cin >> database;
    ifstream infile(database, ios::binary);
    string line;
    // Determines if the file is unable to be opened
    if(!infile){
        cout << "Unable to open file" << endl;
        infile.close();
        return 0;
    }
    
    string puzzleCode;
    int lineCount = 1;
    int SIZE = 81;
    char *ptr = new char[SIZE];
    // Reads through file containing puzzle
    while(getline(infile, line)){
        // If statement to reset line count, if program sees that there is another
        // puzzle
        if(lineCount == 12){
            lineCount = 1;
        }
        // If statement to store the puzzle code/name
        if(lineCount == 1){
            puzzleCode = line;
        }
        // Stores puzzle into array to be checked
        if(lineCount > 1){
            strcat(ptr, line.c_str());
        }
        // After storing one puzzle into an array, the program calls functions from
        // above and prints out the results for the user
        if(lineCount == 10){
            string checked = checkRow(ptr);
            bool valid = true;
            // Calls checkRow function and returns a string, from the string
            // we see which row has multiples of a number.
            // And print it out for the user
            for(int i = 0; i < 9; i++){
                if(checked[i] == '1'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  row " << i + 1 << " has multiple 1s" << endl;
                    valid = false;
                }
                if(checked[i] == '2'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  row " << i + 1 << " has multiple 2s" << endl;
                    valid = false;
                }
                if(checked[i] == '3'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  row " << i + 1 << " has multiple 3s" << endl;
                    valid = false;
                }
                if(checked[i] == '4'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  row " << i + 1 << " has multiple 4s" << endl;
                    valid = false;
                }
                if(checked[i] == '5'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  row " << i + 1 << " has multiple 5s" << endl;
                    valid = false;
                }
                if(checked[i] == '6'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  row " << i + 1 << " has multiple 6s" << endl;
                    valid = false;
                }
                if(checked[i] == '7'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  row " << i + 1 << " has multiple 7s" << endl;
                    valid = false;
                }
                if(checked[i] == '8'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  row " << i + 1 << " has multiple 8s" << endl;
                    valid = false;
                }
                if(checked[i] == '9'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  row " << i + 1 << " has multiple 9s" << endl;
                    valid = false;
                }
            }
            // Calls checkCol function and returns a string, from the string
            // we see which column has multiples of a number
            // And print it out for the user
            checked = checkCol(ptr);
            for(int i = 0; i < 9; i++){
                if(checked[i] == '1'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  column " << i + 1 << " has multiple 1s" << endl;
                    valid = false;
                }
                if(checked[i] == '2'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  column " << i + 1 << " has multiple 2s" << endl;
                    valid = false;
                }
                if(checked[i] == '3'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  column " << i + 1 << " has multiple 3s" << endl;
                    valid = false;
                }
                if(checked[i] == '4'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  column " << i + 1 << " has multiple 4s" << endl;
                    valid = false;
                }
                if(checked[i] == '5'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  column " << i + 1 << " has multiple 5s" << endl;
                    valid = false;
                }
                if(checked[i] == '6'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  column " << i + 1 << " has multiple 6s" << endl;
                    valid = false;
                }
                if(checked[i] == '7'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  column " << i + 1 << " has multiple 7s" << endl;
                    valid = false;
                }
                if(checked[i] == '8'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  column " << i + 1 << " has multiple 8s" << endl;
                    valid = false;
                }
                if(checked[i] == '9'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  column " << i + 1 << " has multiple 9s" << endl;
                    valid = false;
                }
            }
            // Calls checkGrid function and returns a string, from the string
            // we see which sector has multiples of a number
            // And print it out for the user
            checked = checkGrid(ptr);
            string sector[9] = {"upper left", "upper middle", "upper right",
                    "left", "middle", "right", "lower left", "lower middle",
                    "lower right"};
            string *ptrSec = sector;
            for(int i = 0; i < 9; i++){
                if(checked[i] == '1'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  " << *ptrSec << " has multiple 1s" << endl;
                    valid = false;
                }
                if(checked[i] == '2'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  " << *ptrSec << " has multiple 2s" << endl;
                    valid = false;
                }
                if(checked[i] == '3'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  " << *ptrSec << " has multiple 3s" << endl;
                    valid = false;
                }
                if(checked[i] == '4'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  " << *ptrSec << " has multiple 4s" << endl;
                    valid = false;
                }
                if(checked[i] == '5'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  " << *ptrSec << " has multiple 5s" << endl;
                    valid = false;
                }
                if(checked[i] == '6'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  " << *ptrSec << " has multiple 6s" << endl;
                    valid = false;
                }
                if(checked[i] == '7'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  " << *ptrSec << " has multiple 7s" << endl;
                    valid = false;
                }
                if(checked[i] == '8'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  " << *ptrSec << " has multiple 8s" << endl;
                    valid = false;
                }
                if(checked[i] == '9'){
                    cout << std::setw(9) << left << puzzleCode << "invalid  " << *ptrSec << " has multiple 9s" << endl;
                    valid = false;
                }
                ptrSec = ptrSec + 1;
            }
            // If went through each of the three for loops without flagging the
            // variable "valid" as false, it means the puzzle is either valid
            // or solved
                if(valid){
                    if(!(checked.find_first_of("123456789") != std::string::npos)){
                        // Checks the string to see if there there is a 'v',
                        // if so it can only be valid
                        // Else the puzzle is solved
                        if(checked.find('v') != std::string::npos){
                            cout << std::setw(9) << left << puzzleCode << "valid" << endl;
                        }else if(checked.find('s') != std::string::npos){
                            cout << std::setw(9) << left << puzzleCode << "solved" << endl;
                        }
                    }
                }
        // Empties the current array, in case there is another puzzle
        memset(ptr, 0, 81);
        }
        lineCount++;
    }
    infile.close();
    
    return 0;
}
