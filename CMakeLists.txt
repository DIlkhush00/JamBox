cmake_minimum_required(VERSION 3.1...3.29.5)

# -------------- Project --------------------------------------
project(JamBox VERSION 1.0.0 LANGUAGES CXX)


# ------------------- Include Required Libraries ---------------

include(FetchContent)

# ------------------- Include FTXUI Library --------------------

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


# ---------------------- CLI11 -----------------------------------


FetchContent_Declare(
  cli11_proj
  QUIET
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
  GIT_TAG v2.3.2
)

FetchContent_MakeAvailable(cli11_proj)


# ------------------------ SFML -----------------------------------

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
  GIT_SHALLOW ON
  EXCLUDE_FROM_ALL
  SYSTEM
)
  
FetchContent_MakeAvailable(SFML)

if(WIN32)
  add_custom_command(
    TARGET JamBox
    COMMENT "Copy OpenAL DLL"
    PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
    VERBATIM
  )
endif()

# ------------------------------------------------------------------

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_link_libraries( 
  ${CMAKE_PROJECT_NAME}
    PRIVATE ftxui::screen
    PRIVATE ftxui::dom
    PRIVATE ftxui::component
    PRIVATE CLI11::CLI11
    PRIVATE sfml-audio
)
