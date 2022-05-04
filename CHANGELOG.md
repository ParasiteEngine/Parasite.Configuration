# Changelog
All notable changes to this project will be documented in this file.

## [Unreleased]

## [0.2.1] - 2022-05-04
### Modified
-   `CMakeSources.txt` has been modified to include `Parasite/Configuration/Macros.hh` and `Parasite/Configuration/Platform.hh`

## [0.2.0] - 2022-05-04
### Added
-   `Parasite/Configuration/Macros.hh` to provide some useful utility macros
-   `Parasite/Configuration/Platform.hh` to provide Platform detection, identification and declaration of conditional
    compilation flags

### Modified
-   `CMakeLists.txt` to reflect version changes

## [0.1.0] - 2022-05-01
### Added
-   `CMakeLists.txt` for configuring and generating build system specific configurations
-   `CMakeSources.txt` to isolate the library header and source configuration from the rest of `CMakeLists.txt`
-   `Parasite/Configuration.hh` to include all the header files that are public and part of **Parasite::Configuration** library
-   `Parasite/Configuration/Version.hh.in` that will be configured by *CMake* to provide version info the library
-   `CHANGELOG.md` to keep track of changes made to the project