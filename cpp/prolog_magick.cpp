#define PL_ARITY_AS_SIZE 1
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <SWI-cpp.h>
#include <SWI-Prolog.h>
#include <SWI-Stream.h>

#include <Magick++.h>

Magick::Image open_image(term_t name);
std::string pl_get_file_name(term_t n, int flags);

PREDICATE(image_columns, 2)
{
  Magick::Image img {open_image(A1)};
  return A2 = static_cast<long>(img.columns());
}

PREDICATE(image_format, 2)
{
  Magick::Image img {open_image(A1)};
  return A2 = img.magick().c_str();
}

PREDICATE(image_rows, 2)
{
  Magick::Image img {open_image(A1)};
  return A2 = static_cast<long>(img.rows());
}

/**
 * Returns an image object for the image stores in the file name by
 * the supplied Prolog term.
 */
Magick::Image open_image(term_t name)
{
  return Magick::Image(pl_get_file_name(name, PL_FILE_EXIST));
}

/**
 * Returns the supplied Prolog term as a C++ standard library string
 * file name.
 */
std::string pl_get_file_name(term_t n, int flags)
{
  char *string;
  if (!PL_get_file_name(n, &string, flags)) {
    PL_fail;
  }
  return string;
}

extern "C" {
  install_t install_prolog_magick()
  {
  }
}
