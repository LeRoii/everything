project(testcv)
find_package(OpenCV REQUIRED)
add_executable(cm test.cpp)
target_link_libraries(cm ${OpenCV_LIBS})