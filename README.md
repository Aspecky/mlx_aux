# mlx_aux

Auxiliary utilities and helpers for MLX42.

## Building

To build the project, run `make` in the `source` directory:

```bash
cd source
make
```

### Configuration

If `MLX42/MLX42.h` does not exist in your standard include paths, you need to set the `CODAM_MLX_INCLUDE` environment variable.

Create a `.env` file inside the `source` folder with the path to your MLX42 include directory:

```bash
# source/.env
CODAM_MLX_INCLUDE=/path/to/MLX42/include
```

For example:
```bash
CODAM_MLX_INCLUDE=/usr/local/include/MLX42
```

The Makefile will automatically include this path during compilation if the variable is set.
