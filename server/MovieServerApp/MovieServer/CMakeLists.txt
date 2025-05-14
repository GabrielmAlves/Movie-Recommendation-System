set(CPR_DIR "C:/Users/Usuario/OneDrive/Documentos/vcpkg/installed/x64-windows/include/cpr")
include_directories("C:/Users/Usuario/OneDrive/Documentos/vcpkg/installed/x64-windows/include")
link_directories("C:/Users/Usuario/OneDrive/Documentos/vcpkg/installed/x64-windows/lib")
link_directories("C:/Users/Usuario/OneDrive/Documentos/vcpkg/installed/x64-windows/debug/bin")

project(MovieServer)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE "C:/Users/Usuario/OneDrive/Documentos/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

set(OPENSSL_ROOT_DIR "C:/Users/Usuario/OneDrive/Documentos/vcpkg/installed/x64-windows")
set(OPENSSL_USE_STATIC_LIBS TRUE)

add_definitions(-DCPPHTTPLIB_OPENSSL_SUPPORT)

find_package(OpenSSL REQUIRED)

add_executable(MovieServer 
    "MovieServer.cpp"  
    "src/routes/login.cpp" 
    "include/login.h" 
    "include/config.h" 
    "include/create_account.h" 
    "include/router.h" 
    "src/routes/router.cpp" 
    "include/reccomend.h" 
    "src/routes/recommend.cpp" 
    "include/user.h" 
    "src/routes/create_account.cpp"
    "include/utils.h"
 "include/home.h" "src/routes/home.cpp")


target_link_libraries(MovieServer OpenSSL::SSL OpenSSL::Crypto ws2_32 crypt32 user32)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MovieServer PROPERTY CXX_STANDARD 20)
endif()
