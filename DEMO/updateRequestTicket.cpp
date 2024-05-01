#include "PQueue.h"
void updateRequestTicket(PQueue& qu) {
	if (isEmpty(qu)) {
		printf("\nDanh sach phieu giai quyet yeu cau cua sinh vien rong!\n");
		return;
	}

	char mssv[250];
	printf("\nNhap ma so sinh vien cua phieu muon cap nhat: ");
	scanf("%s", &mssv);

	PQueueNode* student = findStudentByStudentCode(qu, mssv);
	if (!student) {
		printf("\nKhong tim thay sinh vien co ma so sinh vien la %s.\n", mssv);
		return;
	}

	printf("\nThong tin phieu yeu cau cua sinh vien can cap nhat la: \n");
	showPQueueNode(student);

	printf("\nCap nhat thong tin cho phieu yeu cau cua sinh vien:\n");
	enterInfoForStudentRequestTicket(student->Info);

	student->priority = calculatePriority(&student->Info);
	printf("\nCap nhat thong tin thanh cong.\n");
}