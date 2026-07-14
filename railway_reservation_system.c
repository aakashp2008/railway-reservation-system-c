#include <stdio.h>

struct Passenger
{
    int id;
    char name[50];
    int age;
    char source[30];
    char destination[30];
};

struct Passenger p[100];
int count = 0;

void bookTicket()
{
    printf("\nEnter Passenger ID: ");
    scanf("%d", &p[count].id);

    printf("Enter Passenger Name: ");
    scanf(" %[^\n]", p[count].name);

    printf("Enter Age: ");
    scanf("%d", &p[count].age);

    printf("Enter Source: ");
    scanf("%s", p[count].source);

    printf("Enter Destination: ");
    scanf("%s", p[count].destination);

    count++;

    printf("\nTicket Booked Successfully!\n");
}

void displayTickets()
{
    if(count == 0)
    {
        printf("\nNo Reservation Records Found!\n");
        return;
    }

    printf("\n========== Reservation Details ==========\n");

    for(int i = 0; i < count; i++)
    {
        printf("\nPassenger %d\n", i + 1);
        printf("Passenger ID : %d\n", p[i].id);
        printf("Name         : %s\n", p[i].name);
        printf("Age          : %d\n", p[i].age);
        printf("Source       : %s\n", p[i].source);
        printf("Destination  : %s\n", p[i].destination);
    }
}

void searchTicket()
{
    int id, found = 0;

    printf("\nEnter Passenger ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(p[i].id == id)
        {
            printf("\nPassenger Found!\n");
            printf("Passenger ID : %d\n", p[i].id);
            printf("Name         : %s\n", p[i].name);
            printf("Age          : %d\n", p[i].age);
            printf("Source       : %s\n", p[i].source);
            printf("Destination  : %s\n", p[i].destination);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nPassenger Not Found!\n");
}

void updateTicket()
{
    int id, found = 0;

    printf("\nEnter Passenger ID to Update: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(p[i].id == id)
        {
            printf("Enter New Name: ");
            scanf(" %[^\n]", p[i].name);

            printf("Enter New Age: ");
            scanf("%d", &p[i].age);

            printf("Enter New Source: ");
            scanf("%s", p[i].source);

            printf("Enter New Destination: ");
            scanf("%s", p[i].destination);

            printf("\nReservation Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nPassenger Not Found!\n");
}

void cancelTicket()
{
    int id, found = 0;

    printf("\nEnter Passenger ID to Cancel: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(p[i].id == id)
        {
            for(int j = i; j < count - 1; j++)
            {
                p[j] = p[j + 1];
            }

            count--;
            printf("\nReservation Cancelled Successfully!\n");
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("\nPassenger Not Found!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n========== Railway Reservation System ==========\n");
        printf("1. Book Ticket\n");
        printf("2. Display Reservations\n");
        printf("3. Search Reservation\n");
        printf("4. Update Reservation\n");
        printf("5. Cancel Reservation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bookTicket();
                break;

            case 2:
                displayTickets();
                break;

            case 3:
                searchTicket();
                break;

            case 4:
                updateTicket();
                break;

            case 5:
                cancelTicket();
                break;

            case 6:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}
