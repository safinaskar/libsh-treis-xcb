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
//@ class connection
//@ {
//@   xcb_connection_t *_connection;

//@ public:

//@   connection (const char *displayname, int *screenp) : _connection (libsh_treis::xcb::no_raii::x_connect (displayname, screenp))
//@   {
//@   }

//@   connection (connection &&) = delete;
//@   connection (const connection &) = delete;
//@   connection &operator= (connection &&) = delete;
//@   connection &operator= (const connection &) = delete;

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
