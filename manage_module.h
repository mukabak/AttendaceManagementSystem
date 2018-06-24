void vAddModule() {
    system("cls||clear");
    FILE *fp;
    struct stModuleList st;
    fp=fopen(dbModuleList, "ab");
    printf("\n\n====================== ADD NEW MODULE ======================\n\n");
    printf("Enter Module Name: ");
    scanf("%s", st.chModuleName);
    vUpper(st.chModuleName);
    fflush(stdin);

    fwrite(&st, sizeof(st), 1, fp);
    fclose(fp);
    printf("\n============================================================\n\n");
}


void vDeleteModule() {
system("cls||clear");
FILE *fp, *fp1;
struct stModuleList st;
int intFound=0;
char chModule[16];

fp=fopen(dbModuleList, "rb");
fp1=fopen("dbTemp.txt", "wb");

printf("\n\n====================== DELETE MODULE =======================\n\n");
printf("Enter The Module Name You Want To Delete: ");
scanf("%s", chModule);
vUpper(chModule);
fflush(stdin);

while(1) {
fread(&st, sizeof(st), 1, fp);

if(feof(fp)) {
break;
}

int intCompare;
intCompare=strcmp(chModule, st.chModuleName);
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
fp=fopen(dbModuleList, "wb");
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


void vViewAllModules() {
FILE *fp;
struct stModuleList st;
fp=fopen(dbModuleList, "rb");
system("cls||clear");
printf("\n\n===================== VIEW ALL MODULES =====================\n\n");
printf("\tMODULE NAME:\n");
while(1) {
fread(&st, sizeof(st), 1, fp);
if(feof(fp)) {
break;
}
printf("\n");
printf("\t%s",st.chModuleName);
}
printf("\n\n============================================================\n\n");
fclose(fp);
}


void vViewMyModules() {
FILE *fp1;
int intFound1=0, intCompare;
struct stModuleRecord st1;
fp1=fopen(dbModuleRecord, "rb");
system("cls||clear");
printf("\n\n===================== VIEW MY MODULES ======================\n\n");
printf("LIST OF MY MODULES:\n");
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
printf("\n\n============================================================\n\n");
fclose(fp1);
}
