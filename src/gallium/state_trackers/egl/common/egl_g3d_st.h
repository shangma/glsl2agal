/*
 * Mesa 3-D graphics library
 * Version:  7.9
 *
 * Copyright (C) 2010 LunarG Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * BRIAN PAUL BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors:
 *    Chia-I Wu <olv@lunarg.com>
 */

#ifndef _EGL_G3D_ST_H_
#define _EGL_G3D_ST_H_

#include "pipe/p_compiler.h"
#include "state_tracker/st_api.h"
#include "egltypedefs.h"

struct st_api *
egl_g3d_create_st_api(enum st_api_type api);

struct st_manager *
egl_g3d_create_st_manager(_EGLDisplay *dpy);

void
egl_g3d_destroy_st_manager(struct st_manager *smapi);

struct st_framebuffer_iface *
egl_g3d_create_st_framebuffer(_EGLSurface *surf);

void
egl_g3d_destroy_st_framebuffer(struct st_framebuffer_iface *stfbi);

/**
 * Return the EGL_<api>_BIT of the st api.
 */
static INLINE int
egl_g3d_st_api_bit(enum st_api_type api)
{
   int bit;

   switch (api) {
   case ST_API_OPENGL:
      bit = EGL_OPENGL_BIT;
      break;
   case ST_API_OPENGL_ES1:
      bit = EGL_OPENGL_ES_BIT;
      break;
   case ST_API_OPENGL_ES2:
      bit = EGL_OPENGL_ES2_BIT;
      break;
   case ST_API_OPENVG:
      bit = EGL_OPENVG_BIT;
      break;
   default:
      bit = 0;
      break;
   }

   return bit;
}

#endif /* _EGL_G3D_ST_H_ */