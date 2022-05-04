##  Parasite::Configuration
##  Copyright 2022 DeathBlizzard
##  
##  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
##  conditions are met:
##  
##  1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following
##      disclaimer.
##  
##  2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
##      disclaimer in the documentation and/or other materials provided with the distribution.
##  
##  3.  Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products
##      derived from this software without specific prior written permission.
##  
##  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
##  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
##  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
##  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
##  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
##  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
##  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

##  Parasite Engine CMake Requirements
##  Parasite Engine uses modern cmake configuration and feature set and therefore requires atleast version 3.11.0 for proper
##  configuration of the project
cmake_minimum_required(VERSION 3.11.0 FATAL_ERROR)

##  Global Variables
##  The following are the set of global variables that are requierd throughout this cmake configuration and all its modules
set(PARASITE_CONFIGURATION_ROOT_DIRECTORY       ${CMAKE_CURRENT_SOURCE_DIR})
set(PARASITE_CONFIGURATION_BUILD_DIRECTORY      ${CMAKE_CURRENT_BINARY_DIR})
set(PARASITE_CONFIGURATION_MODULES_DIRECTORY    ${PARASITE_CONFIGURATION_ROOT_DIRECTORY}/CMake)
set(PARASITE_CONFIGURATION_INCLUDE_DIRECTORY    ${PARASITE_CONFIGURATION_ROOT_DIRECTORY}/Include)

##  Parasite::Configutation Module Version
##  Parasite::Configutation Module  follows "Semantic Versioning" scheme inorder to achieve easily incrementable and maintainable
##  version of the project. For more information, visit https://semver.org 
if(NOT DEFINED PARASITE_CONFIGURATION_MODULE_VERSION)
    set(PARASITE_CONFIGURATION_VERSION_MAJOR    0)
    set(PARASITE_CONFIGURATION_VERSION_MINOR    2)
    set(PARASITE_CONFIGURATION_VERSION_PATCH    0)
    set(
        PARASITE_CONFIGURATION_MODULE_VERSION
        ${PARASITE_CONFIGURATION_VERSION_MAJOR}.${PARASITE_CONFIGURATION_VERSION_MINOR}.${PARASITE_CONFIGURATION_VERSION_PATCH}
    )
endif()

##  Parasite::Configuration CMake Project
project(
    ParasiteConfiguration
    DESCRIPTION "Encapsulates platform, compiler, language standard, CMake modules and other prerequisites for Parasite Engine"
    VERSION ${PARASITE_CONFIGURATION_MODULE_VERSION}
    LANGUAGES CXX
)

##  Parasite::Configuration Module
add_library(ParasiteConfiguration INTERFACE)
add_library(Parasite::Configuration ALIAS ParasiteConfiguration)

include(CMakeSources.txt)

message(STATUS "Parasite::Configuration Version                 : v${PARASITE_CONFIGURATION_MODULE_VERSION}")       
message(STATUS "Parasite::Configuration Include Directory       : ${PARASITE_CONFIGURATION_INCLUDE_DIRECTORY}")