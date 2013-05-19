#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int InputNum(void)
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

char *MyGets(char *str, size_t strin_size)
{
    fgets(str, strin_size, stdin);
    str[strlen(str) - 1] = '\0';
    return str;
}

student InputAddrA(student list)
{
    printf("Enter name of the street: ");
    MyGets(list.addr_type.minsk.street, string_size);
    printf("Enter the number of house: ");
    list.addr_type.minsk.house = InputNum();
    printf("Enter the number of flat: ");
    list.addr_type.minsk.flat = InputNum();
    return list;
}

student InputAddrB(student list)
{
    printf("Enter name of the regional city: ");
    MyGets(list.addr_type.regional_city.city, string_size);
    printf("Enter name of the street: ");
    MyGets(list.addr_type.regional_city.street, string_size);
    printf("Enter the number of house: ");
    list.addr_type.regional_city.house = InputNum();
    printf("Enter the number of flat: ");
    list.addr_type.regional_city.flat = InputNum();
    return list;
}

student InputAddrC(student list)
{
    printf("Enter name of the region: ");
    MyGets(list.addr_type.district_town.region, string_size);
    printf("Enter name of the town: ");
    MyGets(list.addr_type.district_town.town, string_size);
    printf("Enter name of the street: ");
    MyGets(list.addr_type.district_town.street, string_size);
    printf("Enter the number of house: ");
    list.addr_type.district_town.house = InputNum();
    printf("Enter the number of flat: ");
    list.addr_type.district_town.flat = InputNum();
    return list;
}

student InputAddrD(student list)
{
    printf("Enter name of the region: ");
    MyGets(list.addr_type.village.region, string_size);
    printf("Enter name of the district: ");
    MyGets(list.addr_type.village.district, string_size);
    printf("Enter name of the village: ");
    MyGets(list.addr_type.village.village, string_size);
    printf("Enter name of the street: ");
    MyGets(list.addr_type.village.street, string_size);
    printf("Enter the number of house: ");
    list.addr_type.village.house = InputNum();
    return list;
}

student AddressSelection(student list)
{
    while (1) {
        printf("Enter adress of %sSelect the type of address\na - Minsk\nb - Regional сity\nc - Distriсt town\nd - Village\n",list.surname);
        list.type_of_addr = getchar();
        getchar();
        if (list.type_of_addr > 'd' || list.type_of_addr < 'a') {
            puts("ERROR INPUT");
            continue;
        }
        break;
    }
    switch (list.type_of_addr) {
    case 'a':
        list = InputAddrA(list);
        break;
    case 'b':
        list = InputAddrB(list);
        break;
    case 'c':
        list = InputAddrC(list);
        break;
    case 'd':
        list = InputAddrD(list);
        break;
    }
    return list;
}


void Help(void)
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

void InputInform(student * list)
{
    int i;
    for (i = 0; i < num_of_students; i++) {
        printf("Enter surname of %d student\n", i + 1);
        MyGets(list[i].surname, string_size);
        list[i] = AddressSelection(list[i]);
    }
}

void OutputStudFromMinsk(student * list)
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

void OutputStudFromCities(student * list)
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

void OutputStudFromTowns(student * list)
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

void OutputStudFromVillages(student * list)
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
            Help();
    }
    InputInform(list);
    if (argc > 1) {
        if (!strcmp(argv[1], "-m"))
            OutputStudFromMinsk(list);
        if (!strcmp(argv[1], "-c"))
            OutputStudFromCities(list);
        if (!strcmp(argv[1], "-t"))
            OutputStudFromTowns(list);
        if (!strcmp(argv[1], "-v"))
            OutputStudFromVillages(list);
    }
    return 0;
}