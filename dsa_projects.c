#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
// structure for sentbox/trash box
struct messeges{
    char* number;
    char* time;
    char* messege;
    struct messeges* link;
}*top=NULL,*topt=NULL;
// structure for inbox
struct node
{
	char* number;
	char * message;
	int read;
    char* time;
	struct node *next;
}*head=NULL;
// Insertion in inbox
void create(struct node* node)
{
	struct node * newnode;
	newnode = node;
			if(head==NULL){
				head=newnode;
				newnode->next=NULL;
			}
			else{
				newnode->next=head;
				head=newnode;
			}
}
// insertion in  sent box
void push (){
    struct messeges* temp = (struct messeges*)malloc(sizeof(struct messeges));
    printf("enter the receiver mobile number: \n");
    temp->number=(char*)malloc(sizeof(char)*14);
    scanf(" %[^\n]s",temp->number);
    printf("enter the message:\n");
	temp->messege = (char*)malloc(sizeof(char)*200);
	scanf(" %[^\n]s",temp->messege);
    char* Time = (char*)malloc(sizeof(char)*25);
    time_t t;
    time(&t);
    strcpy(Time, ctime(&t));
    temp->time = Time;
	struct node * tem=(struct node*)malloc(sizeof(struct node));
	tem->number= temp->number;
	tem->message=temp->messege;
	tem->time = Time;
	tem->read=0;
	//create(tem);
    if(top == NULL){
        top=temp;
        temp->link=NULL;
    }
    else{
        temp->link=top;
        top=temp;
    }
}
void display(){
    struct messeges* temp=top;
    if (temp==NULL)
    printf("empty\n");
	else{
    while(temp != NULL){
        printf("%s\n",temp->number);
        printf("messege:%s\n",temp->messege);
        printf("This message was sent at:%s\n",temp->time);
        temp=temp->link;
    }
	}
}
void pushtrash(struct messeges* tem){
    if(topt==NULL) {
        topt=tem;
        tem->link=NULL;
    }
    else {
        tem->link=topt;
        topt=tem;
    }
}
void deleteatk()
{
     int flag ;
	  char* Num = (char*) malloc(sizeof(char)*14);
	 printf("enter number to search:\n");
        scanf(" %[^\n]s",Num);
		if(strcmp(top->number,Num)==0){
			struct messeges* temp1=top;
			 char* Time = (char*)malloc(sizeof(char)*30);
           time_t t;
           time(&t);
           strcpy(Time, ctime(&t));
           temp1->time=Time;
			top=top->link;
		   pushtrash(temp1);
		}
		else{
		struct messeges* temp = top;
		 while(temp!=NULL){
		flag =strcmp(temp->link->number,Num);
        if(flag == 0){
            struct messeges * temp2=temp->link;
           char* Time = (char*)malloc(sizeof(char)*30);
           time_t t;
           time(&t);
           strcpy(Time, ctime(&t));
           temp2->time=Time;
		   temp->link=temp->link->link;
            pushtrash(temp2);
            break;
        }
        else {
            temp=temp->link;
        }
		 }
    }
 }

void displayt()
{
	 struct messeges* temp=topt;
    if(temp==NULL)
    printf("empty\n");
	else{
    while(temp != NULL){
        printf("%s\n",temp->number);
        printf("%s\n",temp->messege);
         printf("This message was deleted at:%s\n",temp->time);
        temp=temp->link;
    }
	}
}
void search(){
    int flag ,count=0;
    struct messeges* temp = top;
	 char* Num = (char*) malloc(sizeof(char)*14);
	 printf("enter number to search:\n");
        scanf(" %[^\n]s",Num);
    while(temp!=NULL){
       flag=strcmp(temp->number,Num);
       if(flag == 0){
            printf("%s\n",temp->number);
            printf("%s\n",temp->messege);
			count =1;
            break;
        }
        else{
            temp=temp->link;
        }
    }
	if(count == 0)
	printf("no message found with that number\n");
}
void deleteinbox()
{
     int flag ;
	  char* Num = (char*) malloc(sizeof(char)*14);
	 printf("enter number to search:\n");
        scanf(" %[^\n]s",Num);
		if(strcmp(head->number,Num)==0){
			struct messeges* temp1=top;
			 char* Time = (char*)malloc(sizeof(char)*30);
           time_t t;
           time(&t);
           strcpy(Time, ctime(&t));
           temp1->time=Time;
			top=top->link;
		   pushtrash(temp1);
		}
		else{
		struct messeges* temp = top;
		 while(temp!=NULL){
		flag =strcmp(temp->link->number,Num);
        if(flag == 0){
            struct messeges * temp2=temp->link;
           char* Time = (char*)malloc(sizeof(char)*30);
           time_t t;
           time(&t);
           strcpy(Time, ctime(&t));
           temp2->time=Time;
		   temp->link=temp->link->link;
            pushtrash(temp2);
            break;
        }
        else {
            temp=temp->link;
        }
		 }
    }
 }
void displayinbox()
{
	if(head==NULL)
	printf("List is empty\n");
	else{
		printf("\nelements in list are :\n");
		struct node *temp;
		temp=head;
		while(temp!=NULL){
			printf("Number is %s\n",temp->number);
			printf("Mesaage is %s\n ",temp->message);
            temp->read == 1 ?printf("read status:Read \n"):printf("read status:Not Read\n");
            printf("the time is:%s\n",temp->time);
			temp=temp->next;
		}
		printf("\n");
	}
}
void function()
{
    struct node * temp1 = (struct node *)malloc(sizeof(struct node));
    temp1->message="hai";temp1->number="mummy";temp1->read=0;temp1->time="Mon Jun 1 11:49:52 2022";
    create(temp1);
     struct node * temp2 = (struct node *)malloc(sizeof(struct node));
    temp2->message="how are you";temp2->number="9951165067";temp2->read=0;temp2->time="Mon Jun 04 15:59:52 2022";
    create(temp2);
     struct node * temp3= (struct node *)malloc(sizeof(struct node));
    temp3->message="who are you";temp3->number="bro";temp3->read=0;temp3->time="Mon Jun 5 19:52:59 2022";
    create(temp3);
     struct node * temp4 = (struct node *)malloc(sizeof(struct node));
    temp4->message="Dear Customer, Your a/c no. XXXXXXXX9240 is debited for Rs.1.00 on 10-06-22 , If not done by you, call 1800111109-SBI";temp4->number="SBI";temp4->read=0;temp4->time="Mon Jun 10 09:50:52 2022";
    create(temp4);
     struct node * temp5 = (struct node *)malloc(sizeof(struct node));
    temp5->message="welcome to chai club";temp5->number="9959118077";temp5->read=0;temp5->time="Mon Jun 15 09:49:52 2022";
    create(temp5);
     struct node * temp6 = (struct node *)malloc(sizeof(struct node));
    temp6->message="hai";temp6->number="friend";temp6->read=0;temp6->time="Sun Jun 26 22:49:54 2022";
    create(temp6);
     struct node * temp7 = (struct node *)malloc(sizeof(struct node));
    temp7->message="";temp7->number="9951285792";temp7->read=0;temp7->time="Mon Jun 27 09:50:58 2022";
    create(temp7);
}
void searchbymessage()
{
	int mycount=0;
	char str2[100];
	if(head==NULL){
		printf("\n\n list is empty...no elements to search..!!\n\n");
	}
	else{
		printf("\n\n enter the message to search\n\n");
		scanf("%s",&str2);
		struct node *temp;
		temp=head;
		while(temp!=NULL){
			if(strcmp(temp->message, str2)==0){
				printf("\nMessage is found in the list\n");
				printf("Message read is %d\n",temp->read);
				mycount=1;
				break;
			}
			else{
				temp=temp->next;
			}
		}
		if(mycount==0) printf("\nMessage not found in list\n");
	}
}
void searchbynumber()
{
	int mycount=0;
	char str2[100];
	if(head==NULL){
		printf("\n\n list is empty...no elements to search..!!\n\n");
	}
	else{
		printf("\n enter the Number to search\n");
		scanf("%s",&str2);
		struct node *temp;
		temp=head;
		while(temp!=NULL){
			if(strcmp(temp->number, str2)==0){
				printf("\nNumber is found in the list\n");
                 printf("%s",temp->message);
				printf("Message read is %d\n",temp->read); 
				mycount=1;
				break;
			}
			else{
				temp=temp->next;
			}
		}
		if(mycount==0) printf("\n\nMessage not found in list\n\n");
	}
}
void markread()
{
	int mycount=0;
	char str2[100];
	if(head==NULL){
		printf("\n\n list is empty...no elements to search..!!\n\n");
	}
	else{
		printf("\n\n enter the message to search\n\n");
		scanf("%s",&str2);
		struct node *temp;
		temp=head;
		while(temp!=NULL){
			if(strcmp(temp->number, str2)==0){
				printf("\nMessage is found in the list\n");
				temp->read=1;
				printf("Message marked as read\n");
				mycount=1;
				break;
			}
			else{
				temp=temp->next;
			}
		}
		if(mycount==0) printf("\n\nMessage not found in list\n\n");
	}
}
void read_messages()
{
	if(head==NULL){
		printf("\n\n list is empty...no elements to search..!!\n\n");
	}
	else{
		struct node *temp;
		temp=head;
		while(temp!=NULL){
			if(temp->read==1){
				printf("\n\nphone is %s\n",temp->number);
				printf("\n\n Message is %s\n\n",temp->message);
				temp=temp->next;
			}
			else{
				temp=temp->next;
			}
		}
	}
}
void unread_messeges()
{
	if(head==NULL){
		printf("\n\n list is empty...no elements to search..!!\n\n");
	}
	else{
		struct node *temp;
		temp=head;
		while(temp!=NULL){
			if(temp->read==0)	{
				printf("\n\nphone is %s\n",temp->number);
				printf("\n\n Message is %s\n\n",temp->message);
				temp=temp->next;
			}
			else{
				temp=temp->next;
			}
		}
	}
}
void markallasread()
{
	if(head==NULL)
	printf("\n\nList is empty\n\n");
	else
	{
		printf("\nelements in list are :\n\n");
		struct node *temp;
		temp=head;
		while(temp!=NULL)
		{
			temp->read=1;
			temp=temp->next;
		}
		printf("\n Marked all as read\n");
	}
}
int main(){
      int option;
	   int i=1;
       function();
      while(i !=0)
      { int c;
		printf("which box you want to use:1.SENT BOX\n 2.INBOX\n 3.TRASH BOX\n4.TO OPEN BOTH INBOX AND SENTBOX\n");
		scanf("%d",&c);
		if(c==1){
        printf("enter the choice:1.to send a message\n2.to see sent messages\n3.to delete messages\n4.to search a message\n");
        scanf("%d",&option);
       switch(option)
       {
         case 1: push();
         break;
         case 2:display();
         break;
         case 3:deleteatk();
          break;
		   case 4:search();
		 break;
		  default:printf("enter correct option\n");
	   }
		}
        else if (c==2){
			printf("enter the choice:1.to search a message by message\n2.to search a message by number\n3.to delete messages\n4.to see unread messeges\n5.to mark all messages as read\n6.to display inbox\n7.to display read messages\n8.to read a message\n");
            scanf("%d",&option);
            switch(option){
		    case 1:searchbymessage();
			break;
	        case 2:searchbynumber();
		    break;
            case 3: deleteinbox();
            break;
		    case 4: unread_messeges();
			break;
			case 5: markallasread();
            break;
			case 6:displayinbox();
			break;
			case 7:read_messages();
		    break;
			case 8: markread();
			break;
         default:printf("enter correct option\n");
       }
		}
	   else if(c == 3){
		printf("enter the choice:1.to display trash box\n");
        scanf("%d",&option);
       switch(option){
		case 1:
		 displayt();
		 break;
		 default:printf("enter correct option\n");
	   }
	   }
	   else if(c==4){
		  display();
		  displayinbox();
	   }
	   else{
		printf("try again by entering correct option\n");
	   }
      printf("press 0 to exit or any key to continue:\n");
       scanf("%d",&i);
      }
    return 0;
}