#!/bin/sh

current_dir=$1

srcs=$(find "$current_dir" -type f -name '*.c' ! -path "$current_dir/library/*" | sed "s|^$current_dir/src/||" | awk '{printf(" %s \\\\\n\t\t\t\t", $0)}')
hdr_flags=$(find "$current_dir/includes" -type d | sed "s|^$current_dir/| -I |" | awk '{printf("%s \\\\\n\t\t\t\t", $0)}')
hdr_flags="\\t-I library/MLX42/include/MLX42\\\\\n\t\t\t\t\t-I library/libft/includes\\\\\n\t\t\t\t$hdr_flags"

perl -0777 -i -pe "BEGIN {undef $/; \$srcs = qq(${srcs}); \$hdr_flags = qq(${hdr_flags})} s/(SRCS\s+=).*?(?=SRC_DIR\s+=)/\$1\$srcs\\n/smg; s/(HDR_FLAGS\s+=).*?(?=LIB\s+)/\$1\$hdr_flags\\n/smg" "$current_dir/Makefile"

header_files=$(find "$current_dir/includes" -type f -name '*.h' ! -name 'minirt.h' ! -name 'typedef.h' | sed "s|^$current_dir/includes/|# include \"|" | sed 's|$|"|' | awk '{printf("%s\n", $0)}')

perl -0777 -i -pe "BEGIN {undef $/; \$header_files = qq(${header_files})} s/(# include \"typedef.h\"\n).*?(#endif)/\$1\$header_files\n\n\$2/smg" "$current_dir/includes/minirt.h"
