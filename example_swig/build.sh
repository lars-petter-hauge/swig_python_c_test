# Use swig to create bindings:
# Creates example_wrap.c for use in compiling and example.py
# that handles importing the .so file (prefixed with _)
swig -python example.i

# Compile and link (note the prefixed underscore on the output file)
g++ -g -fPIC -shared example.c example_wrap.c -o _example.so $(python3-config --cflags --ldflags)
