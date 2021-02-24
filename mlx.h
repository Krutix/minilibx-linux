/*
** mlx.h for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Tue May 15 16:23:28 2007 Olivier Crouzet
*/

/*
**   MinilibX -  Please report bugs
*/


/*
** FR msg - FR msg - FR msg
**
** La MinilibX utilise 2 librairies supplementaires qu'il
**      est necessaire de rajouter a la compilation :
**   -lmlx -lXext -lX11
**
** La MinilibX permet le chargement des images de type Xpm.
** Notez que cette implementation est incomplete.
** Merci de communiquer tout probleme de chargement d'image
** de ce type.
*/


#ifndef MLX_H

#define	MLX_H


#define MLX_KeyPress              2
#define MLX_KeyRelease            3
#define MLX_ButtonPress           4
#define MLX_ButtonRelease         5
#define MLX_MotionNotify          6
#define MLX_EnterNotify           7
#define MLX_LeaveNotify           8
#define MLX_FocusIn               9
#define MLX_FocusOut              10
#define MLX_KeymapNotify          11
#define MLX_Expose                12
#define MLX_GraphicsExpose        13
#define MLX_NoExpose              14
#define MLX_VisibilityNotify      15
#define MLX_CreateNotify          16
#define MLX_DestroyNotify         17
#define MLX_UnmapNotify           18
#define MLX_MapNotify             19
#define MLX_MapRequest            20
#define MLX_ReparentNotify        21
#define MLX_ConfigureNotify       22
#define MLX_ConfigureRequest      23
#define MLX_GravityNotify         24
#define MLX_ResizeRequest         25
#define MLX_CirculateNotify       26
#define MLX_CirculateRequest      27
#define MLX_PropertyNotify        28
#define MLX_SelectionClear        29
#define MLX_SelectionRequest      30
#define MLX_SelectionNotify       31
#define MLX_ColormapNotify        32
#define MLX_ClientMessage         33
#define MLX_MappingNotify         34
#define MLX_GenericEvent          35
#define MLX_LASTEvent             36


#define MLX_KeyPressMask                (1L<<0)
#define MLX_KeyReleaseMask              (1L<<1)
#define MLX_ButtonPressMask             (1L<<2)
#define MLX_ButtonReleaseMask           (1L<<3)
#define MLX_EnterWindowMask             (1L<<4)
#define MLX_LeaveWindowMask             (1L<<5)
#define MLX_PointerMotionMask           (1L<<6)
#define MLX_PointerMotionHintMask       (1L<<7)
#define MLX_Button1MotionMask           (1L<<8)
#define MLX_Button2MotionMask           (1L<<9)
#define MLX_Button3MotionMask           (1L<<10)
#define MLX_Button4MotionMask           (1L<<11)
#define MLX_Button5MotionMask           (1L<<12)
#define MLX_ButtonMotionMask            (1L<<13)
#define MLX_KeymapStateMask             (1L<<14)
#define MLX_ExposureMask                (1L<<15)
#define MLX_VisibilityChangeMask        (1L<<16)
#define MLX_StructureNotifyMask         (1L<<17)
#define MLX_ResizeRedirectMask          (1L<<18)
#define MLX_SubstructureNotifyMask      (1L<<19)
#define MLX_SubstructureRedirectMask    (1L<<20)
#define MLX_FocusChangeMask             (1L<<21)
#define MLX_PropertyChangeMask          (1L<<22)
#define MLX_ColormapChangeMask          (1L<<23)
#define MLX_OwnerGrabButtonMask         (1L<<24)


void	*mlx_init();
/*
**  needed before everything else.
**  return (void *)0 if failed
*/


/*
** Basic actions
*/

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
/*
**  return void *0 if failed
*/
int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
*/


/*
** Image stuff
*/

void	*mlx_new_image(void *mlx_ptr,int width,int height);
/*
**  return void *0 if failed
**  obsolete : image2 data is stored using bit planes
**  void	*mlx_new_image2(void *mlx_ptr,int width,int height);
*/
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);
/*
**  endian : 0 = sever X is little endian, 1 = big endian
**  for mlx_new_image2, 2nd arg of mlx_get_data_addr is number_of_planes
*/
int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
				int x, int y);
int	mlx_get_color_value(void *mlx_ptr, int color);


/*
** dealing with Events
*/

int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);

int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop (void *mlx_ptr);
int mlx_loop_end (void *mlx_ptr);

/*
**  hook funct are called as follow :
**
**   expose_hook(void *param);
**   key_hook(int keycode, void *param);
**   mouse_hook(int button, int x,int y, void *param);
**   loop_hook(void *param);
**
*/


/*
**  Usually asked...
*/

int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color,
		       char *string);
void	mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);
void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height);
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height);
int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);

int	mlx_destroy_display(void *mlx_ptr);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int	mlx_hook(void *win_ptr, int x_event, int x_mask,
                 int (*funct)(), void *param);

int	mlx_do_key_autorepeatoff(void *mlx_ptr);
int	mlx_do_key_autorepeaton(void *mlx_ptr);
int	mlx_do_sync(void *mlx_ptr);

int	mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
int	mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
int	mlx_mouse_show(void *mlx_ptr, void *win_ptr);

int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

#endif /* MLX_H */
