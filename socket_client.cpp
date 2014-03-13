#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
int main()
{   
    int ch;
    initscr();

    raw();
    keypad(stdscr,TRUE);
    noecho();
        
    int sockfd;
    int len,choice;
    char s;
    struct sockaddr_in address;
    int result,numbytes;
/*  Create a socket for the client.  */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
/*  Name the socket, as agreed with the server.  */
    address.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr);
    address.sin_port = 8889;
   len = sizeof(address);
/*  Now connect our socket to the server's socket.  */
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if(result == -1) {
        perror("oops: client2");
        exit(1);
    }
      
printw("Press E to Exit\n");

while((ch = getch()) != 'E')
{
    switch(ch)
    {
    case KEY_UP:         
		printw("Up Arrow \n");
		break;
    case KEY_DOWN:      
		printw("Down Arrow \n");
		break;
    case KEY_LEFT:      
		printw("Left Arrow \n");
		break;
    case KEY_RIGHT:     
		printw("Right Arrow \n");
		break;
    case 1:     
		printw(" Exiting \n");
		break;
    default:
                printw("The pressed key is %c \n",ch);

    }
    printf("%d \n",ch);
    write(sockfd,&ch,1);
    if(ch == 1){
    close(sockfd);
    endwin();
    }
}

printf("%d \n",ch);
}
