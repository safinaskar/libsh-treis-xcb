// 2018DECTMP

//@ #pragma once

#include "libsh-treis/libsh-treis.hpp"
#include "libsh-treis-xcb.hpp"

//@ #include <xcb/xcb.h>
namespace libsh_treis::xcb::no_raii //@
{ //@
xcb_connection_t * //@
x_connect (const char *displayname, int *screenp)//@;
{
  // Документация на xcb_connect и её код подтверждают, что xcb_connect не возвращает nullptr
  xcb_connection_t *result = xcb_connect (displayname, screenp);

  if (xcb_connection_has_error (result) != 0)
    {
      xcb_disconnect (result);
      _LIBSH_TREIS_THROW_MESSAGE ("Failed");
    }

  return result;
}
} //@

//@ #include <xcb/xcb.h>
//@ namespace libsh_treis::xcb
//@ {
//@ class connection: libsh_treis::tools::not_movable
//@ {
//@   xcb_connection_t *_connection;

//@   explicit connection (xcb_connection_t *conn) noexcept : _connection (conn)
//@   {
//@   }

//@   friend connection
//@   x_connect (const char *displayname, int *screenp);

//@ public:

//@   ~connection (void)
//@   {
//@     xcb_disconnect (_connection);
//@   }

//@   xcb_connection_t *
//@   get (void) const noexcept
//@   {
//@     return _connection;
//@   }
//@ };
//@ }

namespace libsh_treis::xcb //@
{ //@
connection //@
x_connect (const char *displayname, int *screenp)//@;
{
  return connection (libsh_treis::xcb::no_raii::x_connect (displayname, screenp));
}
} //@

//@ #include <stdint.h>
//@ #include <xcb/xcb.h>
//@ #include <xcb/xcb_image.h>
namespace libsh_treis::xcb::no_raii //@
{ //@
xcb_image_t * //@
x_image_get (xcb_connection_t *conn, xcb_drawable_t draw, int16_t x, int16_t y, uint16_t width, uint16_t height, uint32_t plane_mask, xcb_image_format_t format)//@;
{
  xcb_image_t *result = xcb_image_get (conn, draw, x, y, width, height, plane_mask, format);

  if (result == nullptr)
    {
      _LIBSH_TREIS_THROW_MESSAGE ("Failed");
    }

  return result;
}
} //@

//@ #include <stdint.h>
//@ #include <xcb/xcb.h>
//@ #include <xcb/xcb_image.h>
//@ namespace libsh_treis::xcb
//@ {
//@ class image: libsh_treis::tools::not_movable
//@ {
//@   xcb_image_t *_image;

//@   explicit image (xcb_image_t *im) noexcept : _image (im)
//@   {
//@   }

//@   friend image
//@   x_image_get (xcb_connection_t *conn, xcb_drawable_t draw, int16_t x, int16_t y, uint16_t width, uint16_t height, uint32_t plane_mask, xcb_image_format_t format);

//@ public:

//@   ~image (void)
//@   {
//@     xcb_image_destroy (_image);
//@   }

//@   xcb_image_t *
//@   get (void) const noexcept
//@   {
//@     return _image;
//@   }
//@ };
//@ }

namespace libsh_treis::xcb //@
{ //@
image //@
x_image_get (xcb_connection_t *conn, xcb_drawable_t draw, int16_t x, int16_t y, uint16_t width, uint16_t height, uint32_t plane_mask, xcb_image_format_t format)//@;
{
  return image (libsh_treis::xcb::no_raii::x_image_get (conn, draw, x, y, width, height, plane_mask, format));
}
} //@
