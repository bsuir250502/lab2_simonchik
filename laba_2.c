#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define string_size 256
#define num_of_students 3

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

student input_addr_a(student list)
{
    printf("Enter name of the street: ");
    fgets(list.addr_type.minsk.street, string_size, stdin);
    printf("Enter the number of house: ");
    list.addr_type.minsk.house = input_num();
    printf("Enter the number of flat: ");
    list.addr_type.minsk.flat = input_num();
    return list;
}

student input_addr_b(student list)
{
    printf("Enter name of the regional city: ");
    fgets(list.addr_type.regional_city.city, string_size, stdin);
    printf("Enter name of the street: ");
    fgets(list.addr_type.regional_city.street, string_size, stdin);
    printf("Enter the number of house: ");
    list.addr_type.regional_city.house = input_num();
    printf("Enter the number of flat: ");
    list.addr_type.regional_city.flat = input_num();
    return list;
}

student input_addr_c(student list)
{
    printf("Enter name of the region: ");
    fgets(list.addr_type.district_town.region, string_size, stdin);
    printf("Enter name of the town");
    fgets(list.addr_type.district_town.town, string_size, stdin);
    printf("Enter name of the street: ");
    fgets(list.addr_type.district_town.street, string_size, stdin);
    printf("Enter the number of house: ");
    list.addr_type.regional_city.house = input_num();
    printf("Enter the number of flat: ");
    list.addr_type.district_town.flat = input_num();
    return list;
}

student input_addr_d(student list)
{
    printf("Enter name of the region: ");
    fgets(list.addr_type.village.region, string_size, stdin);
    printf("Enter name of the district: ");
    fgets(list.addr_type.village.district, string_size, stdin);
    printf("Enter name of the village: ");
    fgets(list.addr_type.village.village, string_size, stdin);
    printf("Enter name of the street: ");
    fgets(list.addr_type.village.street, string_size, stdin);
    printf("Enter the number of house: ");
    list.addr_type.village.house = input_num();
    return list;
}

void address_selection(student list)
{

    while (1) {
        printf("Enter adress of %sSelect the type of address\na - Minsk\nb - Regional сity\nc - Distriсt town\nd - Village\n",list.surname);
        fgets(&list.type_of_addr, string_size, stdin);
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
}


void input_of_inform(student * list)
{
    int i;
    for (i = 0; i < num_of_students; i++) {
        printf("Enter surname of %d student\n", i + 1);
        fgets(list[i].surname, string_size, stdin);
        address_selection(list[i]);
        system("clear");
    }
}

int main()
{
    student list[num_of_students];
    input_of_inform(list);
    return 0;
}
