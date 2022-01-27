#include "basiclib.h"
#include "resource.h"
#include "queue.h"
#include "encryption.h"
#include "keyexchange.h"
#include "transmit.h"

int main()
{
   struct datacontainer device1 = {'\0', 0}, server = {'\0', 0}, device2 = {'\0', 0};		//the three devices
   int i = 1;
   int choice;				
   char message[1000] = {'\0'};		//temporarily stores the message
   int link;						//stores the number of transmission link
   float time;						//stores the time taken to transmit the datas
   int bw[5];						//contains the bandwidth for the links
   struct Queue *q[5];				//To represent the transmission link

	//setting up the transmission links
   q[0] = createqueue();
   q[1] = createqueue();
   q[2] = createqueue();
   q[3] = createqueue();
   q[4] = createqueue();

	//This function initializes all the messages and key values to null and zero in all devices.
   void initDC()
   {
      memset(device1.msg, 0, sizeof(device1.msg));	
      device1.key[0] = 0;
      device1.key[1] = 0;
      device1.key[2] = 0;
      memset(device2.msg, 0, sizeof(device2.msg));
      device2.key[0] = 0;
      device2.key[1] = 0;
      device2.key[2] = 0;
      memset(server.msg, 0, sizeof(server.msg));
      server.key[0] = 0;
      server.key[1] = 0;
      server.key[2] = 0;
   }
	
	//Displays the information present in all the devices.
   void printdevice()
   {
      printf("\n\nDevice1 Data : ");
      if (strlen(device1.msg) == 0)
         printf("NULL");
      else
         printf("%s", device1.msg);

      printf("\nServer Data : ");
      if (strlen(server.msg) == 0)
         printf("NULL");
      else
         printf("%s", server.msg);

      printf("\nDevice2 Data : ");
      if (strlen(device2.msg) == 0)
         printf("NULL");
      else
         printf("%s", device2.msg);

      printf("\n");
   }
	//To get the integral input from the user.
   int input()
   {
      int number;
      scanf("%d", &number);
      getchar();
      return (number);
   }

	//User Interface
   while (i)		
   {
   	
      printf("\nPress 1 to Send Message\n");
      printf("Press 2 to Recieve Message\n");
      printf("Press 3 to Display Device Content\n");
      printf("Press 4 to Exit\n");
      printf("\nEnter your choice : ");

      choice = input();

      switch (choice)
      {
      case 1:
      {

         initDC();
         emptyqueue(q);

         printf("\nEnter the message (MAX: 1000 Characters): \n");
         scanf("%[^\n]%*c", message);
         if (strlen(message) == 0 || strlen(message) > 1000)
         {
            printf("\n!Invalid input!\n");
            break;
         }

         strcpy(device1.msg, message);

         printf("\ndevice1 data : %s\n", device1.msg);

         memset(message, 0, sizeof(message));

         printf("\nEnter no of Network Links (MAX: 5): \n");
         link = input();

         while (link < 1 || link > 5)
         {
            printf("\n!Invalid Input!\n");
            printf("Enter no of Network Links (MAX: 5): \n");
            link = input();
         }

         printf("\nEnter bandwidths for %d links (MAX: 25 Bytes/sec) : \n", link);
         for (int j = 0; j < link; j++)
         {
            bw[j] = input();

            if (bw[j] < 1 || bw[j] > 25)
            {
               j--;
               printf("\n!Invalid Input!\n");
            }
         }

         keyexchange(&device1, &device2, &server);
         encrypt(device1.msg, device1.key);

         // decrypt(device1.msg, device2.key);
         // printdevice();

         time = push(device1, q, link, bw);
         printf("\n\nTime taken to Send : %f", time);

         memset(device1.msg, 0, sizeof(device1.msg));

         printf("\n\nEnter to continue\n");
         getchar();

         printf("\n\nQueue History :");
         for (int j = 0; j < link; j++)
         {
            printf("\n link%d : ", j + 1);
            display(q[j]);
         }

         strcpy(server.msg, pop(server, q, link, message));
         memset(message, 0, sizeof(message));

         printdevice();

         printf("\n\nYour Message has been successfully sent to the server\nChoose Recieve to transfer it to device2");

         printf("\n\nEnter to continue\n\n");
         getchar();

         break;
      }

      case 2:
      {
         emptyqueue(q);

         printf("\nServer data : %s", server.msg);

         printf("\n\nEnter no of Network Links (MAX: 5): \n");
         link = input();

         while (link < 1 || link > 5)
         {
            printf("\n!Invalid Input!\n");
            printf("Enter no of Network Links (MAX: 5): \n");
            link = input();
         }

         printf("\nEnter bandwidths for %d links (MAX: 25 Bytes/sec) : \n", link);
         for (int j = 0; j < link; j++)
         {
            bw[j] = input();

            if (bw[j] < 1 || bw[j] > 25)
            {
               j--;
               printf("\n!Invalid Input!\n");
            }
         }

         time = push(server, q, link, bw);
         printf("\n\nTime taken to recieve : %f", time);

         memset(server.msg, 0, sizeof(server.msg));

         printf("\n\nQueue History :");
         for (int j = 0; j < link; j++)
         {
            printf("\n link%d : ", j + 1);
            display(q[j]);
         }

         strcpy(device2.msg, pop(device2, q, link, message));
         memset(message, 0, sizeof(message));

         decrypt(device2.msg, device2.key);

         printdevice();

         printf("\n\nYour Message has been successfully recieved by the device2");

         printf("\n\nEnter to continue\n\n");
         getchar();

         break;
      }

      case 3:
      {
         printdevice();
         printf("\n\nEnter to continue\n\n");
         getchar();

         break;
      }

      case 4:
      {
         exit(0);
         break;
      }

      default:
         printf("\n!!Invalid Input!!\n\n");
      }
   }

   return 0;
}
