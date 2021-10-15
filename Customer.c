#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


struct dimensions
{
	float length,width,height,diameter;
	int cavity;
};


struct order
{
	int order_id;
	int qty;
	char name[50];
	char contact[20];
	char address[200] ;	
	char order_type[50];
	char order_subtype[20];
	struct dimensions dim;
	char status[50];	
}s;




void create_record(struct order s)
{
	system("cls");
	fflush(stdin);
	printf("Enter your name: ");
	fgets(s.name,49,stdin);
	fflush(stdin);
	printf("Enter your address details: ");
	fgets(s.address,199,stdin);
	fflush(stdin);
	printf("Enter your Contact number: ");
	fgets(s.contact,19,stdin);
	fflush(stdin);
	printf("Enter quantity of your order: ");
	scanf("%d",&s.qty);
	strcpy(s.status,"Response Pending");
	s.order_id = create_id();
		
		FILE *fp;
		fp = fopen("customer.txt","ab+");
		if (fp==NULL)
			{
				printf("\ncannot open file.\nPress any key to continue...");
				getch();
				fclose(fp);
				return;			
			}
			
		fwrite(&s,sizeof(s),1,fp);
		
		fclose(fp);
		printf("RECORD STORED SUCCESSFULLY!!!!!\nPress any key to continue...");
		getch();
}
int create_id()
{
	int id;
		FILE *fp;
			fp = fopen("customer.txt","ab+");
			if (fp==NULL)
			{
				printf("\ncannot open file.\nPress any key to continue...\n");
				getch();
				fclose(fp);
				return;	
			}
			while (fread(&s,sizeof(s),1,fp)>0)
				{
					
				}	
			if(s.order_id == '\0')
			{
				id = 1;
			}
			else
			{
				id = s.order_id + 1;
			}
			fclose(fp);
			printf("\nyour order id is: %d\n",id);
			return id;
}
int check_id(int id)
{
	int flag=0;
	FILE *fp;
		fp = fopen("customer.txt","rb+");
		if (fp==NULL)
		{
			printf("\ncannot open file.\nPress any key to continue...");
			getch();
			fclose(fp);
			return;	
		}
		while (fread(&s,sizeof(s),1,fp)>0)
		{
			if (s.order_id==id)
			{
				flag = 1;
			}
		}
		fclose(fp);
		return flag;
}

void search(int id)
{
	int flag=0;
		FILE *fp;
		fp = fopen("customer.txt","rb+");
		if (fp==NULL)
		{
			printf("\ncannot open file.\nPress any key to continue...\n");
			getch();
			fclose(fp);
			return;	
		}
		while (fread(&s,sizeof(s),1,fp)>0)
		{
			if (s.order_id==id)
			{
				flag = 1;
				printf("\n\n\tYour Record Is As Follows:\n\n");
				printf("\nID: %d\nQuantity: %d\nName: %s\nContact: %s\nAddress: %s\nOrder Type: %s\nOrder Sub-type: %s\nOrder Dimensions:\n	Height: %.2f\n	Length: %.2f\n	Width: %.2f\n	Diameter: %.2f\n	Cavity: %d\nStatus: %s",s.order_id,s.qty,s.name,s.contact,s.address,s.order_type,s.order_subtype,s.dim.height,s.dim.length,s.dim.width,s.dim.diameter,s.dim.cavity,s.status);
				printf("\nPress any key to continue...");
				getch();				
			}
		}
		if(flag == 0)
		{
			printf("\nNo Search Record Found!");
		}
		fclose(fp);
		return;
}
void buy()
{
	int ch_2,ch_3;

	printf("What would you like to buy?\n\n");
	printf("\t\t1: Buy mould of caps\n ");
	printf("\t\t2: Buy mould of basket\n ");
	printf("\t\t3: Buy mould of Simple air-tight container\n ");
	scanf("%d",&ch_2);
	if(ch_2 == 1)
	{
		strcpy(s->order_type,"Cap");
	}
	else if (ch_2 == 2)
	{
		strcpy(s->order_type,"Basket");
	}
	else if (ch_2 == 3)
	{
		strcpy(s->order_type,"Simple air-tight container");
	}
		
	switch(ch_2)
	{
		case 1:
			{
				baskket.basketdimset()
			}
		case 2:
			{
				system("cls");
				printf("Which kind of basket mould would you like to buy?\n\n");
				printf("\t\t1:acrylic-design basket \n ");
				printf("\t\t2:simple-plastic basket \n ");
				scanf("%d",&ch_3);
				if(ch_3 == 1)
				{
					strcpy(s->order_subtype,"Acrylic-design");
				}
				else if (ch_3 == 2)
				{
					strcpy(s->order_subtype,"Simple Plastic");
				}
				else
				{
					printf("Invalid Input.\nPress any key to  continue...");
					getch();
					return;
				}
				printf("Enter the height of mould in mm:");
				scanf("%f",&s->dim.height);
				printf("Enter the length of mould in mm:");
				scanf("%f",&s->dim.length);
				printf("Enter the width of mould in mm:");
				scanf("%f",&s->dim.width);
				s->dim.diameter=0.0;
				s->dim.cavity=0;
				break;
			}
		case 3:
			{
				system("cls");
				printf("What shape of simple air-tight container mould would you like to buy?\n\n");
				printf("\t\t1:Round \n ");
				printf("\t\t2:Rectangle \n ");
				scanf("%d",&ch_3);
				if(ch_3 == 1)
				{
					strcpy(s->order_subtype,"Round");
				}
				else if (ch_3 == 2)
				{
					strcpy(s->order_subtype,"Rectangle");
				}
				else
				{
					printf("Invalid Input.\nPress any key to  continue...");
					getch();
					return;
				}
				printf("Enter the height of mould in mm:");
				scanf("%f",&s->dim.height);
				printf("Enter the width of mould in mm:");
				scanf("%f",&s->dim.width);
				printf("Enter the length of mould in mm:");
				scanf("%f",&s->dim.length);
				s->dim.diameter=0.0;
				s->dim.cavity=0;
				break;
			}
		default:
			{
				system("cls");
				printf("Invalid Input.\nPress any key to  continue...");
				getch();
				return;
			}
	}
	return;	
}
int main()
{
	
	char ch_1;
	while(ch_1!=4)
	{
		system("cls");
		printf("\t***********************************************\n");
		printf("\t\tPATEL and KHAN Mould Walai\n");
		printf("\t***********************************************\n");
		
			printf("\t\n\n\n***What would you like to do?***\n\n\n");
			printf("\t\t1: Buy\n");
			printf("\t\t2: Check order status\n");
			printf("\t\t3: Exit\n");
			ch_1 = getch();
			
		switch(ch_1)
		{
			case '1':
				{
					system("cls");
					buy(&s);
					create_record(s);
					break;
				}
			case '2':
				{
					int check,id;
					system("cls");
					printf("Enter your order ID:");
					scanf("%d",&id);
					check = check_id(id);
					if(check == 0)
					{
						printf("ID does not exist.\nPress any key to  continue...");
						getch();
						break;
					}
					search(id);
					break;
				}
			case '3':
				{
					system("cls");
					exit(1);
					break;
				}

			default:
				{
					system("cls");
					printf("Invalid Input.\nPress any key to continue...");
					getch();
					break;
				}
		}
		
			
	}
	
	return 0;
	
}
