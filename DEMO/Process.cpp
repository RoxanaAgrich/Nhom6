#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void process() {
	ItemType X, Y;
	PQueueNode* P, * Q;
	PQueue PQU;
	initPQueue(PQU);
	int luachon;
	int kq;
	const char* fileName = "dsSinhVien.txt";
	ItemType x;
	PQueueNode* student;
	char mssv[250]{};
	do
	{
		showMenu();
		printf("\nLua chon mot chuc nang: ");
		scanf_s("%d", &luachon);

		switch (luachon)
		{
		case 1:
		{
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		}
		case 2:
		{
			createPQueue(PQU);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		}
		case 3:
		{
			insertAStudentNodeIntoPQueue(PQU);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		}
		case 4:
		{
			populateToStudentListFromReadingFile(PQU, fileName);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		}
		case 5:
		{
			printf("\n nhap mssv can xoa: ");
			scanf("%s", &mssv);
			deleteStudentFromStudentCode(PQU, mssv);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		}
		case 6:
		{
			printf("\n Nhap ma so sinh vien can tim kiem trong danh sach phieu giai quyet cong viec: ");
			scanf("%s", &mssv);
			student = findStudentByStudentCode(PQU, mssv);
			if (!student) {
				printf("\n sinh vien co ma so sinh vien %s khong co trong phieu giai quyet cong viec ", mssv);
				return;
			}
			printf("\n Thong tin phieu uu cau cua sinh vien can tim la: \n");
			showPQueueNode(student);
			break;
		}
		case 7:
		{
			bool canSaveToFile = saveToFile(PQU, fileName);
			if (canSaveToFile) {
				printf("\n Chuc mung! Ban da dong bo file luu tru danh sach phieu giai quyet yeu cau cua sinh vien hien tai thanh cong!");
			}
			else {
				printf("\n Loi! That bai viec dong bo!");
			}
			break;
		}
		case 10: {
			int resultSize = 0;
			ClassWithStudents* classesWithMost = getClassesWithMostRequestTickets(PQU, &resultSize);
			if (resultSize > 0) {
				if (resultSize == 1) {
					printf("\nLop co so phieu giai quyet yeu cau cua sinh vien cao nhat la %s voi %d so phieu yeu cau", classesWithMost[0].className, classesWithMost[0].studentCount);
					printf("\Duoi day la danh sach phieu giai quyet yeu cau cua hoc sinh cua lop %s:\n", classesWithMost[0].className);
					for (int j = 0; j < classesWithMost[0].studentCount; j++) {
						int jobNumber = classesWithMost[0].students[j].CV;
						const char* jobDescription = getJobDescription(jobNumber);
						printf("  - %s (MSSV: %s) - %s\n", classesWithMost[0].students[j].TenSV, classesWithMost[0].students[j].Mssv, jobDescription);
					}
				}
				else 
				{
					printf("Co tong cong %d lop sau day la co so phieu giai quyet yeu cau sinh vien cao nhat, do la:\n", resultSize);
					for (int i = 0; i < resultSize; i++)
					{
						printf("Lop %s voi %d so phieu yeu cau\n", classesWithMost[i].className, classesWithMost[i].studentCount);
					}
					for (int i = 0; i < resultSize; i++)
					{
						printf("\n\n\nDuoi day la danh sach phieu giai quyet yeu cau cua hoc sinh cua lop %s:\n", classesWithMost[i].className);
						for (int j = 0; j < classesWithMost[i].studentCount; j++) {
							int jobNumber = classesWithMost[i].students[j].CV;
							const char* jobDescription = getJobDescription(jobNumber);
							printf("  - %s (MSSV: %s) - %s\n", classesWithMost[i].students[j].TenSV, classesWithMost[i].students[j].Mssv, jobDescription);
						}
					}
					free(classesWithMost);
				}
			}
			else {
				printf("Khong co lop nao dang xu ly yeu cau cua sinh vien.\n");
			}
		}
		default:
			break;
		}
	} while (luachon != 0);
}