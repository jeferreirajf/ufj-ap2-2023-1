#include <stdio.h>

#define AGENDA_LENGTH 100

struct s_data {
    int day;
    int month;
    int year;
};

typedef struct s_data Data;

struct s_agenda {
    int n;
    Data data[AGENDA_LENGTH];
    char* description[AGENDA_LENGTH];
};

typedef struct s_agenda Agenda;

Data createData(int day, int month, int year){
    Data d;
    d.day = day;
    d.month = month;
    d.year = year;

    return d;
}

void scheduleEvent(Agenda* agenda, Data d, char* description){
    agenda->data[agenda->n] = d;
    agenda->description[agenda->n] = description;
    agenda->n++;
}

Agenda createAgenda(){
    Agenda agenda;
    agenda.n = 0;

    return agenda;
}

void printAgenda(Agenda agenda){
    for(int i = 0; i < agenda.n; i++){
        printf("%d/%d/%d: %s\n", agenda.data[i].day, 
            agenda.data[i].month, agenda.data[i].year,
            agenda.description[i]);
    }
}

int main(){

    Agenda mySchedule = createAgenda();

    Data d = createData(23, 6, 23);

    scheduleEvent(&mySchedule, d, "Aula de Ap2");

    Data d2 = createData(30, 6, 23);

    scheduleEvent(&mySchedule, d2, "Nova aula de Ap2");

    printAgenda(mySchedule);

    return 0;
}