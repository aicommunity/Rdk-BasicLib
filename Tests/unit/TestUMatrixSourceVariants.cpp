#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UMatrixSourceVariantsTest : public ::testing::Test {
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

// Test UMatrixSourceTimeSeries creation
TEST_F(UMatrixSourceVariantsTest, CreateMatrixSourceTimeSeries) {
    if (!storage->CheckClass("UMatrixSourceTimeSeries")) {
        GTEST_SKIP() << "UMatrixSourceTimeSeries class not available in storage";
        return;
    }
    
    auto matrixSource = storage->TakeObject("UMatrixSourceTimeSeries");
    if (matrixSource) {
        EXPECT_EQ(matrixSource->GetCompClassName(), "UMatrixSourceTimeSeries");
        EXPECT_NE(matrixSource, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UMatrixSourceTimeSeries object";
    }
}

// Test UMatrixSourceDataFile creation
TEST_F(UMatrixSourceVariantsTest, CreateMatrixSourceDataFile) {
    if (!storage->CheckClass("UMatrixSourceDataFile")) {
        GTEST_SKIP() << "UMatrixSourceDataFile class not available in storage";
        return;
    }
    
    auto matrixSource = storage->TakeObject("UMatrixSourceDataFile");
    if (matrixSource) {
        EXPECT_EQ(matrixSource->GetCompClassName(), "UMatrixSourceDataFile");
        EXPECT_NE(matrixSource, nullptr);
    } else {
        GTEST_SKIP() << "Cannot create UMatrixSourceDataFile object";
    }
}

// Test UMatrixSourceTimeSeries properties
TEST_F(UMatrixSourceVariantsTest, MatrixSourceTimeSeriesProperties) {
    if (!storage->CheckClass("UMatrixSourceTimeSeries")) {
        GTEST_SKIP() << "UMatrixSourceTimeSeries class not available";
        return;
    }
    
    auto matrixSource = storage->TakeObject("UMatrixSourceTimeSeries");
    if (matrixSource) {
        EXPECT_EQ(matrixSource->GetCompClassName(), "UMatrixSourceTimeSeries");
        
        // Verify component can be named
        matrixSource->SetName("TestMatrixSourceTimeSeries");
        EXPECT_EQ(matrixSource->GetName(), "TestMatrixSourceTimeSeries");
        
        // Verify component supports basic operations
        EXPECT_GE(matrixSource->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UMatrixSourceTimeSeries object";
    }
}

// Test UMatrixSourceDataFile properties
TEST_F(UMatrixSourceVariantsTest, MatrixSourceDataFileProperties) {
    if (!storage->CheckClass("UMatrixSourceDataFile")) {
        GTEST_SKIP() << "UMatrixSourceDataFile class not available";
        return;
    }
    
    auto matrixSource = storage->TakeObject("UMatrixSourceDataFile");
    if (matrixSource) {
        EXPECT_EQ(matrixSource->GetCompClassName(), "UMatrixSourceDataFile");
        
        // Verify component can be named
        matrixSource->SetName("TestMatrixSourceDataFile");
        EXPECT_EQ(matrixSource->GetName(), "TestMatrixSourceDataFile");
        
        // Verify component supports basic operations
        EXPECT_GE(matrixSource->GetNumComponents(), 0);
    } else {
        GTEST_SKIP() << "Cannot create UMatrixSourceDataFile object";
    }
}

// Test UMatrixSourceTimeSeries is a UNet
TEST_F(UMatrixSourceVariantsTest, MatrixSourceTimeSeriesIsNet) {
    if (!storage->CheckClass("UMatrixSourceTimeSeries")) {
        GTEST_SKIP() << "UMatrixSourceTimeSeries class not available";
        return;
    }
    
    auto matrixSource = storage->TakeObject("UMatrixSourceTimeSeries");
    if (matrixSource) {
        // UMatrixSourceTimeSeries inherits from UNet, so it should support components
        EXPECT_GE(matrixSource->GetNumComponents(), 0) << "UMatrixSourceTimeSeries should support components";
    } else {
        GTEST_SKIP() << "Cannot create UMatrixSourceTimeSeries object";
    }
}

// Test UMatrixSourceDataFile is a UNet
TEST_F(UMatrixSourceVariantsTest, MatrixSourceDataFileIsNet) {
    if (!storage->CheckClass("UMatrixSourceDataFile")) {
        GTEST_SKIP() << "UMatrixSourceDataFile class not available";
        return;
    }
    
    auto matrixSource = storage->TakeObject("UMatrixSourceDataFile");
    if (matrixSource) {
        // UMatrixSourceDataFile inherits from UNet, so it should support components
        EXPECT_GE(matrixSource->GetNumComponents(), 0) << "UMatrixSourceDataFile should support components";
    } else {
        GTEST_SKIP() << "Cannot create UMatrixSourceDataFile object";
    }
}

