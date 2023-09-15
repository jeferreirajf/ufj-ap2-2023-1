#include <stdio.h>
#include <string.h>

struct s_date
{
    int day;
    int month;
    int year;
};

typedef struct s_date Date;

struct s_appointment
{
    char description[50];
    Date date;
};

typedef struct s_appointment Appointment;

struct s_agenda
{
    int size;
    Appointment appointments[100];
};

typedef struct s_agenda Agenda;

Date createDate(int day, int month, int year)
{
    Date date;

    date.day = day;
    date.month = month;
    date.year = year;

    return date;
}

void printDate(Date date)
{
    printf("%d/%d/%d", date.day, date.month, date.year);
}

Appointment createAppointment(char *description, Date date)
{
    Appointment appointment;

    strcpy(appointment.description, description);
    appointment.date = date;

    return appointment;
}

void printAppointment(Appointment appointment)
{
    printDate(appointment.date);
    printf("\n");
    printf("%s\n", appointment.description);
}

Agenda createAgenda()
{
    Agenda agenda;

    agenda.size = 0;

    return agenda;
}

void printAgenda(Agenda agenda)
{
    int i;

    printf("size: %d\n", agenda.size);

    for (i = 0; i < agenda.size; i++)
    {
        printAppointment(agenda.appointments[i]);
        printf("==================\n");
    }
}

void addAppointment(Agenda *agenda, char *description, Date date)
{
    Appointment appointment = createAppointment(description, date);
    agenda->appointments[agenda->size] = appointment;
    agenda->size++;
}

int main()
{
    int option = 0;

    Agenda agenda = createAgenda();

    do
    {
        printf("1 - Add Appointment\n");
        printf("2 - Print Agenda\n");
        printf("3 - Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                char description[100];
                printf("Digite a descricao do compromisso: \n");
                scanf("%s", description);

                printf("O compromisso: %s\n", description);

                Date date;

                printf("Digite a data do compromisso no formato dd mm aaaa: \n");
                scanf("%d %d %d", &date.day, &date.month, &date.year);

                addAppointment(&agenda, description, date);

                break;

            case 2:
                printAgenda(agenda);
                break;
        }
    } while (option != 3);

    return 0;
}