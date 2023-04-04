#include "cub3d.h"

void *ft_realloc(void *ptr, size_t size) 
{
    void *new_ptr;

    if (size == 0)
    {
        free(ptr);
        cub3d_error("REALLOC_FAIL");
    }
    if (ptr == NULL)
        return (malloc(size));
    new_ptr = malloc(size);
    if (new_ptr == NULL)
        cub3d_error("REALLOC_FAIL");;
    ft_memcpy(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}