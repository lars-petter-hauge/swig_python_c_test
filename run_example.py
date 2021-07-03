try:
    from example import add
except ImportError: # Example is installed under example namespace in skbuild
    from example.example import add

print(example.add(2,3))
