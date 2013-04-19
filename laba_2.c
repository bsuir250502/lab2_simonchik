#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define string_size 256
#define num_of_students 4

typedef struct addr_a {
    char street[string_size];
    int house;
    int flat;
} addr_a;

typedef struct addr_b {
    char city[string_size];
    char street[string_size];
    int house;
    int flat;
} addr_b;

typedef struct addr_c {
    char region[string_size];
    char town[string_size];
    char street[string_size];
    int house;
    int flat;
} addr_c;

typedef struct addr_d {
    char region[string_size];
    char district[string_size];
    char village[string_size];
    char street[string_size];
    int house;
} addr_d;

typedef struct student {
    char surname[string_size];
    char type_of_addr;
    union addr_type {
        struct addr_a minsk;
        struct addr_b regional_city;
        struct addr_c district_town;
        struct addr_d village;
    } addr_type;
} student;

int input_num(void)
{
    char number[string_size];
    int num;
    while (1) {
        fgets(number, string_size, stdin);
        num = atoi(number);
        if (num <= 0) {
            printf("ERROR!!! ENTER NUMBER: ");
            continue;
        }
        break;
    }
    return num;
}

char *my_gets(char *str, size_t strin_size)
{
    fgets(str, strin_size, stdin);
    str[strlen(str) - 1] = '\0';
    return str;
}

student input_addr_a(student list)
{
    printf("Enter name of the street: ");
    my_gets(list.addr_type.minsk.street, string_size);
    printf("Enter the number of house: ");
    list.addr_type.minsk.house = input_num();
    printf("Enter the number of flat: ");
    list.addr_type.minsk.flat = input_num();
    return list;
}

student input_addr_b(student list)
{
    printf("Enter name of the regional city: ");
    my_gets(list.addr_type.regional_city.city, string_size);
    printf("Enter name of the street: ");
    my_gets(list.addr_type.regional_city.street, string_size);
    printf("Enter the number of house: ");
    list.addr_type.regional_city.house = input_num();
    printf("Enter the number of flat: ");
    list.addr_type.regional_city.flat = input_num();
    return list;
}

student input_addr_c(student list)
{
    printf("Enter name of the region: ");
    my_gets(list.addr_type.district_town.region, string_size);
    printf("Enter name of the town: ");
    my_gets(list.addr_type.district_town.town, string_size);
    printf("Enter name of the street: ");
    my_gets(list.addr_type.district_town.street, string_size);
    printf("Enter the number of house: ");
    list.addr_type.district_town.house = input_num();
    printf("Enter the number of flat: ");
    list.addr_type.district_town.flat = input_num();
    return list;
}

student input_addr_d(student list)
{
    printf("Enter name of the region: ");
    my_gets(list.addr_type.village.region, string_size);
    printf("Enter name of the district: ");
    my_gets(list.addr_type.village.district, string_size);
    printf("Enter name of the village: ");
    my_gets(list.addr_type.village.village, string_size);
    printf("Enter name of the street: ");
    my_gets(list.addr_type.village.street, string_size);
    printf("Enter the number of house: ");
    list.addr_type.village.house = input_num();
    return list;
}

student address_selection(student list)
{

    while (1) {
        printf
            ("Enter adress of %sSelect the type of address\na - Minsk\nb - Regional сity\nc - Distriсt town\nd - Village\n",list.surname);
        list.type_of_addr=getchar();
        if (list.type_of_addr > 'd' || list.type_of_addr < 'a') {
            puts("ERROR INPUT");
            continue;
        }
        break;
    }
    switch (list.type_of_addr) {
    case 'a':
        list = input_addr_a(list);
        break;
    case 'b':
        list = input_addr_b(list);
        break;
    case 'c':
        list = input_addr_c(list);
        break;
    case 'd':
        list = input_addr_d(list);
        break;
    }
    return list;
}


void checkHelp(void)
{
    printf
        ("================================================================================\n"
         "MANUAL:\n"
         "Enter information about the students: surname and address\n"
         "=================================OPTIONS=======================================\n"
         "-m list of students from Minsk\n"
         "-c list of students from the cities\n"
         "-t list of students from towns\n"
         "-v list of students from villages\n"
         "===============================================================================\n");
    exit(0);
}

void input_of_inform(student * list)
{
    int i;
    for (i = 0; i < num_of_students; i++) {
        printf("Enter surname of %d student\n", i + 1);
        my_gets(list[i].surname, string_size);
        list[i] = address_selection(list[i]);
        system("clear");
    }
}

void output_stud_from_Minsk(student * list)
{
    int i = 0;
    for (i = 0; i < num_of_students; i++) {
        if (list[i].type_of_addr == 'a') {
            printf("Student %s from Minsk, street %s, house %d, flat %d\n",
                   list[i].surname,
                   list[i].addr_type.minsk.street,
                   list[i].addr_type.minsk.house,
                   list[i].addr_type.minsk.flat);
        }
    }
}

void output_stud_from_cities(student * list)
{
    int i = 0;
    for (i = 0; i < num_of_students; i++) {
        if (list[i].type_of_addr == 'b') {
            printf("Student %s from %s, street %s, house %d, flat %d\n",
                   list[i].surname,
                   list[i].addr_type.regional_city.city,
                   list[i].addr_type.regional_city.street,
                   list[i].addr_type.regional_city.house,
                   list[i].addr_type.regional_city.flat);
        }
    }
}

void output_stud_from_towns(student * list)
{
    int i = 0;
    for (i = 0; i < num_of_students; i++) {
        if (list[i].type_of_addr == 'c') {
            printf
                ("Student %s from %s region, town %s, street %s, house %d, flat %d\n",
                 list[i].surname, list[i].addr_type.district_town.region,
                 list[i].addr_type.district_town.town,
                 list[i].addr_type.district_town.street,
                 list[i].addr_type.district_town.house,
                 list[i].addr_type.district_town.flat);
        }
    }
}

void output_stud_from_villages(student * list)
{
    int i = 0;
    for (i = 0; i < num_of_students; i++) {
        if (list[i].type_of_addr == 'd') {
            printf
                ("Student %s from %s region, %s district, village %s, street %s, house %d\n",
                 list[i].surname, list[i].addr_type.village.region,
                 list[i].addr_type.village.district,
                 list[i].addr_type.village.village,
                 list[i].addr_type.village.street,
                 list[i].addr_type.village.house);
        }
    }
}

int main(int argc, char *argv[])
{
    struct student list[num_of_students];
    if (argc > 1) {
        if (!strcmp(argv[1], "-h"))
            checkHelp();
    }
    input_of_inform(list);
    if (argc > 1) {
        if (!strcmp(argv[1], "-m"))
            output_stud_from_Minsk(list);
        if (!strcmp(argv[1], "-c"))
            output_stud_from_cities(list);
        if (!strcmp(argv[1], "-t"))
            output_stud_from_towns(list);
        if (!strcmp(argv[1], "-v"))
            output_stud_from_villages(list);
    }
    return 0;
}
