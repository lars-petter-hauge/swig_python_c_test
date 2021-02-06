from skbuild import setup
from setuptools import find_packages

setup(
    name="example",
    packages=["example"],# find_packages(include=["example*"]),
    #package_dir={"": "src"},
    cmake_args=["-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON"],
    cmake_with_sdist=True,
)