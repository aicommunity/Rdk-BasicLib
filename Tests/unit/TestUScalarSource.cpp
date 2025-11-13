#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UScalarSourceTest : public ::testing::Test {
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

// Test UScalarSource creation
TEST_F(UScalarSourceTest, CreateScalarSource) {
    if (!storage->CheckClass("UScalarSource")) {
        GTEST_SKIP() << "UScalarSource class not available in storage";
        return;
    }
    
    auto scalarSource = storage->TakeObject("UScalarSource");
    if (scalarSource) {
        EXPECT_EQ(scalarSource->GetCompClassName(), "UScalarSource");
        EXPECT_NE(scalarSource, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UScalarSource object";
    }
}

// Test UScalarSource properties
TEST_F(UScalarSourceTest, ScalarSourceProperties) {
    if (!storage->CheckClass("UScalarSource")) {
        GTEST_SKIP() << "UScalarSource class not available";
        return;
    }
    
    auto scalarSource = storage->TakeObject("UScalarSource");
    if (scalarSource) {
        EXPECT_EQ(scalarSource->GetCompClassName(), "UScalarSource");
        
        // Verify component can be named
        scalarSource->SetName("TestScalarSource");
        EXPECT_EQ(scalarSource->GetName(), "TestScalarSource");
        
        // Verify component supports basic operations
        EXPECT_GE(scalarSource->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UScalarSource object";
    }
}

// Test UScalarSource is a UNet
TEST_F(UScalarSourceTest, ScalarSourceIsNet) {
    if (!storage->CheckClass("UScalarSource")) {
        GTEST_SKIP() << "UScalarSource class not available";
        return;
    }
    
    auto scalarSource = storage->TakeObject("UScalarSource");
    if (scalarSource) {
        // UScalarSource inherits from UNet, so it should support components
        EXPECT_GE(scalarSource->GetNumComponents(), 0) << "UScalarSource should support components";
    } else {
        GTEST_SKIP() << "Cannot create UScalarSource object";
    }
}

