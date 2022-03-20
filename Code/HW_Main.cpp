//samuel culp

//This program will read a file line and then put the content on a new line after hitting 80 characters long.
//After it reads the 1st line in the file it will go on the next column 

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;
// Function/Method Declaration - START
//	define function/method declaration signatures between the two markers
string RCCount(string txt, int num){ // function for the column 
    string col1 = "|";
    string col = " |";
    string sid = to_string(num); // takes the number for the row and converts it to string
    string next = "\n";
    char arra[10000] = {""};
    string mi (80, '-');// separates the columns
    string tot;
    long int n;
    char c;
    long int lineCount = 80; 
    txt.insert(0, mi); // inserts this at the start of a new column
    txt.insert(0, col1); // inserts this at the start of a newcolumn
    for (int i = 0; i < txt.length(); i++){ // for loop for the column new line
        c = txt[i];
        arra[i] += c;
        if (i == lineCount){// if the row has hit 80 then starts a new line
            n = i + 1;
            txt.insert(n, next); // inserts a \n
            n = i + 2;
            txt.insert(n, col); // inserts a |
            lineCount += 80; // adds a 80 for the next time the loop starts
        }
    }
    cout << endl;
    tot = arra;
    tot.insert(0, sid);
    return tot; // return the value 
}// Function/Method Declaration - END
// Function/Method Definition - START
//	define function/method declaration signatures between the two markers
int main() {// Variable - START
//	define variables that are global between the two Variable markers
    string txt;
    string txt2;
    ifstream myFile("hwfunwords.txt"); // for the file 
    string tot;
    int col = 1;
    int count = 0;
    int i;// Variable - END

    cout << " |";
    for (int i = 0; i < 9; i++){// this is for the rulers
        cout << i << "         ";
    }
    cout << "\n |";    
   for (int i = 0; count < 80;){ // this is for the rulers 
       cout << i;
       count++;
       i++;
       if (i == 10){// every 10 it restarts at 0  
           i = 0;
       }
   }

    while (getline (myFile, txt2)){ // loop to read a files lines  
       string txt1 = txt2;
       cout << RCCount(txt1, col); // sends to a function
       col++;
    }
    myFile.close();
    return 0;// Function/Method Definition - END
}
