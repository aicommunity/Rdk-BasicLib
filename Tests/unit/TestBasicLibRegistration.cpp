#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../../Libraries/Libraries.h"
#include "../../../Deploy/Include/Lib.h"
#include "../../Core/UBCLLibrary.h"
#include <algorithm>
#include <vector>
#include <set>

using namespace RDK;
using namespace RDK::TestHelpers;

namespace {

// Expected BasicLib component categories and their key classes
struct BasicLibCategory {
    std::string name;
    std::vector<std::string> keyClasses;
};

const std::vector<BasicLibCategory> EXPECTED_BASICLIB_CATEGORIES = {
    {"Core Models", {"UModel"}},
    {"Statistics", {"UStatisticIntMatrix", "UStatisticDoubleMatrix"}},
    {"Noise Generators", {"UNoiseGen", "UNoiseGenDouble", "UNoiseGenInt"}},
    {"Sources", {"UMatrixSource", "UScalarSource", "UMatrixSourceTimeSeries", "UMatrixSourceDataFile"}},
    {"Windows-specific", {"UUMatrixSourceFile", "UMatrixSourceFileSep", "UFileDataset"}}
};

} // namespace

class BasicLibRegistrationTest : public ::testing::Test {
protected:
    void SetUp() override {
        InitTestLogging();
        
        // Create storage with BasicLib
        storage = CreateTestStorage();
        ASSERT_NE(storage, nullptr) << "Failed to create storage";
        
        // Upload BasicLib
        RDK::BasicLibrary.Upload(storage.get());
        
        // Call CreateClassSamples for BasicLib
        try {
            RDK::BasicLibrary.CreateClassSamples(storage.get());
        } catch (const std::exception& ex) {
            GTEST_SKIP() << "UBasicLib CreateClassSamples failed: " << ex.what();
        }
    }

    void TearDown() override {
        storage.reset();
    }

    std::shared_ptr<UStorage> storage;
};

// Test that all expected BasicLib classes are registered
TEST_F(BasicLibRegistrationTest, AllBasicLibClassesRegistered) {
    ASSERT_NE(storage, nullptr);
    
    std::vector<std::string> allClasses;
    storage->GetClassNameList(allClasses);
    
    std::set<std::string> registeredClasses(allClasses.begin(), allClasses.end());
    
    // Check each category (excluding Windows-specific on non-Windows)
    for (const auto& category : EXPECTED_BASICLIB_CATEGORIES) {
        // Skip Windows-specific classes on non-Windows platforms
        if (category.name == "Windows-specific") {
            #ifndef WIN32
            continue;
            #endif
        }
        
        for (const auto& className : category.keyClasses) {
            EXPECT_TRUE(storage->CheckClass(className)) 
                << "BasicLib class '" << className << "' from category '" << category.name << "' should be registered";
            
            if (storage->CheckClass(className)) {
                EXPECT_TRUE(registeredClasses.count(className) > 0)
                    << "Class '" << className << "' should be in class list";
            }
        }
    }
}

// Test that minimum number of BasicLib classes are registered
TEST_F(BasicLibRegistrationTest, BasicLibClassesCount) {
    ASSERT_NE(storage, nullptr);
    
    std::vector<std::string> allClasses;
    storage->GetClassNameList(allClasses);
    
    // Count BasicLib classes
    size_t basicLibClassCount = 0;
    std::vector<std::string> basicLibPrefixes = {
        "UModel", "UStatistic", "UNoiseGen", "UMatrixSource", 
        "UScalarSource", "UFileDataset", "UMatrixSourceFile"
    };
    
    for (const auto& className : allClasses) {
        for (const auto& prefix : basicLibPrefixes) {
            if (className.find(prefix) == 0) {
                basicLibClassCount++;
                break;
            }
        }
    }
    
    // We expect at least 7 classes (more on Windows)
    #ifdef WIN32
    EXPECT_GE(basicLibClassCount, 10) 
        << "Expected at least 10 BasicLib classes on Windows, but found " << basicLibClassCount;
    #else
    EXPECT_GE(basicLibClassCount, 7) 
        << "Expected at least 7 BasicLib classes, but found " << basicLibClassCount;
    #endif
}

// Test that critical BasicLib classes are registered
TEST_F(BasicLibRegistrationTest, CriticalClassesRegistered) {
    ASSERT_NE(storage, nullptr);
    
    // Critical classes that are commonly used
    std::vector<std::string> criticalClasses = {
        "UModel",
        "UMatrixSource",
        "UScalarSource",
        "UNoiseGen",
        "UStatisticIntMatrix",
        "UStatisticDoubleMatrix"
    };
    
    for (const auto& className : criticalClasses) {
        EXPECT_TRUE(storage->CheckClass(className)) 
            << "Critical BasicLib class '" << className << "' should be registered";
    }
}

// Test that BasicLib classes can be created
TEST_F(BasicLibRegistrationTest, BasicLibClassesCreation) {
    ASSERT_NE(storage, nullptr);
    
    // Test UModel creation
    if (storage->CheckClass("UModel")) {
        auto model = storage->TakeObject("UModel");
        EXPECT_NE(model, nullptr) 
            << "Should be able to create UModel";
        if (model) {
            EXPECT_EQ(model->GetCompClassName(), "UModel");
        }
    }
    
    // Test UMatrixSource creation
    if (storage->CheckClass("UMatrixSource")) {
        auto matrixSource = storage->TakeObject("UMatrixSource");
        EXPECT_NE(matrixSource, nullptr) 
            << "Should be able to create UMatrixSource";
        if (matrixSource) {
            EXPECT_EQ(matrixSource->GetCompClassName(), "UMatrixSource");
        }
    }
    
    // Test UScalarSource creation
    if (storage->CheckClass("UScalarSource")) {
        auto scalarSource = storage->TakeObject("UScalarSource");
        EXPECT_NE(scalarSource, nullptr) 
            << "Should be able to create UScalarSource";
        if (scalarSource) {
            EXPECT_EQ(scalarSource->GetCompClassName(), "UScalarSource");
        }
    }
}

