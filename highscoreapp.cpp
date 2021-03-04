#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//function display content of higscore.txt
void displayHighScore(){
    //declared variables
    string content;
    fstream file;
    //open file
    file.open("highscore.txt", ios::out | ios::in);
    //condtion close, if file is open
    if(file.is_open()){
        //loops through file to display result in terminal
        while(getline(file,content)){
            cout << content << '\n';
        }
        //close file
        file.close();
    }else{
        cout <<"Unable to open file";
    }
}

//function accept int as score and write it in a file
void userInput(int score){
    //declare a file variable
    std::ofstream file;
    //open highscore.txt file
    file.open("highscore.txt", std::ios::app);
    //convert int to string
    std:: string str = to_string(score);
    //write a newline
    file<<'\n';
    //save score value in the highscore.txt
    file<<str;
    //close file
    file.close();
}

int main()
{
     //declared variables
        int highscore;
        char yes_no;
        string username;
		string address;

    //execute the program for the first time
    do
    {
        //display content of text file (highscore.txt)
        displayHighScore();
        //prompt user to enter new Highscore as Integer
        cout <<"Please Enter a High Score: ";
        //get the user entered values
        cin >> highscore;
        cout << "Please Enter Username: ";
        cin >> username;
        //function appends user entered value
        userInput(highscore);
        //function display content of highscore.txt
        displayHighScore();
        //prompt USER to repeat operation
        cout <<"Do you want to Repeat Operation [y/n]: ";
        //get user's choice of operation
        cin >> yes_no;

    } while (yes_no=='y');//repeat program if your input 'y'
    

}