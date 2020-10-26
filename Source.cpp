#include<iostream>
#include<vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <Windows.h>
#include <conio.h>
using namespace std;

vector<int> obstacle;
int dinosaur_jump = 0;
int die = 0;

void init() {
    int i;
    for (i = 0; i < 8; i++) {
        obstacle.push_back(0);
    }
    obstacle.push_back(1);
    obstacle.push_back(0);
}

void next_frame() {
    obstacle.erase(obstacle.begin(), obstacle.begin() + 1);
    srand((unsigned)time(NULL));
    int random = rand() % 10;
    if (random <= 2)
        obstacle.push_back(1);
    else
        obstacle.push_back(0);
}

void print_map() {
    int i;
    for (i = 0; i < 10; i++) {
        cout << obstacle[i];
    }
}

void draw() {
    int i;
    if(!dinosaur_jump){
        cout << "0000000000" <<endl;
        cout << "0020000000" <<endl;
        cout << obstacle[0] << obstacle[1] << "2";
        for(i=3;i<10;i++)
            cout << obstacle[i];
        cout << endl;
    }
    else{
        cout << "0020000000" << endl;
        cout << "0020000000" << endl;
        for(i=0;i<10;i++)
            cout << obstacle[i];
        cout << endl;
    }

}

void GetKeyPress()
{
    //cout << "asdasdas";
    while (!die) {
        int k = _getch();
        if (k == 72) {
            //cout << "up" << endl;
            dinosaur_jump=1;
        }
    }
}

int main() {
    thread t(GetKeyPress);
    init();
    int i;
    while (!die) {
        draw();
        if (dinosaur_jump == 0 && obstacle[2] == 1)
            die = 1;
        dinosaur_jump = 0;
        cout << endl;
        next_frame();
        Sleep(1000);
    }
    t.detach();
    cout << "Game Over" << endl;
    return 0;
}
