from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout, CMakeToolchain, CMakeDeps

class GameConan(ConanFile):
    name = "putt-it"
    settings = "os", "arch", "compiler", "build_type"

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generator="Ninja"
        tc.generate()

        deps = CMakeDeps(self)
        deps.generate()

    def layout(self):
        cmake_layout(self)

    def requirements(self):
        self.requires("sdl/2.32.10")
        self.requires("sdl_image/2.8.8")
        self.requires("gtest/1.17.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()