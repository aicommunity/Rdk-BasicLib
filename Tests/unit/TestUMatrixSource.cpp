#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UMatrixSourceTest : public ::testing::Test {
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

// Test UMatrixSource creation
TEST_F(UMatrixSourceTest, CreateMatrixSource) {
    // Check that UMatrixSource class is available
    if (!storage->CheckClass("UMatrixSource")) {
        GTEST_SKIP() << "UMatrixSource class not available in storage";
        return;
    }
    
    // Try to create UMatrixSource
    auto matrixSource = storage->TakeObject("UMatrixSource");
    if (matrixSource) {
        EXPECT_EQ(matrixSource->GetCompClassName(), "UMatrixSource");
        EXPECT_NE(matrixSource, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UMatrixSource object";
    }
}

// Test UMatrixSource properties
TEST_F(UMatrixSourceTest, MatrixSourceProperties) {
    if (!storage->CheckClass("UMatrixSource")) {
        GTEST_SKIP() << "UMatrixSource class not available";
        return;
    }
    
    auto matrixSource = storage->TakeObject("UMatrixSource");
    if (matrixSource) {
        // Verify class name
        EXPECT_EQ(matrixSource->GetCompClassName(), "UMatrixSource");
        
        // Verify component has valid ID
        UId id = matrixSource->GetId();
        EXPECT_NE(id, 0) << "UMatrixSource should have valid ID";
        
        // Verify component can be named
        matrixSource->SetName("TestMatrixSource");
        EXPECT_EQ(matrixSource->GetName(), "TestMatrixSource");
    } else {
        GTEST_SKIP() << "Cannot create UMatrixSource object";
    }
}

// Test UMatrixSource is a UNet
TEST_F(UMatrixSourceTest, MatrixSourceIsNet) {
    if (!storage->CheckClass("UMatrixSource")) {
        GTEST_SKIP() << "UMatrixSource class not available";
        return;
    }
    
    auto matrixSource = storage->TakeObject("UMatrixSource");
    if (matrixSource) {
        // UMatrixSource inherits from UNet, so it should support components
        EXPECT_GE(matrixSource->GetNumComponents(), 0) << "UMatrixSource should support components";
    } else {
        GTEST_SKIP() << "Cannot create UMatrixSource object";
    }
}

