cmake_minimum_required(VERSION 3.10.2)
project(challenge)

set(GLOB HELLO_INC "include/*.h")

include_directories(include)
add_library(linkedlist SHARED src/linkedlist.c)
add_library(stack SHARED src/stack.c)
add_library(queue SHARED src/queue.c)

set_target_properties(linkedlist PROPERTIES PUBLIC_HEADER "include/linkedlist.h")
set_target_properties(stack PROPERTIES PUBLIC_HEADER "include/stack.h")
set_target_properties(queue PROPERTIES PUBLIC_HEADER "include/queue.h")

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} linkedlist stack queue)

install(TARGETS linkedlist 
	LIBRARY DESTINATION lib 
	PUBLIC_HEADER DESTINATION include)

install(TARGETS stack 
	LIBRARY DESTINATION lib
	PUBLIC_HEADER DESTINATION include)

install(TARGETS queue 
	LIBRARY DESTINATION lib
	PUBLIC_HEADER DESTINATION include)

install(TARGETS challenge 
	RUNTIME DESTINATION bin)

