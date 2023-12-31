# Cmake script for ivp_compactbuilder

cmake_minimum_required(VERSION 3.16)
project(ivp_compactbuilder)
set(SRCDIR "${CMAKE_SOURCE_DIR}")
set(CMAKE_MODULE_PATH ${SRCDIR}/cmake)
set(OUTLIBNAME "ivp_compactbuilder")

include(${CMAKE_MODULE_PATH}/detect_platform.cmake)
include(${CMAKE_MODULE_PATH}/source_lib_base.cmake)

include_directories(${SRCDIR}/ivp/ivp_physics)
include_directories(${SRCDIR}/ivp/ivp_utility)
include_directories(${SRCDIR}/ivp/ivp_compact_builder)
include_directories(${SRCDIR}/ivp/ivp_collision)
include_directories(${SRCDIR}/ivp/ivp_controller)
include_directories(${SRCDIR}/ivp/ivp_surface_manager)

include_directories(${SRCDIR}/ivp/havana/havok)

#TODO: pretty sure the valve guy made a typo here, it's supposed to be HAVOK_MOPP
add_definitions(-D_LIB -DIVP_VERSION_SDK -DHAVOK_MOOP)

if( LINUXALL )
    target_compile_options(${OUTLIBNAME} PRIVATE -fpic -fno-semantic-interposition -fpermissive)
endif()

#target_sources(${OUTLIBNAME} PRIVATE 3dsimport_co.cxx)
#target_sources(${OUTLIBNAME} PRIVATE 3dsimport_load.cxx)
#target_sources(${OUTLIBNAME} PRIVATE 3dsimport_out.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_cutfac.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_cvdec3.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_drdec3.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_dsphdc.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_edght.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_initcb.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_insed3.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_insfac.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_insvr3.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_prime.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_ptpolg.cxx)
target_sources(${OUTLIBNAME} PRIVATE geompack_resedg.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_compact_ledge_gen.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_compact_modify.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_compact_recursive.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_convex_decompositor.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_halfspacesoup.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_i_fpoint_vhash.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_i_point_vhash.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_object_polygon_tetra.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_rot_inertia_solver.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_surbuild_halfspacesoup.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_surbuild_ledge_soup.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_surbuild_pointsoup.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_surbuild_polygon_convex.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_surbuild_polyhdrn_cncv.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_surbuild_q12.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_templates_intern.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivp_tetra_intrude.cxx)
target_sources(${OUTLIBNAME} PRIVATE ivv_cluster_min_hash.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_geom2.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_geom.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_global.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_io.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_mem.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_merge.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_poly2.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_poly.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_qset.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_stat.cxx)
target_sources(${OUTLIBNAME} PRIVATE qhull_user.cxx)
