g++ -g -fPIC -shared wrapper_example.c example.c -o example.so $(python3-config --cflags --ldflags)
