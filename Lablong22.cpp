#include <stdio.h>
#include <string.h>
struct student{
    char name[100];
    char code[100];
    char birth[100];
    double point;
}list[100];
int n=0;

void AddStudent(){
	fflush(stdin);
    printf("\nEnter Code: ");
	gets(list[n].code);
    printf("\nEnter Student's Name: ");
	gets(list[n].name);
    printf("\nEnter Date of Birth: ");
	gets(list[n].birth);
    printf("\nEnter learning points: ");
	scanf("%lf", &list[n].point);
    n++;
}
void FindStudent(){
	fflush(stdin);
	int check=0;
	char name[100];
	printf("\nEnter student name that you want to find : ");
    gets(name);
    for (int i=0;i<n;i++)
        if (strcmp(list[i].name,name) == 0){
        	printf("\nCode: %s \nName: %s \nBirth: %s \nLearning Points: %.2lf\n",list[i].code, list[i].name, list[i].birth, list[i].point);
        	check=1;
    	}
    if (check==0) printf("\nUnknow student!!");
}

void Sort(){
    struct student temp;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (strcmp(list[i].name, list[j].name) == 1){
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }
    }
}

void studentlist(){
	char read[400];
	FILE *f = fopen("Student.txt","r");
    fread(read, 1, 500, f);
    printf("%s", read);
    fclose(f);
}

void Save(){
    FILE *f=fopen("Student.txt","w+");
    for (int i=0; i<n; i++){
        fprintf(f,"\nCode: %s \nName: %s \nBirth: %s \nLearning Points: %.2lf\n",list[i].code, list[i].name, list[i].birth, list[i].point);
    }
    fclose(f);
}

int main(){
    int choice;
    double point;
    FILE* f;
    printf("\nWelcome to Students Management Program");
    printf("\n1-Add Students");
    printf("\n2-Look upStudents");
    printf("\n3-Display the student list");
    printf("\n4-Exit");
    do{
        printf("\nWhich option do you want\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:AddStudent();
               Sort();
               Save();
               break;
        case 2: FindStudent(); break;
        case 3: studentlist(); break;
        case 4: printf("Exited!!"); break;
        }
    }
    while (choice!=4);
}

