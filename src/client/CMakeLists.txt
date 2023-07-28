#定义一个SRC_LIST变量，包含该目录下所有源文件
aux_source_directory(. SRC_LIST)

#指定可生成文件
add_executable(ChatClient ${SRC_LIST})
#指定可执行文件链接时所需的库文件
target_link_libraries(ChatClient  pthread)