int vMainMenu() {
char chChoice;
while(1) {
system("cls||clear");
printf("\n\n=============== ATTENDANCE MANAGEMENT SYSTEM ===============\n\n");
printf("\t1. ADMIN\n\n");
printf("\t2. LECTURER\n\n");
printf("\t3. STUDENT\n\n");
printf("\t0. EXIT");
printf("\n\n============================================================\n\n");
printf("Please Enter Your Choice: ");
scanf("%c", &chChoice);
fflush(stdin);
switch(chChoice) {
case '1':
vCallAdmin();
break;
case '2':
vCallLecturer();
break;
case '3':
vCallStudent();
break;
case '0':
exit(0);
default:
vMainMenu();
break;
}
vGet();
}
    return 0;
}


void vCallStudent() {
system("cls||clear");
printf("\n\n====================== STUDENT LOGIN =======================\n\n");
FILE *fp;
struct stLogin st;
int intFound=0, intCompare, intCompare2;
fp=fopen(dbLoginList, "rb");
printf("Please Enter Your Student TP Number: ");
scanf("%s", chUsername);
vUpper(chUsername);
fflush(stdin);
while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}
intCompare=strcmp(chUsername, st.chTP);
if(intCompare==0) {
    printf("\nPlease Enter Your Student Password: ");
    scanf("%s", chUserPassword);
    vUpper(chUserPassword);
    fflush(stdin);
    intCompare2=strcmp(chUserPassword, st.chPass);
    if((intCompare2==0)&&(st.intType==1)) {
            intUserType=1;
            vStudentMenu();
    }
    else {
        printf("\nIncorrect Password!");
        vGet();
        vMainMenu();
    }
intFound=1;
}
}
if(intFound==0) {
fclose(fp);
printf("\nIncorrect TP Number!");
vGet();
vMainMenu();
}
fclose(fp);
}

void vCallLecturer() {
system("cls||clear");
printf("\n\n====================== LECTURER LOGIN ======================\n\n");
FILE *fp;
struct stLogin st;
int intFound=0, intCompare, intCompare2;
fp=fopen(dbLoginList, "rb");
vUpper(chUsername);
fflush(stdin);
printf("Please Enter Your Lecturer TP Number: ");
scanf("%s", chUsername);
vUpper(chUsername);
fflush(stdin);

while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}
intCompare=strcmp(chUsername, st.chTP);
if(intCompare==0) {
    printf("\nPlease Enter Your Lecturer Password: ");
    scanf("%s", chUserPassword);
    vUpper(chUserPassword);
    fflush(stdin);
    intCompare2=strcmp(chUserPassword, st.chPass);
    if((intCompare2==0)&&(st.intType==2)) {
            intUserType=2;
            vLecturerMenu();
    }
    else {
        printf("\nIncorrect Password!");
        vGet();
        vMainMenu();
    }
intFound=1;
}
}
if(intFound==0) {
fclose(fp);
printf("\nIncorrect TP Number!");
vGet();
vMainMenu();
}
fclose(fp);
}

void vCallAdmin() {
system("cls||clear");
printf("\n\n======================= ADMIN LOGIN ========================\n\n");
int intCompare, intCompare2;
vUpper(chAdminUsername);
vUpper(chAdminPassword);
printf("Please Enter Your Username: ");
scanf("%s", chUsername);
fflush(stdin);
vUpper(chUsername);
intCompare=strcmp(chUsername, chAdminUsername);
if(intCompare==0) {
    printf("\nPlease Enter Your Password: ");
    scanf("%s", chUserPassword);
    fflush(stdin);
    vUpper(chUserPassword);
    intCompare2=strcmp(chUserPassword, chAdminPassword);
    if(intCompare2==0) {
            intUserType=3;
            vAdminMenu();
    }
    else {
        printf("\nIncorrect Password!");
        vGet();
        vMainMenu();
    }
}
else {
    printf("\nIncorrect Username!");
    vGet();
    vMainMenu();
}
}
