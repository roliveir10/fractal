#include "fractal.h"

static int			initPanelFont(t_panel *panel)
{
	if (TTF_Init() == -1)
		return (0);
	if (!(panel->arial_black_20 = TTF_OpenFont("/Library/Fonts/Arial Black.ttf", 20)))
		return (0);
	return (1);
}

static int			initPanelTexture(t_panel *panel)
{
	SDL_Surface		*surface = NULL;

	if (!(surface = SDL_LoadBMP("textures/panel_bg.bmp")))
		return (0);
	panel->panel_bg = SDL_CreateTextureFromSurface(panel->renderer, surface);
	SDL_FreeSurface(surface);
	return (1);
}

int					initPanel(t_panel *panel)
{
	if (SDL_CreateWindowAndRenderer(PANEL_WIDTH, PANEL_HEIGHT,
			0, &panel->window, &panel->renderer) < 0)
		return (0);
	panel->wId = SDL_GetWindowID(panel->window);
	SDL_SetWindowPosition(panel->window, 2330, 300);
	SDL_SetWindowTitle(panel->window, "Color Setup");
	if (!initPanelTexture(panel))
		return (0);
	if (!initPanelFont(panel))
		return (0);
	return (1);
}

static void			setRgbaText(SDL_Color *color, int value)
{
	color->b = value % 256;
	value /= 256;
	color->g = value % 256;
	value /= 256;
	color->r = value % 256;
	value /= 256;
	color->a = 0;
}

static int			writeText(t_text *msg)
{
	if (!(msg->texte = TTF_RenderText_Shaded(msg->police, msg->str,
			msg->fg_color, msg->bg_color)))
		return (0);
	if (!(msg->texture = SDL_CreateTextureFromSurface(msg->renderer,
			msg->texte)))
		return (0);
	SDL_FreeSurface(msg->texte);
	if (SDL_QueryTexture(msg->texture, NULL, NULL,
			&msg->pos.w, &msg->pos.h) < 0)
	{
		SDL_DestroyTexture(msg->texture);
		return (0);
	}
	if (SDL_RenderCopy(msg->renderer, msg->texture, NULL, &msg->pos) < 0)
	{
		SDL_DestroyTexture(msg->texture);
		return (0);
	}
	SDL_DestroyTexture(msg->texture);
	return (1);
}

static int			drawColorValue(t_text *msg, t_vector color)
{
	char			nbr[4];

	setRgbaText(&msg->bg_color, 0xffffff);
	setRgbaText(&msg->fg_color, 0x0);
	msg->pos.x = 76;
	msg->pos.y = 54;
	sprintf(nbr, "%03.f", color.x * 255);
	msg->str = ft_strdup(nbr);
	if (!writeText(msg))
	{
		ft_strdel(&msg->str);
		return (0);
	}
	ft_strdel(&msg->str);
	msg->pos.y = 118;
	sprintf(nbr, "%03.f", color.y * 255);
	msg->str = ft_strdup(nbr);
	if (!writeText(msg))
	{
		ft_strdel(&msg->str);
		return (0);
	}
	msg->pos.y = 182;
	sprintf(nbr, "%03.f", color.z * 255);
	msg->str = ft_strdup(nbr);
	if (!writeText(msg))
	{
		ft_strdel(&msg->str);
		return (0);
	}
	ft_strdel(&msg->str);
	return (1);
}

static t_text		getTextInfo(t_env *env)
{
	t_text			msg;

	msg.renderer = env->lib.panel.renderer;
	msg.texture = env->lib.panel.panel_bg;
	msg.pos.x = 0;
	msg.pos.y = 0;
	msg.pos.w = PANEL_WIDTH;
	msg.pos.h = PANEL_HEIGHT;
	msg.police = env->lib.panel.arial_black_20;
	return (msg);
}

int					drawPanelMain(t_env *env)
{
	t_text			msg;

	msg = getTextInfo(env);
	if (SDL_RenderCopy(msg.renderer, msg.texture, NULL, &msg.pos) < 0)
		return (0);
	if (!drawColorValue(&msg, env->f.color))
		return (0);
	return (1);
}

int					drawPanel(t_env *env)
{
	if (!(drawPanelMain(env)))
		return (0);
	SDL_RenderPresent(env->lib.panel.renderer);
	return (1);
}
