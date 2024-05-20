#include "PQueue.h"
void printAllRequestTickets(PQueue qu) {
	if (isEmpty(qu)) {
		printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien rong!\n");
		return;
	}

	printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien:\n");
	printf("\n%-4s  %-15s  %-20s  %-10s  %-10s  %-30s  %-10s\n", "STT", "MA SO SINH VIEN", "TEN SINH VIEN", "LOP", "BENH", "CONG VIEC", "THOI GIAN");

	int stt = 1;
	PQueueNode* p = qu.Head;
	while (p != NULL) {
		const char* illnessStatus = strcmp(p->Info.Ill, "Y") == 0 || strcmp(p->Info.Ill, "y") == 0 ? "Co" : "Khong";
		const char* jobDescription = getJobDescription(p->Info.CV);

		printf("%-4d  %-15s  %-20s  %-10s  %-10s  %-30s  %d/%d/%d\n", stt++, p->Info.Mssv, p->Info.TenSV, p->Info.Lop, illnessStatus, jobDescription, p->Info.Tgian.day, p->Info.Tgian.month, p->Info.Tgian.year);
		p = p->Next;
	}
}