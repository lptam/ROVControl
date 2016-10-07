#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>
#include<unistd.h>
#include<sys/types.h>

int b=0, i=0;

int system(char  *xdotool );

int main(){

system("xdotool key alt+Tab");

while (i<10) { 


system("xdotool key 5");

system("xdotool keydown ctrl; sleep 2");

system("xdotool keyup ctrl");

system("xdotool key 2");

system("xdotool keydown 0xff51; sleep 2; xdotool keyup 0xff51");/* mover para frente*/

system("xdotool keydown 0xff52; sleep 2"); /* mover para a esquerda*/

system("xdotool keyup 0xff52");

system("xdotool keydown 0xff51; sleep 2; xdotool keyup 0xff51");

system("xdotool keydown 0xff54; sleep 2"); /* mover para a esquerda*/

system("xdotool keyup 0xff54");

i==i++;

/*
#define XK_Left                          0xff51   Move left, left arrow 
#define XK_Up                            0xff52   Move up, up arrow 
#define XK_Right                         0xff53   Move right, right arrow 
#define XK_Down                          0xff54   Move down, down arrow 


system("xdotool keydown alt key Tab; xdotool keyup alt");


printf ("%i  ", b);

printf("Próximo movimento acontecerá em 3 segundos...\n");

sleep(3);
*/
}

printf("Fim dos movimentos\n\n\n");

return 0;
}

