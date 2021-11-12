#include <iostream>
#define WIDTH 50
#define HEIGHT 50
#include <thread>
#include <Windows.h>
#include <unistd.h>
using namespace std;
static int code=0;
void exit(int code)
{
    ::code=code;
}
void start();
void update();
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
int main(){
    start();
    while (!code==1)
    {
        update();
    }

}
char arr[HEIGHT][WIDTH];
class Box {
public:
    int COORDINATES[4][2]{{0,0},{0,1},{1,0},{1,1}};
    void setxy(int x , int y)
    {
        for (int i = 0; i < 4; ++i) {
            COORDINATES[i][0]+=x;
            COORDINATES[i][1]+=y;
        }
    }
    void place()
    {
        for (int i = 0; i < 4; ++i) {
            arr[COORDINATES[i][0]][COORDINATES[i][1]]='#';
        }
    }
    void clear()
    {
        for (int i = 0; i < 4; ++i) {
            arr[COORDINATES[i][0]][COORDINATES[i][1]]=' ';
        }
    }
     void setClearPlace(int x,int y)
    {
        for (int i = 0; i < 4; ++i) {
            arr[COORDINATES[i][0]][COORDINATES[i][1]]=' ';
            COORDINATES[i][0]+=x;
            COORDINATES[i][1]+=y;
            arr[COORDINATES[i][0]][COORDINATES[i][1]]='#';
        }
    }
};
void  init(){
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if(i==0||i==HEIGHT-1)
                arr[i][j]='*';
            else  if(j==0||j==WIDTH-1)
                arr[i][j]='*';
            else arr[i][j]=' ';
        }

    }
}
void  draw(){
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}
void start(){
    init();
    Box box;
    ShowConsoleCursor(false);
    draw();
    box.setxy(3,3);
    box.place();
    draw();
    box.clear();
    draw();
    box.setClearPlace(5,5);
    draw();
    getchar();
}
void update(){
    exit(0);
}
