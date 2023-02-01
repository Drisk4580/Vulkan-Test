#include "window.h"

typedef uint32_t xcb_window_t;

void window::initialize_vk_window() {
	vk_window_instance();
}

window::window() {

}

void window::clean_vk_engine() {
	Debug(NAMESPACE_DEBUG::init());
	Dout(dc::notice, "Not implemented yet");
	xcb_disconnect(connection);
}

void window::vk_window_instance() {
    this->connection = xcb_connect (NULL, NULL);

		/* Get the first screen */
    const xcb_setup_t      *setup  = xcb_get_setup (connection);
    xcb_screen_iterator_t   iter   = xcb_setup_roots_iterator (setup);
	xcb_screen_t           *screen = iter.data;


        /* Create the window */
    this->vk_window = xcb_generate_id (connection);
	xcb_create_window (connection,                    /* Connection          */
                           XCB_COPY_FROM_PARENT,          /* depth (same as root)*/
                           vk_window,                        /* window Id           */
                           screen->root,                  /* parent window       */
                           0, 0,                          /* x, y                */
                           150, 150,                      /* width, height       */
                           10,                            /* border_width        */
                           XCB_WINDOW_CLASS_INPUT_OUTPUT, /* class               */
                           screen->root_visual,           /* visual              */
                           0, NULL );                     /* masks, not used yet */

    /* Map the window on the screen */
    xcb_map_window (connection, vk_window);

    /* Create a black graphic context for drawing in the foreground */
    xcb_drawable_t  vk_g_window   = screen->root;
    xcb_gcontext_t  black    = xcb_generate_id (connection);
    uint32_t        mask     = XCB_GC_BACKGROUND;
    uint32_t        value[]  = { screen->black_pixel };

    xcb_create_gc (connection, black, vk_g_window, mask, value);
	xcb_void_cookie_t xcb_change_gc (xcb_connection_t *c,            /* The XCB Connection */
                                xcb_gcontext_t    gc,           /* The Graphic Context */
                                uint32_t          value_mask,   /* Components of the Graphic Context that have to be set */
								const uint32_t   *value_list ); /* Value as specified by value_mask */
	/* Make sure commands are sent before we pause so that the window gets shown */
    xcb_flush (connection);
	DoutFatal(dc::core|error_cf, "Shouln't reach here");
    pause ();    /* hold client until Ctrl-C */
	window::clean_vk_engine();
}
