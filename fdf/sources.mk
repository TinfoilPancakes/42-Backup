# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppatil <ppatil@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/12 12:43:59 by ppatil            #+#    #+#              #
#    Updated: 2016/11/12 12:43:59 by ppatil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES += main.c

# Image Buffer Struct
C_FILES += img_buff.c
C_FILES += img_buff_destroy.c
C_FILES += img_buff_plot.c
C_FILES += img_line_draw.c
C_FILES += img_buff_clear.c

# Mesh Struct
C_FILES += mesh.c
C_FILES += mesh_del.c
C_FILES += mesh_vert_transform.c

# Viewport Struct
C_FILES += viewport.c
C_FILES += viewport_del.c
C_FILES += viewport_draw_mesh.c
C_FILES += viewport_vert_transform.c
C_FILES += viewport_mesh_plot.c

# Other stuff
C_FILES += fdf_colorize.c
C_FILES += fdf_expose.c
C_FILES += fdf_from_file.c
C_FILES += fdf_key_down.c
C_FILES += fdf_key_up.c
C_FILES += fdf_loop.c
C_FILES += fdf_redraw.c
