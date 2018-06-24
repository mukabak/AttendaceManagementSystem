char chUsername[16];
char chUserPassword[16];
int intUserType;
char chAdminUsername[16]="abdullah";
char chAdminPassword[16]="123";

char dbLoginList[]={"dbLoginList.txt"};
char dbIntakeList[]={"dbIntakeList.txt"};
char dbModuleList[]={"dbModuleList.txt"};
char dbIntakeRecord[]={"dbIntakeRecord.txt"};
char dbModuleRecord[]={"dbModuleRecord.txt"};
char dbAttendance[]={"dbAttendance.txt"};
struct stLogin {
int intType;
char chTP[16];
char chPass[16];
char chName[30];
};

struct stIntakeList {
char chIntakeCode[16];
};

struct stModuleList {
char chModuleName[16];
};

struct stIntakeRecord {
char chIndex[16];
char chUserID[16];
char chIntakeCode[16];
};

struct stModuleRecord {
char chIndex[16];
char chUserID[16];
char chModuleName[16];
};

struct stAttendance {
char chDate[16];
char chStartTime[16];
char chEndTime[16];
char chModuleName[16];
char chStudentName[30];
char chIntakeCode[16];
char chLecturerID[16];
char chStudentTP[16];
int intStatus;
};

struct stAttendance stA;

void vUpper(char []);
char vGet();
int main();
int vRandomNumber(int, int);

void vCallStudent();
void vCallLecturer();
void vCallAdmin();

int vMainMenu();
int vAdminMenu();
int vLecturerMenu();
int vStudentMenu();
int vLecturerMenu();
int vManageStudentMenu();
int vManageLecturerMenu();
int vManageIntakeMenu();
int vManageModuleMenu();
void vAdminModifyAttendance();

void vAddStudent();
void vSearchStudent();
void vModifyStudent();
void vDeleteStudent();
void vViewAllStudents();
void vAddStudentIntake();
void vDeleteStudentIntake();
void vAddStudentModule();
void vDeleteStudentModule();

void vAddLecturer();
void vSearchLecturer();
void vModifyLecturer();
void vDeleteLecturer();
void vViewAllLecturer();
void vAddLecturerIntake();
void vDeleteLecturerIntake();
void vAddLecturerModule();
void vDeleteLecturerModule();

void vAddIntake();
void vDeleteIntake();
void vViewAllIntakes();

void vAddModule();
void vDeleteModule();
void vViewAllModules();

void vTakeAttendance();
void vMarkAttendance();
void vModifyAttendance();
void vViewMyIntakes();
void vViewMyModules();

void vViewAttendance();

char vGet() {
char chVal;
char chRel;
scanf("%c",&chVal);
scanf("%c",&chRel);
return (chVal);
}


void vUpper(char chString[]) {
   int i=0;
   while(chString[i]!='\0') {
      if(chString[i]>='a'&&chString[i]<='z') {
         chString[i]=chString[i]-32;
      }
      i++;
   }
}


int vRandomNumber(int intMin, int intMax)
{
    int intResult = 0, intLow = 0, intHigh = 0;
    if (intMin < intMax) {
        intLow = intMin;
        intHigh = intMax + 1;
    } else {
        intLow = intMax + 1;
        intHigh = intMin;
    }

    srand(time(NULL));
    intResult = (rand() % (intHigh - intLow)) + intLow;
    return intResult;
}
