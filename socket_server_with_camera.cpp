#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <string.h>
#include "SimpleGPIO.h"

void forward(int,int);
void reverse(int,int);

using namespace std;

void forward(int ie,int je){
	gpio_set_value(ie,HIGH);
        gpio_set_value(je,LOW);
        sleep(1);
        gpio_set_value(ie,LOW);
        gpio_set_value(je,LOW);
}
void reverse(int ke,int me){

        gpio_set_value(ke,LOW);
        gpio_set_value(me,HIGH);
        sleep(1);
        gpio_set_value(ke,LOW);
        gpio_set_value(me,LOW);
}

void *stream(void *arg){
system("./streamVideoUDP");
}

void *PrintHello(void *threadid){
	long tid;
	tid = (long)threadid;
	char  a,b,c,d;
	int byte,ch;
	int server_sockfd,client_sockfd;
	int server_len,client_len;
	struct sockaddr_in server_address,client_address;
	int result,numbytes,fd;
	char buff[200],str2[50],num1[200],num2[200];
	server_sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(server_sockfd==-1){
	perror(" socket create :");
	exit(1);
}
	server_address.sin_family=AF_INET;
	server_address.sin_port=8889;
	server_address.sin_addr.s_addr=INADDR_ANY;
	server_len=sizeof(server_address);
	result=bind(server_sockfd,(struct sockaddr*)&server_address,server_len);
	if(result==-1){
	perror("error in bind\n");
	exit(1);
	}
	result=listen(server_sockfd,5);
	if(result==-1){
	perror("error in listen");
	exit(1);
	}

	client_len= sizeof(client_address);
	client_sockfd=accept(server_sockfd,(struct sockaddr*)NULL, NULL);
	if(client_sockfd==-1){
	perror("error accept :");
	exit(1);
	}
	gpio_export(48);
	gpio_export(51);
	gpio_export(50);
	gpio_export(49);
	gpio_export(66);
	gpio_export(67);
	gpio_export(69);
	gpio_export(68);
	gpio_export(45);
	gpio_export(44);
	gpio_export(26);
	gpio_export(47);
	gpio_export(46);
	gpio_export(27);
	gpio_export(65);
           
	gpio_set_dir(48,OUTPUT_PIN);
	gpio_set_dir(51,OUTPUT_PIN);
	gpio_set_dir(50,OUTPUT_PIN);
	gpio_set_dir(49,OUTPUT_PIN);
	gpio_set_dir(66,OUTPUT_PIN);
	gpio_set_dir(67,OUTPUT_PIN);
	gpio_set_dir(69,OUTPUT_PIN);
	gpio_set_dir(68,OUTPUT_PIN);
	gpio_set_dir(45,OUTPUT_PIN);
	gpio_set_dir(44,OUTPUT_PIN);
	gpio_set_dir(26,OUTPUT_PIN);
	gpio_set_dir(47,OUTPUT_PIN);
	gpio_set_dir(46,OUTPUT_PIN);
	gpio_set_dir(27,OUTPUT_PIN);
	gpio_set_dir(65,OUTPUT_PIN);

	while(1){     
	byte= read(client_sockfd,&ch,1);
	if(ch==3){
		gpio_set_value(48,HIGH);
		gpio_set_value(51,HIGH);
		gpio_set_value(50,LOW);
		gpio_set_value(49,LOW);
		sleep(1);
		gpio_set_value(48,HIGH);
		gpio_set_value(51,HIGH);
		gpio_set_value(50,HIGH);
		gpio_set_value(49,HIGH);
	}
	if(ch==2){
		gpio_set_value(48,LOW);
		gpio_set_value(51,LOW);
		gpio_set_value(50,HIGH);
		gpio_set_value(49,HIGH);
		sleep(1);
		gpio_set_value(48,HIGH);
		gpio_set_value(51,HIGH);
		gpio_set_value(50,HIGH);
		gpio_set_value(49,HIGH);
	}
	if(ch==4){
		gpio_set_value(48,HIGH);
		gpio_set_value(51,LOW);
		gpio_set_value(50,LOW);
		gpio_set_value(49,HIGH);
		sleep(1);
		gpio_set_value(48,HIGH);
		gpio_set_value(51,HIGH);
		gpio_set_value(50,HIGH);
		gpio_set_value(49,HIGH);
	}

	if(ch==5){
		gpio_set_value(48,LOW);
		gpio_set_value(51,HIGH);
		gpio_set_value(50,HIGH);
		gpio_set_value(49,LOW);
		sleep(1);
		gpio_set_value(48,HIGH);
		gpio_set_value(51,HIGH);
		gpio_set_value(50,HIGH);
		gpio_set_value(49,HIGH);
	}
	if(ch==97){
		forward(66,67);
	}
	if(ch==115){
	forward(69,68);
	}
	if(ch==100){
	forward(45,44);
	}
	if(ch==102){
	forward(26,47);
	}
	if(ch==103){
	forward(46,27);
	}
	if(ch==104){
	gpio_set_value(65,HIGH);	
	}
	if(ch==122){
	reverse(66,67);	
	}
	if(ch==120){
	reverse(69,68);	
	}
	if(ch==99){
	reverse(45,44);
	}
	if(ch==118){
	reverse(26,47);
	}
	if(ch==98){
	reverse(46,27);
	}
	if(ch==110){
	gpio_set_value(65,LOW);
	}
	if(ch==49){
		gpio_set_value(48,LOW);
        	gpio_set_value(51,LOW);
           	gpio_set_value(50,LOW);
           	gpio_set_value(49,LOW);
           	gpio_set_dir(48,INPUT_PIN);
           	gpio_set_dir(58,INPUT_PIN);
           	gpio_set_dir(50,INPUT_PIN);
           	gpio_set_dir(49,INPUT_PIN);
            	gpio_unexport(48);
           	gpio_unexport(51);
           	gpio_unexport(50);
           	gpio_unexport(49);
             	close(server_sockfd);
		pthread_exit(NULL);
             	exit(0);
	}}
	gpio_set_value(48,LOW);
        gpio_set_value(51,LOW);
        gpio_set_value(50,LOW);
        gpio_set_value(49,LOW);
        gpio_set_dir(48,INPUT_PIN);
        gpio_set_dir(51,INPUT_PIN);
        gpio_set_dir(50,INPUT_PIN);
        gpio_set_dir(31,INPUT_PIN);
        gpio_unexport(48);
        gpio_unexport(51);
        gpio_unexport(50);
        gpio_unexport(49);
        close(server_sockfd);
	pthread_exit(NULL);
}

int main (){
   pthread_t threads1,threads2;
   int rc1,rc2;
   int i,k;
   
   rc1 = pthread_create(&threads1, NULL, PrintHello, (void *)i);
	if (rc1){
         	exit(-1);
      }
   rc2=pthread_create(&threads2, NULL,  stream, (void *)k);
	if(rc2){
         exit(-1);
        }
  pthread_exit(NULL);	
}


