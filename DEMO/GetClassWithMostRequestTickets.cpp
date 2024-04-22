#include"PQueue.h"

ClassWithStudents* getClassesWithMostRequestTickets(PQueue qu, int* resultSize) {
    *resultSize = 0;

    if (isEmpty(qu)) {
        return NULL;
    }

    typedef struct {
        char className[250];
        int count;
        ItemType* students;
        int studentIndex;
    } ClassCount;

    const int MAX_CLASSES = 10000;
    ClassCount* classCounts = (ClassCount*)malloc(sizeof(ClassCount) * MAX_CLASSES);
    if (!classCounts) {
        return NULL;
    }

    int classCountSize = 0;

    PQueueNode* current = qu.Head;

    while (current != NULL) {
        const char* className = current->Info.Lop;

        int found = 0;
        for (int i = 0; i < classCountSize; i++) {
            if (strcmp(classCounts[i].className, className) == 0) {
                if (classCounts[i].students) {
                    classCounts[i].students[classCounts[i].studentIndex++] = current->Info;
                }
                classCounts[i].count++;
                found = 1;
                break;
            }
        }

        if (!found && classCountSize < MAX_CLASSES) {
            strncpy(classCounts[classCountSize].className, className, sizeof(classCounts[classCountSize].className));
            classCounts[classCountSize].count = 1;
            classCounts[classCountSize].students = (SinhVien*)malloc(sizeof(SinhVien) * 100);
            if (classCounts[classCountSize].students) {
                classCounts[classCountSize].students[0] = current->Info;
                classCounts[classCountSize].studentIndex = 1;
            }
            else {
                for (int j = 0; j < classCountSize; j++) {
                    free(classCounts[j].students);
                }
                free(classCounts);
                return NULL;
            }
            classCountSize++;
        }

        current = current->Next;
    }

    int maxCount = 0;
    for (int i = 0; i < classCountSize; i++) {
        if (classCounts[i].count > maxCount) {
            maxCount = classCounts[i].count;
        }
    }

    ClassWithStudents* maxClasses = (ClassWithStudents*)malloc(sizeof(ClassWithStudents) * classCountSize);
    if (!maxClasses) {
        for (int i = 0; i < classCountSize; i++) {
            free(classCounts[i].students);
        }
        free(classCounts);
        return NULL;
    }

    int maxClassCount = 0;
    for (int i = 0; i < classCountSize; i++) {
        if (classCounts[i].count == maxCount) {
            strncpy(maxClasses[maxClassCount].className, classCounts[i].className, sizeof(maxClasses[maxClassCount].className));
            maxClasses[maxClassCount].studentCount = classCounts[i].count;
            maxClasses[maxClassCount].students = classCounts[i].students;
            maxClassCount++;
        }
        else {
            free(classCounts[i].students);
        }
    }

    free(classCounts);

    *resultSize = maxClassCount;

    return maxClasses;
}