cmake_minimum_required(VERSION 3.16)
set (CMAKE_SYSTEM_VERSION 10)
project(StereoPlugin)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wno-unused-parameter")


#including CPM.cmake, a package manager:
#https://github.com/TheLartians/CPM.cmake
include(CMake/CPM.cmake)

#Compile commands, useful for some IDEs like VS-Code
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

#Minimum MacOS target, set globally
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.9" CACHE STRING "Minimum OS X deployment version" FORCE)

option(UniversalBinary "Build universal binary for mac" OFF)

if (UniversalBinary)
    set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE INTERNAL "")
endif()

#static linking in Windows
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

#Adds all the module sources so they appear correctly in the IDE
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)

#Fetching JUCE from git
#IF you want to instead point it to a local version, you can invoke CMake with
#-DCPM_JUCE_SOURCE="Path_To_JUCE"
CPMAddPackage(
        NAME JUCE
        GITHUB_REPOSITORY juce-framework/JUCE
        GIT_TAG origin/develop)

# Include KFR subdirectory
add_subdirectory(ThirdParty/kfr)

#include("CMake/FINDIPP.cmake")
#message(FATAL_ERROR  "kek ${IPP_LIBRARIES}")

set (BaseTargetName StereoPlugin)
juce_add_plugin("${BaseTargetName}"
        VERSION 0.0.1                               # Set this if the plugin version is different to the project version
        # ICON_BIG ...                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone
        # ICON_SMALL ...
        COMPANY_NAME "misha1sh"
        COMPANY_WEBSITE "https://github.com/misha1sh"
        COMPANY_EMAIL "mike.vologda@gmail.com"
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT FALSE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS FALSE
        COPY_PLUGIN_AFTER_BUILD TRUE
        PLUGIN_MANUFACTURER_CODE M1sh
        PLUGIN_CODE Stpf
        VST2_CATEGORY "kPlugCategEffect"
    #    VST3_CATEGORIES "Fx Stereo"
        AU_MAIN_TYPE "kAudioUnitType_Effect"
        AAX_CATEGORY "AAX_ePlugInCategory_Effect"

        FORMATS AU VST3 Standalone
        VST3_COPY_DIR "C:\\Program Files\\Common Files\\VST3"
        PRODUCT_NAME "Stereo Plugin")
juce_generate_juce_header("${BaseTargetName}")

file(GLOB_RECURSE SUB_SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "Source/*.cpp")
target_sources(${BaseTargetName} PRIVATE
        ${SUB_SOURCES})


target_compile_definitions(${BaseTargetName}
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_USE_WINDOWS_MEDIA_FORMAT=0
        JUCE_VST3_CAN_REPLACE_VST2=0)
target_link_libraries(${BaseTargetName} PRIVATE
        juce_audio_plugin_client
        juce_audio_processors
        juce_audio_utils
        juce_data_structures
        juce_dsp
        juce_graphics
        juce_gui_basics
        juce_gui_extra
        juce_opengl
        juce_recommended_config_flags
        juce_recommended_lto_flags
      #  juce_recommended_warning_flags
        kfr # Add header-only KFR to your executable or library, this sets include directories etc
        kfr_dft # Add KFR DFT to your executable or library, (cpp file will be built for this)
#        ${IPP_LIBRARIES}
        )


target_compile_options(${BaseTargetName} PRIVATE -Wno-unused-parameter)
