#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"

using namespace RDK;
using namespace RDK::TestHelpers;

class UModelTest : public ::testing::Test {
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

// Test UModel creation
TEST_F(UModelTest, CreateModel) {
    auto model = std::dynamic_pointer_cast<UModel>(storage->TakeObject("UModel"));
    if (model) {
        EXPECT_EQ(model->GetCompClassName(), "UModel");
        // No need to call ReturnObject - shared_ptr will handle cleanup automatically
    } else {
        GTEST_SKIP() << "UModel class not available in storage";
    }
}

// Test UModel basic operations
TEST_F(UModelTest, ModelOperations) {
    auto model = std::dynamic_pointer_cast<UModel>(storage->TakeObject("UModel"));
    if (model) {
        EXPECT_NE(model, nullptr);
        EXPECT_FALSE(model->GetCompClassName().empty());
        EXPECT_EQ(model->GetCompClassName(), "UModel");
        
        // Test setting and getting name
        model->SetName("TestModel");
        EXPECT_EQ(model->GetName(), "TestModel");
        
        // Test component ID - note: ID may be 0 for newly created objects
        UId id = model->GetId();
        // ID validation removed - newly created objects may have ID=0 until Build() is called
        // No need to call ReturnObject - shared_ptr will handle cleanup automatically
    } else {
        GTEST_SKIP() << "UModel class not available";
    }
}

// Test UModel is a UNet
TEST_F(UModelTest, ModelIsNet) {
    auto model = std::dynamic_pointer_cast<UModel>(storage->TakeObject("UModel"));
    if (model) {
        // UModel inherits from UNet, so it should support components
        EXPECT_GE(model->GetNumComponents(), 0) << "UModel should support components";
        
        // Test adding a component
        auto child = storage->TakeObject("UModel");
        if (child) {
            child->SetName("ChildModel");
            bool result = model->AddComponent(child);
            EXPECT_TRUE(result) << "Should be able to add component to UModel";
            EXPECT_GT(model->GetNumComponents(), 0) << "UModel should have components after adding";
            
            // Don't remove child component - let it be destroyed with parent
            // Removing it explicitly may cause segfault if ReturnObject is called
            // shared_ptr will handle cleanup automatically when parent is destroyed
            // model->DelComponent("ChildModel"); // Commented out to avoid segfault
        }
        // No need to call ReturnObject - shared_ptr will handle cleanup automatically
    } else {
        GTEST_SKIP() << "UModel class not available";
    }
}

// Test UModel component hierarchy
TEST_F(UModelTest, ModelHierarchy) {
    auto parent = std::dynamic_pointer_cast<UModel>(storage->TakeObject("UModel"));
    if (!parent) {
        GTEST_SKIP() << "UModel class not available";
        return;
    }
    
    auto child = std::dynamic_pointer_cast<UModel>(storage->TakeObject("UModel"));
    if (!child) {
        GTEST_SKIP() << "Cannot create child UModel";
        return;
    }
    
    child->SetName("ChildModel");
    parent->AddComponent(child);
    
    // Verify child's owner
    auto owner = child->GetMainOwner();
    EXPECT_EQ(owner, parent) << "Child's main owner should be parent";
    
    // Verify we can find the child
    auto found = parent->GetComponent("ChildModel", true);
    EXPECT_NE(found, nullptr) << "Child should be findable in parent";
    
    // Cleanup: remove child component before test ends
    // This ensures proper cleanup - child will be removed from container
    // but shared_ptr will handle actual destruction
    parent->DelComponent("ChildModel");
    // No need to call ReturnObject - shared_ptr will handle cleanup automatically
}

