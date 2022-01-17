#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void sign_in_up()
{
    struct signup
    {
        char name[100];
        char last_name[100];
        char email_mobno[100];
        char password[100];
    }a[100][100];
    struct signin
    {
        char email_mob_no[100];
        char password[100];
    }b;
    int c,i,n=0;
    while(1)
    {
        int t=1;
        printf("Enter 1-Sign up OR 2-Sign in:");
        scanf("%d",&c);
        if(c==1)
        {
            for(i=n;i<100;i++)
            {
                printf("Enter your name:");
                scanf("%s",a[i][100].name);
                printf("Enter your last name:");
                scanf("%s",a[i][100].last_name);
                printf("Enter your email/mob no.:");
                scanf("%s",a[i][100].email_mobno);
                printf("Enter your password:");
                scanf("%s",a[i][100].password);
                n++;
                break;
            }
            continue;
        }
        else if(c==2)
        {
            printf("Enter email/mob no.:");
            scanf("%s",b.email_mob_no);
            for(i=0;i<=n;i++)
            {
                if(strcmp(b.email_mob_no,a[i][100].email_mobno)==0)
                {
                    while(t>0)
                    {
                        printf("Enter password:");
                        scanf("%s",b.password);
                        if(strcmp(b.password,a[i][100].password)==0)
                        {
                            printf("Welcome %s %s\n",a[i][100].name,a[i][100].last_name);
                            break;
                        }
                        else
                        {
                            printf("You entered wrong password.\n");
                            continue;
                        }
                    }   
                    break;
                }
                else
                {
                    if(i==n)
                    {
                        printf("User does not exist.\nPLease enter valid email or mob no.");
                        printf("\nIf you are not signed up please sign up\n");
                        t=2;
                        break;
                    }
                    else 
                    {
                        continue;
                    }
                }
            }
            if(t==2)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("Wrong Input\a\n");
        }
    }
}
void room()
{
    int i,j,n,e,total,g;
    int a[20]={101,102,103,104,105,106,107,108,109,110,201,202,203,204,205,206,207,208,209,210};
    int b[20];
    char c[8]="Booked";
    char s[6]="Open";
    printf("Welcome to WEEB HUB HOTEL room booking.\nAll rooms are AC\n");
    printf("List of all the rooms.\n");
    printf("The check in price of the room is Rs.2500\nAfter first day Rs.300 per night\n");
    for(i=0;i<20;i++)
    {
        printf("%d\t%s\n",a[i],s);
    }
    printf("Enter the no. of rooms that you want to book:");
    scanf("%d",&n);
    printf("Enter the no. of days you will be staying:");
    scanf("%d",&e);
    if(e>1)
    {
        total=(n*2500)+(e*n*300);
    }
    else
    {
        total=n*2500;
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the room no. that you wnat to book from the avobe list:");
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t%s\n",b[i],c);
    }
    g=rand();
    printf("Total Amount of room booking=Rs.%d\nTicket No.=%d",total,g);
    FILE *fr;
    fr = fopen("record2.txt", "a");
    char f[200];
    printf("\nEnter Customer Name:");
    scanf("%s", f); 
    fprintf(fr, "------------------------------------------\nName of Customer=>%s\nTotal room rent=Rs.%d\nNo. of days staying=%d\nTicket no.=%d\n------------------------------------------\n", f, total, e, g); 
    fclose(fr);
}
void employee()
{
    char c;
    FILE *fr;
    fr=fopen("LOE.txt","r");
    while( c != EOF)
    {
        c = fgetc(fr);
        printf("%c",c); 
    }
}
void bill()
{
    struct billing
    {
        int item_no;
        int quantity;
        int price_single_item;
    }a[17];
    int total_price=0;
    char item_name[17][100]={"French_Fries","Chilli_Cheese_Toast","Grilled_Sandwich","Russian_Salad/Maccroni","Veg_Burger","Shahi_Paneer","Kadhai_Paneer","Paneer_Butter_Masala","Tandoori_Roti","Butter_Naan","Garlic_Naan_Butter","Jeera_Rice","Dal_Makhani","Idli_Sambhar","Mysore_Dosa","Sambhar_Vada","Mix_Veg_Uttapam"};
    int rate[17]={106,115,175,119,72,210,210,250,30,58,60,150,192,81,123,85,155};
    int i=0,k;
    printf("-----------MENU-----------\n");
    for(i;i<17;i++)
    {
        printf("%d---",(i+1));
        for(k=0;k<100;k++)
        {
            printf("%c",item_name[i][k]);
        }
        printf("---%d\n",rate[i]);
    }
    char snt[2];
    int f,j=0;
    i=0;
    printf("Enter total no. of different item ordered:");
    scanf("%d",&f);
    for(i=0;i<f;i++)
    {
        printf("Please enter item no.:");
        scanf("%d",&a[i].item_no);
        printf("Please enter quantity purchased:");
        scanf("%d",&a[i].quantity);
        a[i].price_single_item=(rate[(a[i].item_no-1)])*(a[i].quantity);
        total_price+=a[i].price_single_item;
    }
    printf("Items will be displayed in the format given below.\n");
    printf("SNo.   Item No.   Item Name   Rate   Quantity   Price\n");
    for(i=0;i<f;i++)
    {
        printf("%d---%d---",(i+1),a[i].item_no);
        for(k=0;k<100;k++)
        {
            printf("%c",item_name[((a[i].item_no)-1)][k]);
        }
        printf("---%d---%d---%d\n",rate[(a[i].item_no-1)],a[i].quantity,a[i].price_single_item);
    }
    printf("Total Price is:Rs.%d",total_price);
    FILE *fr;
    fr = fopen("record.txt", "a");
    char s[200];
    printf("\nEnter Customer Name:");
    scanf("%s", s); 
    fprintf(fr, "\nName of Customer=>%s----Amount spent=Rs.%d", s, total_price); 
    fclose(fr);
}
void admin()
{
    char a[6]="admin";
    char b[6];
    char c[6];
    int t=1;
    while(t>0)
    {
        printf("Enter username:");
        scanf("%s",b);
        if(strcmp(b,a)==0)
        {
            while(t>0)
            {
                printf("Enter Password:");
                scanf("%s",c);
                if(strcmp(c,a)==0)
                {
                    printf("welcome Admin\n");
                    break;
                }
                else
                {
                    printf("Wrong Password\nTry again\n");
                }
            }
            break;
        }
        else
        {
            printf("Wrong username!\nTry again\n");
        }
    }
}
void main()
{
    int a,t=0;
    printf("welcome to:\n***************************WEEB HUB HOTEL***************************\n");
    while(t==0)
    {
        printf("Please enter\n");
        printf("1-Admin login\n2-User login\n3-Exit the program\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            {
                admin();
                printf("1-To make bill\n2-To see employee list\n3-To see the record of food bill\n4-To see record of room booking\n");
                scanf("%d",&a);
                switch(a)
                {
                    case 1:
                    {
                        bill();
                        printf("\n");
                        break;
                    }
                    case 2:
                    {
                        employee();
                        printf("\n");
                        break;
                    }
                    case 3:
                    {
                        char c;
                        FILE *fr;
                        fr=fopen("record.txt","r");
                        while( c != EOF)
                        {
                            c = fgetc(fr);
                            printf("%c",c); 
                        }
                        printf("\n");
                        break;
                    }
                    case 4:
                    {
                        char c;
                        FILE *fr;
                        fr=fopen("record2.txt","r");
                        while( c != EOF)
                        {
                            c = fgetc(fr);
                            printf("%c",c); 
                        }   
                        printf("\n");
                        break;
                    }
                    default:
                    {
                        printf("Wrong Input\a\n");
                        break;
                    } 
                }
                break;
            }
            case 2:
            {
                sign_in_up();
                printf("1-To book room\n");
                scanf("%d",&a);
                if(a==1)
                {
                    room();
                    printf("\n");
                }
                else
                {
                    printf("Wrong Input\a\n");
                    continue;
                }
                break;
            }
            case 3:
            {
                printf("Exiting the program!");
                exit(1);
            }
            default:
            {
                printf("Wrong Input\a\n");
                break;
            }
        }
    }
}