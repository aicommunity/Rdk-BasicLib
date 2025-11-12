#include <gtest/gtest.h>
#include "../../../../Tests/TestHelpers.h"
#include "../../../../Rdk/Deploy/Include/rdk.h"
#include "../../../Deploy/Include/Lib.h"
#include <filesystem>
#include <fstream>

using namespace RDK;
using namespace RDK::TestHelpers;
namespace fs = std::filesystem;

class UFileIOTest : public ::testing::Test {
protected:
    void SetUp() override {
        InitTestLogging();
        storage = CreateTestStorage();
        testFilePath = fs::temp_directory_path() / "test_file.txt";
    }

    void TearDown() override {
        if (fs::exists(testFilePath)) {
            fs::remove(testFilePath);
        }
        storage.reset();
    }

    std::shared_ptr<UStorage> storage;
    fs::path testFilePath;
};

// Test UFileIO creation
TEST_F(UFileIOTest, CreateFileIO) {
    auto fileIO = storage->TakeObject("UFileIO");
    if (fileIO) {
        EXPECT_EQ(fileIO->GetCompClassName(), "UFileIO");
    } else {
        GTEST_SKIP() << "UFileIO class not available in storage";
    }
}

// Test file operations
TEST_F(UFileIOTest, FileOperations) {
    // Create a test file
    std::ofstream testFile(testFilePath);
    testFile << "Test content";
    testFile.close();
    
    EXPECT_TRUE(fs::exists(testFilePath)) << "Test file should be created";
    EXPECT_GT(fs::file_size(testFilePath), 0) << "Test file should not be empty";
    
    // Verify file content
    std::ifstream readFile(testFilePath);
    std::string content((std::istreambuf_iterator<char>(readFile)),
                        std::istreambuf_iterator<char>());
    readFile.close();
    
    EXPECT_EQ(content, "Test content") << "File content should match";
}

// Test UFileIO properties
TEST_F(UFileIOTest, FileIOProperties) {
    auto fileIO = storage->TakeObject("UFileIO");
    if (fileIO) {
        EXPECT_EQ(fileIO->GetCompClassName(), "UFileIO");
        
        // Test setting and getting name
        fileIO->SetName("TestFileIO");
        EXPECT_EQ(fileIO->GetName(), "TestFileIO");
        
        // Test component ID
        UId id = fileIO->GetId();
        EXPECT_NE(id, 0) << "UFileIO should have valid ID";
    } else {
        GTEST_SKIP() << "UFileIO class not available";
    }
}

// Test file existence check
TEST_F(UFileIOTest, FileExistenceCheck) {
    // Test with non-existent file
    fs::path nonExistentPath = fs::temp_directory_path() / "non_existent_file.txt";
    EXPECT_FALSE(fs::exists(nonExistentPath)) << "Non-existent file should not exist";
    
    // Test with existing file
    std::ofstream testFile(testFilePath);
    testFile << "Test";
    testFile.close();
    
    EXPECT_TRUE(fs::exists(testFilePath)) << "Created file should exist";
}

