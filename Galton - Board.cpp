#include <iostream>
#include <vector>
using namespace std;

int main() {

    int nLevels;
    int nBalls;

    cout << "How many balls? ";
    cin >> nBalls;
    cout << "How many levels? ";
    cin >> nLevels;

    vector<int> listPosition_withWalls(nLevels * 2 + 1);
    vector<int> listPosition(nLevels + 1);
    
    //Calculate the movement of the balls in the galton board
    for (int b = 0; b < nBalls; b++) {

        int innerPositon = 0;
        for (int p = 0; p < nLevels; p++) {

            //If random value is 1 I consider that it moves to right position. Otherwise if is 0, it move to left position. 
            bool isRight = rand() % 2;

            if (isRight) {
                innerPositon += 1;
            
            }else {
                innerPositon -= 1;
            }
        }

        innerPositon += nLevels;

        //Increment number of balls endend in final position
        listPosition_withWalls[innerPositon] += 1;
    }

    /*
    cout << "End Galton Board Balls Positions: \n";
    for (int i = 0; i < listPosition_withWalls.size(); i++) {
        cout << listPosition_withWalls[i];
        if (i < listPosition_withWalls.size() - 1) cout << " - ";

    }
    cout << "\n";
    */

    //Erase empty positions that represents separation walls
    for (int i = 0; i < nLevels + 1; i++) {
        if (i == 1) {
            listPosition[i] = listPosition_withWalls[2];
        }else {
            listPosition[i] = listPosition_withWalls[i * 2];
        }
    }
    
    cout << "End Galton Board Balls Positions: \n";
    for (int i = 0; i < nLevels + 1; i++) {
        cout << listPosition[i];
        if (i < nLevels) cout << " - ";

    }

    
}

