#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_time.h"
#include "sokol_glue.h"
#include "sokol_debugtext.h"
#include "dbgui/dbgui.h"

sg_pass_action pass_action;


// HTML-lite
#include <iostream>
#include <assert.h>

#include "litehtml.h"
#include "win32_container.h"


extern const litehtml::tchar_t master_css[] = 
{
#include "master.css.inc"
};

/**
static void Test() {
  litehtml::context ctx;
  ctx.load_master_stylesheet(master_css);
}
**/



void init(void) {

    printf("Thallium web engine.\n\n");
    
    sg_desc desc = { };
    desc.context = sapp_sgcontext();
    sg_setup(&desc);

    pass_action.colors[0].action = SG_ACTION_CLEAR;
    pass_action.colors[0].val[0] = 0.0f;
    pass_action.colors[0].val[1] = 0.0f;
    pass_action.colors[0].val[2] = 1.0f;
    pass_action.colors[0].val[3] = 0.5f;

    __dbgui_setup(sapp_sample_count());

    printf(" init() [OK]\n");

    Test();


}

void frame(void) {
    sg_begin_default_pass(&pass_action, sapp_width(), sapp_height());
    __dbgui_draw();
    sg_end_pass();
    sg_commit();
}

void cleanup(void) {
    __dbgui_shutdown();
    sg_shutdown();
}

sapp_desc sokol_main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    sapp_desc desc = { };

    desc.init_cb = init;
    desc.frame_cb = frame;
    desc.cleanup_cb = cleanup;
    /*desc.event_cb = __dbgui_event;*/
    desc.width = 800;
    desc.height = 600;
    desc.gl_force_gles2 = true;
    desc.window_title = "Thallium web browser experimentation. SPinti Software-VLiance";


    return desc;
}