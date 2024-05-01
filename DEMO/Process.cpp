#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void process() {
	ItemType X, Y;
	PQueueNode* P;
	PQueueNode* Q;
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
			populateToStudentListFromReadingFile(PQU,fileName);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien: ");
			showPQueue(PQU);
			break;
		}
		case 5:
		{
			printf("\n nhap mssv can xoa: ");
			scanf("%s", &mssv);
			PQueueNode* student = findStudentByStudentCode(PQU, mssv);
			if (student) {
			printf("\n Thong tin phieu uu cau cua sinh vien can xoa la: \n");
			const char* illnessStatus = (strcmp(student->Info.Ill, "Y") == 0) ? "Co" : "Khong";
			const char* jobDescription = getJobDescription(student->Info.CV);
			printf("  %-15s  %-20s  %-10s  %-10s  %-30s  %d/%d/%d\n", student->Info.Mssv, student->Info.TenSV, student->Info.Lop, illnessStatus, jobDescription, student->Info.Tgian.day, student->Info.Tgian.month, student->Info.Tgian.year);

				deleteStudentFromStudentCode(PQU, mssv);
			}
			else {
				printf("\n khong tim thay sinh vien can xoa  ");
			}
			
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
		case 8:
		{
			printf("\nNhap ma so sinh vien can uu tien: ");
			scanf("%s", &mssv);
			prioritizeJob(PQU, mssv);
			printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien sau khi uu tien: ");
			showPQueue(PQU);
			break;
		}
		case 9:
		{
			findClassWithMostJobs(PQU);
			printf("\nSinh vien lop co nhieu viec can khoa xu ly nhat:");
			break;
		}
		case 10:
		{
			showNext10Jobs(PQU);
			break;
		}
		case 11:
		{
			printAllRequestTickets(PQU);
			break;
		}
		case 12:
		{
			updateRequestTicket(PQU);
			break;
		}
		default:
			break;
		}
	} while (luachon != 0);
}