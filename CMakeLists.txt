cmake_minimum_required(VERSION 3.9)
project(dhont C)

set(CMAKE_C_STANDARD 11)

add_executable(dhont main.c data.c data.h dhont.c dhont.h)