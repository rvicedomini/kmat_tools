from libc.stdlib cimport malloc, free
from libc.string cimport strdup


# Declare main_reverse function from C
cdef extern from "km_reverse.cpp":
    int main_reverse(int argc, char **argv)

def py_main_reverse(list argv):
    cdef int argc = len(argv)
    
    if argc == 0:
        # Handle empty argv gracefully
        return
    
    cdef char **c_argv = <char **>malloc((argc+1) * sizeof(char *))
    if c_argv is NULL:
        # Handle allocation failure
        raise MemoryError("Failed to allocate memory")
    
    try:
        for i in range(argc):
            if argv[i] is None:
                # Handle invalid argument
                raise ValueError("Invalid argument at index {}".format(i))
            c_argv[i] = strdup(argv[i].encode('utf-8'))
            if c_argv[i] is NULL:
                # Handle strdup failure
                raise MemoryError("Failed to allocate memory for argument {}".format(i))
        c_argv[argc] = NULL
        return main_reverse(argc, c_argv)
    finally:
        for i in range(argc):
            if c_argv[i] is not NULL:
                free(c_argv[i])
        free(c_argv)
