# Enable testing
enable_testing()

# Find GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Locate Threads library
find_package(Threads REQUIRED)

# Use glob to get all .cpp files in src directory (replace src/*.cpp if files are in a subdirectory)
file(GLOB SOURCE_FILES "*.cpp")


# Create executable for the GoogleTest unit tests
add_executable(unitTests tests/test_main.cpp ${SOURCE_FILES})
target_link_libraries(unitTests ${GTEST_LIBRARIES} Threads::Threads)

# Register the unit tests with CTest
add_test(NAME UnitTests COMMAND unitTests)
