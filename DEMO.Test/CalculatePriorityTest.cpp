#include <gtest/gtest.h>
#include "../DEMO/PQueue.h"
#include "../DEMO/CalculatePriority.cpp"
#include "../DEMO/PQueue.cpp"
#include "../DEMO/ShowListStudentTickets.cpp"

class CalculatePriorityTest : public ::testing::Test {
protected:
    SinhVien sv;

    void SetUp() override {
        memset(sv.Mssv, 0, sizeof(sv.Mssv));
        memset(sv.TenSV, 0, sizeof(sv.TenSV));
        memset(sv.Lop, 0, sizeof(sv.Lop));
        memset(sv.Ill, 0, sizeof(sv.Ill));
        sv.CV = 0;
        sv.Tgian = {1,1,2020};
        sv.SoKhoa = 0;
        sv.IsCntt = false;
        sv.IsGoodHeal = false;
    }
};

// Assert that the nonIT student is 10000
static TEST_F(CalculatePriorityTest, CalculatePriorityForNonITStudent) {
    int expected_priority = 10000;
    ASSERT_EQ(calculatePriority(&sv), expected_priority);
}

// Assert that the IT student is 0
static TEST_F(CalculatePriorityTest, CalculatePriorityForITStudent) {
    sv.IsCntt = true;
    int expected_priority = 0;
    ASSERT_EQ(calculatePriority(&sv), expected_priority);
}

// Assert that the IT student which is in good health is 100
static TEST_F(CalculatePriorityTest, CalculatePriorityForITStudentWithGoodHealth) {
    sv.IsCntt = true;
    sv.IsGoodHeal = true;
    int expected_priority = 100;
    ASSERT_EQ(calculatePriority(&sv), expected_priority);
}

// Assert that the IT student with other factors
static TEST_F(CalculatePriorityTest, NonITStudentWithGoodHealth) {
    sv.SoKhoa = 1;
    sv.CV = 5;
    sv.IsGoodHeal = true;
    int expected_priority = 10000 + 1000 + 50 + 100;
    ASSERT_EQ(calculatePriority(&sv), expected_priority);
}

// Assert that the IT student with all factors
static TEST_F(CalculatePriorityTest, ITStudentWithMultipleYearsAndCV) {
    sv.IsCntt = true;
    sv.SoKhoa = 3;
    sv.CV = 7;
    sv.Tgian = {1,1,2020};
    sv.IsGoodHeal = true;
    int expected_priority = 3000 + 70 + 100;
    ASSERT_EQ(calculatePriority(&sv), expected_priority);
}
