/* 
 * File:   main.cpp
 * Author: Jacob Kwiat
 *
 * Created on October 27, 2024, 9:40 PM
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

enum colors {
    red, green, blue, yellow, brown, orange, black, white
};
enum results {
    Fcolor, Fspot, Tspot
};

void setReal(vector<colors>&, int, bool);
void guess();
void check(vector<colors>&, colors[], results[]);

int main(int argc, char** argv) {
    srand(time(0));
    vector<colors> real;
    int amount = 0;
    int holdG;
    int win;
    bool repeat = false;
    cout << "how many marbles? enter 4-8" << endl;
    cin >> amount;
    cout << "would you like repeat colors? enter 1 for yes and 0 for no" << endl;
    cin >> repeat;
    setReal(real, amount, repeat);
    colors guesses[amount];
    results checked[amount];
    //for(int i = 0; i < amount; i++) {
    do {
        cout << "input colors one at a time. 0 for red, 1 for green, 2 for blue, 3 for yellow, 4 for brown, 5 for orange, 6 for black, 7 for white" << endl;
        for(int j = 0; j < amount; j++) {
            cout << " ";
            cin >> holdG;
            guesses[j] = static_cast<colors>(holdG);
        }
        win = 1;
        cout << endl;
        check(real, guesses, checked);
        cout << "results:";
        for(int j = 0; j < amount; j++) {
            cout << " " << checked[j];
            if(checked[j] != 2) win = 0;
        }
        cout << endl;
    } while(win == 0);
    cout << "you win!";
    return 0;
}

void setReal(vector<colors>& holder, int length, bool repeat) {
    //vector holding the options so they can be removed to avoid repeats
    vector<int> options = {1,2,3,4,5,6,7,8};
    int temp;
    for(int i = 0; i < length; i++) {
        temp = rand()%(options.size());
        holder.push_back(static_cast<colors>(options[temp]));
        //remove this part for repeat colors
        if(repeat != true) {
            options.erase(options.begin()+temp);
        }
    }
    return;
}

void check(vector<colors>& actual, colors in[], results out[]) {
    for(int i = 0; i < actual.size(); i++) {
        out[i] = Fcolor;
        for(int j = 0; j < actual.size(); j++) {
            if(in[i] == actual[j]) {
                if(i == j) {
                    out[i] = Tspot;
                    break;
                }
                else {
                    out[i] = Fspot;
                }
            }
        }
    }
    return;
}
