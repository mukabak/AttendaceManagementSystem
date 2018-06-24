void vAdminModifyAttendance() {
int intCompare, intFound=0;
struct stAttendance st;
struct stAttendance st1;
FILE *fp, *fp1;
fp=fopen(dbAttendance, "rb");
strncpy(stA.chLecturerID, chUsername, 16);
system("cls||clear");
printf("\n\n==================== MODIFY ATTENDANCE =====================\n\n");
printf("Please Enter The Intake Code: ");
scanf("%s", stA.chIntakeCode);
vUpper(stA.chIntakeCode);
fflush(stdin);

printf("\n============================================================\n\n");
printf("Please Enter The Module Name: ");
scanf("%s", stA.chModuleName);
vUpper(stA.chModuleName);
fflush(stdin);

printf("\n============================================================\n\n");
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
intCompare=(strcmp(stA.chStartTime,st.chStartTime))+(strcmp(stA.chEndTime,st.chEndTime))+(strcmp(stA.chDate,st.chDate))+(strcmp(stA.chIntakeCode,st.chIntakeCode))+(strcmp(stA.chModuleName,st.chModuleName));
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
printf("1. PRESENT    2. LATE    3. ABSENT    4. ABSENT WITH REASON\n");
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
case '4':
st1.intStatus=4;
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
printf("\nAttendance Successfully Modified!");
printf("\n\n============================================================\n\n");
}
