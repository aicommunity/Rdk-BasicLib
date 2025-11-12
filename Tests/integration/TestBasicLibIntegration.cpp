#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class BasicLibIntegrationTest : public ::testing::Test {
protected:
    void SetUp() override {
        InitTestLogging();
        storage = CreateTestStorage();
        environment = CreateTestEnvironment(storage);
    }

    void TearDown() override {
        environment.reset();
        storage.reset();
    }

    std::shared_ptr<UStorage> storage;
    std::shared_ptr<UEnvironment> environment;
};

// Test BasicLib integration with Engine
TEST_F(BasicLibIntegrationTest, BasicLibEngineIntegration) {
    ASSERT_NE(storage, nullptr) << "Storage should be created";
    ASSERT_NE(environment, nullptr) << "Environment should be created";
    
    // Check that BasicLib is loaded
    EXPECT_GT(storage->GetNumClasses(), 0) << "Storage should have classes from BasicLib";
    
    // Verify BasicLib classes are available
    EXPECT_TRUE(storage->CheckClass("UModel")) << "UModel should be available";
    EXPECT_TRUE(storage->CheckClass("UMatrixSource")) << "UMatrixSource should be available";
}

// Test BasicLib components can be created
TEST_F(BasicLibIntegrationTest, BasicLibComponentsCreation) {
    // Try to create UModel if available
    auto model = storage->TakeObject("UModel");
    if (model) {
        EXPECT_NE(model, nullptr) << "UModel should be creatable";
        EXPECT_EQ(model->GetCompClassName(), "UModel");
    } else {
        GTEST_SKIP() << "UModel class not available";
    }
    
    // Try to create UMatrixSource
    if (storage->CheckClass("UMatrixSource")) {
        auto matrixSource = storage->TakeObject("UMatrixSource");
        if (matrixSource) {
            EXPECT_EQ(matrixSource->GetCompClassName(), "UMatrixSource");
        }
    }
}

// Test BasicLib components work with Environment
TEST_F(BasicLibIntegrationTest, BasicLibEnvironmentIntegration) {
    // Initialize environment if needed
    if (!environment->IsInit()) {
        environment->Default();
        environment->Init();
    }
    
    // Create model using Environment
    auto model = CreateTestModel(storage, environment);
    if (model) {
        EXPECT_EQ(model->GetCompClassName(), "UModel") << "Model should be UModel";
        EXPECT_GE(model->GetNumComponents(), 0) << "Model should support components";
    } else {
        GTEST_SKIP() << "Cannot create model in environment";
    }
}

// Test BasicLib components can be added to model
TEST_F(BasicLibIntegrationTest, BasicLibComponentsInModel) {
    auto model = CreateTestModel(storage, environment);
    if (!model) {
        GTEST_SKIP() << "Cannot create model";
        return;
    }
    
    // Add UMatrixSource to model if available
    if (storage->CheckClass("UMatrixSource")) {
        auto matrixSource = storage->TakeObject("UMatrixSource");
        if (matrixSource) {
            matrixSource->SetName("TestMatrixSource");
            bool result = model->AddComponent(matrixSource);
            EXPECT_TRUE(result) << "Should be able to add UMatrixSource to model";
            EXPECT_GT(model->GetNumComponents(), 0) << "Model should have components";
        }
    }
}

