// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#ifndef APP_LOOP_TAG_H_INCLUDED
#define APP_LOOP_TAG_H_INCLUDED
#pragma once

#include "doc/frame.h"

namespace doc {
  class FrameTag;
  class Sprite;
}

namespace app {

  doc::FrameTag* get_shortest_tag(const doc::Sprite* sprite, doc::frame_t frame);
  doc::FrameTag* get_loop_tag(doc::Sprite* sprite);
  doc::FrameTag* create_loop_tag(doc::frame_t from, doc::frame_t to);

} // namespace app

#endif
