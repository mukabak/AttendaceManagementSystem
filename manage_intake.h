void vAddIntake() {
    system("cls||clear");
    FILE *fp;
    struct stIntakeList st;
    fp=fopen(dbIntakeList, "ab");
    printf("\n\n====================== ADD NEW INTAKE ======================\n\n");
    printf("Enter The Intake Code: ");
    scanf("%s", st.chIntakeCode);
    vUpper(st.chIntakeCode);
    fflush(stdin);

    fwrite(&st, sizeof(st), 1, fp);
    fclose(fp);
    printf("\n============================================================\n\n");
}


void vDeleteIntake() {
system("cls||clear");
FILE *fp, *fp1;
struct stIntakeList st;
int intFound=0;
char chIntake[16];

fp=fopen(dbIntakeList, "rb");
fp1=fopen("dbTemp.txt", "wb");

printf("\n\n====================== DELETE INTAKE =======================\n\n");
printf("Enter The Intake Code You Want To Delete: ");
scanf("%s", chIntake);
vUpper(chIntake);
fflush(stdin);

while(1) {
fread(&st, sizeof(st), 1, fp);

if(feof(fp)) {
break;
}

int intCompare;
intCompare=strcmp(chIntake, st.chIntakeCode);
if(intCompare==0) {
intFound=1;
}
else
{
fwrite(&st, sizeof(st), 1, fp1);
}
}
fclose(fp);
fclose(fp1);

if(intFound==0) {
printf("\nSorry, No Record Found!\n");
}
else {
fp=fopen(dbIntakeList, "wb");
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


void vViewAllIntakes() {
FILE *fp;
struct stIntakeList st;
fp=fopen(dbIntakeList, "rb");
system("cls||clear");
printf("\n\n===================== VIEW ALL INTAKES =====================\n\n");
printf("\tINTAKE CODE:\n");
while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}
printf("\n");
printf("\t%s",st.chIntakeCode);
}
printf("\n\n============================================================\n\n");
fclose(fp);
}


void vViewMyIntakes() {
FILE *fp1;
int intFound1=0, intCompare;
struct stIntakeRecord st1;
fp1=fopen(dbIntakeRecord, "rb");
system("cls||clear");
printf("\n\n===================== VIEW MY INTAKES ======================\n\n");
printf("LIST OF MY INTAKES:\n");
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
printf("\n\n============================================================\n\n");
fclose(fp1);
}
