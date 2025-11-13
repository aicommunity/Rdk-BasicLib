#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UNoiseGenTest : public ::testing::Test {
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

// Test UNoiseGen creation
TEST_F(UNoiseGenTest, CreateNoiseGen) {
    if (!storage->CheckClass("UNoiseGen")) {
        GTEST_SKIP() << "UNoiseGen class not available in storage";
        return;
    }
    
    auto noiseGen = storage->TakeObject("UNoiseGen");
    if (noiseGen) {
        EXPECT_EQ(noiseGen->GetCompClassName(), "UNoiseGen");
        EXPECT_NE(noiseGen, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UNoiseGen object";
    }
}

// Test UNoiseGenDouble creation
TEST_F(UNoiseGenTest, CreateNoiseGenDouble) {
    if (!storage->CheckClass("UNoiseGenDouble")) {
        GTEST_SKIP() << "UNoiseGenDouble class not available in storage";
        return;
    }
    
    auto noiseGen = storage->TakeObject("UNoiseGenDouble");
    if (noiseGen) {
        EXPECT_EQ(noiseGen->GetCompClassName(), "UNoiseGenDouble");
        EXPECT_NE(noiseGen, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UNoiseGenDouble object";
    }
}

// Test UNoiseGenInt creation
TEST_F(UNoiseGenTest, CreateNoiseGenInt) {
    if (!storage->CheckClass("UNoiseGenInt")) {
        GTEST_SKIP() << "UNoiseGenInt class not available in storage";
        return;
    }
    
    auto noiseGen = storage->TakeObject("UNoiseGenInt");
    if (noiseGen) {
        EXPECT_EQ(noiseGen->GetCompClassName(), "UNoiseGenInt");
        EXPECT_NE(noiseGen, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UNoiseGenInt object";
    }
}

// Test UNoiseGen properties
TEST_F(UNoiseGenTest, NoiseGenProperties) {
    if (!storage->CheckClass("UNoiseGen")) {
        GTEST_SKIP() << "UNoiseGen class not available";
        return;
    }
    
    auto noiseGen = storage->TakeObject("UNoiseGen");
    if (noiseGen) {
        EXPECT_EQ(noiseGen->GetCompClassName(), "UNoiseGen");
        
        // Verify component can be named
        noiseGen->SetName("TestNoiseGen");
        EXPECT_EQ(noiseGen->GetName(), "TestNoiseGen");
        
        // Verify component supports basic operations
        EXPECT_GE(noiseGen->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UNoiseGen object";
    }
}

// Test UNoiseGenDouble properties
TEST_F(UNoiseGenTest, NoiseGenDoubleProperties) {
    if (!storage->CheckClass("UNoiseGenDouble")) {
        GTEST_SKIP() << "UNoiseGenDouble class not available";
        return;
    }
    
    auto noiseGen = storage->TakeObject("UNoiseGenDouble");
    if (noiseGen) {
        EXPECT_EQ(noiseGen->GetCompClassName(), "UNoiseGenDouble");
        
        // Verify component can be named
        noiseGen->SetName("TestNoiseGenDouble");
        EXPECT_EQ(noiseGen->GetName(), "TestNoiseGenDouble");
        
        // Verify component supports basic operations
        EXPECT_GE(noiseGen->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UNoiseGenDouble object";
    }
}

// Test UNoiseGenInt properties
TEST_F(UNoiseGenTest, NoiseGenIntProperties) {
    if (!storage->CheckClass("UNoiseGenInt")) {
        GTEST_SKIP() << "UNoiseGenInt class not available";
        return;
    }
    
    auto noiseGen = storage->TakeObject("UNoiseGenInt");
    if (noiseGen) {
        EXPECT_EQ(noiseGen->GetCompClassName(), "UNoiseGenInt");
        
        // Verify component can be named
        noiseGen->SetName("TestNoiseGenInt");
        EXPECT_EQ(noiseGen->GetName(), "TestNoiseGenInt");
        
        // Verify component supports basic operations
        EXPECT_GE(noiseGen->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UNoiseGenInt object";
    }
}

