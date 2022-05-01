#   Parasite::Configuration
##  Table of Contents
1.  [Introduction](#introduction)
2.  [Building](#building)
3.  [Build Options](#build-options)
4.  [License](#license)

##  Introduction
[Parasite::Configuration][Parasite::Configuration] is a part of the [Parasite Engine][Parasite Engine] that encapsulates
several conditional compilation flags, language standard, compiler, platform identification, convenience macros
and some other utility macros. This module provides all the necessary framework that is required to write and build
platform, compiler and language standard independent code.

##  Building

1. Cloning the repository

This module resides in the github repository [https://github.com/ParasiteEngine/Parasite.Configuration][Parasite::Configuration].
```sh
git clone https://github.com/ParasiteEngine/Parasite.Configuration.git
```

2. Configuring the Parasite

[Parasite::Configuration] utilizes CMake to configure and build the module. The available build options are explained in the [following section](#build-options)
```sh
##  Configuring the CMake project
mkdir Build && cd Build
cmake -S ../ -G <YOUR_GENERATOR>

##  Building the CMake project
cmake --build . --target all
```

##  Build Options
|                     Build Options                     |                       Description                     |
| ----------------------------------------------------- | ----------------------------------------------------- |
| PARASITE_CONFIGURATION_DISABLE_PEDANTIC_ERRORS        | Disables pedantic compilation flags while compiling   |
| PARASITE_CONFIGURATION_DISABLE_WARNINGS_AS_ERRORS     | Disables -Werror or similar flags while compiling     |
| PARASITE_CONFIGURATION_BUILD_DOCUMENATION             | (**Required Doxygen**) Builds the documentation       |

##  License
[Parasite Engine][Parasite Engine] and [Parasite::Configuration][Parasite::Configuration] are licensed under
[BSD 3-Clause License][BSD 3-Cluase License]. For more information, refer [LICENSE][LICENSE].

[Parasite Engine]:          https://github.com/ParasiteEngine
[Parasite::Configuration]:  https://github.com/ParasiteEngine/Parasite.Configuration
[BSD 3-Cluase License]:     https://opensource.org/licenses/BSD-3-Clause
[LICENSE]:                  https://github.com/ParasiteEngine/Parasite.Configuration/blob/master/LICENSE
