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
  xcb_connection_t *result = xcb_connect (displayname, screenp);

  if (xcb_connection_has_error (result) != 0)
    {
      xcb_disconnect (result);
      _LIBSH_TREIS_THROW_MESSAGE ("Failed");
    }

  return result;
}
} //@
