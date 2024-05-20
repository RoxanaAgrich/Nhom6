#include"PQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

PQueueNode* createPQueueNode(ItemType x) {
	//Cap phat 1 node moi de luu tru gia tri x
	PQueueNode* p = new PQueueNode;
	if (p == NULL) {
		printf("Khong the cap phat node moi!");
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

//====================================================
void showPQueueNode(PQueueNode* p) {
	//Hien thi thong tin 1 node ra man hinh
	printf("\n %-20s  %-20s  %-10s  %-10s  %-30s  %-10s\n", "MA SO SINH VIEN", "TEN SINH VIEN", "LOP", "BENH", "CONG VIEC", "THOI GIAN");

	const char* illnessStatus = (strcmp(p->Info.Ill, "Y") == 0) ? "Co" : "Khong";
	const char* jobDescription = getJobDescription(p->Info.CV);

	printf(" %-20s  %-20s  %-10s  %-10s  %-30s  %d/%d/%d\n", p->Info.Mssv, p->Info.TenSV, p->Info.Lop, illnessStatus, jobDescription, p->Info.Tgian.day, p->Info.Tgian.month, p->Info.Tgian.year);
}

//====================================================
void initPQueue(PQueue& qu) {
	//Khoi tao hang doi rong
	qu.Head = NULL;
	qu.Tail = NULL;
}

//====================================================
int isEmpty(PQueue qu) {
	//Kiem tra ds rong
	if (qu.Head == NULL) {
		return 1; //hang doi qu rong
	}
	else {
		return 0; //hang doi qu ko rong
	}
}

//====================================================
int insert(PQueue& qu, PQueueNode* p) {
    // Insert a node into the priority queue
    if (qu.Head == NULL) {
        qu.Head = p;
        qu.Tail = p;
        return 1;
    }

    PQueueNode* current = qu.Head;
    PQueueNode* previous = NULL;

    while (current != NULL && current->priority < p->priority) {
        previous = current;
        current = current->Next;
    }

    if (previous == NULL) {
        p->Next = qu.Head;
        qu.Head = p;
    }
    else if (current != NULL && current->priority == p->priority) {
        // Compare date and time if priority is same
        if (compareDateTime(&current->Info.Tgian, &p->Info.Tgian) == -1) {
            previous->Next = p;
            p->Next = current;
            return 1;
        }
        else {
            PQueueNode* nextNode = current->Next;
            current->Next = p;
            p->Next = nextNode;
            return 1;
        }
    }
    else {
        previous->Next = p;
        p->Next = current;
    }

    if (current == NULL) {
        qu.Tail = p;
    }

    return 1;
}
