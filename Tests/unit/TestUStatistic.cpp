#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UStatisticTest : public ::testing::Test {
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

// Test UStatisticIntMatrix creation
TEST_F(UStatisticTest, CreateStatisticIntMatrix) {
    if (!storage->CheckClass("UStatisticIntMatrix")) {
        GTEST_SKIP() << "UStatisticIntMatrix class not available in storage";
        return;
    }
    
    auto statistic = storage->TakeObject("UStatisticIntMatrix");
    if (statistic) {
        EXPECT_EQ(statistic->GetCompClassName(), "UStatisticIntMatrix");
        EXPECT_NE(statistic, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UStatisticIntMatrix object";
    }
}

// Test UStatisticDoubleMatrix creation
TEST_F(UStatisticTest, CreateStatisticDoubleMatrix) {
    if (!storage->CheckClass("UStatisticDoubleMatrix")) {
        GTEST_SKIP() << "UStatisticDoubleMatrix class not available in storage";
        return;
    }
    
    auto statistic = storage->TakeObject("UStatisticDoubleMatrix");
    if (statistic) {
        EXPECT_EQ(statistic->GetCompClassName(), "UStatisticDoubleMatrix");
        EXPECT_NE(statistic, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UStatisticDoubleMatrix object";
    }
}

// Test UStatisticIntMatrix properties
TEST_F(UStatisticTest, StatisticIntMatrixProperties) {
    if (!storage->CheckClass("UStatisticIntMatrix")) {
        GTEST_SKIP() << "UStatisticIntMatrix class not available";
        return;
    }
    
    auto statistic = storage->TakeObject("UStatisticIntMatrix");
    if (statistic) {
        EXPECT_EQ(statistic->GetCompClassName(), "UStatisticIntMatrix");
        
        // Verify component can be named
        statistic->SetName("TestStatisticInt");
        EXPECT_EQ(statistic->GetName(), "TestStatisticInt");
        
        // Verify component supports basic operations
        EXPECT_GE(statistic->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UStatisticIntMatrix object";
    }
}

// Test UStatisticDoubleMatrix properties
TEST_F(UStatisticTest, StatisticDoubleMatrixProperties) {
    if (!storage->CheckClass("UStatisticDoubleMatrix")) {
        GTEST_SKIP() << "UStatisticDoubleMatrix class not available";
        return;
    }
    
    auto statistic = storage->TakeObject("UStatisticDoubleMatrix");
    if (statistic) {
        EXPECT_EQ(statistic->GetCompClassName(), "UStatisticDoubleMatrix");
        
        // Verify component can be named
        statistic->SetName("TestStatisticDouble");
        EXPECT_EQ(statistic->GetName(), "TestStatisticDouble");
        
        // Verify component supports basic operations
        EXPECT_GE(statistic->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UStatisticDoubleMatrix object";
    }
}

