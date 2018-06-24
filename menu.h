int vAdminMenu() {
char chChoice;
while(1) {
system("cls||clear");
printf("\n\n======================== ADMIN MENU ========================\n\n");
printf("\t1. MANAGE STUDENT\n\n");
printf("\t2. MANAGE LECTURE\n\n");
printf("\t3. MANAGE INTAKE\n\n");
printf("\t4. MANAGE MODULE\n\n");
printf("\t5. MODIFY ATTENDANCE\n\n");
printf("\t0. LOG OUT");
printf("\n\n============================================================\n\n");
printf("Please Enter Your Choice: ");
scanf("%c", &chChoice);
fflush(stdin);
switch(chChoice) {
case '1':
vManageStudentMenu();
break;
case '2':
vManageLecturerMenu();
break;
case '3':
vManageIntakeMenu();
break;
case '4':
vManageModuleMenu();
break;
case '5':
vAdminModifyAttendance();
break;
case '0':
main();
default:
vAdminMenu();
break;
}
vGet();
}
    return 0;
}


int vLecturerMenu() {
char chChoice;
while(1) {
system("cls||clear");
printf("\n\n======================= LECTURER MENU ======================\n\n");
printf("\t1. TAKE ATTENDANCE\n\n");
printf("\t2. MODIFY ATTENDANCE\n\n");
printf("\t3. VIEW ALL STUDENTS\n\n");
printf("\t4. VIEW MY INTAKES\n\n");
printf("\t5. VIEW MY MODULES\n\n");
printf("\t0. LOG OUT");
printf("\n\n============================================================\n\n");
printf("Please Enter Your Choice: ");
scanf("%c", &chChoice);
fflush(stdin);
switch(chChoice) {
case '1':
vTakeAttendance();
break;
case '2':
vModifyAttendance();
break;
case '3':
vViewAllStudents();
break;
case '4':
vViewMyIntakes();
break;
case '5':
vViewMyModules();
break;
case '0':
main();
default:
vLecturerMenu();
break;
}
vGet();
}
    return 0;
}


int vStudentMenu() {
char chChoice;
while(1) {
system("cls||clear");
printf("\n\n======================= STUDENT MENU =======================\n\n");
printf("\t1. VIEW MY ATTENDANCE\n\n");
printf("\t2. VIEW MY MODULES\n\n");
printf("\t0. LOG OUT");
printf("\n\n============================================================\n\n");
printf("Please Enter Your Choice: ");
scanf("%c", &chChoice);
fflush(stdin);
switch(chChoice) {
case '1':
vViewAttendance();
break;
case '2':
vViewMyModules();
break;
case '0':
main();
default:
vStudentMenu();
break;
}
vGet();
}
    return 0;
}


int vManageStudentMenu() {
char chChoice;
while(1) {
system("cls||clear");
printf("\n\n==================== MANAGE STUDENT MENU ===================\n\n");
printf("\t1. NEW STUDENT\n\n");
printf("\t2. SEARCH STUDENT\n\n");
printf("\t3. MODIFY STUDENT\n\n");
printf("\t4. DELETE STUDENT\n\n");
printf("\t5. VIEW ALL STUDENTS\n\n");
printf("\t6. ADD STUDENT INTAKE\n\n");
printf("\t7. DELETE STUDENT INTAKE\n\n");
printf("\t8. ADD STUDENT MODULE\n\n");
printf("\t9. DELETE STUDENT MODULE\n\n");
printf("\t0. BACK");
printf("\n\n============================================================\n\n");
printf("Please Enter Your Choice: ");
scanf("%c", &chChoice);
fflush(stdin);
switch(chChoice) {
case '1':
vAddStudent();
break;
case '2':
vSearchStudent();
break;
case '3':
vModifyStudent();
break;
case '4':
vDeleteStudent();
break;
case '5':
vViewAllStudents();
break;
case '6':
vAddStudentIntake();
break;
case '7':
vDeleteStudentIntake();
break;
case '8':
vAddStudentModule();
break;
case '9':
vDeleteStudentModule();
break;
case '0':
vAdminMenu();
default:
vManageStudentMenu();
break;
}
vGet();
}
    return 0;
}


int vManageLecturerMenu() {
char chChoice;
while(1) {
system("cls||clear");
printf("\n\n=================== MANAGE LECTURER MENU ===================\n\n");
printf("\t1. ADD NEW LECTURER\n\n");
printf("\t2. SEARCH LECTURER\n\n");
printf("\t3. MODIFY LECTURER\n\n");
printf("\t4. DELETE LECTURER\n\n");
printf("\t5. VIEW ALL LECTURER\n\n");
printf("\t6. ADD LECTURER INTAKE\n\n");
printf("\t7. DELETE LECTURER INTAKE\n\n");
printf("\t8. ADD LECTURER MODULE\n\n");
printf("\t9. DELETE LECTURER MODULE\n\n");
printf("\t0. BACK");
printf("\n\n============================================================\n\n");
printf("Please Enter Your Choice: ");
scanf("%c", &chChoice);
fflush(stdin);
switch(chChoice) {
case '1':
vAddLecturer();
break;
case '2':
vSearchLecturer();
break;
case '3':
vModifyLecturer();
break;
case '4':
vDeleteLecturer();
break;
case '5':
vViewAllLecturer();
break;
case '6':
vAddLecturerIntake();
break;
case '7':
vDeleteLecturerIntake();
break;
case '8':
vAddLecturerModule();
break;
case '9':
vDeleteLecturerModule();
break;
case '0':
vAdminMenu();
default:
vManageLecturerMenu();
break;
}
vGet();
}
    return 0;
}


int vManageIntakeMenu() {
char chChoice;
while(1) {
system("cls||clear");
printf("\n\n==================== MANAGE INTAKE MENU ====================\n\n");
printf("\t1. ADD INTAKE\n\n");
printf("\t2. DELETE INTAKE\n\n");
printf("\t3. VIEW ALL INTAKES\n\n");
printf("\t0. BACK");
printf("\n\n============================================================\n\n");
printf("Please Enter Your Choice: ");
scanf("%c", &chChoice);
fflush(stdin);
switch(chChoice) {
case '1':
vAddIntake();
break;
case '2':
vDeleteIntake();
break;
case '3':
vViewAllIntakes();
break;
case '0':
vAdminMenu();
default:
vManageIntakeMenu();
break;
}
vGet();
}
    return 0;
}


int vManageModuleMenu() {
char chChoice;
while(1) {
system("cls||clear");
printf("\n\n==================== MANAGE MODULE MENU ====================\n\n");
printf("\t1. ADD MODULE\n\n");
printf("\t2. DELETE MODULE\n\n");
printf("\t3. VIEW ALL MODULES\n\n");
printf("\t0. BACK");
printf("\n\n============================================================\n\n");
printf("Please Enter Your Choice: ");
scanf("%c", &chChoice);
fflush(stdin);
switch(chChoice) {
case '1':
vAddModule();
break;
case '2':
vDeleteModule();
break;
case '3':
vViewAllModules();
break;
case '0':
vAdminMenu();
default:
vManageModuleMenu();
break;
}
vGet();
}
    return 0;
}
