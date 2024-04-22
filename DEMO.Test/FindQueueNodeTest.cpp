#include <gtest/gtest.h>
#include <cstring>
#include "../DEMO/PQueue.h"
#include "../DEMO/FindQueueNode.cpp"

class FindQueueNodeTest : public ::testing::Test {
protected:
    PQueue queue;

    void SetUp() override {
        queue.Head = nullptr;
        queue.Tail = nullptr;
    }

    void addStudent(const char* mssv, const char* tenSV, int priority) {
        PQueueNode* newNode = new PQueueNode;
        strncpy(newNode->Info.Mssv, mssv, sizeof(newNode->Info.Mssv));
        strncpy(newNode->Info.TenSV, tenSV, sizeof(newNode->Info.TenSV));
        newNode->priority = priority;
        newNode->Next = nullptr;

        if (queue.Tail) {
            queue.Tail->Next = newNode;
        }
        else {
            queue.Head = newNode;
        }
        queue.Tail = newNode;
    }

    bool isEmpty() const {
        return queue.Head == nullptr;
    }
};

// Finding a student by student code
static TEST_F(FindQueueNodeTest, FindExistingStudent) {
    addStudent("123", "John Doe", 10);
    addStudent("124", "Jane Doe", 20);

    PQueueNode* found = findStudentByStudentCode(queue, "123");
    ASSERT_NE(found, nullptr);
    EXPECT_STREQ(found->Info.Mssv, "123");
    EXPECT_STREQ(found->Info.TenSV, "John Doe");
}

// Finding a non-existent student
static TEST_F(FindQueueNodeTest, FindNonExistentStudent) {
    addStudent("123", "John Doe", 10);
    addStudent("124", "Jane Doe", 20);

    PQueueNode* found = findStudentByStudentCode(queue, "999");
    EXPECT_EQ(found, nullptr);
}

// Finding a student in an empty queue
static TEST_F(FindQueueNodeTest, FindInEmptyQueue) {
    PQueueNode* found = findStudentByStudentCode(queue, "123");
    EXPECT_EQ(found, nullptr);
}

// Null student code
static TEST_F(FindQueueNodeTest, FindWithNullStudentCode) {
    addStudent("123", "John Doe", 10);

    PQueueNode* found = findStudentByStudentCode(queue, nullptr);
    EXPECT_EQ(found, nullptr);
}
