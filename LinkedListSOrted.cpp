/* Write Menu Driven Program to Implement Single Linked List Operations Using C */
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*ptr;
void counter(){
	int cnt=0;
	if(head==NULL)
		printf("The list is empty");
		else{
			ptr=head;
			//while(ptr!=NULL)
			while(ptr->next!=NULL)
			{
				cnt++;
				ptr=ptr->next;	
			}
			printf("The no. of nodes are %d",cnt);
		}
	}

void  insertatpos(int pos,int data,struct node*head){
	int cnt=0;
	struct node* ptr;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	while(ptr!=NULL){
		cnt++;
		printf("%d ok\n",cnt);
		if(cnt==pos-1){
			temp->data=data;
			temp->next=ptr->next;
			ptr->next=temp;
			printf("%d\n",head->data);
			printf("kol %d",head->next->next->data);
			printf("\n Inserted\n");
			break;
			}
		ptr=ptr->next;
	}
}
/*void  insertatpos(int pos,int data,struct node*head){
	int cnt=0;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	while(head!=NULL){
		cnt++;
		if(cnt==pos){
			temp->data=data;
			temp=head->next;
			temp->next=head->next->next;
			printf("\ninserted\n");
					}
		head=head->next;
	}
}*/
void insert_begin(int value)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	if (head==NULL)
	{
		head=temp;
		printf("scs\n");
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}
void insert_end(int value)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;

	if (head== NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->next=NULL;
	}
}

void insert_After_specified_ele(int value,int ele)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if (head== NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;
		while(ptr->data != ele)
		{
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}
	
}
void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head

        printf("\nSUCCESSFULLY REVERSED LIST\n");
    }
}
void delete_begin()
{
	if (head== NULL)
	{
		printf("List is Empty, Deletion is not Possible");
	}
	else
	{
		ptr=head;
		head=head->next;
		//printf("%d",ptr->next);
		ptr->next=NULL;
		free(ptr);
	}
}
/*void delete_end()
{
	if (head== NULL)
	{
		printf("List if Empty, Deletion is not Possible");
	}
	else
	{
		struct node *p; 
		ptr=head;
		while(ptr->next != NULL)
		{
		p=ptr;
		ptr=ptr->next;	
		}
		p->next=NULL;
		free(ptr);
	}
}*/
//iss delete k code m kya dikkat hai?

void del_end(){
	if(head==NULL)
	printf("The list is empty");
	else{
		ptr=head;
		while(ptr->next->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next=NULL;
		//ASK THE QUESTION ABOUT wether necessary to use the free() or not;
			}
}
void delete_middle(int ele)
{
	if (head== NULL)
	{
		printf("List if Empty, Deletion is not Possible");
	}
	else
	{
		struct node *p; 
		ptr=head;
		while(ptr->data != ele)
		{
			p=ptr;
			ptr=ptr->next;
		}
		p->next=ptr->next;
		free(ptr);
	}
}
void display()
{
	if (head== NULL)
	{
		printf("List if Empty");
	}
	else
	{
		ptr=head;
		while( ptr != NULL)
		{
			printf("-> %d", ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}
int main()
{	struct node*one=(struct node*)malloc(sizeof(struct node));
	one->data=45;
	one->next=NULL;
	int value,ele,ch=0;
	printf("1. Insert_begin \n");
	printf("2. Insert_end \n");
	printf("3. Insert_After_specified_element \n");
	printf("4. delete_begin \n");
	printf("5. delete_end \n");
	printf("6. delete_middle \n");
	printf("7. insert at Given position\n");
	printf("8. Display\n");
	printf("9. exit \n");
	printf("10.Count of elements\n");
	printf("11.Reverse dsiplay\n");
	printf("12.Want to finish\n");
	
	while(ch!=12)
	{
		printf("Enter the Choice \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("Enter the value");
					scanf("%d",&value);
					insert_begin(value);
					display();
					break;
				}
				case 2:
				{
					printf("Enter the value");
					scanf("%d",&value);
					insert_end(value);
					display();
					break;
				}	
				case 3:
					{
					printf("Enter the value");
					scanf("%d",&value);
					printf("After which element u want to insert");
					scanf("%d",&ele);
					insert_After_specified_ele(value,ele);
					display();
					break;
				}
				case 4:
					{
					delete_begin();
					display();
					break;
				}
				case 5:
				{
					del_end();
					display();
					break;
				}
				case 6:
				{
					printf("Enter the element you want to delete");
					scanf("%d",&ele);
					delete_middle(ele);
					display();
					break;
				}	
				case 7:
					{
					int data,pos;
					printf("Enter the data\n");
					scanf("%d",&data);
					printf("Enter the position\n");
					scanf("%d",&pos);
					insertatpos(pos,data,head);}
					display();
					break;
				case 8:
					display();
					//exit(0);
					break;
				case 10:
					counter();
					break;
					case 11:
						reverseList();
						display();
						break;
					case 12:
						printf("Good to see u again!!");
						break;
						default:
							printf("WRoGN choice selected\n");
								
				}
		}
	}
	
	
	
	

