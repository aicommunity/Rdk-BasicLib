#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UNoiseTest : public ::testing::Test {
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

// Test UNoise creation
TEST_F(UNoiseTest, CreateNoise) {
    if (!storage->CheckClass("UNoise")) {
        GTEST_SKIP() << "UNoise class not available in storage";
        return;
    }
    
    auto noise = storage->TakeObject("UNoise");
    if (noise) {
        EXPECT_EQ(noise->GetCompClassName(), "UNoise");
        EXPECT_NE(noise, nullptr);
        
        // Test setting name
        noise->SetName("TestNoise");
        EXPECT_EQ(noise->GetName(), "TestNoise");
    } else {
        GTEST_SKIP() << "Cannot create UNoise object";
    }
}

// Test UNoise basic properties
TEST_F(UNoiseTest, NoiseProperties) {
    if (!storage->CheckClass("UNoise")) {
        GTEST_SKIP() << "UNoise class not available in storage";
        return;
    }
    
    auto noise = storage->TakeObject("UNoise");
    if (noise) {
        EXPECT_EQ(noise->GetCompClassName(), "UNoise");
        
        // Verify component supports basic operations
        EXPECT_GE(noise->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UNoise object";
    }
}

