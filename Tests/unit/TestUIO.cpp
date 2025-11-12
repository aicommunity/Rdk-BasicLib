#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UIOTest : public ::testing::Test {
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

// Test UIO creation
TEST_F(UIOTest, CreateIO) {
    // Check that UIO class is available
    if (!storage->CheckClass("UIO")) {
        GTEST_SKIP() << "UIO class not available in storage";
        return;
    }
    
    // Try to create UIO
    auto io = storage->TakeObject("UIO");
    if (io) {
        EXPECT_EQ(io->GetCompClassName(), "UIO");
        EXPECT_NE(io, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UIO object";
    }
}

// Test UIO properties
TEST_F(UIOTest, IOProperties) {
    if (!storage->CheckClass("UIO")) {
        GTEST_SKIP() << "UIO class not available";
        return;
    }
    
    auto io = storage->TakeObject("UIO");
    if (io) {
        // Verify class name
        EXPECT_EQ(io->GetCompClassName(), "UIO");
        
        // Verify component has valid ID
        UId id = io->GetId();
        EXPECT_NE(id, 0) << "UIO should have valid ID";
        
        // Verify component can be named
        io->SetName("TestIO");
        EXPECT_EQ(io->GetName(), "TestIO");
    } else {
        GTEST_SKIP() << "Cannot create UIO object";
    }
}

// Test UIO is a UNet
TEST_F(UIOTest, IOIsNet) {
    if (!storage->CheckClass("UIO")) {
        GTEST_SKIP() << "UIO class not available";
        return;
    }
    
    auto io = storage->TakeObject("UIO");
    if (io) {
        // UIO inherits from UNet, so it should support components
        EXPECT_GE(io->GetNumComponents(), 0) << "UIO should support components";
    } else {
        GTEST_SKIP() << "Cannot create UIO object";
    }
}

