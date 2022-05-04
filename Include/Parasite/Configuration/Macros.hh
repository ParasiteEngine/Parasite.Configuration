//  Parasite::Configuration
//  Copyright 2022 DeathBlizzard
//  
//  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
//  conditions are met:
//  
//  1.  Redistributions of source code must retain the above copyright notice, this list of conditions and the following
//      disclaimer.
//  
//  2.  Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
//      disclaimer in the documentation and/or other materials provided with the distribution.
//  
//  3.  Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products
//      derived from this software without specific prior written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
//  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
//  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
//  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#ifndef PARASITE_CONFIGURATION__MACROS_HH_
#define PARASITE_CONFIGURATION__MACROS_HH_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @file       Parasite/Configuration/Macros.hh
/// @brief      Utility Macros and definitions
/// @details    This header contains macro definitions and constant definitions that come in handy while configuring
///             Parasite modules
/// @note       This file is not supposed to be directly included in the client source. In order to include this header file,
///             please include @c Parasite/Configuration.hh
/// @addtogroup parasite_configuration
/// @{
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Convinience macro to represent boolean @c TRUE
/// @details    This macro is widely used in defining conditional compilation flags to denote that a particular feature or
///             condition is satisfied and is available or evaluates to @c TRUE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_ENABLE  1

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Convinience macro to represent boolean @c FALSE
/// @details    This macro is widely used in defining conditional compilation flags to denote that a particular feature or
///             condition is not satisfied and is not available or evaluates to @c FALSE
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_DISABLE 0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Converts a parameter @p __ARGUMENT__ into a string.
/// @details    This macro makes use of the `#` operator to convert the given argument @p _ARGUMENT_ into a string
/// @param[in]  _ARGUMENT_  The argument that has to be converted into a string
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_STRINGIZE(_ARGUMENT_) #_ARGUMENT_

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief      Converts a parameter @p __ARGUMENT__ into a string after macro replacement.
/// @details    This macro makes use of the `#` operator to convert the given argument @p _ARGUMENT_. The argument is
///             converted into string after macro replacment
/// @param[in]  _ARGUMENT_  The argument that has to be converted into a string
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define PARASITE_STRINGIFY(_ARGUMENT_) PARASITE_STRINGIZE (_ARGUMENT_)

/// @}

#endif