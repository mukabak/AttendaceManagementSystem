void vViewAttendance() {
char chModuleName[16];
int intCompare, intCompare_2, intFound1=0;
struct stAttendance st;
struct stModuleRecord st1;
FILE *fp, *fp1;
fp=fopen(dbAttendance, "rb");
fp1=fopen(dbModuleRecord, "rb");
system("cls||clear");
printf("\n\n=================== VIEW MY ATTENDANCE =====================\n\n");
printf("List Of %s's Registered Modules:\n", chUsername);
while(1) {
fread(&st1, sizeof(st1), 1, fp1);
if(feof(fp1)) {
break;
}
intCompare=strcmp(chUsername, st1.chUserID);
if(intCompare==0) {
printf("\n\t%s", st1.chModuleName);
intFound1=1;
}
}
if(intFound1==0) {
printf("\n\tNOT FOUND!");
}
fclose(fp1);

printf("\n\nEnter The Module's Name To View Attendance: ");
scanf("%s", chModuleName);
vUpper(chModuleName);
fflush(stdin);


system("cls||clear");
printf("\n\n=================== VIEW MY ATTENDANCE =====================\n\n");
printf("MODULE: %s", chModuleName);
printf("\t\tTP NUMBER: %s", chUsername);
printf("\n\nDATE\t\tSTART\t\tEND\t\tSTATUS\n");
while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}
intCompare=strcmp(chUsername,st.chStudentTP);
intCompare_2=strcmp(chModuleName,st.chModuleName);
if((intCompare==0) && (intCompare_2==0)) {
    printf("\n");
    printf("%s", st.chDate);
    printf("\t%s", st.chStartTime);
    printf("\t\t%s", st.chEndTime);
    if(st.intStatus==4){
        printf("\t\tABSENTR");
    }
    else if(st.intStatus==3){
        printf("\t\tABSENT ");
    }
    else if(st.intStatus==2){
        printf("\t\tLATE   ");
    }
    else {
        printf("\t\tPRESENT");
    }
}
}
fclose(fp);
printf("\n\n============================================================\n\n");
}
