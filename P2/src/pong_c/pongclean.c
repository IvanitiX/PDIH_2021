#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

#define DELAY 80000

int main(void) {
    int rows, cols;
    int x = cols/2, y = 0;
    int pos_p1, pos_p2;
    int old_x, old_y;
    int max_y = 25, max_x = 80;
    int next_x = 0;
    int directionx = 1;
    int next_y = 0;
    int directiony = 1;
    int points_p1 = 0;
    int points_p2 = 0;

 initscr();
 keypad(stdscr, TRUE);
 noecho();
 cbreak();
 curs_set(FALSE);
     nodelay(stdscr,FALSE);


    if (has_colors() == FALSE) {
    	endwin();
    	printf("Your terminal does not support color\n");
    	exit(1);
	}

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3,COLOR_WHITE,COLOR_BLUE);
    clear();

    refresh();
    getmaxyx(stdscr, rows, cols);
    getmaxyx(stdscr, max_y, max_x);

    WINDOW *window = newwin(rows,cols,0,0);
    wbkgd(window, COLOR_PAIR(3));
    box(window, '|', '-'); 

    WINDOW *window2 = newwin(rows-4,cols,4,0);
    wbkgd(window2, COLOR_PAIR(2));
    box(window2, '|', '-'); 

    WINDOW *window3 = newwin(rows,cols/2,0,cols/4);
    wbkgd(window3, COLOR_PAIR(1));
    box(window3, '|', '-');




    mvwprintw(window3, 1, 1, "Bienvenidos a PONG");
    mvwprintw(window3, 5, 1, "Estos son los controles:");
    mvwprintw(window3, 7, 1, "W/S : Mover la paleta del P1");
    mvwprintw(window3, 9, 1, "UP/DOWN : Mover la paleta del P2");
    mvwprintw(window3, rows-5, 1, "<Pulse una tecla para empezar>");
    wrefresh(window);
    wrefresh(window2);
    wrefresh(window3);

    getch(); 

       nodelay(stdscr,TRUE);
    pos_p1 = pos_p2 = (rows-4)/2;
    wclear(window);
    wclear(window2);

    box(window, '|', '-'); 
      mvwprintw(window, 2,(cols/2)-3, "0");
      mvwprintw(window, 2,(cols/2), "|");
      mvwprintw(window, 2,(cols/2)+3, "0");

    wrefresh(window);
    

    while(1) {
       wclear(window2);

       getmaxyx(stdscr, max_y, max_x);

       if (cols != max_x || rows != max_y){
          old_x = x;
          old_y = y;
          x = old_x * (float)((max_x*1.0/cols)) ;
          y = old_y * (float)((max_y*1.0/rows));

          getmaxyx(stdscr, rows, cols);

          wresize(window, rows, cols);
          wresize(window2, rows-4, cols);


            wclear(window);
            box(window, '|', '-'); 
            mvwprintw(window, 2,(cols/2)-3, "%d", points_p1);
            mvwprintw(window, 2,(cols/2), "|");
            mvwprintw(window, 2,(cols/2)+3, "%d", points_p2);
            pos_p1 = pos_p2 = (rows-4)/2;

          box(window2, '|', '-');
          box(window, '|', '-');

          wrefresh(window);
          wrefresh(window2);
       }
       else{

          switch(getch()){
             case 'w':
             case 'W':
               if(pos_p1 > 1) pos_p1--;
             break;
             case 's':
             case 'S':
               if(pos_p1 < rows - 8) pos_p1++;
             break;
             case KEY_UP:
               if(pos_p2 > 1) pos_p2--;
             break;
             case KEY_DOWN:
               if(pos_p2 < rows - 8)pos_p2++;
             break;
          }

          box(window2, '|', '-'); 
 	      mvwprintw(window2, y, x, "o");
          mvwprintw(window2, pos_p1,1,"N" );
          mvwprintw(window2, pos_p1 + 1,1, "N" );
          mvwprintw(window2, pos_p1 + 2,1, "N" );

          mvwprintw(window2, pos_p2,cols-2, "N" );
          mvwprintw(window2, pos_p2 + 1,cols-2, "N" );
          mvwprintw(window2, pos_p2 + 2,cols-2, "N" );


         wrefresh(window2);

         usleep(DELAY);

         next_x = x + directionx;
         next_y = y + directiony;

         int testch = mvwinch(window2,y,x);
         int character = testch & A_CHARTEXT ;

         if(character == 'N'){
            directionx*= -1;
            x+= directionx;
         }
         else if (next_x >= max_x || next_x < 0) {
            
            (directionx == 1)? points_p1++ : points_p2++;
          wclear(window);
            box(window, '|', '-'); 
            mvwprintw(window, 2,(cols/2)-3, "%d", points_p1);
            mvwprintw(window, 2,(cols/2), "|");
            mvwprintw(window, 2,(cols/2)+3, "%d", points_p2);
            wrefresh(window);
            directionx*= -1;
            x = cols/2;
         } else {
            x+= directionx;
         }

         if (next_y >= max_y - 5 || next_y < 1) {
            directiony*= -1;
         } else {
            y+= directiony;
         }
       }


      
      
      
   }

    endwin();
    return 0;
}
