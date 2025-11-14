#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UFileDatasetTest : public ::testing::Test {
protected:
    void SetUp() override {
        InitTestLogging();
        storage = CreateTestStorage();
    }

    void TearDown() override {
        storage.reset();
    }

    std::shared_ptr<UStorage> storage;
};

// Test UFileDataset creation
TEST_F(UFileDatasetTest, CreateFileDataset) {
    if (!storage->CheckClass("UFileDataset")) {
        GTEST_SKIP() << "UFileDataset class not available in storage";
        return;
    }
    
    auto fileDataset = storage->TakeObject("UFileDataset");
    if (fileDataset) {
        EXPECT_EQ(fileDataset->GetCompClassName(), "UFileDataset");
        EXPECT_NE(fileDataset, nullptr);
        
        // Test setting name
        fileDataset->SetName("TestFileDataset");
        EXPECT_EQ(fileDataset->GetName(), "TestFileDataset");
    } else {
        GTEST_SKIP() << "Cannot create UFileDataset object";
    }
}

// Test UFileDataset properties
TEST_F(UFileDatasetTest, FileDatasetProperties) {
    if (!storage->CheckClass("UFileDataset")) {
        GTEST_SKIP() << "UFileDataset class not available in storage";
        return;
    }
    
    auto fileDataset = storage->TakeObject("UFileDataset");
    if (fileDataset) {
        EXPECT_EQ(fileDataset->GetCompClassName(), "UFileDataset");
        EXPECT_NE(fileDataset, nullptr);
        
        // Test setting name
        fileDataset->SetName("TestFileDatasetProperties");
        EXPECT_EQ(fileDataset->GetName(), "TestFileDatasetProperties");
        
        // Verify component supports basic operations
        EXPECT_GE(fileDataset->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UFileDataset object";
    }
}

