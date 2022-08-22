#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#define MAX 500
#define PORT 8888
#define SA struct sockaddr
// I've Decleared a Buffer For Each Type Of service to keep the code tiddy instead of using the same buffer .
char buff[MAX];// Buffer that is responsible for the data transmition

//----------------------------------------------------------------------------------------------------------------------------------
void welcomeMessage() // Declear Welcome messaga that will be First Seen by Client
{
   
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        $                 WELCOME                   =");
    printf("\n\t\t\t        $                   TO                      =");
    printf("\n\t\t\t        $                   BUE                     =");
    printf("\n\t\t\t        $                 LIBRARY                   =");
    printf("\n\t\t\t        $               MANAGEMENT                  =");
    printf("\n\t\t\t        $                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    }
    
 //-----------------------------------------------------------------------------------------------------------------------------------
void client_menu_display() // Declear Menu That client Will be Picking Service From
{
	
printf("******************************************\n*********\n""****\t\t\t		 CHOOSE YOUR SERVICE              ****\n**********\n\t\t\t * * * * * * * * * * 1. ROOM BOOKING * * * * * * * * * *\n\n\t\t\t* * * * * * * * * * 2. BORROW BOOKS * * * * * * * *\n\n\t\t\t * * * * * * * * * * 3. DISPLAY WORKING HOURS         * * * * * * *\n\n\t\t\t     * * * *  * * 4. EXIT * * * * * * * * * * * *\n\n");
}
//------------------------------------------------------------------------------------------------------------------------------------
void func(int sockfd){

    int n;
    int j;
    int k;
    for (;;) {
        bzero(buff, MAX); // initilize the buffer
        printf("Enter the string : ");// get input from client on which service he would like to use
        n = 0;
        j = 0;
        k = 0;
        while ((buff[n++] = getchar()) != '\n');// function for inputting char from user
        
        write(sockfd, buff, sizeof(buff));// send inputting from client to server using buff
           if(strncmp(buff , "1",1)==0) {//checking for which the buff value is equal to '1'
      read(sockfd,buff,sizeof(buff));//Read the buff message which comes from server 
	
	
	printf("From Server : %s", buff);	// 			Display the message of the Room booking service in client
								bzero(buff, MAX); // initilize the buffer
        while((buff[k++] = getchar()) != '\n');	// 		get input from client on which room he would like to book
        

        write(sockfd,buff,sizeof(buff));	// 		send the value to server
        if(strncmp(buff, "SFLR",4)==0){	//		check wheather buff contains the code of the second floor room
        read(sockfd,buff,sizeof(buff));	//	if its true the read the message from server for confirmation of second floor booking
        printf("From Server : %s ",buff);		// 		display message of conifrmation
       
        }
        
      //------------------------------------------------------------------------------------------------------------------------          
        else if(strncmp(buff, "FFLR",4)==0){		//check wheather buff contains the code of the first floor room
        read(sockfd,buff,sizeof(buff));	//if its true the read the message from server for confirmation of first floor booking
        printf("From Server : %s ",buff);		// display message of conifrmation
        
        }
        //-------------------------------------------------------------------------------------------------------------------------------------------------
        else{
        read(sockfd,buff,sizeof(buff)); // Read Error Buffer containing Error message for any wrong inputs from server
        printf("From Server : %s ",buff); // Print error message in client.				
        } 
        }
        
        //----------------------------------------------------------------------------------------------------------------------------------------------Book Borrowing
        
        else if(strncmp(buff , "2",1)==0){ //checking for which the buff value is equal to '2' to enter the Book borrwing functions
        read(sockfd,buff,sizeof(buff));  //Read the buff message which comes from server 
        printf("From Server : %s", buff); // Print Buff Containing book borrwing welcome message
    bzero(buff,MAX);
        while((buff[k++] = getchar()) != '\n'); // get input from client
        write(sockfd,buff,sizeof(buff)); // write buff and send it to server
        if(strncmp(buff, "SDRA",4)==0){ // check wheather buffContains code for SDRA book
        read(sockfd,buff,sizeof(buff)); // read the confirmation message for the book
        printf("From Server : %s ",buff); //display the message inm clinet 
        }
        
        //----------------------------------------------------------------------------------------------------------------------------------
        else if(strncmp(buff, "PYTH",4)==0){// check wheather buff Contains code for Pyth book
        read(sockfd,buff,sizeof(buff));// read the confirmation message for the book
        printf("From Server : %s ",buff);//display the message inm clinet 
        }
        else if(strncmp(buff, "BGAE",4)==0){// check wheather buff Contains code for Betond good & evil book
        read(sockfd,buff,sizeof(buff));// read the confirmation message for the book
        printf("From Server : %s ",buff);//display the message inm clinet 
        }
        else if(strncmp(buff, "REPU",4)==0){// check wheather buff Contains code for Republic book
        read(sockfd,buff,sizeof(buff));// read the confirmation message for the book
        printf("From Server : %s ",buff);//display the message in clinet 
        }
        
        //---------------------------------------------------------------------------------------------------------------------------------
        else{
        read(sockfd,buff,sizeof(buff));// Read Error Buffer containing Error message for any wrong inputs from server
        printf("From Server : %s ",buff);// Print error message in client.
        }
        }
        //--------------------------------------------------------------------------------------------------------------------------------
        else if (strncmp(buff , "3",1)==0){ // check wheather the input of the user from main menu = '3'
        read(sockfd,buff,sizeof(buff));// read buff from server 
        printf("From Server : %s", buff);// display buff containg working hours welcome message from server .
           }
    else if (strncmp("exit", buff, 4) == 0 || strncmp("Exit", buff, 4) == 0){ 

            printf("Server Exit...\n"); 

            break; }
            
             else if (strncmp(buff , "4",1)==0){// check wheather the buff that user inputted = '4' 
          printf("Server Exit...\n"); 

            break;
        }
    else{
        read(sockfd,buff,sizeof(buff));// Read Error Buffer containing Error message for any wrong inputs from server
        printf("From Server : %s ",buff);// Print error message in client.
}
}
}
   
int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;
   
    // socket create and varification
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
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
   
    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else 
    welcomeMessage();
    client_menu_display();
        
   
    // function for chat
    func(sockfd);
   
    // close the socket
    close(sockfd);
    }

