:- module(
  imagemagick,
  [
    image_columns/2,    % +File, -Columns
    image_dimensions/3, % +File, -Columns, -Rows
    image_format/2,     % +File, -Format
    image_rows/2,       % +File, -Rows
    is_image/1          % +File
  ]
).

/** <module> ImageMagick binding for Prolog

This library allows inquiring properties of image files.

*/

:- use_module(library(shlib)).

:- use_foreign_library(foreign(imagemagick)).





%! image_columns(+File:atom, -Columns:nonneg) is det.



%! image_dimensions(+File:atom, -Columns:nonneg, -Rows:nonneg) is det.

image_dimensions(File, Columns, Rows) :-
  image_columns(File, Columns),
  image_rows(File, Rows).



%! image_format(+File:atom, -Format:atom) is det.



%! image_rows(+File:atom, -Rows:nonneg) is det.



%! is_image(+File:atom) is semidet.
