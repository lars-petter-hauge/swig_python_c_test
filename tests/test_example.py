try:
    from example import add
except ImportError: # Example is installed under example namespace in skbuild
    from example.example import add

def test_example():
    assert add(2,3) == 5
