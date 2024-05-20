#include <gtest/gtest.h>
#include "../DEMO/PQueue.h"

class CreatePQueueNodeWithValidSinhVienTest : public ::testing::Test {
};

// Test for creating a valid PQueueNode
static TEST_F(CreatePQueueNodeWithValidSinhVienTest, CreatePQueueNodeWithValidSinhVien) {
    SinhVien sv = { "123456789", "John Doe", "Class 1", 1, 120, "No", 5, true, true };
    PQueueNode* node = createPQueueNode(sv);

    ASSERT_NE(node, nullptr);
    EXPECT_EQ(strcmp(node->Info.Mssv, sv.Mssv), 0);
    EXPECT_EQ(strcmp(node->Info.TenSV, sv.TenSV), 0);
    EXPECT_EQ(strcmp(node->Info.Lop, sv.Lop), 0);
    EXPECT_EQ(node->Info.CV, sv.CV);
    EXPECT_EQ(node->Info.Tgian, sv.Tgian);
    EXPECT_EQ(strcmp(node->Info.Ill, sv.Ill), 0);
    EXPECT_EQ(node->Info.SoKhoa, sv.SoKhoa);
    EXPECT_EQ(node->Info.IsCntt, sv.IsCntt);
    EXPECT_EQ(node->Info.IsGoodHeal, sv.IsGoodHeal);
    EXPECT_EQ(node->Next, nullptr);

    delete node;
}

static TEST_F(CreatePQueueNodeWithValidSinhVienTest, CreatePQueueNodeWithEmptySinhVien) {
    SinhVien sv = { "", "", "", 0, 0, "", 0, false, false };

    PQueueNode* node = createPQueueNode(sv);

    ASSERT_NE(node, nullptr); // Check if node is not null
    EXPECT_STREQ(node->Info.Mssv, "");
    EXPECT_STREQ(node->Info.TenSV, "");
    EXPECT_STREQ(node->Info.Lop, "");
    EXPECT_EQ(node->Info.CV, 0);
    EXPECT_EQ(node->Info.Tgian, 0);
    EXPECT_STREQ(node->Info.Ill, "");
    EXPECT_EQ(node->Info.SoKhoa, 0);
    EXPECT_FALSE(node->Info.IsCntt);
    EXPECT_FALSE(node->Info.IsGoodHeal);
    EXPECT_EQ(node->Next, nullptr);

    delete node; // Clean up
}
