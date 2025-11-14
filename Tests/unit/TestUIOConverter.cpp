#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UIOConverterTest : public ::testing::Test {
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

// Test UIOConverter creation
TEST_F(UIOConverterTest, CreateIOConverter) {
    if (!storage->CheckClass("UIOConverter")) {
        GTEST_SKIP() << "UIOConverter class not available in storage";
        return;
    }
    
    auto ioConverter = storage->TakeObject("UIOConverter");
    if (ioConverter) {
        EXPECT_EQ(ioConverter->GetCompClassName(), "UIOConverter");
        EXPECT_NE(ioConverter, nullptr);
        
        // Test setting name
        ioConverter->SetName("TestIOConverter");
        EXPECT_EQ(ioConverter->GetName(), "TestIOConverter");
    } else {
        GTEST_SKIP() << "Cannot create UIOConverter object";
    }
}

// Test UIOTextConverter creation
TEST_F(UIOConverterTest, CreateTextConverter) {
    if (!storage->CheckClass("UIOTextConverter")) {
        GTEST_SKIP() << "UIOTextConverter class not available in storage";
        return;
    }
    
    auto textConverter = storage->TakeObject("UIOTextConverter");
    if (textConverter) {
        EXPECT_EQ(textConverter->GetCompClassName(), "UIOTextConverter");
        EXPECT_NE(textConverter, nullptr);
        
        // Test setting name
        textConverter->SetName("TestTextConverter");
        EXPECT_EQ(textConverter->GetName(), "TestTextConverter");
    } else {
        GTEST_SKIP() << "Cannot create UIOTextConverter object";
    }
}

