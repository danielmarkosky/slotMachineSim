from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout

class SlotMachineSimConan(ConanFile):
    name = "slotmachinesim"
    version = "1"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    requires = ()

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()