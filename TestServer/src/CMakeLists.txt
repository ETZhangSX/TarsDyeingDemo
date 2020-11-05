cmake_minimum_required(VERSION 2.8)

project(TestApp-TestServer)

gen_server(TestApp TestServer)

#target_link_libraries(mysqlclient ssl crypto nghttp2-static)
