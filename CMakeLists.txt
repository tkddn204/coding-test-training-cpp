cmake_minimum_required(VERSION 3.12.0)
project(coding-test-training-cpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(PROGRAM_NAME main)

# main.cpp가 존재하지 않으면 생성
if(NOT EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
  configure_file(${CMAKE_SOURCE_DIR}/template.cpp ${CMAKE_SOURCE_DIR}/main.cpp COPYONLY)
else()
  # main.cpp 빌드
  add_executable(${PROGRAM_NAME} ${CMAKE_SOURCE_DIR}/main.cpp)

  # 컴파일 옵션
  target_compile_options(${PROGRAM_NAME} PRIVATE
    -g
    -O2
  )
endif()
  
# main.cpp 파일을 생성하는 custom_target을 추가합니다.
add_custom_target(init
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/template.cpp ${CMAKE_SOURCE_DIR}/main.cpp
  COMMENT "Initializing main.cpp from template.cpp"
)

# 실행 파일이 실행될 때
# output.txt 파일 내용을 초기화
add_custom_command(TARGET ${PROGRAM_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E echo "" > ${CMAKE_SOURCE_DIR}/output.txt
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
