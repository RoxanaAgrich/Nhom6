#include <gtest/gtest.h>
#include <cstring>
#include "../DEMO/PQueue.h"
#include "../DEMO/CreateListStudentTicketsByHand.cpp"

class CreateListStudentTicketsByHandTest : public ::testing::Test {
protected:
    PQueueNode* newNode;

    virtual void SetUp() {
        newNode = new PQueueNode(); // Allocate memory for newNode
    }

    virtual void TearDown() {
        delete newNode; // Deallocate memory for newNode
    }

    void createPQueueNode(const ItemType& x) {
        newNode = new PQueueNode(); // Allocate memory for newNode
        strncpy(newNode->Info.Mssv, x.Mssv, sizeof(newNode->Info.Mssv));
        strncpy(newNode->Info.TenSV, x.TenSV, sizeof(newNode->Info.TenSV));
        strncpy(newNode->Info.Lop, x.Lop, sizeof(newNode->Info.Lop));
        strncpy(newNode->Info.Ill, x.Ill, sizeof(newNode->Info.Ill));
        newNode->Info.CV = x.CV;
        newNode->Info.IsCntt = x.IsCntt;
        newNode->Info.SoKhoa = x.SoKhoa;
        newNode->Info.Tgian = x.Tgian;
        newNode->Info.IsGoodHeal = x.IsGoodHeal;
        delete newNode;
    }
};

TEST_F(CreateListStudentTicketsByHandTest, CreateANewStudent) {
    ItemType expectedStudentTicket{ "111111111","Roxana Agriche","14DHTH",4,1,"N",1,0 };

    createPQueueNode(expectedStudentTicket);
    EXPECT_STREQ(newNode->Info.Mssv, "111111111");
    EXPECT_STREQ(newNode->Info.TenSV, "Roxana Agriche");
    EXPECT_STREQ(newNode->Info.Lop, "14DHTH");
    EXPECT_EQ(newNode->Info.CV, 4);
    EXPECT_EQ(newNode->Info.Tgian, 1);
    EXPECT_STREQ(newNode->Info.Ill, "N");
    EXPECT_EQ(newNode->Info.IsCntt, 1);
    EXPECT_EQ(newNode->Info.IsGoodHeal, 0);
}