cmake_minimum_required(VERSION 3.29.5)

# -------------- Project -----------------------------
project(JamBox)


# ---------- Include FTXUI Library --------------------

include(FetchContent)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


message("Boost is going here...")
# ------------ Boost Program Options -------------------
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.86.0
  GIT_PROGRESS ON
  GIT_SHALLOW ON
  OVERRIDE_FIND_PACKAGE TRUE # needed to find correct Boost
  EXCLUDE_FROM_ALL # compile only what you need
)

FetchContent_MakeAvailable(Boost)

find_package(
  Boost
  1.86.0
  REQUIRED
  COMPONENTS program_options
)

# ------------------------------------------------------

message("Done...")

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_link_libraries( 
  ${CMAKE_PROJECT_NAME}
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
    PRIVATE Boost::program_options
)
