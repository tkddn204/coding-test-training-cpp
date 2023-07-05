cmake_minimum_required(VERSION 3.12.0)
project(coding-test-training-cpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(PROGRAM_NAME main)

if(NOT EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
  configure_file(${CMAKE_SOURCE_DIR}/template.cpp ${CMAKE_SOURCE_DIR}/main.cpp COPYONLY)
endif()

# main.cpp 빌드
add_executable(${PROGRAM_NAME} ${CMAKE_SOURCE_DIR}/main.cpp)

# main.cpp 파일을 생성하는 custom_target을 추가합니다.
add_custom_target(init
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/template.cpp ${CMAKE_SOURCE_DIR}/main.cpp
  COMMENT "Initializing main.cpp from template.cpp"
)

# main.cpp 파일이 존재하지 않을 때 init 명령을 실행합니다.
add_custom_command(OUTPUT main.cpp
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/template.cpp ${CMAKE_SOURCE_DIR}/main.cpp
  COMMENT "Initializing main.cpp from template.cpp"
)

# 컴파일 옵션
target_compile_options(${PROGRAM_NAME} PRIVATE
  -g
  -O2
)

# 실행 파일이 실행될 때 input.txt 파일을 build 디렉토리로 복사
add_custom_command(TARGET ${PROGRAM_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/input.txt ${CMAKE_BINARY_DIR}/input.txt
)

# 실행 파일이 실행될 때 output.txt 파일을 build 디렉토리에서 복사
add_custom_target(RUN
  COMMAND ${CMAKE_BINARY_DIR}/${PROGRAM_NAME}
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_BINARY_DIR}/output.txt ${CMAKE_SOURCE_DIR}/output.txt
  COMMENT "Running main and copying output.txt"
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  DEPENDS ${PROGRAM_NAME}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
