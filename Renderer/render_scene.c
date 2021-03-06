surface_set_target(surfaces[MRT]);
gpu_set_tex_filter(true);

SET_UNIFORM_I("vertex_mode", VERTEX_REGULAR)
SET_UNIFORM_I("fragment_mode", FRAGMENT_REGULAR)

#ifdef UNIFORM_BUFFER
texture_set_stage(shader_get_sampler_index(standard, "uniform_buffer"), surface_get_texture(surfaces[UNIFORM_BUFFER]));
#endif

ITERATE_VISIBLES
{
    #include "mrt.c"
}

gpu_set_tex_filter(false);
surface_reset_target();

//#include "edge.c"

//#include "collect_lights.c"

//non-shadow lights (deferred omni-lights)
//#include "lighting.c"

//shadow lights (shadow mapped spotlights)
//#include "shadowing.c"

//#include "post_processing.c"

SET_UNIFORM_I("vertex_mode", VERTEX_FLAT)
SET_UNIFORM_I("fragment_mode", FRAGMENT_FLAT)
surface_set_target(FINAL_SURFACE);
var scale = surface_info[MRT];
draw_surface_ext(surfaces[MRT],0,0, 1/scale[0], 1/scale[1],0,c_white,1.0);
surface_reset_target();

#ifdef SHOW_USE
//uses_mrt, uses_uniform_buffer, uses_visibility_culling
#endif
