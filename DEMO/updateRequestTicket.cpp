#include "PQueue.h"
void updateRequestTicket(PQueue& qu) {
    char mssv[250];
    printf("\nNhap ma so sinh vien can cap nhat thong tin: ");
    scanf("%s", mssv);

    PQueueNode* student = findStudentByStudentCode(qu, mssv);
    if (!student) {
        printf("\nKhong tim thay sinh vien co ma so sinh vien %s trong danh sach.", mssv);
        return;
    }

    // Hiển thị thông tin cũ của sinh viên trước khi cập nhật
    printf("\nThong tin phieu uu cau cua sinh vien truoc khi cap nhat: \n");
    showPQueueNode(student);

    // Nhập thông tin mới cho sinh viên
    printf("\nNhap thong tin moi cho sinh vien: \n");
    enterInfoForStudentRequestTicket(student->Info);

    // Cập nhật lại độ ưu tiên của sinh viên sau khi thay đổi thông tin
    student->priority = calculatePriority(&(student->Info));

    // Xác định vị trí cần chèn lại trong hàng đợi sau khi cập nhật thông tin
    PQueueNode* curr = qu.Head;
    PQueueNode* prev = NULL;
    while (curr && curr != student) {
        prev = curr;
        curr = curr->Next;
    }

    // Nếu sinh viên được cập nhật là đầu danh sách
    if (!prev) {
        qu.Head = student->Next;
    }
    else {
        prev->Next = student->Next;
    }

    // Chèn lại sinh viên sau khi cập nhật thông tin và tính lại độ ưu tiên
    insert(qu, student);

    // Hiển thị thông tin sau khi cập nhật
    printf("\nThong tin phieu uu cau cua sinh vien sau khi cap nhat: \n");
    showPQueueNode(student);
}