#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 500
#define PORT 8888
#define SA struct sockaddr


char buff[MAX];

char buff_Room[500]={"\n\n\n\n\n\n\n* * * * * * *ROOM BOOKING* * * * * *  * \nAvailable Rooms:\n 1-ROOM A (FIRST FLOOR)\n Code:-FFFR\n 2-ROOM B (SECOND FLOOR )\n Code:-SFLR\n To book A Room Please Enter the Code of the Room :- " };
	
char buff_Book[]={"\n\n\n\n\n* * * * * * * BORROW BOOKS* * * * * * * \n*The library conatains 2 Floors \n*Floor 1 Contains 2 Computer Engineering Books which are:-\n1-Sedra (Electronics Book)\nCode:-SDRA\n2-Pyhton(Programming Book)\nCode:-PYTH\n \nThe second Floor Conatains 2 philosophy books which are :-\n1-Beyond Good and Evil \nCode :BGAE \n2-Republic (Plato)\nCode:REPU\nTo Check if Book is Available Please Enter the Code of the Book :\n"};

char buff_Hours[]={"\n\n\n\n\n* * * * * * *DISPLAY WORKING HOURS* * * * * * * \n*-*-*-*-*-*-*-BUE Library *-*-*-*-*-*-*-\n Working From Saturday to Thursday From 9:30 until 4:00\n The library contains 2 floors, 2 Rooms and 4 Books . You Are allowed to make booking for Rooms as much as you like , and you can reserve the books for borrowing unfourtunatly some books might not be available, We hope you find the system useful.\n  We Are waiting For Your Visit. :)\nType 'Exit' to end the program) or Renter the number of service you would like"};

char buff_Room1[]={"\n\n\nROOM 1 BOOKING SUCCESSFUL\n\n\nThank You For Using BUE Library system \n(Type 'Exit' to end the program) or Renter the number of service you would like "};

char buff_Room2[]={"\n\n\nROOM 2 BOOKING SUCCESSFUL\n\n\nThank You For Using BUE Library system \n(Type 'Exit' to end the program) or Renter the number of service you would like"};

char buff_error[]="\n\n*****YOU HAVE ENTERED A WRONG CODE !!***** \n\n\nThank You For Using BUE Library system \n(Type 'Exit' to end the program) or Renter the number of service you would like";

char buff_Book1[]={"\n\n\nSEDRA BOOK IS BOOKED SUCCESSFULLY\nThank You For Using BUE Library system \n(Type 'Exit' to end the program) or Renter the number of service you would like"};

char buff_Book2[]={"\n\n\nPYTHON BOOK IS NOT AVAILABLE !? :(  iT WILL BE AVAILABLE TOMMORROW \n\n\nThank You For Using BUE Library system \n(Type 'Exit' to end the program) or Renter the number of service you would like"};

char buff_Book3[]={"\n\n\nBEYOND GOOD AND EVIL BOOKED SUCCESSFULLY\n\n\nThank You For Using BUE Library system \n(Type 'Exit' to end the program) or Renter the number of service you would like"};

char buff_Book4[]={"\n\n\nREPUBLIC BOOK IS NOT AVAILABLE!! IT WON'T BE AVAILABLE SOON :(( \n\nThank You For Using BUE Library system \n(Type 'Exit' to end the program) or Renter the number of service you would like"};

//--------------------------------Buffers Declearation-------------------------------------------------
    int n;
    int j;
    int k;
    int i=0;
void func(int sockfd)
{
    for (;;) {
        bzero(buff, MAX);//	initilizing buffer
        
        
        read(sockfd, buff, sizeof(buff));//	read buffer from client to see which service the server should do
        
        
       printf("From client: %s\t", buff);// to test weather the buff is sending correct value to server we print the value on the server terminal
       
       
       //----------------------------------Room Booking ------------------------------------------------------------------
           if(strncmp(buff , "1",1)==0) { // check wheather the buff that user inputted == 1
           bzero(buff, MAX);//	initilizing buffer
           for(int i=0;i<sizeof(buff_Room);i++){ //storing buff_Room in buff 
           buff[i]=buff_Room[i];//storing buff_Room in buff
           }
      write(sockfd,buff,sizeof(buff));// 	if condition met send buff_Room to client
     
  //---------------------------------------------------------------------------   
     
      read(sockfd,buff,sizeof(buff));//get user input for which floor he would like to book his room
      
        printf("From client: %s\t", buff);//print on server terminal
        
        if(strncmp(buff, "SFLR",4)==0){//	check wheather buff meets the code for 2nd floor room
        
        bzero(buff, MAX);
        
           for(int i=0;i<sizeof(buff_Room);i++){
           
           buff[i]=buff_Room2[i];//storing buff_Room2 in buff
           }
           
        write(sockfd,buff,sizeof(buff));// 	if condition met send buff to client
        }
        
        
        else if(strncmp(buff, "FFFR",4)==0){// check weather buff meets code for 1st floor room
        
        bzero(buff, MAX);
        
           for(int i=0;i<sizeof(buff_Room);i++){//storing buff in buff
           
           buff[i]=buff_Room1[i];//storing buff in buff
           }
           
        write(sockfd,buff,sizeof(buff));// if condition met send buff to client
        }
        
        
        else {
        bzero(buff, MAX);
        
           for(int i=0;i<sizeof(buff_error);i++){
           
           buff[i]=buff_error[i];//storing buff_error in buff
           }
           
        write(sockfd,buff,sizeof(buff));// send error message to client.
        }
        
        //-----------------------------------------Book Borrowing--------------------------------------------------------------------------
        }
	else if(strncmp(buff , "2",1)==0){ // check wheather the buff that user inputted == 2
	
        bzero(buff, MAX);
        
           for(int i=0;i<sizeof(buff_Book);i++){
           
           buff[i]=buff_Book[i];
           }
        write(sockfd,buff,sizeof(buff));// 	if condition met send buff_Book to client
        
        
        read(sockfd,buff,sizeof(buff));//get user input for which Book he would like to borrow
        printf("From client: %s\t", buff);//print on server terminal
        
        if(strncmp(buff, "SDRA",4)==0){//	check wheather buff meets the code for SDRA book
        
        bzero(buff, MAX);
        
           for(int i=0;i<sizeof(buff_Book1);i++){
           
           buff[i]=buff_Book1[i];
           }
           
        write(sockfd,buff,sizeof(buff));// 	if condition met send buff_Book1 to client
        }
        
        
        else if(strncmp(buff, "PYTH",4)==0){//	check wheather buff meets the code for PYTH book
        
        bzero(buff, MAX);
        
           for(int i=0;i<sizeof(buff_Book2);i++){
           
           buff[i]=buff_Book2[i];
           }
           
        write(sockfd,buff,sizeof(buff));// 	if condition met send buff to client
        }
        
        
        else if(strncmp(buff, "BGAE",4)==0){//	check wheather buff meets the code for BGAE book
        
        bzero(buff, MAX);
        
           for(int i=0;i<sizeof(buff_Book3);i++){
           
           buff[i]=buff_Book3[i];
           }
           
        write(sockfd,buff,sizeof(buff));// 	if condition met send buff to client
        }
        
        
        else if(strncmp(buff, "REPU",4)==0){//	check wheather buff meets the code for REPU book
        
        bzero(buff, MAX);
        
           for(int i=0;i<sizeof(buff_Book4);i++){
           
           buff[i]=buff_Book4[i];
           }
           
        write(sockfd,buff,sizeof(buff));// 	if condition met send buff to client
        }
        
        
        else {
        
        bzero(buff, MAX);// init buffer
        
           for(int i=0;i<sizeof(buff_error);i++){ // store buff error  in buff 
           
           buff[i]=buff_error[i];
           }
           
        write(sockfd,buff,sizeof(buff));// send error message to client.
        }
        }
       //------------------------------------------------------Display info-----------------------------------------------------------------
        else if (strncmp(buff , "3",1)==0){// check wheather the buff that user inputted == 3
        
           bzero(buff, MAX);
           for(int i=0;i<sizeof(buff_Room);i++){
           buff[i]=buff_Hours[i];
           }
        write(sockfd,buff,sizeof(buff));// write buff_Hours to client 
        }
 // --------------------------------------------------------------
        else if (strncmp(buff , "4",1)==0){// check wheather the buff that user inputted == 4
          printf("Server Exit...\n"); 

            break;
        }
        
        else if (strncmp("exit", buff, 4) == 0) { 

            printf("Server Exit...\n"); 

            break; }
            
        else{
        bzero(buff, MAX);
           for(int i=0;i<sizeof(buff_Book1);i++){
           buff[i]=buff_error[i];
           }
        write(sockfd,buff,sizeof(buff));// send error message to client , if the input from user was not 1,2,3 or 4.
        }
        }
    }
   
// Driver function
int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
   
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
   
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
   
    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");
   
    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);
   
    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");
   
    // Function for chatting between client and server
    func(connfd);
   
    // After chatting close the socket
    close(sockfd);
}
