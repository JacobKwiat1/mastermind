/*
    Dr. Mark E. Lehr
    CSC 7 Template for Mastermind AI
    May 11th, 2021
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

//Function Prototypes
string AI(char,char);
bool eval(string,string,char &,char &);
string set();
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    string code,guess;  //code to break, and current guess
    char rr,rw;         //right digit in right place vs. wrong place
    int nGuess;         //number of guesses
    
    //Initialize Values
    nGuess=0;
    code=set();
    rr=rw=0;
    
    //Loop until solved and count to find solution
    do{
       nGuess++;
       guess=AI(rr,rw);
    }while(eval(code,guess,rr,rw) && nGuess < 30);
    
    //Output the solution
    cout<<"Number of guesses using Linear Search = "<<nGuess<<endl;
    cout<<code<<"="<<guess<<endl;

    //Exit the program
    return 0;
}

string AI(char rr,char rw){
    static int guess=-1;
    guess++;
    static string sguess = "xxxx";
    static vector<char> colors = {'x','x','x','x'};
    static bool colored = false;
    static int slot = 0;
    static char current = '0'-1;
    static int ctwo = -1;
    static bool flag = false;
    if(!colored)    {
        for(char i = 0; i < rr+rw; i++)  {
            colors[slot] = current;
            slot++;
        }
        current++;
        for(int i = 0; i < 4; i++)  {
            sguess[i] = current;
        }
        if(slot == 4) {
            colored = true; 
            slot = 0;
            sguess = "xxxx";
        }
        if(current > '8') {
            while(colors[slot] == 'x') {
                colors[slot] = '9';
                slot++;
            }
            sguess = "xxxx";
            colored = true;
            slot = 0;
        }
    }
    
    if(colored) {
        if(slot < rr && flag) {
            slot++;
            colors.erase(colors.begin()+ctwo);
            ctwo = -1;
        }
        if(ctwo == colors.size()-2) {
            sguess[slot] = colors[ctwo+1];
            colors.erase(colors.begin()+(ctwo+1));
            ctwo = -1;
            slot++;
        }
        flag = true;
        ctwo++;
        sguess[slot] = colors[ctwo];
        if(slot == 2) sguess[3] = colors[1-ctwo];
    }
    return sguess;
}

bool eval(string code,string guess,char &rr,char &rw){
    string check="    ";
    rr=0,rw=0;
    //Check how many are right place
    for(int i=0;i<code.length();i++){
        if(code[i]==guess[i]){
            rr++;
            check[i]='x';
            guess[i]='x';
        }
    }
    //Check how many are wrong place
    for(int j=0;j<code.length();j++){
        for(int i=0;i<code.length();i++){
            if((i!=j)&&(code[i]==guess[j])&&(check[i]==' ')){
                rw++;
                check[i]='x';
                break;
            }
        }
    }
    
    //Found or not
    if(rr==4)return false;
    return true;
}

string set(){
    string code="0000";
    for(int i=0;i<code.length();i++){
        code[i]=rand()%10+'0';
    }
    return code;
}
