set(TEST_SOURCES
        mesTests.cpp
        ${PROJECT_SOURCE_DIR}/Livre.cpp
        ${PROJECT_SOURCE_DIR}/Emprunteur.cpp
        ${PROJECT_SOURCE_DIR}/ContratException.cpp
        ${PROJECT_SOURCE_DIR}/Bibliotheque.cpp
        ${PROJECT_SOURCE_DIR}/Livre.h
        ${PROJECT_SOURCE_DIR}/Emprunteur.h
        ${PROJECT_SOURCE_DIR}/ContratException.h
        ${PROJECT_SOURCE_DIR}/Bibliotheque.h
)

add_executable(
        tests_bibliotech
        ${TEST_SOURCES}
)

target_include_directories(tests_bibliotech PRIVATE ${PROJECT_SOURCE_DIR})

target_link_libraries(
        tests_bibliotech
        gtest_main
        gtest
)

include(GoogleTest)
gtest_discover_tests(tests_bibliotech)