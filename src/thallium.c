#include "sokol_app.h"
#include "sokol_gfx.h"
#include "sokol_time.h"
#include "sokol_glue.h"
#include "sokol_debugtext.h"
#include "dbgui/dbgui.h"

/*#include <iostream>
#include "litehtml/os_types.h"
#include "litehtml/types.h"
#include "litehtml/context.h"
#include "litehtml/document.h"
*/
sg_pass_action pass_action;

void init(void) {
    sg_setup(&(sg_desc){
        .context = sapp_sgcontext()
    });
    pass_action = (sg_pass_action) {
        .colors[0] = { .action=SG_ACTION_CLEAR, .val ={0.0f, 0.0f, 1.0f, 1.0f} }
    };
    __dbgui_setup(sapp_sample_count());
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
    return (sapp_desc){
        .init_cb = init,
        .frame_cb = frame,
        .cleanup_cb = cleanup,
        .event_cb = __dbgui_event,
        .width = 800,
        .height = 600,
        .gl_force_gles2 = true,
        .window_title = "Thallium web browser experimentation. SPinti Software-VLiance",
    };
}