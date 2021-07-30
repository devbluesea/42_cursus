/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seobaek <seobaek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:08:34 by seobaek           #+#    #+#             */
/*   Updated: 2020/11/10 22:59:19 by seobaek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include "ggl_mlx_define.h"
# include "libft.h"
# include "libvct.h"
# include "figures.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <stdio.h>

# ifdef MACOS
#  define OS_NAME 1
# endif

# ifdef LINUX
#  define OS_NAME 2
# endif

# define BUFSIZE 32

# ifndef NUM_THREADS
#  define NUM_THREADS 4
# endif

# define REFLECTION_LIMIT 3

# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4
# define CU 5
# define PY 6

# define EPSILON 0.00001

typedef struct		s_v3
{
	t_p3	o; // origin
	t_p3	d; // direction
}					t_v3;

typedef struct		s_camera
{
	int				init; // 없어도 된다.
	int				idx; // node number
	t_p3			o; // 카메라 광원 .rt
	t_p3			nv; // 카메라 법선벡터의 단위벡터 .rt
	int				fov; // 카메라 화각 .rt
	void			*img_ptr; // 카메라당 이미지
	int				*px_img; // image 선언
	int				bits_per_pixel; // 32
	int				size_line; // image line의 char size
	int				endian; // 0 : little endian
	struct s_camera	*next; // 다음 카메라
}					t_camera;

typedef struct		s_light
{
	t_p3			o; // 광원 parse_light
	double			br; // 밝기 parse_light
	int				color; // 컬러 parse_light
	struct s_light	*next; // 다음 노드 parse_light
}					t_light;

typedef struct		s_scene
{
	int				res_init; // window 개수 flag parse_res
	int				xres; // window x축 parse_res
	int				yres; // window y축 parse_res
	int				cam_nb; // 카메라 개수 parse_camera
	t_light			*l; // 광원 리스트 parse_light
	int				al_init; // 주변광 개수 flag
	double			ambient_light; // 주변광 parse_ambent_light
	int				al_color; // 주변광 컬러 parse_ambient_light
	int				bgr; // default color calc_pixel_color
}					t_scene;

typedef struct		s_figures // 물체
{
	int				flag; // type of figures
	union u_figures	fig; // sp, pl, sq, cy, tr 중 하나
	int				color; // 컬러
	int				specular; // 정반사
	double			refl_idx; // 반사율
	double			refr_idx; // 굴절
	int				texture; // 질감 타입
	t_p3			normal; // 법선벡터
	double			wavelength; // 파장
	struct s_figures*next;
}					t_figures;

typedef struct		s_minilibx
{
	void			*mlx_ptr; // mlx 받는 곳 init_mlx
	void			*win_ptr; // window 받는 곳 init_mlx
	t_camera		*cam; // 카메라 노드 parse_info
	t_camera		*begin; // 첫 카메라 노드 init_mlx
}					t_minilibx;

typedef struct		s_wrapper
{
	t_minilibx		mlx;
	t_scene			data;
	t_figures		*lst;
	int				tid; // thread id
	int				i; // 픽셀 x축 주소
	int				j; // 픽셀 y축 주소
}					t_wrapper;

typedef struct		s_rss
{
	int		limit; // 3
	int		xres; // 이미지 폭
	int		yres; // 이미지 높이
	int		i; // 픽셀 x축 주소
	int		j; // 픽셀 y축 주소
}					t_rss;
typedef struct		s_inter
{
	int				color; // 굴절된 컬러
	int				ref_color; // 반사된 컬러
	t_p3			normal; // 만난 점의 법선벡터
	t_p3			p; // 만난 점의 좌표
	t_p3			ref_vec; // 안 씀
}					t_inter;

typedef struct		s_bmp_header
{
	char			type[2]; // BMP 파일 매직 넘버, 비트맵 파일이 맞는지 확인
	unsigned int	size; // 파일 크기(바이트)
	unsigned int	reserved; // 미래를 위해 예약된 공간
	unsigned int	offset; // 비트맵 데이터의 시작 위치
}					t_bmphead;

typedef struct		s_dib_header
{
	unsigned int	size; // 현재 비트맵 정보 헤더의 크기
	int				width; // 비트맵 이미지의 가로 크기(픽셀)
	int				height; // 비트맵 이미지의 세로 크기(픽셀). 양수 : 이밎의 상하가 뒤집혀서 저장된 상태. 음수: 이미지가 그대로 저장된 상태
	unsigned short	colplanes; //사용하는 색상판의 수. 항상 1
	unsigned short	bpp; // 픽셀 하나를 표현하는 비트수
	unsigned int	compression; // 압축방식. 보통 비트맵은 압축하지 않으므로 0
	unsigned int	img_size; // 비트맵 이미지의 픽셀 데이터 크기(압축 되지 않은 크기)
	int				x_ppm; // 그림의 가로 해상도(미터당 픽셀)
	int				y_ppm; // 그림의 세로 해상도(미터당 픽셀)
	unsigned int	color_number; // 색상 테이블에서 실제 사용되는 색상 수
	unsigned int	important_color; // 비트맵을 표현하기 위해 필요한 색상 인덱스 수
}					t_dibhead;

typedef struct		s_thread
{
	pthread_t		threads[NUM_THREADS];
	t_wrapper		wrapper[NUM_THREADS];
	int				i;
}					t_thread;

typedef struct		s_sq
{
	t_p3			half_size; // 중심에서 한 변으로 가로지르는 벡터
	t_p3			floor; // 바닥 벡터
	t_p3			center_to_ip; // 중점에서 point
}					t_sq;

typedef struct		s_cube
{
	t_figures		sq;
	t_p3			center; // 중심 좌표
	t_p3			normal[6]; // 6면의 법선벡터
}					t_cube;

typedef struct		s_pyramid
{
	t_figures		sq; // 사각형 정보
	t_figures		tr; // 삼각형 정보, 4번 돌림
	t_p3			tr_center; // 피라미드 꼭지점 좌표
	t_p3			normal[5];
	t_p3			corner[4];
}					t_pyr;

/*
**			 	Parsing functions
*/

void				parse_scene(t_minilibx *mlx, t_scene *data, t_figures **lst,
																	char **av);

void				parse_res(t_scene *data, char **str);

void				parse_ambient_light(t_scene *data, char **str);

void				parse_camera(t_minilibx *mlx, t_scene *data, char **str);

void				parse_light(t_scene **data, char **str);

void				parse_sphere(t_figures **elem, char **str);

void				parse_plane(t_figures **elem, char **str);

void				parse_square(t_figures **elem, char **str);

void				parse_triangle(t_figures **elem, char **str);

void				parse_cylinder(t_figures **elem, char **str);

void				parse_cube(t_figures **elem, char **str);

void				parse_pyramid(t_figures **elem, char **str);

/*
**				Parsing help functions
*/

char				*readfile(char *str, int fd);

int					stoi(char **str);

double				stof(char **str);

void				in_range(double nb, double min, double max, char *function);

void				next(char **str);

void				comma(char **str);

t_p3				parse_p3(char **str);

int					parse_color(char **str);

void				ft_addnewlst_back(t_figures **alst);

/*
**				Intersection functions
*/
double				sphere_intersection(t_p3 o, t_p3 d, t_figures *lst);

double				plane_intersection(t_p3 o, t_p3 d, t_figures *lst);

double				square_intersection(t_p3 o, t_p3 d, t_figures *lst);

double				triangle_intersection(t_p3 o, t_p3 d, t_figures *lst);

double				cylinder_intersection(t_p3 o, t_p3 d, t_figures *lst);

double				cube_intersection(t_p3 o, t_p3 d, t_figures *lst);

double				pyramid_intersection(t_p3 o, t_p3 d, t_figures *lst);

/*
**				Intersections help functions
*/

void				try_all_intersections(t_v3 ray, t_figures *lst,
											t_figures *clfig, double *clint);

double				solve_plane(t_p3 o, t_p3 d, t_p3 plane_p,
														t_p3 plane_nv);

/*
**				Ray tracing
*/

void				render_scene(t_wrapper *w);

int					trace_ray(t_p3 o, t_p3 d, t_wrapper *w, int depth);

int					calc_ray(int n, t_rss rss, t_wrapper *w);

void				calc_normal(t_p3 p, t_p3 d, t_p3 *normal, t_figures *lst);

int					is_lit(t_p3 o, t_p3 d, t_figures *lst);

void				compute_light(t_v3 ray, t_inter *inter, t_scene data,
															t_figures *lst);

/*
**				Super Sampling
*/

int					*sample_pixel(int *edge_color, int last[2], t_rss rss,
																t_wrapper *w);

int					supersample(int *color, t_rss rss, t_wrapper *w);

/*
**				Multithreaded rendering
*/

void				wrapp_data(t_minilibx mlx, t_scene data, t_figures *lst,
															t_wrapper *wrapper);

void				multithreaded_render(t_wrapper wrapper[NUM_THREADS]);

/*
**				Error handling functions and success message
*/

void				*ec_malloc(unsigned int size);

void				fatal(char *message);

void				scene_error(char *message);

void				usage(char *program_name);

void				success_message(int ac);

/*
**				Minilibx functions
*/

void				init_mlx(t_minilibx *mlx, t_scene *data);

void				graphic_loop(t_minilibx mlx, t_scene data);

int					next_cam(int keycode, t_minilibx *mlx);

int					close_program(void *param);

/*
**				Bmp exporter
*/

void				do_the_bmp_thing(t_minilibx mlx, t_scene data, char *name);

/*
**				Color Operations
*/

int					cproduct(int color, double coef);

int					cadd(int color_a, int color_b);

int					color_difference(int color1, int color2);

int					color_x_light(int color, double rgb[3]);

int					average(int color1, int color2);

int					average_supersampled_color(int *color);

/*
**				Utils
*/

t_p3				reflect_ray(t_p3 ray, t_p3 normal);

void				apply_texture(int texture, t_inter *inter, t_figures *lst);

int					rainbow(t_inter *inter);

/*
**				rt_check
*/

void				rt_file_check(char **argv);

//cam_xorigin_adjust.c
void	cam_adjust(t_minilibx mlx, t_figures *lst, t_scene *data);

#endif
