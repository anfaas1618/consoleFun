#include <iostream>
#include <thread>
#include <Windows.h>
#define SQUARECHAR 2
#define SPACE ' '
#include <string.h>
#include <unistd.h>
using namespace std;
const static char square =(char) SQUARECHAR;
static int code=0;
void exit(int code)
{
    ::code=code;
}
void start();
void update();
void collisionCheck();
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
//****************************************meta data************************************//
#define WIDTH 50
#define HEIGHT 50
char arr[HEIGHT][WIDTH];
static bool collision = false;
class Box {
public:
    int COORDINATES[4][2]{{0,0},{0,1},{1,0},{1,1}};
    void setxy(int x , int y)
    {

        for (int i = 0; i < 4; ++i) {
                COORDINATES[i][0] += x;
                COORDINATES[i][1] += y;

        }
    }

    static bool canplace(int i) {
        char l=' ';
        char m='#';
        int g=(int)m;
        int k =(int)l;
       if(i==k||i==g)
         return true;

        else {
            collision=true;
            return false;
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
     bool setClearPlace(int x,int y)
    {
        bool a = false;
        for (int i = 0; i <4 ; ++i) {
            int checkX = COORDINATES[i][0]+x;
            int checkY = COORDINATES[i][1]+y;

            a= canplace(arr[checkX][checkY]);
            if (a== false) return true;
        }
        if (a== true)  for (int i = 0; i < 4; ++i) {
            arr[COORDINATES[i][0]][COORDINATES[i][1]] = ' ';
            COORDINATES[i][0] += x;
            COORDINATES[i][1] += y;
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
int down_x=1;
int up_x=-1;
int left_y=-1;
int right_y=1;
Box box;


void start(){
    ShowConsoleCursor(false);
    init();
    box.setxy(20,4);


    //////////////char finder////////
//    for (int i = 219; i < 255; ++i) {
//        char a= i;
//        cout<<a;
//    }
    ////////////////////////////////////
//    ShowConsoleCursor(false);
//    draw();
//    box.setxy(3,3);
//    box.place();
//    draw();
//    box.clear();
//    draw();
//    box.setClearPlace(5,5);
//    draw();
//    getchar();
}
static int y= 1;
static int x=1;
bool col1=false;
bool col2 = false;
bool col3 = false;
bool col4 = false;
void update(){
box.place();
    draw();
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    if (col1== false)
        col1 = box.setClearPlace(down_x, right_y);//move down right

     else if (col2 == false)
       col2 =  box.setClearPlace(up_x, right_y);//move up right
       else if (col3 == false)
           col3 =box.setClearPlace(up_x,left_y);
    else if (col4 == false)
        col4 =box.setClearPlace(down_x,left_y);
    else {
        col1 = col2 = col3 =col4 = false;
    }




    ShowConsoleCursor(false);
}
