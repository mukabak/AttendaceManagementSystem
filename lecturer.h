void vTakeAttendance() {
system("cls||clear");
printf("\n\n===================== TAKE ATTENDANCE ======================\n\n");
int intFound1=0, intFound2=0, intCompare;

struct stLogin st;
struct stIntakeRecord st1;
struct stModuleRecord st2;
FILE *fp, *fp1, *fp2, *fp3;
fp=fopen(dbLoginList, "rb");
fp1=fopen(dbIntakeRecord, "rb");
fp2=fopen(dbModuleRecord, "rb");
fp3=fopen(dbAttendance, "ab");

stA.intStatus=1;
strncpy(stA.chLecturerID, chUsername, 16);

printf("List Of %s's Intakes:\n", chUsername);
while(1) {
fread(&st1, sizeof(st1), 1, fp1);
if(feof(fp1)) {
break;
}
intCompare=strcmp(chUsername, st1.chUserID);
if(intCompare==0) {
printf("\n\t%s", st1.chIntakeCode);
intFound1=1;
}
}
if(intFound1==0) {
printf("\n\tNOT FOUND!");
}
fclose(fp1);
printf("\n\nPlease Select The Suitable Intake Code: ");
scanf("%s", stA.chIntakeCode);
vUpper(stA.chIntakeCode);
fflush(stdin);
printf("\n============================================================\n\n");
printf("List Of %s's Modules:\n", chUsername);
while(1) {
fread(&st2, sizeof(st2), 1, fp2);
if(feof(fp2)) {
break;
}

intCompare=strcmp(chUsername, st2.chUserID);
if(intCompare==0) {
printf("\n\t%s", st2.chModuleName);
intFound2=1;
}
}
if(intFound2==0) {
printf("\n\tNOT FOUND!");
}
fclose(fp2);
printf("\n\nPlease Select The Suitable Module Name: ");
scanf("%s", stA.chModuleName);
vUpper(stA.chModuleName);
fflush(stdin);
printf("\n============================================================\n\n");

printf("Sample Format: 29-12-2000\n");
printf("\nPlease Enter The Lecture Date: ");
scanf("%s", stA.chDate);
vUpper(stA.chDate);
fflush(stdin);
printf("\n============================================================\n\n");

printf("Sample Format: 14:45\n");
printf("\nPlease Enter The Lecture Start Time: ");
scanf("%s", stA.chStartTime);
vUpper(stA.chStartTime);
fflush(stdin);
printf("\n============================================================\n\n");

printf("Sample Format: 16:30\n");
printf("\nPlease Enter The Lecture End Time: ");
scanf("%s", stA.chEndTime);
vUpper(stA.chEndTime);
fflush(stdin);
system("cls||clear");

while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}
if (st.intType==1) {

struct stIntakeRecord st4;
FILE *fp4;
fp4=fopen(dbIntakeRecord, "rb");

while(1) {
fread(&st4, sizeof(st4), 1, fp4);
if(feof(fp4)) {
break;
}
intCompare=strcmp(st.chTP, st4.chUserID);
if(intCompare==0) {
intCompare=strcmp(stA.chIntakeCode, st4.chIntakeCode);
if(intCompare==0) {

struct stModuleRecord st5;
FILE *fp5;
fp5=fopen(dbModuleRecord, "rb");

while(1) {
fread(&st5, sizeof(st5), 1, fp5);
if(feof(fp5)) {
break;
}
intCompare=strcmp(st.chTP, st5.chUserID);
if(intCompare==0) {
intCompare=strcmp(stA.chModuleName, st5.chModuleName);
if(intCompare==0) {
    strncpy(stA.chStudentName, st.chName, 30);
    strncpy(stA.chStudentTP, st.chTP, 16);
    fwrite(&stA, sizeof(stA), 1, fp3);
    }
}
}
fclose(fp5);
}
}
}
fclose(fp4);
}
}
fclose(fp);
fclose(fp3);
vMarkAttendance();
}


void vMarkAttendance() {
system("cls||clear");
printf("\n\n===================== TAKE ATTENDANCE ======================\n\n");
int intCompare;
struct stAttendance st6;
FILE *fp6;
fp6=fopen(dbAttendance, "rb");
printf("TP NUMBER:\tSTATUS\t\tNAME:\n");
while(1) {
fread(&st6, sizeof(st6), 1, fp6);
if(feof(fp6)) {
break;
}
intCompare=(strcmp(stA.chStartTime,st6.chStartTime))+(strcmp(stA.chEndTime,st6.chEndTime))+(strcmp(stA.chDate,st6.chDate));
if(intCompare==0) {
    printf("\n");
    printf("%s", st6.chStudentTP);
    if(st6.intStatus==4){
        printf("\tABSENTR");
    }
    else if(st6.intStatus==3){
        printf("\tABSENT ");
    }
    else if(st6.intStatus==2){
        printf("\tLATE   ");
    }
    else {
        printf("\tPRESENT");
    }
    printf("\t\t%s",st6.chStudentName);
}
}
fclose(fp6);
printf("\n\n============================================================\n\n");

char chTP[16];
int intFound=0;
FILE *fp1, *fp;
struct stAttendance st;
fp=fopen(dbAttendance, "rb");
fp1=fopen("dbTemp.txt", "wb");

printf("1. MARK ATTENDANCE\n0. FINISH\n");
printf("\nChoose Your Option: ");
char chChoice1;
scanf("%c", &chChoice1);
fflush(stdin);

switch(chChoice1) {
case '1':

break;
case '0':
vLecturerMenu();
break;
default:
vMarkAttendance();
break;
}

printf("\nPlease Enter The TP Number To Mark Attendance: ");
scanf("%s", chTP);
vUpper(chTP);
fflush(stdin);
while(1) {
fread(&st, sizeof(st), 1, fp);

if(feof(fp)) {
break;
}
int intCompare;
intCompare=(strcmp(chTP, st.chStudentTP))+(strcmp(stA.chStartTime,st.chStartTime))+(strcmp(stA.chEndTime,st.chEndTime))+(strcmp(stA.chDate,st.chDate));
if(intCompare==0) {
intFound=1;
printf("\n============================================================\n\n");
printf("1. PRESENT      2. LATE      3. ABSENT\n");
printf("\nChoose Your Option: ");
char chChoice;
scanf("%c", &chChoice);
fflush(stdin);

switch(chChoice) {
case '1':
st.intStatus=1;
break;
case '2':
st.intStatus=2;
break;
case '3':
st.intStatus=3;
break;
default:
vMarkAttendance();
break;
}
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
fp=fopen(dbAttendance, "wb");
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
vMarkAttendance();
}


void vModifyAttendance() {
int intCompare, intFound=0;
struct stAttendance st;
struct stAttendance st1;
FILE *fp, *fp1;
fp=fopen(dbAttendance, "rb");
strncpy(stA.chLecturerID, chUsername, 16);
system("cls||clear");
printf("\n\n==================== MODIFY ATTENDANCE =====================\n\n");
printf("Sample Format: 29-12-2000\n");
printf("\nPlease Enter The Attendance Taken Date: ");
scanf("%s", stA.chDate);
vUpper(stA.chDate);
fflush(stdin);

printf("\n============================================================\n\n");
printf("Sample Format: 14:45\n");
printf("\nPlease Enter The Class Started Time: ");
scanf("%s", stA.chStartTime);
vUpper(stA.chStartTime);
fflush(stdin);

printf("\n============================================================\n\n");
printf("Sample Format: 16:30\n");
printf("\nPlease Enter The Class Ended Time: ");
scanf("%s", stA.chEndTime);
vUpper(stA.chEndTime);
fflush(stdin);

system("cls||clear");
printf("\n\n==================== MODIFY ATTENDANCE =====================\n\n");
printf("TP NUMBER:\tSTATUS\t\tNAME:\n");
while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}
intCompare=(strcmp(stA.chStartTime,st.chStartTime))+(strcmp(stA.chEndTime,st.chEndTime))+(strcmp(stA.chDate,st.chDate))+(strcmp(stA.chLecturerID,st.chLecturerID));
if(intCompare==0) {
    printf("\n");
    printf("%s", st.chStudentTP);
    if(st.intStatus==4){
        printf("\tABSENTR");
    }
    else if(st.intStatus==3){
        printf("\tABSENT ");
    }
    else if(st.intStatus==2){
        printf("\tLATE   ");
    }
    else {
        printf("\tPRESENT");
    }
    printf("\t\t%s",st.chStudentName);
}
}
fclose(fp);
printf("\n\n============================================================\n\n");


fp=fopen(dbAttendance, "rb");
fp1=fopen("dbTemp.txt", "wb");

printf("1. MARK ATTENDANCE\n0. FINISH\n");
printf("\nChoose Your Option: ");
char chChoice;
scanf("%c", &chChoice);
fflush(stdin);

switch(chChoice) {
case '1':

break;
case '0':
vLecturerMenu();

break;
}

printf("\nEnter The Student's TP Number To Modify Attendance: ");
scanf("%s", stA.chStudentTP);
vUpper(stA.chStudentTP);
fflush(stdin);
while(1) {
fread(&st1, sizeof(st1), 1, fp);

if(feof(fp)) {
break;
}
int intCompare;
intCompare=(strcmp(stA.chStudentTP, st1.chStudentTP))+(strcmp(stA.chStartTime,st1.chStartTime))+(strcmp(stA.chEndTime,st1.chEndTime))+(strcmp(stA.chDate,st1.chDate));
if(intCompare==0) {
intFound=1;
printf("\n============================================================\n\n");
printf("1. PRESENT      2. LATE      3. ABSENT\n");
printf("\nChoose Your Option: ");
char chChoice1;
scanf("%c", &chChoice1);
fflush(stdin);

switch(chChoice1) {
case '1':
st1.intStatus=1;
break;
case '2':
st1.intStatus=2;
break;
case '3':
st1.intStatus=3;
break;
}
fwrite(&st1, sizeof(st1), 1, fp1);
}
else {
fwrite(&st1, sizeof(st1), 1, fp1);
}
}
fclose(fp);
fclose(fp1);

if(intFound==0) {
printf("\nSorry, No Record Found!\n");
}
else {
fp=fopen(dbAttendance, "wb");
fp1=fopen("dbTemp.txt", "rb");

while(1) {
fread(&st1, sizeof(st1), 1, fp1);

if(feof(fp1)) {
break;
}
fwrite(&st1, sizeof(st1), 1, fp);
}
}
fclose(fp);
fclose(fp1);
printf("\n============================================================\n\n");
}
