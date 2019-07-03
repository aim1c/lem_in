/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:24:07 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/06/08 18:57:46 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"


int		close_sdl(t_mlx *m)
{
	SDL_DestroyWindow(m->sdl->win);
	SDL_DestroyRenderer(m->sdl->renderer);
	SDL_Quit();
	TTF_Quit();
	exit(EXIT_SUCCESS);
	return (1);
}

void	val_of_levels(t_levels *l, int n)
{
	l->main_level = (n - 2) / 10;
	l->mod = (n - 2) % 10;
	l->cur = 1;
}

void	y_range(t_levels *l, int i, int *y, int *x)
{
	if (l->cur == i / 10)
	{
		*y = *y + ((640 - (50 * l->main_level + 1)) / (l->main_level + 1));
		*x = 100;
		l->cur += 1;
	}
}

void	x_range(t_levels *l, int *x, int *y)
{
	int mod;

	if (l->main_level == 0)
		mod = l->mod - 2;
	else
		mod = 10;
	if (*x == 100)
		*x = 101;
	else
	{
		if (mod == 10)
			*x = *x + ((900 - (50 * mod)) / (mod - 2) + 40);
		else
			*x = *x + ((800 - (50 * mod)) / (mod - 1) - 50);
	}
	if (l->main_level == 0)
		*y = 360;
}

void	draw_lem_in_rooms(t_sdl **s, t_full **f)
{
	int			i;
	SDL_Surface	*su;
	SDL_Rect	srcrect = { 0, 0, 512, 512 };
	SDL_Rect	dstrect;
	t_room		*r;

	i = -1;
	su = SDL_LoadBMP("../pic.bmp");
	SDL_Texture *tex = SDL_CreateTextureFromSurface((*s)->renderer, su);
	SDL_FreeSurface(su);
	while (++i < (*f)->n)
	{
		r = (*f)->room[i];
		dstrect = (SDL_Rect) {r->x, r->y, 50, 50};
		SDL_RenderCopy((*s)->renderer, tex, &srcrect, &dstrect);
	}
	SDL_DestroyTexture(tex);
}

void	get_pointers(t_full **f)
{
	int			i;
	SDL_Rect	xy = {100, 90, 0, 0};
	t_levels	lev;

	i = -1;
	val_of_levels(&lev, (*f)->n);
	while (++i < (*f)->n)
	{
		if (i != 0 && i != (*f)->n - 1)
		{
			if (i - 1 > 0 && (lev.cur == i / 10))
				y_range(&lev, i, &xy.y, &xy.x);
			else
				x_range(&lev, &xy.x, &xy.y);
			(*f)->room[i]->x = xy.x;
			(*f)->room[i]->y = xy.y;
		} else
		{
			if (i == 0)
			{
				(*f)->room[0]->x = 500;
				(*f)->room[0]->y = 20;
			} else
			{
				(*f)->room[(*f)->n - 1]->x = 500;
				(*f)->room[(*f)->n - 1]->y = 660;
			}
		}
	}
}

int		lll(t_data *d)
{
	int r;
	char *l;

	r = 0;
	while (d->data)
	{
		l = d->data->content;
		if (l[0] == 0)
			break ;
		if (ft_strchr(l, '-'))
			r++;
		d->data = d->data->next;
	}
	return (r);
}

void	ffff(SDL_Point *p, SDL_Point *p1, t_full **f, char **s)
{
	int		i;

	i = -1;
	while (++i <= (*f)->n - 1)
	{
		if (ft_strstr(s[0], (*f)->room[i]->name) && ft_strstr((*f)->room[i]->name, s[0]))
		{
			p->x = (*f)->room[i]->x + 25;
			p->y = (*f)->room[i]->y + 25;
		}
		if (ft_strstr(s[1], (*f)->room[i]->name) && ft_strstr((*f)->room[i]->name, s[1]))
		{
			p1->x = (*f)->room[i]->x + 25;
			p1->y = (*f)->room[i]->y + 25;
		}
	}
}

void	get_links_pointers(t_mlx *m, t_full **f, t_data *d)
{
	SDL_Point	*s;
	char		**sp;
	char		*l;
	int			i;

	i = -1;
	d->data = d->data_head;
	(*f)->l = lll(d);
	d->data = d->data_head;
	s = malloc(sizeof(SDL_Point) * ((*f)->l * 2) + 1);
	while (++i <= (*f)->l * 2)
	{
		s->x = 0;
		s->y = 0;
	}
	i = 0;
	while (d->data)
	{
		l = d->data->content;
		if (l[0] == 0)
			break ;
		if (ft_strchr(l, '-'))
		{
			sp = ft_strsplit(l, '-');
			ffff(&s[i], &s[i + 1], f, sp);
			i += 2;
		}
		d->data = d->data->next;
	}
	m->sdl->p = s;
}

void	draw_lines(t_sdl **s, t_full **f)
{
	int i;

	i = 0;
	SDL_SetRenderDrawColor((*s)->renderer, 127, 0, 255, 1);
	while (i < (*f)->l * 2)
	{
		SDL_RenderDrawLine((*s)->renderer, (*s)->p[i].x, (*s)->p[i].y, (*s)->p[i + 1].x, (*s)->p[i + 1].y);
		i += 2;
	}
}

void	init_ant(t_full **f, t_data *d)
{
	int i;
	t_ant **a;

	i = -1;
	a = malloc(sizeof(t_ant *) * ((*f)->ants + 1));
	while (++i < (*f)->ants)
	{
		a[i] = malloc(sizeof(t_ant));
		a[i]->name = ft_strdup(ft_strjoin("L", ft_itoa(i + 1)));
		a[i]->d.x = 500;
		a[i]->d.y = 70;
		a[i]->d.h = 50;
		a[i]->d.w = 50;
		a[i]->p.x = 500;
		a[i]->p.y = 70;
		a[i]->p.h = 50;
		a[i]->p.w = 50;
	}
	(*f)->anta = a;
}

void	save(SDL_Rect *a, SDL_Rect b)
{
	a->x = b.x;
	a->y = b.x;
	a->h = a->h;
	a->w = a->w;
}

void	search_set(t_full **f, int w, char *l)
{
	char **step;
	char **name;
	int i;
	int a;
	int b;

	i = -1;
	step = ft_strsplit(l, ' ');
	while (++i < w)
	{
		name = ft_strsplit(step[i], '-');
		a = -1;
		while (++a < (*f)->ants)
		{
			b = -1;
			if (ft_strstr(name[0], (*f)->anta[a]->name) && ft_strstr((*f)->anta[a]->name, name[0]))
			{
				while (++b < (*f)->n)
				{
					if (ft_strstr(name[1], (*f)->room[b]->name) && ft_strstr((*f)->room[b]->name, name[1]))
					{
						save(&(*f)->anta[a]->p, (*f)->anta[a]->d);
						(*f)->anta[a]->d.x = (*f)->room[b]->x;
						(*f)->anta[a]->d.y = (*f)->room[b]->y;
						break ;
					}
				}
				break ;
			}
		}
	}
}

void	read_l_set_point_ants(t_full **f, t_data **d)
{
	if ((*d)->data)
	{
		int w;
		char *l;

		while ((*d)->data)
		{
			l = (*d)->data->content;
			w = ft_wordcount(l, ' ');
			search_set(f, w, l);
			(*d)->data = (*d)->data->next;
			break;
		}
	}
}

void	set_ants_to_win(t_sdl **s, t_full **f, t_data *d)
{
	int			i;
	SDL_Surface	*su;
	SDL_Rect	srcrect = { 0, 0, 512, 512 };
	t_ant		**a;

	a = (*f)->anta;
	su = SDL_LoadBMP("../1.bmp");
	SDL_Texture *tex = SDL_CreateTextureFromSurface((*s)->renderer, su);
	SDL_FreeSurface(su);
	i = -1;
	int e = 0;
	while (++i < (*f)->ants)
		SDL_RenderCopy((*s)->renderer, tex, &srcrect, &(*f)->anta[i]->d);
	SDL_DestroyTexture(tex);
}

void	navalnyi(t_sdl **s, t_full **f, t_data *d)
{
	int			i;
	SDL_Surface	*su;
	SDL_Rect	srcrect = { 0, 0, 512, 512 };
	t_ant		**a;
	static int b;

		i = -1;
		a = (*f)->anta;
		su = SDL_LoadBMP("../1.bmp");
		SDL_Texture *tex = SDL_CreateTextureFromSurface((*s)->renderer, su);
		SDL_FreeSurface(su);
		d->data = d->data_head;
		char *l = d->data->content;
		while (l[0] != 'L')
		{
			l = d->data->content;
			if (l[0] != 'L')
				d->data = d->data->next;
		}
		i = -1;
		read_l_set_point_ants(f, &d);
		SDL_DestroyTexture(tex);
		b++;
	i = -1;
	while (++i < (*f)->ants)
		SDL_RenderCopy((*s)->renderer, tex, &srcrect, &(*f)->anta[i]->d);
}

void	render(t_sdl **s, t_full **f, t_data *d)
{
	SDL_SetRenderDrawColor((*s)->renderer, 255, 102, 0, 1);
	SDL_RenderClear((*s)->renderer);
	draw_lem_in_block(s, f);
	draw_lem_in_rooms(s, f);
	draw_lines(s, f);
	set_ants_to_win(s, f, d);
	SDL_RenderPresent((*s)->renderer);
}

void	move_l(t_full **f, t_data *d, t_sdl **s)
{
	read_l_set_point_ants(f, &d);
}

void 	break_game_while(int *f, t_sdl **s, t_data *d, t_full **a)
{
	while (SDL_PollEvent(&(*s)->e) != 0)
	{
		if ((*s)->e.type == SDL_QUIT)
			*f = TRUE;
		else if ((*s)->e.type == SDL_KEYDOWN)
		{
			if ((*s)->e.key.keysym.sym == SDLK_RIGHT)
			{
				move_l(a, d, s);
				break ;
			}
		}
	}
}

int		main()
{
	t_mlx	*m;
	int		f = FALSE;
	int		en = FALSE;

	if ((m = init_all()) == NULL)
		exit_warn("()");
	get_lst_data(&m->dat);
	get_full_data(&m->f, &m->dat);
	get_pointers(&m->f);
	get_links_pointers(m, &m->f, m->dat);
	init_ant(&m->f, m->dat);
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	init_create(&m->sdl);
	while (!en)
		let_start(&en, &f, &m->sdl);
	SDL_DestroyRenderer(m->sdl->renderer);
	m->sdl->renderer = SDL_CreateRenderer(m->sdl->win, -1, 0);
	while (!f)
	{
		render(&m->sdl, &m->f, m->dat);
		break_game_while(&f, &m->sdl, m->dat, &m->f);
	}
	close_sdl(m);
	return 0;
}