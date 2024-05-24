#include "pch.h"
#include "../DEMO/PQueue.h"

class CalculatePriorityTest : public ::testing::Test {
//protected:
//    SinhVien sv;
//
//    void SetUp() override {
//        memset(sv.Mssv, 0, sizeof(sv.Mssv));
//        memset(sv.TenSV, 0, sizeof(sv.TenSV));
//        memset(sv.Lop, 0, sizeof(sv.Lop));
//        memset(sv.Ill, 0, sizeof(sv.Ill));
//        sv.CV = 0;
//        sv.Tgian = { 1,1,2020 };
//        sv.SoKhoa = 0;
//        sv.IsCntt = false;
//        sv.IsGoodHeal = false;
//    }
};

static TEST_F(CalculatePriorityTest, CalculatePriorityForNonITStudent) {
    DateTime dt = { 1, 1, 2000 };
    ItemType sv = { "123456789", "John Doe", "Class 1", 1, "N", 10, true, true, dt};

    int expected_priority = 10000;
    ASSERT_EQ(calculatePriority(&sv), expected_priority);
}