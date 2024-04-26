#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dos.h>

/*Hospital Management System (Vaccine hospital) is an application where the hospital maintains all the data about the patients and vaccines data
The function:
1. Print Vaccine data
    1.1. Add Vaccine
    1.2. Update Vaccine
    1.3. Delete Vaccine
2. Print patient data
    2.1. Add patient
    2.2. Update patient
*/

int numberVaccine = 0;
int numberPatient = 0;

typedef struct pt{
    char fullname[50] ;
    int age;
    int idNumber;
    int healthInsurance;
    bool isDelete;
}patient;

typedef struct d{
    int day;
    int month;
    int year;
}date;

typedef struct va{
    char vaccineName[100];
    char target[100];
    char vaccineType[100];
    date MFG;
    bool outOfDate;
    bool isDelete;
}vaccien;

void AddPatient(patient patients[]){
    printf("\nPatient Fullname: ");
    scanf(" %[^\n]s", patients[numberPatient].fullname);
    fflush(stdin);


    printf("\nPatient Age: ");
    scanf("%d", &patients[numberPatient].age);
    fflush(stdin);

    printf("\nPatient Id Number: ");
    scanf("%d", &patients[numberPatient].idNumber);
    fflush(stdin);

    printf("\nPatient Health Insurance Number: ");
    scanf("%d", &patients[numberPatient].healthInsurance);
    fflush(stdin);

    ++numberPatient;
}

void UpdatePatient(patient patients[], int index){
    printf("\nPatient name: %s", patients[index].fullname);
    printf("\nPatient name: ");
    scanf(" %[^\n]s", patients[index].fullname);
    fflush(stdin);


    printf("\nPatient Age: %d", patients[index].age);
    printf("\nPatient Age: ");
    scanf("%d", &patients[index].age);
    fflush(stdin);

    printf("\nPatient Id Number: %d", patients[index].idNumber);
    printf("\nPatient Id Number: ");
    scanf("%d", &patients[index].idNumber);
    fflush(stdin);


    printf("\nPatient Health Insurance Number: %d", patients[index].healthInsurance);
    printf("\nPatient Health Insurance Number: ");
    scanf("%d", &patients[index].healthInsurance);
    fflush(stdin);
}
void patientMenu(patient patients[]){
    int choice;
    do{
        printf("\n1. Add new Patient\n");
        printf("2. Update Patient\n");
        printf("3. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                AddPatient(patients);
                break;
            case 2:
                printf("\nInput index you want to update: ");
                int index;
                scanf("%d", &index);
                UpdatePatient(patients, index - 1);
                fflush(stdin);
                break;
            default:
                break;
        }
    }while(choice != 3);
}
void printPatientdatas(patient patients[]){
    if(numberPatient == 0){
        printf("\nDon't have any patient datas at this time\n");
    }
    else{
        int i;
        printf("    Patient Name                Patient Age\n");
        for(i = 0; i < numberPatient;++i){
            if(patients[i].isDelete == false){
                printf("%d", i+1);
                printf("\t%s\t\t\t\t%d\n", patients[i].fullname, patients[i].age);
            }

        }
    }
    patientMenu(patients);
}

void AddVaccine(vaccien vaccines[]){
    printf("\nVaccine name: ");
    scanf(" %[^\n]s", vaccines[numberVaccine].vaccineName);
    fflush(stdin);


    printf("\nVaccine target: ");
    scanf(" %[^\n]s", vaccines[numberVaccine].target);
    fflush(stdin);

    printf("\nVaccine type: ");
    scanf(" %[^\n]", vaccines[numberVaccine].vaccineType);
    fflush(stdin);

    printf("\nManufacturing Date by type(month day year): ");
    scanf("%d%d%d", &vaccines[numberVaccine].MFG.month, &vaccines[numberVaccine].MFG.day, &vaccines[numberVaccine].MFG.year);
    fflush(stdin);

    vaccines[numberVaccine].outOfDate = false;

    vaccines[numberVaccine].isDelete = false;

    ++numberVaccine;
}

void UpdateVaccine(vaccien vaccines[], int index){
    printf("\nVaccine name: %s", vaccines[index].vaccineName);
    printf("\nVaccine name: ");
    scanf(" %[^\n]s", vaccines[index].vaccineName);
    fflush(stdin);


    printf("\nVaccine target: %s", vaccines[index].target);
    printf("\nVaccine target: ");
    scanf(" %[^\n]s", vaccines[index].target);
    fflush(stdin);

    printf("\nVaccine type: %s", vaccines[index].vaccineType);
    printf("\nVaccine type: ");
    scanf(" %[^\n]", vaccines[index].vaccineType);
    fflush(stdin);



    printf("\nManufacturing Date: %d/%d/%d", vaccines[index].MFG.month, vaccines[index].MFG.day, vaccines[index].MFG.year);
    printf("\nManufacturing Date by type(month day year): ");
    scanf("%d%d%d", &vaccines[index].MFG.month, &vaccines[index].MFG.day, &vaccines[index].MFG.year);
    fflush(stdin);

    printf("\nIs out of date", vaccines[index].outOfDate);
    printf("\nEnter 'true' or 'false': ");
    scanf("\s",  vaccines[index].outOfDate);
}

void DeleteVaccine(vaccien vaccines[], int index){
    printf("\nVaccine name: %s", vaccines[index].vaccineName);
    printf("\nVaccine name: %s", vaccines[index].target);
    printf("\nVaccine name: %s", vaccines[index].vaccineType);
    printf("\nManufacturing Date: %d/%d/%d", vaccines[index].MFG.month, vaccines[index].MFG.day, vaccines[index].MFG.year);
    printf("\nIs out of date", vaccines[index].outOfDate);

    printf("\nAre you sure you want to delete it");
    printf("\n1. Yes");
    printf("\n2. No\n");
    int choice;
    scanf("%d",  &choice);
    if(choice == 1){
         vaccines[index].isDelete = true;
    }
}


void MenuVaccine(vaccien vaccines[]){
    int choice;
    do{
        printf("\n1. Add new Viccine\n");
        printf("2. Update Vaccine\n");
        printf("3. Delete Vaccine\n");
        printf("4. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                AddVaccine(vaccines);
                break;
            case 2:
                printf("\nInput index you want to update: ");
                int index;
                scanf("%d", &index);
                UpdateVaccine(vaccines, index - 1);
                fflush(stdin);
                break;
            case 3:
                printf("\nInput index you want to delete: ");
                int indexDelete;
                scanf("%d", &indexDelete);
                DeleteVaccine(vaccines, indexDelete - 1);
                fflush(stdin);
                break;
            default:
                break;
        }
    }while(choice != 4);
}
void printVaccinedatas(vaccien vaccines[]){
    if(numberVaccine == 0){
        printf("\nDon't have any vaccine datas at this time\n");
    }
    else{
        int i;
        printf("    Vaccine Name                Vaccine target              Vaccine Type\n");
        for(i = 0; i < numberVaccine;++i){
            if(vaccines[i].isDelete == false){
                printf("%d", i+1);
                printf("\t%s\t\t\t\t%s\t\t\t\t%s\n", vaccines[i].vaccineName, vaccines[i].target, vaccines[i].vaccineType);
            }

        }
    }
    MenuVaccine(vaccines);

}

int main()
{
    vaccien *vaccines = malloc(100^6);
    patient *patient = malloc(100^6);
    int choice;
    do{
        printf("1. Print Vaccine data\n");
        printf("2. Print patient data\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printVaccinedatas(vaccines);
                break;
            case 2:
                printPatientdatas(patient);
            break;
            default:
                break;
        }
    }while(choice !=3);
    free(vaccines);
    free(patient);
    return 0;
}
