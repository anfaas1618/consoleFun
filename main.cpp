#include <iostream>
#define WIDTH 50
#define HEIGHT 15
using namespace std;
void draw();
void init();
char arr[HEIGHT][WIDTH];
int main(int len,char** args){
    init();
    arr[(HEIGHT/2)-1][(WIDTH/2)-1]='#';
    draw();

    return  0;

}void  draw(){
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
           cout<<arr[i][j];
        }
        cout<<endl;
    }
}void  init(){
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
