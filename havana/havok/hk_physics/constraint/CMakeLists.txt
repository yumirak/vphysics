# Cmake script for havana_constraints

cmake_minimum_required(VERSION 3.16)
project(havana_constraints)
set(SRCDIR "${CMAKE_SOURCE_DIR}")
set(CMAKE_MODULE_PATH ${SRCDIR}/cmake)
set(OUTLIBNAME "havana_constraints")

include(${CMAKE_MODULE_PATH}/detect_platform.cmake)
include(${CMAKE_MODULE_PATH}/source_lib_base.cmake)

# This must be included before havana folder. They share a subfolder "hk_physics", but the ivp is what we want most of the time.
include_directories(${SRCDIR}/ivp/ivp_physics)
include_directories(${SRCDIR}/ivp/havana/havok)
include_directories(${SRCDIR}/ivp)
include_directories(${SRCDIR}/ivp/ivp_utility)
include_directories(${SRCDIR}/ivp/ivp_controller)

add_definitions(-D_LIB -DHAVANA_CONSTRAINTS -DIVP_VERSION_SDK)

if( LINUXALL )
    target_compile_options(${OUTLIBNAME} PRIVATE -fpic -fno-semantic-interposition -fno-strict-aliasing)
endif()

target_sources(${OUTLIBNAME} PRIVATE constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE ball_socket/ball_socket_constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE limited_ball_socket/limited_ball_socket_constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE ragdoll/ragdoll_constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE ragdoll/ragdoll_constraint_bp_builder.cpp)
target_sources(${OUTLIBNAME} PRIVATE hinge/hinge_constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE hinge/hinge_bp_builder.cpp)
target_sources(${OUTLIBNAME} PRIVATE breakable_constraint/breakable_constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE fixed/fixed_constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE prismatic/prismatic_constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE pulley/pulley_constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE stiff_spring/stiff_spring_constraint.cpp)
target_sources(${OUTLIBNAME} PRIVATE local_constraint_system/local_constraint_system.cpp)
target_sources(${OUTLIBNAME} PRIVATE ../core/rigid_body_core.cpp)
target_sources(${OUTLIBNAME} PRIVATE ../effector/rigid_body_binary_effector.cpp)
