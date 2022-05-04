# Changelog
All notable changes to this project will be documented in this file.

## [Unreleased]

### Added
-   `CMakeLists.txt` for configuring and generating build system specific configurations
-   `CMakeSources.txt` to isolate the library header and source configuration from the rest of `CMakeLists.txt`
-   `Parasite/Configuration.hh` to include all the header files that are public and part of **Parasite::Configuration** library
-   `Parasite/Configuration/Version.hh.in` that will be configured by *CMake* to provide version info the library
-   `CHANGELOG.md` to keep track of changes made to the project