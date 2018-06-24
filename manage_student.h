void vAddStudent() {
    system("cls||clear");
    FILE *fp;
    struct stLogin st;
    st.intType = 1;
    fp=fopen(dbLoginList, "ab");
    printf("\n\n===================== ADD NEW STUDENT ======================\n\n");
    printf("Enter The Student TP Number: ");
    scanf("%s", st.chTP);
    vUpper(st.chTP);
    fflush(stdin);

    printf("\nEnter The Student Password: ");
    scanf("%s", st.chPass);
    vUpper(st.chPass);
    fflush(stdin);

    printf("\nEnter The Student Name: ");
    scanf("%[^\n]%*c", st.chName);
    vUpper(st.chName);
    fflush(stdin);

    fwrite(&st, sizeof(st), 1, fp);
    fclose(fp);
    printf("\n============================================================\n\n");
}


void vSearchStudent() {
system("cls||clear");
FILE *fp, *fp1, *fp2;
struct stLogin st;
struct stIntakeRecord st1;
struct stModuleRecord st2;
int intFound=0, intFound1=0, intFound2=0, intCompare, intCompare1, intCompare2;
char chTP[16];
fp=fopen(dbLoginList, "rb");
fp1=fopen(dbIntakeRecord, "rb");
fp2=fopen(dbModuleRecord, "rb");
printf("\n\n====================== SEARCH STUDENT ======================\n\n");
printf("Enter The Student TP Number: ");
scanf("%s", chTP);
vUpper(chTP);
fflush(stdin);

system("cls||clear");
printf("\n\n====================== SEARCH STUDENT ======================\n\n");
while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}
intCompare=strcmp(chTP, st.chTP);
if(intCompare==0) {
printf("\tTP NUMBER:\n");
printf("\t%s\n", st.chTP);
printf("\n\tNAME:\n");
printf("\t%s\n", st.chName);
printf("\n\tPASSWORD:\n");
printf("\t%s\n", st.chPass);
intFound=1;
}
}
if(intFound==0) {
printf("Sorry, No Record Found!");
printf("\n\n============================================================\n\n");
fclose(fp);
return;
}
fclose(fp);

printf("\n\tINTAKE CODE:");
while(1) {
fread(&st1, sizeof(st1), 1, fp1);
if(feof(fp1)) {
break;
}
intCompare1=strcmp(chTP, st1.chUserID);
if(intCompare1==0) {
printf("\n\t%s", st1.chIntakeCode);
intFound1=1;
}
}
if(intFound1==0) {
printf("\n\tNOT FOUND!");
}
fclose(fp1);

printf("\n\n\tMODULE NAME:");
while(1) {
fread(&st2, sizeof(st2), 1, fp2);
if(feof(fp2)) {
break;
}

intCompare2=strcmp(chTP, st2.chUserID);
if(intCompare2==0) {
printf("\n\t%s", st2.chModuleName);
intFound2=1;
}
}
if(intFound2==0) {
printf("\n\tNOT FOUND!");
}
fclose(fp2);
printf("\n\n============================================================\n\n");
}


void vModifyStudent() {
system("cls||clear");
FILE *fp, *fp1;
struct stLogin st;
int intFound=0;
char chTP[16];
st.intType=1;

fp=fopen(dbLoginList, "rb");
fp1=fopen("dbTemp.txt", "wb");
printf("\n\n====================== MODIFY STUDENT ======================\n\n");
printf("Enter The Student's TP Number You Want To Modify: ");
scanf("%s", chTP);
vUpper(chTP);
fflush(stdin);

while(1) {
fread(&st, sizeof(st), 1, fp);

if(feof(fp)) {
break;
}

int intCompare;
intCompare=strcmp(chTP, st.chTP);
if(intCompare==0) {
intFound=1;
printf("\nEnter The New Student TP Number: ");
scanf("%s", st.chTP);
vUpper(st.chTP);
fflush(stdin);

printf("\nEnter The New Student Password: ");
scanf("%s", st.chPass);
vUpper(st.chPass);
fflush(stdin);

printf("\nEnter The New Student Name: ");
scanf("%[^\n]%*c", st.chName);
vUpper(st.chName);
fflush(stdin);

fwrite(&st, sizeof(st), 1, fp1);
}
else {
fwrite(&st, sizeof(st), 1, fp1);
}
}
fclose(fp);
fclose(fp1);

if(intFound==0) {
printf("Sorry, No Record Found!\n");
}
else {
fp=fopen(dbLoginList,"wb");
fp1=fopen("dbTemp.txt","rb");

while(1) {
fread(&st, sizeof(st), 1, fp1);

if(feof(fp1)) {
break;
}
fwrite(&st, sizeof(st), 1, fp);
}
}
fclose(fp);
fclose(fp1);
printf("\n============================================================\n\n");
}


void vDeleteStudent() {
system("cls||clear");
FILE *fp,*fp1;
struct stLogin st;
int intFound=0;
char chTP[16];
st.intType=1;

fp=fopen(dbLoginList, "rb");
fp1=fopen("dbTemp.txt", "wb");

printf("\n\n====================== DELETE STUDENT ======================\n\n");
printf("Enter The Student's TP Number You Want To Delete: ");
scanf("%s", chTP);
vUpper(chTP);
fflush(stdin);

while(1) {
fread(&st, sizeof(st), 1, fp);

if(feof(fp)) {
break;
}

int intCompare;
intCompare=strcmp(chTP, st.chTP);
if(intCompare==0) {
intFound=1;
}
else {
fwrite(&st, sizeof(st), 1, fp1);
}
}
fclose(fp);
fclose(fp1);

if(intFound==0) {
printf("\nSorry, No Record Found!\n");
}
else {
fp=fopen(dbLoginList, "wb");
fp1=fopen("dbTemp.txt", "rb");

while(1) {
fread(&st, sizeof(st), 1, fp1);

if(feof(fp1)) {
break;
}
fwrite(&st, sizeof(st), 1, fp);
}
}
fclose(fp);
fclose(fp1);
printf("\n============================================================\n\n");
}


void vViewAllStudents() {
FILE *fp;
struct stLogin st;
fp=fopen(dbLoginList, "rb");
system("cls||clear");
printf("\n\n==================== VIEW ALL STUDENTS =====================\n\n");
printf("\tTP NUMBER:\tNAME:\n");
while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}
if (st.intType==1) {
    printf("\n");
    printf("\t%s",st.chTP);
    printf("\t%s",st.chName);
}
}
printf("\n\n============================================================\n\n");
fclose(fp);
}


void vAddStudentIntake() {
    system("cls||clear");
    FILE *fp, *fp2;
    struct stIntakeRecord st;
    struct stIntakeList st2;
    itoa(vRandomNumber(10000000, 99999999), st.chIndex, 10);
    fp=fopen(dbIntakeRecord, "ab");
    fp2=fopen(dbIntakeList, "rb");
    printf("\n\n==================== ADD STUDENT INTAKE ====================\n\n");
    printf("Enter The Student TP Number: ");
    scanf("%s", st.chUserID);
    vUpper(st.chUserID);
    fflush(stdin);

    printf("\nList Of Available Intakes:\n");
    while(1) {
    fread(&st2, sizeof(st2), 1, fp2);
    if(feof(fp2)) {
    break;
    }
    printf("\n\t%s", st2.chIntakeCode);
    }
    fclose(fp2);
    printf("\n");

    printf("\nChoose Intake Code: ");
    scanf("%s", st.chIntakeCode);
    vUpper(st.chIntakeCode);
    fflush(stdin);

    fwrite(&st, sizeof(st), 1, fp);
    fclose(fp);
    printf("\n============================================================\n\n");
}


void vDeleteStudentIntake() {
system("cls||clear");
FILE *fp, *fp2;
struct stIntakeRecord st;
struct stIntakeRecord st2;
int intFound=0, intFound2=0, intCompare, intCompare2;
char chTP[16], chIndex[16];

fp=fopen(dbIntakeRecord, "rb");
fp2=fopen("dbTemp.txt", "wb");

printf("\n\n================== DELETE STUDENT INTAKE ===================\n\n");
printf("Enter The Student's TP Number: ");
scanf("%s", chTP);
vUpper(chTP);
fflush(stdin);

printf("\n%s Registered To Following Intake(s):\n", chTP);
printf("\nINDEX CODE:\tINTAKE CODE:\n");
while(1) {
fread(&st2, sizeof(st2), 1, fp);
if(feof(fp)) {
break;
}

intCompare2=strcmp(chTP, st2.chUserID);
if(intCompare2==0) {
printf("\n%s", st2.chIndex);
printf("\t%s", st2.chIntakeCode);
intFound2=1;
}
}
if(intFound2==0) {
printf("\nSorry, No Record Found!");
printf("\n\n============================================================\n\n");
return;
}
fclose(fp);
fclose(fp2);

fp=fopen(dbIntakeRecord, "rb");
fp2=fopen("dbTemp.txt", "wb");
printf("\n\n============================================================\n\n");
printf("Enter The Index Code To Delete Intake: ");
scanf("%s", chIndex);
vUpper(chIndex);
fflush(stdin);

while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}

intCompare=strcmp(chIndex, st.chIndex);
if(intCompare==0) {
intFound=1;
}
else {
fwrite(&st, sizeof(st), 1, fp2);
}
}
fclose(fp);
fclose(fp2);

if(intFound==0) {
printf("\nSorry, No Record Found!\n");
}
else {
fp=fopen(dbIntakeRecord, "wb");
fp2=fopen("dbTemp.txt", "rb");

while(1) {
fread(&st, sizeof(st), 1, fp2);

if(feof(fp2)) {
break;
}
fwrite(&st, sizeof(st), 1, fp);
}
}
printf("\n============================================================\n\n");
fclose(fp);
fclose(fp2);
}


void vAddStudentModule() {
    system("cls||clear");
    FILE *fp, *fp2;
    struct stModuleRecord st;
    struct stModuleList st2;
    itoa(vRandomNumber(10000000, 99999999), st.chIndex, 10);
    fp=fopen(dbModuleRecord, "ab");
    fp2=fopen(dbModuleList, "rb");
    printf("\n\n==================== ADD STUDENT MODULE ====================\n\n");
    printf("Enter The Student TP Number: ");
    scanf("%s", st.chUserID);
    vUpper(st.chUserID);
    fflush(stdin);

    printf("\nList Of Available Modules:\n");
    while(1) {
    fread(&st2, sizeof(st2), 1, fp2);
    if(feof(fp2)) {
    break;
    }
    printf("\n\t%s", st2.chModuleName);
    }
    fclose(fp2);
    printf("\n");

    printf("\nChoose Module: ");
    scanf("%s", st.chModuleName);
    vUpper(st.chModuleName);
    fflush(stdin);

    fwrite(&st, sizeof(st), 1, fp);
    fclose(fp);
    printf("\n============================================================\n\n");
}


void vDeleteStudentModule() {
system("cls||clear");
FILE *fp, *fp2;
struct stModuleRecord st;
struct stModuleRecord st2;
int intFound=0, intFound2=0, intCompare, intCompare2;
char chTP[16], chIndex[16];

fp=fopen(dbModuleRecord, "rb");
fp2=fopen("dbTemp.txt", "wb");

printf("\n\n================== DELETE STUDENT MODULE ===================\n\n");
printf("Enter The Student's TP Number: ");
scanf("%s", chTP);
vUpper(chTP);
fflush(stdin);

printf("\n%s Registered To Following Module(s):\n", chTP);
printf("\nINDEX CODE:\tMODULE NAME:\n");
while(1) {
fread(&st2, sizeof(st2), 1, fp);
if(feof(fp)) {
break;
}

intCompare2=strcmp(chTP, st2.chUserID);
if(intCompare2==0) {
printf("\n%s", st2.chIndex);
printf("\t%s", st2.chModuleName);
intFound2=1;
}
}
if(intFound2==0) {
printf("\nSorry, No Record Found!");
printf("\n\n============================================================\n\n");
return;
}
fclose(fp);
fclose(fp2);

fp=fopen(dbModuleRecord, "rb");
fp2=fopen("dbTemp.txt", "wb");
printf("\n\n============================================================\n\n");
printf("Enter The Index Code To Delete Module: ");
scanf("%s", chIndex);
vUpper(chIndex);
fflush(stdin);

while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}

intCompare=strcmp(chIndex, st.chIndex);
if(intCompare==0) {
intFound=1;
}
else {
fwrite(&st, sizeof(st), 1, fp2);
}
}
fclose(fp);
fclose(fp2);

if(intFound==0) {
printf("\nSorry, No Record Found!\n");
}
else {
fp=fopen(dbModuleRecord, "wb");
fp2=fopen("dbTemp.txt", "rb");

while(1) {
fread(&st, sizeof(st), 1, fp2);

if(feof(fp2)) {
break;
}
fwrite(&st, sizeof(st), 1, fp);
}
}
printf("\n============================================================\n\n");
fclose(fp);
fclose(fp2);
}
