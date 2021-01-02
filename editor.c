#include <curses.h>
#include <stdlib.h>
#include <string.h>


int main(){
    initscr();
    noecho();
    keypad(stdscr, true);
    while(true) {
        int y, x;
        getyx(stdscr, y, x);
        char buffer[500];
        int ich=getch();
        char ch=ich;

        if(ich == 259){
            move(y-1, x);
        } else if(ich == 258){
            move(y+1, x);
        } else if(ich == 260){
            move(y, x-1);
        } else if(ich == 261) {
            move(y, x+1);
        } else if(ich == 263) {
            move(y, x-1);
            addstr(" ");
            move(y, x-1);
        } else if(ich == 270) {
            clear();
            printw("%s", buffer);
        } else {
            buffer[strlen(buffer)] = ch;
            buffer[strlen(buffer)+1] = '\0';
            printw("%c", ch);
        }
    }
}
