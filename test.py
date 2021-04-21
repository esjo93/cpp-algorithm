a=[("고규현", 2), ("정필준", 0), ("정세원", 1)]
def my_key(a):
    return a[1]
print(sorted(a, key=my_key))
print(sorted(a, key=lambda x: x[1]))
