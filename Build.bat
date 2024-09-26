SET CMAKE=C:\Kleber\RLexamples\vcpkg\downloads\tools\cmake-3.27.1-windows\cmake-3.27.1-windows-i386\bin\cmake.exe
SET VCPKG_TOOLCHAIN=vcpkg/scripts/buildsystems/vcpkg.cmake

mkdir BUILD
cd BUILD

%CMAKE% .. -DCMAKE_TOOLCHAIN_FILE=../%VCPKG_TOOLCHAIN%
%CMAKE% --build . 

pause