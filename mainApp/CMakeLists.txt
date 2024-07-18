find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

set(SOURCE_APP_FILES
        App.h
        App.cpp
        MainFrame.h
        MainFrame.cpp
        ../customWidgets/headerFiles/ActivityInput.h
        ../customWidgets/cppFiles/ActivityInput.cpp
        ../customWidgets/headerFiles/HourMinutePickerCtrl.h
        ../customWidgets/cppFiles/HourMinutePickerCtrl.cpp
)

add_executable(runApp ${SOURCE_APP_FILES})
target_link_libraries(runApp ${CMAKE_PROJECT_NAME}_lib ${wxWidgets_LIBRARIES})
target_include_directories(runApp PRIVATE ${wxWidgets_INCLUDE_DIRS})