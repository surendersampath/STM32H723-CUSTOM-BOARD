# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

# Define HSE value for custom board (25 MHz). Replace if your board uses a different value.
zephyr_compile_definitions(HSE_VALUE=25000000)

target_sources(app PRIVATE src/main.c)
